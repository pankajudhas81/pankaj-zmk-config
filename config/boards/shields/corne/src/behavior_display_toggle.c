// FilePath: config/boards/shields/corne/src/behavior_display_toggle.c

/*
 * Copyright (c) 2024 Ankur
 * SPDX-License-Identifier: MIT
 *
 * behavior_display_toggle.c
 *
 * Custom ZMK behavior: toggles the OLED display's hardware blanking state
 * (SSD1306 commands 0xAE = off / 0xAF = on) without cutting the ext-power
 * rail.  VCC is never cut — the display controller stays powered the entire
 * time, so 0xAF reliably restores the panel.
 *
 * Locality: BEHAVIOR_LOCALITY_GLOBAL — both central and peripheral halves
 * execute this binding, each toggling their own DT_CHOSEN(zephyr_display)
 * device.  State is tracked per-side via a static bool (one per compiled
 * firmware image), initialised false = display on, which matches boot state.
 *
 * IMPORTANT — sole-owner design: correct round-tripping requires that
 * CONFIG_ZMK_DISPLAY_BLANK_ON_IDLE=n is set in config/corne.conf (it is).
 * Without that override, ZMK defaults BLANK_ON_IDLE to 'y' for SSD1306, and
 * its idle activity handler calls display_blanking_off() on every
 * IDLE→ACTIVE transition, desyncing the handler's state from the hardware
 * so the toggle hits the wrong branch and leaves the screen stuck off.
 * With BLANK_ON_IDLE=n the activity listener is compiled out and this
 * behavior is the only code that ever changes the blank state (deep sleep
 * still powers the whole board down after the sleep timeout as usual).
 */

#define DT_DRV_COMPAT zmk_behavior_display_toggle

#include <drivers/behavior.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zmk/behavior.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

/* Per-side toggle state.  Initialised to false (display on) which matches
 * the state after zmk_display_init() calls unblank_display_cb(). */
static bool display_blanked = false;

static int on_keymap_binding_pressed(struct zmk_behavior_binding *binding,
                                     struct zmk_behavior_binding_event event) {
  const struct device *display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));

  if (!device_is_ready(display)) {
    LOG_ERR("display_toggle: display device not ready");
    return -ENODEV;
  }

  if (display_blanked) {
    display_blanking_off(display);
  } else {
    display_blanking_on(display);
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
    /* Global locality so both halves toggle their own display when the
     * central half processes the keymap binding. */
    .locality = BEHAVIOR_LOCALITY_GLOBAL,
};

BEHAVIOR_DT_INST_DEFINE(0, NULL, NULL, NULL, NULL, POST_KERNEL,
                        CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,
                        &behavior_display_toggle_driver_api);

#endif /* DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT) */
