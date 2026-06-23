/*
 * ═══════════════════════════════════════════════════════════════════
 * FILE: config/boards/shields/corne/custom_config.h
 * ROLE: Optional C preprocessor overrides for RGB animation effects.
 *
 * Included by the build to enable specific RGB animations at compile time.
 * All defines here are pure compile-time flags; nothing allocates memory or
 * runs code. If you add new animation defines, put them here. Removing a
 * define excludes that animation's code from the linked binary entirely.
 * ═══════════════════════════════════════════════════════════════════
 */

// Standard include guard using the compiler-native pragma.
// `#pragma once` ensures this header is processed only once per translation
// unit even if it is transitively included from multiple places — functionally
// equivalent to a classic #ifndef/#define/#endif guard but less boilerplate.
#pragma once

// Enable all built-in RGB lighting animation effects.
// RGBLIGHT_ANIMATIONS is a QMK-heritage macro that, when defined, compiles
// in the full suite of RGB underglow animations (breathing, rainbow cycle,
// swirl, snake, knight, etc.) rather than just static colour.
// Note: this symbol originates in QMK's rgblight subsystem.  In ZMK the
// RGB animation API is different, so this define may be vestigial for pure
// ZMK builds — it is kept here for compatibility with any QMK-derived
// display or RGB helper code that checks for it.
#define RGBLIGHT_ANIMATIONS

// Enable the Rainbow Moving Chevron animation specifically.
// This selects one animation effect from the RGB matrix animation library
// (the chevron pattern that sweeps rainbow colours across the keys in a
// V-shape).  Defining this at compile time ensures the effect's code is
// linked into the binary; without it the effect would not be available at
// runtime regardless of any keymap or config setting.
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
