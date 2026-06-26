// FilePath: config/boards/shields/corne/src/behavior_display_toggle.c

/*
 * Copyright (c) 2024 Ankur
 * SPDX-License-Identifier: MIT
 *
 * behavior_display_toggle.c
 *
 * Custom ZMK behavior: toggles the keyboard's screen on and off.  Runs on both
 * halves (BEHAVIOR_LOCALITY_GLOBAL): the central relays the binding to every
 * peripheral and then runs it locally, so each side toggles its own
 * DT_CHOSEN(zephyr_display).
 *
 * Two display families are handled by the SAME code path — hardware blanking
 * first, with an LVGL fallback only when it is unsupported:
 *   - SSD1306 OLED (solomon,ssd1306fb): display_blanking_on/off powers the
 *     panel down (0xAE) / up (0xAF) and returns 0.  On success we STOP here —
 *     this is the native, artifact-free path; an LVGL screen swap on top of it
 *     corrupts the OLED's rendering after a toggle.
 *   - nice!view / Sharp memory LCD (sharp,ls0xx): its driver has no
 *     display-enable GPIO, so display_blanking_on/off return -ENOTSUP
 * (non-zero) and do NOTHING.  Only then do we blank at the LVGL layer — load an
 * empty black screen, and restore by reloading the status screen. The
 * hardware-blanking return value selects the path at runtime, so no
 * compile-time knowledge of which panel is fitted is needed.
 *
 * All LVGL / display work runs on zmk_display_work_q() (never the keymap or BLE
 * thread) — the same queue ZMK's own display tick uses.
 *
 * REQUIRES: CONFIG_ZMK_DISPLAY_BLANK_ON_IDLE=n (set in config/corne.conf) so
 * ZMK's idle handler does not also drive display_blanking_* and desync this
 * behavior's flag from the panel.  Deep sleep re-inits the display on wake,
 * resetting the statics below to their boot values (display on).
 */

#define DT_DRV_COMPAT zmk_behavior_display_toggle

#include <drivers/behavior.h>
#include <lvgl.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/kernel.h>
#include <zmk/behavior.h>
#include <zmk/display.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

static const struct device *display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));

/* Per-side state.  false = display on, matching boot. */
static bool display_blanked = false;

/* Status screen captured when we blank, restored when we unblank. */
static lv_obj_t *saved_screen = NULL;
/* Lazily-created all-black screen shown while blanked. */
static lv_obj_t *blank_screen = NULL;

static void blank_work_cb(struct k_work *work) {
  /* Hardware blanking first.  SSD1306 OLED: powers the panel off (0xAE) and
   * returns 0 — the native, artifact-free path, so we STOP here.  Layering an
   * LVGL screen swap on top of it corrupts the OLED's rendering after a toggle.
   */
  if (display_blanking_on(display) == 0) {
    return;
  }

  /* No hardware blanking (nice!view ls0xx returns -ENOTSUP): blank at the LVGL
   * layer with an all-black screen. */
  if (blank_screen == NULL) {
    blank_screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(blank_screen, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(blank_screen, LV_OPA_COVER, LV_PART_MAIN);
  }
  saved_screen = lv_screen_active();
  lv_screen_load(blank_screen);
  /* Flush the blank frame now (this is what actually blanks a nice!view). */
  lv_task_handler();
}

static void unblank_work_cb(struct k_work *work) {
  /* Mirror of blank: hardware unblanking first (SSD1306: 0xAF, returns 0 =
   * done).  Only fall back to the LVGL restore when hardware blanking is
   * unsupported (nice!view). */
  if (display_blanking_off(display) == 0) {
    return;
  }

  if (saved_screen != NULL) {
    lv_screen_load(saved_screen);
    /* Re-render the status screen into the framebuffer. */
    lv_task_handler();
  }
}

K_WORK_DEFINE(blank_work, blank_work_cb);
K_WORK_DEFINE(unblank_work, unblank_work_cb);

static int on_keymap_binding_pressed(struct zmk_behavior_binding *binding,
                                     struct zmk_behavior_binding_event event) {
  if (!device_is_ready(display)) {
    LOG_ERR("display_toggle: display device not ready");
    return -ENODEV;
  }
  /* Nothing to toggle until the display subsystem (and LVGL) is up. */
  if (!zmk_display_is_initialized()) {
    return ZMK_BEHAVIOR_OPAQUE;
  }

  if (display_blanked) {
    k_work_submit_to_queue(zmk_display_work_q(), &unblank_work);
  } else {
    k_work_submit_to_queue(zmk_display_work_q(), &blank_work);
  }
  display_blanked = !display_blanked;

  return ZMK_BEHAVIOR_OPAQUE;
}

static int on_keymap_binding_released(struct zmk_behavior_binding *binding,
                                      struct zmk_behavior_binding_event event) {
  return ZMK_BEHAVIOR_OPAQUE;
}

static const struct behavior_driver_api behavior_display_toggle_driver_api = {
    .binding_pressed = on_keymap_binding_pressed,
    .binding_released = on_keymap_binding_released,
    .locality = BEHAVIOR_LOCALITY_GLOBAL,
};

BEHAVIOR_DT_INST_DEFINE(0, NULL, NULL, NULL, NULL, POST_KERNEL,
                        CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,
                        &behavior_display_toggle_driver_api);

#endif /* DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT) */
