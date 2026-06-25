// FilePath: config/boards/shields/corne/src/behavior_display_toggle.c

/*
 * Copyright (c) 2024 Ankur
 * SPDX-License-Identifier: MIT
 *
 * behavior_display_toggle.c
 *
 * Custom ZMK behavior: toggles the OLED display's hardware blanking state
 * (SSD1306 commands 0xAE = off / 0xAF = on) without cutting the ext-power
 * rail.  The display controller stays powered so the display reliably comes
 * back on the second press — this sidesteps ZMK issue #674 (display not
 * re-initialising after VCC is cut by ext_power EP_TOG).
 *
 * Locality: BEHAVIOR_LOCALITY_GLOBAL — both central and peripheral halves
 * execute this binding, each toggling their own DT_CHOSEN(zephyr_display)
 * device.  State is tracked per-side via a static bool (one per compiled
 * firmware image), initialised false = display on, which matches boot state.
 *
 * Known edge case: ZMK's display/main.c calls display_blanking_off() on every
 * ZMK_ACTIVITY_IDLE → ZMK_ACTIVITY_ACTIVE transition (main.c:176-177).  If
 * the keyboard sits idle past CONFIG_ZMK_IDLE_TIMEOUT and a key is then
 * pressed, the display will wake even if it was manually blanked here.  This
 * only matters after the full idle timeout (~10 min by default) and is
 * expected behaviour — the display returns to its natural active state.
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
