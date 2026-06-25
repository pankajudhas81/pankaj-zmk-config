# Keyboard Firmware: ZMK, QMK, and Your Setup

> **Your stack:** ZMK firmware · nice!nano v2 controllers · Corne 42-key split · GitHub Actions build · Bluetooth wireless

This guide explains keyboard firmware from first principles, contrasts QMK and ZMK in depth, then dives into exactly how your config repo works — every file, every option, every behavior.

---

## Table of Contents

1. [What Is Keyboard Firmware?](#1-what-is-keyboard-firmware)
2. [QMK — The Community Standard](#2-qmk--the-community-standard)
3. [ZMK — The Wireless Future](#3-zmk--the-wireless-future)
4. [QMK vs ZMK: Full Comparison](#4-qmk-vs-zmk-full-comparison)
5. [Your Controller: nice!nano v2](#5-your-controller-nicenano-v2)
6. [How Your Build Works](#6-how-your-build-works)
7. [ZMK Behaviors — The Building Blocks](#7-zmk-behaviors--the-building-blocks)
8. [Your .keymap File — Line by Line](#8-your-keymap-file--line-by-line)
9. [Your .conf File — Feature Flags](#9-your-conf-file--feature-flags)
10. [Layers Deep Dive](#10-layers-deep-dive)
11. [Home Row Mods Explained](#11-home-row-mods-explained)
12. [Combos in Your Config](#12-combos-in-your-config)
13. [Flashing Firmware](#13-flashing-firmware)
14. [ZMK Studio — GUI Remapping](#14-zmk-studio--gui-remapping)
15. [Common Troubleshooting](#15-common-troubleshooting)
16. [Other Firmware Options](#16-other-firmware-options)
17. [Going Deeper](#17-going-deeper)

---

## 1. What Is Keyboard Firmware?

A keyboard is, at its core, a microcontroller wired to a matrix of switches. When a key is pressed, it closes an electrical circuit at a specific row/column intersection. The microcontroller's job — via firmware — is to:

1. **Scan the matrix** continuously (~1000 times per second) to detect which switches are closed
2. **Apply debouncing** to filter out electrical bounce when switches open/close
3. **Interpret the state** through layers, hold-tap logic, combos, macros
4. **Build HID reports** — standardized USB or Bluetooth packets
5. **Send reports to the host** (your Mac/PC) which translates them to key events

Without firmware, the keyboard is inert copper and silicon. With it, the same physical key can produce `a`, or `LGUI`, or `Page Down`, or move the mouse cursor — depending on context.

```
Physical switch press
        │
        ▼
  Matrix scan (row × col = key position 0–41)
        │
        ▼
  Debounce filter (5 ms in your config)
        │
        ▼
  Hold-tap resolution (tap-preferred / balanced)
        │
        ▼
  Layer stack evaluation (active layers, priority)
        │
        ▼
  Behavior execution (kp, mt, lt, mkp, mmv, macro…)
        │
        ▼
  HID report builder (USB or Bluetooth LE)
        │
        ▼
  Host OS receives keycode event
```

### HID — Human Interface Device

USB and Bluetooth keyboards speak the **HID protocol**, an open standard. A HID report for a keyboard is typically 8 bytes: one byte of modifier flags (Ctrl, Shift, Alt, GUI) plus up to six simultaneous keycodes. The OS never sees "ZMK" or "QMK" — it just receives standard HID packets, making any firmware invisible to software.

Mouse HID reports carry X/Y deltas, buttons, and scroll wheel deltas — this is how `mmv` and `msc` work on your MOUSE layer.

---

## 2. QMK — The Community Standard

**Website:** https://qmk.fm  
**Repository:** https://github.com/qmk/qmk_firmware  
**License:** GPL-2.0

QMK (Quantum Mechanical Keyboard) is the dominant firmware in the custom keyboard hobby. It started in 2015 as a fork of TMK, itself a fork of earlier keyboard projects. Today it supports 3,500+ keyboards.

### Architecture

QMK runs on a bare-metal RTOS called ChibiOS (for ARM) or directly on AVR hardware. It targets:

- **AVR**: ATmega32U4 (the classic Pro Micro, Elite-C) — 8-bit, 32KB flash, no wireless
- **ARM Cortex-M**: STM32, RP2040 (Pi Pico), SAMD — 32-bit, more flash/RAM, still wired

The Pro Micro (ATmega32U4) is the most common controller for Corne builds using QMK. It costs ~$5 USD, communicates over USB, and has no Bluetooth.

### Configuration

QMK config lives in C source files:

```
keyboards/
  crkbd/                     ← the Corne family
    keymaps/
      my_layout/
        keymap.c             ← layer bindings, in C arrays
        config.h             ← #define overrides (tapping term, etc.)
        rules.mk             ← feature flags (MOUSEKEY_ENABLE = yes)
```

A QMK keymap looks like this:

```c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
                              MO(1), KC_SPC, MO(2),  MO(3), KC_ENT, MO(4)
    ),
    // more layers...
};
```

Home row mods in QMK use `MT(MOD_LGUI, KC_A)` — mod-tap, the QMK equivalent of ZMK's `&mt`.

### QMK Features

| Feature | Notes |
|---|---|
| Layers | Up to 16; `MO` (momentary), `TG` (toggle), `TO` (switch), `LT` (layer-tap) |
| Mod-tap | `MT(MOD_LGUI, KC_A)` — hold for GUI, tap for A |
| Tap-dance | One key, multiple tap/hold behaviors |
| Combos | Simultaneous presses → single output |
| Leader keys | Sequence of keys → action (like Vim leader) |
| Macros | Key sequences |
| Auto Shift | Hold any key a bit longer → shifted version |
| Repeat key | Repeat last key press |
| Mouse keys | Software mouse movement (no hardware required) |
| Encoder support | Rotary knob support |
| RGB Matrix | Per-key RGB lighting |
| OLED | Small display support |
| Audio | Speaker/buzzer support |
| Bootmagic | Hold key on plug-in to enter bootloader |

### VIA — Live Remapping Without Reflashing

VIA is one of QMK's killer features. It's a GUI (browser-based at https://usevia.app or desktop app) that communicates with your keyboard over USB HID and lets you:

- Remap any key to any keycode
- Create macros
- Change lighting
- Adjust tap/hold timings

All changes apply instantly without reflashing firmware. The keyboard stores the layout in EEPROM (non-volatile memory).

**VIA requires**: firmware compiled with `VIA_ENABLE = yes`, and a keyboard definition file in VIA's database. Most popular keyboards including Corne are supported.

### Vial — Open Source VIA Alternative

Vial (https://get.vial.today) is an open-source VIA clone with extra features:

- Runs fully offline (desktop app, no server)
- Supports combos, tap-dance, QMK macros in the GUI
- More aggressive feature support

### The Critical Limitation: No Bluetooth

QMK has no native Bluetooth support. Every QMK build requires a USB cable. There are community projects (BlueMicro, QMK on nRF52) but they are unofficial, unmaintained, or hacks. **If you want wireless, QMK is the wrong firmware.** This is why you use ZMK.

---

## 3. ZMK — The Wireless Future

**Website:** https://zmk.dev  
**Repository:** https://github.com/zmkfirmware/zmk  
**License:** MIT

ZMK (Zephyr Mechanical Keyboard) was started by Pete Johanson in 2020, explicitly designed to solve QMK's wireless gap. It is built on top of the **Zephyr RTOS** — an industrial-grade real-time operating system backed by the Linux Foundation, used in everything from hearing aids to medical devices.

### Why Zephyr?

Zephyr has first-class support for the **nRF52840** SoC (System-on-Chip) — the chip in your nice!nano v2. This includes:

- Bluetooth 5.0 stack (SoftDevice / Zephyr BLE host)
- LiPo battery charging management
- Power management / deep sleep
- USB HID
- I²C (for OLED)
- SPI (for displays like nice!view)

Building ZMK on Zephyr means all of this comes for free, battle-tested, and maintained by a large open-source community outside the keyboard hobby.

### Architecture

ZMK uses the **Devicetree** hardware description system — the same format used to describe hardware in Linux kernels. Your keymap file IS a devicetree overlay. This is why `.keymap` files look different from QMK's C arrays.

```
config/
  corne.keymap        ← devicetree overlay: behaviors, combos, macros, layers
  corne.conf          ← Kconfig: feature flags (yes/no switches for modules)
  west.yml            ← west manifest: points to the ZMK repo at a specific revision
  boards/shields/     ← optional: custom shield overrides
```

### ZMK Features

| Feature | Status |
|---|---|
| Bluetooth LE (BLE) | Full support, up to 5 profiles |
| USB HID | Full support |
| Wireless split | BLE between halves (central ↔ peripheral) |
| Layers | Up to 16 |
| Hold-tap (mt, lt) | Full, multiple flavors |
| Combos | Full |
| Macros | Full (press, release, pause, wait-release) |
| Tap-dance | Full |
| Mod-morph | Full (different output with modifier held) |
| Sticky keys | Full (one-shot modifiers/layers) |
| Mouse emulation | Full (mmv, msc, mkp) |
| RGB underglow | Full (WS2812) |
| OLED display | Full (SSD1306) |
| nice!view display | Full (Sharp Memory LCD) |
| Deep sleep | Full (significant battery savings) |
| ZMK Studio | Partially released (live remapping via USB) |
| VIA | Not supported |

### Build System: GitHub Actions

ZMK does not ship pre-compiled firmware. You compile it yourself by pushing your config to GitHub, where GitHub Actions automatically builds firmware for your specific board and shield. This is exactly what your repo does — covered in depth in [Section 6](#6-how-your-build-works).

### ZMK vs QMK: The Split Keyboard Wireless Story

For split keyboards specifically, ZMK's architecture is dramatically different:

**QMK split**: One half is "master" (USB side), other is "slave." They communicate via a physical TRRS cable (or rarely, a pro wireless mod). The slave half is essentially just a matrix scanner that sends raw data over the wire. Only the master talks to USB.

**ZMK split**: Both halves are independent BLE devices. The left half is the **peripheral** (scans its matrix, sends events over BLE). The right half is the **central** (receives peripheral data, merges, sends to host over BLE or USB). They pair once and remember each other. No cable between halves needed — ever.

This is why your Corne has no TRRS cable and can be positioned freely on a desk, on armrests, or angled however you like.

---

## 4. QMK vs ZMK: Full Comparison

| Feature | QMK | ZMK |
|---|---|---|
| **License** | GPL-2.0 | MIT |
| **First release** | 2015 | 2020 |
| **Underlying OS** | Bare-metal / ChibiOS | Zephyr RTOS |
| **Config language** | C (.c, .h) / JSON | Devicetree (.keymap, .conf) |
| **Wireless (Bluetooth)** | ❌ Not supported | ✅ First-class |
| **USB HID** | ✅ | ✅ |
| **Supported controllers** | AVR (Pro Micro) + ARM | nRF52840 (nice!nano, Xiao BLE) + more |
| **Layers** | Up to 16 | Up to 16 |
| **Hold-tap** | ✅ Many options | ✅ Many flavors |
| **Combos** | ✅ | ✅ |
| **Tap-dance** | ✅ | ✅ |
| **Macros** | ✅ Full | ✅ Full |
| **Mod-morph** | ✅ | ✅ |
| **Sticky keys** | ✅ | ✅ |
| **Mouse emulation** | ✅ | ✅ (pointing API) |
| **RGB per-key matrix** | ✅ | ⚠️ Underglow only (WS2812) |
| **OLED** | ✅ | ✅ |
| **VIA / live remap** | ✅ Full (VIA, Vial) | ⚠️ ZMK Studio (partial) |
| **Battery charging** | ❌ | ✅ (nRF52840 + charger IC) |
| **Deep sleep** | Limited | ✅ Weeks-long standby |
| **Community size** | Very large (10+ years) | Growing fast |
| **Keyboard support** | 3,500+ keyboards | ~500+ and growing |
| **Bootloader** | QMK DFU / LUFA | UF2 (drag-and-drop) |
| **Build locally** | ✅ `qmk compile` CLI | ✅ `west build` (complex setup) |
| **Build via CI** | Optional | Standard (GitHub Actions) |
| **Best for** | Wired builds, VIA users | Wireless splits |

### When to choose QMK

- You're building a wired keyboard (no battery concerns)
- You want instant GUI remapping via VIA/Vial
- Your PCB uses a Pro Micro / Elite-C footprint **and** you're going wired
- You want the largest community and most tutorials

### When to choose ZMK (your situation)

- You want wireless — any wireless requirement makes ZMK the answer
- You're using a nice!nano, Seeeduino Xiao BLE, or any nRF52840 board
- Battery life matters (deep sleep, idle power management)
- You want a split with no cable between halves

---

## 5. Your Controller: nice!nano v2

**Made by:** Pete Johanson / Nice Keyboards (https://nicekeyboards.com/nice-nano)  
**Price:** ~$25 USD each; you need two for a split keyboard  
**Footprint:** Pro Micro compatible — drops into any PCB designed for Pro Micro

### The nRF52840 SoC

The nice!nano v2 is powered by Nordic Semiconductor's **nRF52840**, one of the most capable BLE microcontrollers available:

| Spec | Value |
|---|---|
| CPU | ARM Cortex-M4F @ 64 MHz |
| Flash | 1 MB |
| RAM | 256 KB |
| Bluetooth | 5.0 (2 Mbps, long range mode, advertising) |
| USB | USB 2.0 Full Speed (via USB peripheral) |
| GPIO | 48 pins |
| Logic voltage | 3.3V |
| Operating voltage | 1.7V – 3.6V |

The Cortex-M4F has hardware floating-point — overkill for keyboards, but it means ZMK runs with significant headroom for complex behaviors, animations, and future features.

### nice!nano v2 Specifics

```
         nice!nano v2 pinout (Pro Micro compatible)
         ┌─────────────────────────┐
    D3 ──┤ 1               24 ├── RAW (battery +)
    D2 ──┤ 2               23 ├── GND
   GND ──┤ 3               22 ├── RST (reset)
   GND ──┤ 4               21 ├── VCC (3.3V out)
    D1 ──┤ 5               20 ├── F4
    D0 ──┤ 6               19 ├── F5
    D4 ──┤ 7               18 ├── F6
    C6 ──┤ 8               17 ├── F7
    D7 ──┤ 9               16 ├── B1
    E6 ──┤ 10              15 ├── B3
    B4 ──┤ 11              14 ├── B2
    B5 ──┤ 12              13 ├── B6
         └─────────────────────────┘
              [USB-C]  [JST battery]
```

**Key features:**

- **USB-C**: for charging, flashing firmware, and wired USB HID mode
- **JST-PH 2.0 connector**: 3.7V LiPo battery (e.g., 301230 ~100mAh or 301230 ~200mAh)
- **Built-in battery charger**: ~100mA charge rate via MCP73831 or similar
- **Battery voltage divider**: natively reports battery percentage over BLE (your `.conf` sets `CONFIG_ZMK_BATTERY_REPORT_INTERVAL=60`)
- **Reset button**: single tap resets, double-tap enters UF2 bootloader (mass storage mode for flashing)
- **Power switch pins**: P0.13 controls power to the external voltage rail (used for RGB, OLED power management)

### Battery Life Expectations

Battery life depends heavily on what features are active:

| Configuration | Estimated Battery Life (100mAh) |
|---|---|
| RGB on (60% brightness) | 4–8 hours |
| RGB off, OLED on | 1–2 weeks |
| RGB off, OLED off | 3–6 weeks |
| Deep sleep active | Months (while sleeping) |

Your config has:
- `CONFIG_ZMK_RGB_UNDERGLOW_AUTO_OFF_IDLE=y` — RGB turns off when idle ✅
- `CONFIG_ZMK_SLEEP=y` — deep sleep after 15 minutes ✅
- `CONFIG_ZMK_DISPLAY=y` — OLED active (consumes ~5-10mA)
- `CONFIG_ZMK_IDLE_TIMEOUT=600000` — 10 minutes before idle
- `CONFIG_ZMK_IDLE_SLEEP_TIMEOUT=900000` — 15 minutes before deep sleep

This is a solid power configuration. The RGB auto-off and deep sleep together give you multi-week battery life under typical use.

### How Wireless Split Works

The two halves communicate independently over Bluetooth LE:

```
  Left half (PERIPHERAL)           Right half (CENTRAL)
  ┌─────────────────────┐          ┌─────────────────────┐
  │ nice!nano v2        │          │ nice!nano v2        │
  │                     │          │                     │
  │ Scans left matrix   │ ←──BLE──→│ Scans right matrix  │
  │ Sends key events    │          │ Receives left events │
  │                     │          │ Merges both halves   │
  │ Charges via USB     │          │ Sends HID to host   │
  └─────────────────────┘          └──────────┬──────────┘
                                              │
                                         BLE or USB
                                              │
                                         Mac / PC
```

The central (right) half connects to your computer. The peripheral (left) connects only to the central — your computer sees one device. When you connect USB to the left half, it flips to USB HID mode while still relaying right-half events over BLE.

**Pairing between halves**: done once automatically on first boot after flashing. The bond is stored in flash. If you need to re-pair (e.g., after a settings reset flash), hold both reset buttons simultaneously to clear bonds, then power cycle.

### nice!view — The Alternative Display

Your `build.yaml` includes both OLED and nice!view build targets. The **nice!view** is a Sharp Memory LCD:

| | OLED (SSD1306) | nice!view |
|---|---|---|
| Technology | OLED | Sharp Memory LCD |
| Resolution | 128×32 or 128×64 | 160×68 |
| Power | ~5-10mA active, can't partial refresh | ~5µA (extremely low!) |
| Visibility | Bright in dark, washes out in bright light | Excellent in any light |
| Price | ~$5 | ~$20 |
| Requires adapter | No | Yes (nice!view adapter PCB) |

The nice!view's microamp-level power draw makes it dramatically better for battery life. If you want the best combination of display and battery life, nice!view is the upgrade.

---

## 6. How Your Build Works

Your repo is a **ZMK config repository** — it contains only your configuration, not the ZMK source code itself. The ZMK source is fetched during build.

### File Structure

```
yuyudhan-zmk-config/
├── config/
│   ├── corne.keymap        ← your keymap (behaviors, layers, combos, macros)
│   ├── corne.conf          ← Kconfig feature flags
│   ├── west.yml            ← ZMK source location (GitHub, branch: main)
│   └── boards/shields/     ← optional hardware overrides
├── build.yaml              ← build matrix (which board/shield combos to build)
└── .github/workflows/      ← GitHub Actions pipeline
```

### build.yaml — Build Matrix

```yaml
include:
  # OLED display builds
  - board: nice_nano//zmk
    shield: corne_left
    snippet: studio-rpc-usb-uart     # enables ZMK Studio over USB
  - board: nice_nano//zmk
    shield: corne_right

  # nice!view display builds
  - board: nice_nano//zmk
    shield: corne_left nice_view_adapter nice_view
    snippet: studio-rpc-usb-uart
  - board: nice_nano//zmk
    shield: corne_right nice_view_adapter nice_view

  # Reset firmware (clears all bonds/settings)
  - board: nice_nano//zmk
    shield: settings_reset
```

**What each entry means:**

- `board: nice_nano//zmk` — the nice!nano v2 board definition inside ZMK's repo
- `shield: corne_left` — the Corne keyboard shield (PCB + matrix definition) for the left half
- `shield: corne_left nice_view_adapter nice_view` — multiple shields applied together: Corne + display adapter + nice!view
- `snippet: studio-rpc-usb-uart` — adds the ZMK Studio RPC protocol over USB serial (only left half needs it, as the central)
- `shield: settings_reset` — a special shield that produces firmware which clears all stored settings and bonds when flashed

This matrix produces **5 firmware files** per GitHub Actions run:
1. `corne_left-nice_nano_v2-zmk.uf2` (OLED)
2. `corne_right-nice_nano_v2-zmk.uf2` (OLED)
3. `corne_left_nice_view_adapter_nice_view-nice_nano_v2-zmk.uf2`
4. `corne_right_nice_view_adapter_nice_view-nice_nano_v2-zmk.uf2`
5. `settings_reset-nice_nano_v2-zmk.uf2`

### west.yml — The ZMK Source Manifest

```yaml
manifest:
  remotes:
    - name: zmkfirmware
      url-base: https://github.com/zmkfirmware
  projects:
    - name: zmk
      remote: zmkfirmware
      revision: main        ← tracks ZMK's main branch
      import: app/west.yml
  self:
    path: config
```

`west` is Zephyr's meta-tool for managing multi-repo projects. This manifest tells it: "fetch ZMK from GitHub's `zmkfirmware/zmk` repo, at branch `main`, and import its own `west.yml` to pull Zephyr + all dependencies."

**Important**: `revision: main` means you get the latest ZMK every build. If ZMK makes a breaking change, your next push might break. To pin to a stable point, change `revision` to a specific commit hash or tag (e.g., `revision: v0.3.0`). This is a tradeoff: latest features vs. stability.

### GitHub Actions Pipeline

When you `git push` to your repo's default branch:

```
git push
    │
    ▼
GitHub Actions triggers
    │
    ▼
Runner: Ubuntu latest
    │
    ├── Setup: install west, Zephyr SDK, arm-zephyr-eabi toolchain
    │
    ├── west init -l config/          ← initialize workspace from your west.yml
    │
    ├── west update                   ← fetch ZMK source + Zephyr + all modules
    │
    ├── For each build matrix entry:
    │   west build -b nice_nano//zmk -- -DSHIELD="corne_left"
    │       │
    │       ├── Devicetree compilation (merges shield DTS + your .keymap overlay)
    │       ├── Kconfig resolution (merges shield Kconfig + your .conf)
    │       ├── C compilation (Zephyr + ZMK source, ~500+ files)
    │       ├── Linking → zephyr.elf
    │       └── UF2 conversion → corne_left-nice_nano_v2-zmk.uf2
    │
    └── Upload artifacts (all .uf2 files as a .zip)
```

Total build time: typically 5–10 minutes.

**To access your firmware:**
1. Go to your GitHub repo → Actions tab
2. Click the most recent workflow run
3. Scroll to "Artifacts" at the bottom
4. Download the zip, extract, flash the appropriate `.uf2`

### Building Locally (Advanced)

If you want faster iteration without pushing to GitHub:

```bash
# One-time setup (complex; requires Zephyr SDK ~2GB)
pip install west
west init -l config/
west update
west zephyr-export

# Build left half
west build -b nice_nano//zmk -- -DSHIELD=corne_left -DZMK_CONFIG=/path/to/config

# Output: build/zephyr/zmk.uf2
```

Local builds are faster for iteration but require the full Zephyr SDK. For most users, GitHub Actions is the better workflow.

---

## 7. ZMK Behaviors — The Building Blocks

Everything in a ZMK keymap is a **behavior** — a parameterized action triggered by a key event. Behaviors are referenced with `&` in your keymap.

### Basic Key Press: `&kp`

```c
&kp A           // sends keycode A
&kp LGUI        // sends Left GUI (Command on Mac)
&kp LG(C)       // sends Cmd+C (GUI+C modifier combo)
&kp LC(LA(DEL)) // sends Ctrl+Alt+Delete
```

`LG()`, `LC()`, `LA()`, `LS()` wrap a keycode with Left GUI, Ctrl, Alt, Shift. They nest.

### Mod-Tap: `&mt`

```c
&mt LGUI A     // tap=A, hold=LGUI
```

This is the mechanism behind your home row mods. Your `&mt` is configured:

```c
&mt {
    flavor = "tap-preferred";      // tap wins on ambiguity
    tapping-term-ms = <200>;       // 200ms hold/tap decision window
    quick-tap-ms = <175>;          // double-tap within 175ms → tap repeat
    require-prior-idle-ms = <150>; // 150ms idle required before a hold is possible
};
```

See [Section 11](#11-home-row-mods-explained) for a deep dive on these settings.

### Layer-Tap: `&lt`

```c
&lt NAV SPACE   // tap=SPACE, hold=activate NAV layer (momentary)
```

Your thumb keys all use `&lt`. Your `&lt` is configured:

```c
&lt {
    flavor = "balanced";      // hold if another key pressed+released while held
    tapping-term-ms = <200>;
    quick-tap-ms = <175>;
};
```

### Momentary Layer: `&mo`

```c
&mo NAV    // activate NAV layer while held, deactivate on release
```

A simpler version of `&lt` with no tap behavior.

### Layer Toggle: `&tog`

```c
&tog NAV    // toggle NAV layer on/off (stays active after release)
```

Useful for modes you want to "lock into."

### Switch To Layer: `&to`

```c
&to BASE    // permanently switch to BASE layer (deactivates all others)
```

### Mouse Movement: `&mmv`

```c
&mmv MOVE_LEFT     // move cursor left
&mmv MOVE_RIGHT
&mmv MOVE_UP
&mmv MOVE_DOWN
```

The speed is configured via Kconfig (`CONFIG_ZMK_POINTING_DEFAULT_MOVE_VAL`). Your MOUSE layer uses these on HJKL.

### Mouse Scroll: `&msc`

```c
&msc SCRL_UP
&msc SCRL_DOWN
&msc SCRL_LEFT
&msc SCRL_RIGHT
```

On your bottom row of the MOUSE layer.

### Mouse Click: `&mkp`

```c
&mkp LCLK    // left click
&mkp RCLK    // right click
&mkp MCLK    // middle click
&mkp MB4     // button 4 (browser back)
&mkp MB5     // button 5 (browser forward)
```

Your thumb row on MOUSE layer: `&mkp MCLK &mkp LCLK &mkp RCLK`.

### Macros

```c
macro_name: macro_name {
    compatible = "zmk,behavior-macro";
    #binding-cells = <0>;
    bindings = <&kp A &kp B &kp C>;    // sequence of behaviors
};
```

Macro timing primitives:
- `&macro_press` — press without releasing (for holds)
- `&macro_release` — release a previously pressed behavior
- `&macro_pause_for_release` — pause until the macro key is released
- `&macro_tap` — press and release immediately
- `&macro_wait_time N` — wait N milliseconds
- `&macro_tap_time N` — set tap duration for subsequent `&macro_tap`

### Sticky Key: `&sk`

```c
&sk LSHFT    // one-shot shift: press, release, then next key is shifted
```

Useful for capitalizing without holding. After one key, the modifier releases.

### Sticky Layer: `&sl`

```c
&sl NAV    // activate NAV for one keypress, then deactivate
```

### Caps Word: `&caps_word`

```c
&caps_word    // capitalize until a non-word character (like CamelCase typing)
```

You have this on your `combo_caps_word` (F + J).

### Key Repeat: `&key_repeat`

```c
&key_repeat    // re-sends the last key pressed
```

### None and Transparent: `&none` and `&trans`

```c
&none     // do nothing (explicitly blocked position)
&trans    // fall through to the next active layer
```

`&trans` is invisible: if the current layer has `&trans` at position N, ZMK looks at the next lower active layer for that position. `&none` blocks fallthrough entirely.

---

## 8. Your .keymap File — Line by Line

### Includes

```c
#include <behaviors.dtsi>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/ext_power.h>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/outputs.h>
#include <dt-bindings/zmk/pointing.h>
#include <dt-bindings/zmk/rgb.h>
```

Each include pulls in preprocessor definitions from ZMK's source:

| File | Provides |
|---|---|
| `behaviors.dtsi` | `&kp`, `&mt`, `&lt`, `&mo`, `&caps_word`, etc. |
| `bt.h` | `BT_SEL`, `BT_CLR`, `BT_NXT`, `BT_PRV` |
| `ext_power.h` | `EP_TOG` (external power toggle for RGB) |
| `keys.h` | All keycodes: `A`–`Z`, `F1`–`F24`, `LEFT`, `HOME`, etc. |
| `outputs.h` | `OUT_TOG`, `OUT_USB`, `OUT_BLE` |
| `pointing.h` | `mmv`, `msc`, `mkp`, `MOVE_LEFT`, `LCLK`, etc. |
| `rgb.h` | `RGB_TOG`, `RGB_EFF`, `RGB_HUI`, `RGB_SAI`, etc. |

### Layer Number Defines

```c
#define BASE  0
#define NAV   1
#define NUM   2
#define MEDIA 3
#define SYM   4
#define FUN   5
#define MOUSE 6
```

These are C preprocessor macros — they make `&lt NAV SPACE` readable instead of `&lt 1 SPACE`. The numbers are the layer indices ZMK uses internally.

### Key Position Comment

```c
// Corne key positions (42 keys):
// Row 0:  0  1  2  3  4  5    6  7  8  9  10  11
// Row 1: 12 13 14 15 16 17   18 19 20 21  22  23
// Row 2: 24 25 26 27 28 29   30 31 32 33  34  35
// Thumb:          36 37 38   39 40 41
```

This maps physical positions to the 0-based indices used in combo `key-positions`. Extremely useful when adding combos — you can look up which physical keys correspond to positions.

### Behavior Configuration

```c
&mt {
    flavor = "tap-preferred";
    tapping-term-ms = <200>;
    quick-tap-ms = <175>;
    require-prior-idle-ms = <150>;
};

&lt {
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <175>;
};
```

These are **global overrides** of the default `&mt` and `&lt` behaviors. Any `&mt` or `&lt` in your keymap uses these settings.

### Root Node Structure

```
/ {                        ← root node (required by Devicetree)
    combos { … };          ← chord definitions
    macros { … };          ← macro behaviors
    keymap { … };          ← layer definitions
};
```

### Combos Block

```c
combos {
    compatible = "zmk,combos";

    combo_caps_word {
        bindings = <&caps_word>;
        key-positions = <16 19>;      // F (pos 16) + J (pos 19)
        timeout-ms = <30>;
        require-prior-idle-ms = <150>;
    };
    // ...
};
```

Each combo needs:
- `bindings`: what to do
- `key-positions`: which positions must be pressed simultaneously
- `timeout-ms`: window in which both keys must be pressed
- `require-prior-idle-ms`: typing must have been idle for this long (prevents accidental combos during fast typing)
- Optional: `layers = <0 1>` to restrict combo to specific layers

### Macros Block

```c
macros {
    hyper: hyper {
        compatible = "zmk,behavior-macro";
        #binding-cells = <0>;
        bindings =
            <&macro_press &kp LGUI &kp LALT &kp LCTRL &kp LSHFT>,
            <&macro_pause_for_release>,
            <&macro_release &kp LGUI &kp LALT &kp LCTRL &kp LSHFT>;
    };
};
```

The `hyper` macro presses all four modifiers simultaneously (the "hyper" key — all mods at once). `&macro_pause_for_release` holds them until you release the physical key, making it behave like a true modifier. It's placed on the right pinky home row (`SQT` position) in your BASE layer.

### Keymap Block — Layers

```c
keymap {
    compatible = "zmk,keymap";

    base_layer {
        display-name = "BASE";
        bindings = < ... 42 behaviors ... >;
    };

    nav_layer {
        display-name = "NAV";
        bindings = < ... >;
    };
    // ...
};
```

The order of layer definitions determines their index (0, 1, 2…). Layer 0 is always the default/base layer. ZMK displays `display-name` on OLED screens.

---

## 9. Your .conf File — Feature Flags

The `.conf` file uses **Kconfig** syntax — the same system used by the Linux kernel to enable/disable compile-time features. Every `CONFIG_*=y` adds code to the firmware; `=n` removes it.

### Your Current Configuration

```ini
# Bluetooth / HID
CONFIG_ZMK_KEYBOARD_NAME="Corne"        # displayed in Bluetooth device list
CONFIG_BT_GATT_ENFORCE_SUBSCRIPTION=n   # Windows BLE battery fix

# Battery
CONFIG_ZMK_BATTERY_REPORT_INTERVAL=60  # report battery % every 60 seconds

# Debounce
CONFIG_ZMK_KSCAN_DEBOUNCE_PRESS_MS=5   # 5ms press debounce
CONFIG_ZMK_KSCAN_DEBOUNCE_RELEASE_MS=5 # 5ms release debounce

# OLED Display
CONFIG_ZMK_DISPLAY=y
CONFIG_ZMK_DISPLAY_WORK_QUEUE_DEDICATED=y

# Sleep / Power
CONFIG_ZMK_IDLE_TIMEOUT=600000          # 10 min before idle
CONFIG_ZMK_SLEEP=y                      # enable deep sleep
CONFIG_ZMK_IDLE_SLEEP_TIMEOUT=900000    # 15 min before deep sleep

# Mouse
CONFIG_ZMK_POINTING=y                   # enable mouse emulation

# ZMK Studio
CONFIG_ZMK_STUDIO=y                     # enable ZMK Studio protocol
CONFIG_ZMK_STUDIO_LOCKING=n            # don't lock when disconnected
CONFIG_ZMK_STUDIO_LOCK_ON_DISCONNECT=n

# RGB
CONFIG_ZMK_RGB_UNDERGLOW=y
CONFIG_ZMK_RGB_UNDERGLOW_AUTO_OFF_IDLE=y  # RGB off when idle
CONFIG_ZMK_RGB_UNDERGLOW_EFF_START=3      # start on effect #3
CONFIG_ZMK_RGB_UNDERGLOW_BRT_MAX=60       # max brightness 60%
CONFIG_ZMK_RGB_UNDERGLOW_EXT_POWER=n     # don't tie RGB to ext power switch
```

### Common Config Options (not currently set but useful to know)

```ini
# Bluetooth
CONFIG_ZMK_BLE_EXPERIMENTAL_CONN=y     # experimental: better BLE stability
CONFIG_ZMK_BLE_PASSKEY_ENTRY=n         # require passkey pairing

# Mouse speed
CONFIG_ZMK_POINTING_DEFAULT_MOVE_VAL=1500  # cursor pixels/sec (default: 600)
CONFIG_ZMK_POINTING_DEFAULT_SCROLL_VAL=20  # scroll speed

# OLED widgets (commented out in your file)
CONFIG_ZMK_WIDGET_WPM_STATUS=y         # show words per minute
CONFIG_ZMK_WIDGET_LAYER_STATUS=y       # show active layer name
CONFIG_ZMK_WIDGET_PERIPHERAL_STATUS=y  # show if peripheral is connected

# Bongo Cat animation (commented out in your file)
CONFIG_ZMK_WIDGET_BONGO_CAT=y          # animated cat typing

# RGB matrix (if using per-key RGB)
CONFIG_ZMK_RGB_UNDERGLOW=y

# Audio
CONFIG_ZMK_BLE_AUDIO=n                 # not supported on nice!nano
```

### The Debounce Settings

```ini
CONFIG_ZMK_KSCAN_DEBOUNCE_PRESS_MS=5
CONFIG_ZMK_KSCAN_DEBOUNCE_RELEASE_MS=5
```

Debouncing prevents double-registrations from switch bounce. The default in ZMK is 5ms. For very clicky switches (like ALPS SKBL) you might need 8–10ms. For smooth linear switches, 1–2ms works. Your 5ms setting is appropriate for most mechanical switches.

---

## 10. Layers Deep Dive

Your keymap has 7 layers accessed via Miryoku-style thumb holds:

```
Left thumb:  ESC → MEDIA | SPACE → NAV  | TAB → MOUSE
Right thumb: RET → SYM   | BSPC → NUM   | DEL → FUN
```

### Layer Stack Visualization

ZMK evaluates layers from highest number to lowest, using the first non-`&trans` binding found:

```
Active layers (highest priority first):
  Layer 6 (MOUSE) — held via TAB
  Layer 5 (FUN)   — held via DEL
  Layer 4 (SYM)   — held via RET
  Layer 3 (MEDIA) — held via ESC
  Layer 2 (NUM)   — held via BSPC
  Layer 1 (NAV)   — held via SPACE
  Layer 0 (BASE)  — always active
```

Typically only one thumb key is held at a time, activating one layer. But holding two thumb keys activates two layers simultaneously — the higher-numbered one wins for any position both define.

### BASE Layer (Layer 0)

```
TAB   Q  W  E  R  T    Y  U  I  O  P  BSPC
CTRL↗ A  S  D  F  G    H  J  K  L  ' ⌘⌥⌃⇧
SHIFT Z  X  C  V  B    N  M  ,  .  /  ESC
          [ESC] [SPC] [TAB]  [RET] [BSPC] [DEL]
          MED   NAV   MSE    SYM   NUM    FUN
```

Left pinky has `&mt LCTRL ESC` — tap for ESC, hold for Ctrl. Right pinky has `&hyper` (all four modifiers at once).

Home row mods (GACS order):
- A → hold: LGUI (Command ⌘)
- S → hold: LALT (Option ⌥)
- D → hold: LCTRL (Control ^)
- F → hold: LSHFT (Shift ⇧)
- J → hold: RSHFT
- K → hold: RCTRL
- L → hold: RALT
- ' → hold: RGUI

### NAV Layer (Layer 1)

```
----  --  --  --  --  --    redo paste copy cut undo  --
----  ⌘   ⌥   ^   ⇧   --    ←    ↓    ↑   →   CAPS  --
----  --  --  --  --  --    HOME PGDN PGUP END  INS   --
               [--] [--] [--]  [RET] [BSPC] [DEL]
```

Vim arrows on HJKL. Modifiers mirrored on the left (so you can Ctrl+arrow, Shift+arrow, etc., one-handed — left thumb holds NAV, right hand drives arrows with left mods on left home row). This is the Miryoku design philosophy.

### NUM Layer (Layer 2)

```
----  [  7  8  9  ]    --  --  --  --  --  --
----  ;  4  5  6  =    --  ⇧   ^   ⌥   ⌘   --
----  ~  1  2  3  \    --  --  --  --  --  --
              [.] [0] [-]  [--] [--] [--]
```

Numpad layout on the left hand. Dot, zero, minus in thumbs. Brackets, semicolon, equals, tilde, backslash for common programming characters. Right home row mirrors modifiers (for Shift+number, etc.).

### MEDIA Layer (Layer 3)

```
----  --  --  --  --  --    RGB⏻  RGBFX  HUE  SAT  --  --
----  ⌘   ⌥   ^   ⇧   --    PWR⏻  ⏮     VOL↓  VOL↑  ⏭  --
----  --  --  --  --  --    OUT  BT0   BT1  BT2  BT3  BTCLR
              [--] [--] [--]  [⏹] [⏯] [🔇]
```

Bluetooth profile selection (`BT_SEL 0–3`) lets you pair with up to 4 devices and switch between them. `BT_CLR` clears the current profile's bond (useful for re-pairing). `OUT_TOG` switches between USB and Bluetooth output mode.

RGB controls: `RGB_TOG` (on/off), `RGB_EFF` (cycle effects), `RGB_HUI` (hue), `RGB_SAI` (saturation).

### SYM Layer (Layer 4)

```
----  {  &  *  (  }    --  --  --  --  --  --
----  :  $  %  ^  +    --  ⇧   ^   ⌥   ⌘   --
----  ~  !  @  #  |    --  --  --  --  --  --
              [(] [)] [_]  [--] [--] [--]
```

All the symbols you'd use in programming, accessible without shift on the right hand. The layout groups them by type: braces/brackets, math-ish operators, logic/comparison.

### FUN Layer (Layer 5)

```
----  F12 F7 F8 F9 PRNT   --  --  --  --  --  --
----  F11 F4 F5 F6 SLCK   --  ⇧   ^   ⌥   ⌘   --
----  F10 F1 F2 F3 PAUSE  --  --  --  --  --  --
              [APP][SPC][TAB]  [--] [--] [--]
```

Function keys in numpad layout (mirrors NUM). F10–F12 on the pinky home column, F1–F9 in the 3×3 grid. PrintScreen, ScrollLock, Pause/Break for the keys you never use but occasionally need.

### MOUSE Layer (Layer 6)

```
----  --  --  --  --  --    --   --   --   --  --  --
----  ⌘   ⌥   ^   ⇧   --    ←    ↓    ↑    →   --  --
----  --  --  --  --  --    ⟵    ⇩    ⇧    ⟶   --  --
              [--] [--] [--]  [MCK] [LCK] [RCK]
```

HJKL drives mouse movement (right home row). Bottom row drives scroll. Thumb buttons: middle click, left click, right click. Left home row has modifiers for Shift+click, Ctrl+click, etc.

---

## 11. Home Row Mods Explained

Home row mods (HRM) are one of the defining ergonomic features of your layout. They replace the standard modifier positions (far corners of the keyboard) with dual-function home row keys — the most comfortable positions your fingers rest on.

### The GACS Order

Your home row mods follow **GACS** (from pinky to index):
- **G**UI (Command ⌘) — left pinky
- **A**lt (Option ⌥) — left ring
- **C**trl (Control ^) — left middle
- **S**hift (⇧) — left index

This order is deliberate: the most frequently used modifier (Shift) is on the strongest finger (index). The least used (GUI) is on the weakest (pinky). Right hand mirrors it.

Why GACS rather than QWERTY positions? Pure frequency analysis — Shift is used constantly for capitalization; GUI almost never in normal typing.

### The Hold-Tap Problem

Home row mods create a **timing ambiguity**: is `A` held for 200ms because you want GUI, or because you're a slow typist? The firmware must decide.

ZMK's `hold-tap` behavior has multiple **flavors** that resolve this differently:

#### `tap-preferred` (what `&mt` uses in your config)

```
&mt { flavor = "tap-preferred"; tapping-term-ms = <200>; }
```

- If the key is released before `tapping-term-ms` → **tap** (send `a`)
- If another key is pressed AND released while held, AND the hold key was held < `tapping-term-ms` → **tap**
- If held > `tapping-term-ms` without any other key → **hold** (GUI modifier)

This flavor strongly prefers taps. A fast typist typing `as` rapidly won't accidentally trigger `LGUI`. The downside: to trigger a hold modifier, you must hold the key longer than the tapping term even if you've already started pressing another key.

#### `balanced` (what `&lt` uses in your config)

```
&lt { flavor = "balanced"; tapping-term-ms = <200>; }
```

- If another key is pressed AND released while held → **hold** (layer activation)
- If released before anything else → **tap** (keycode)

This flavor favors holds when another key is pressed while it's held. This is ideal for layer keys: you hold a thumb key, press something in the layer, release — the layer key acts as a hold throughout. But it would be terrible for home row mods (every key you typed fast would trigger a modifier).

#### `hold-preferred`

```
flavor = "hold-preferred";
```

- If held longer than `tapping-term-ms` → hold
- If another key pressed while held → hold (regardless of timing)

Aggressive hold detection. Bad for fast typists on home row mods.

#### `tap-unless-interrupted`

- If another key is pressed while held → tap (not hold)
- If held past tapping term → hold

The opposite of `hold-preferred`. Ultra safe for typists who roll keys quickly.

### `require-prior-idle-ms` — The Key to Making HRM Work

This is the most important tuning parameter for home row mods:

```c
require-prior-idle-ms = <150>;
```

If the **prior key event** was less than 150ms ago, the hold-tap behaves as a **tap only** — it will never trigger the hold behavior, regardless of how long it's held.

**Why this matters**: When typing fast (e.g., `sad`), your fingers roll from key to key within 50–100ms. Without `require-prior-idle-ms`, pressing `S` (LALT) and then `A` quickly could trigger `LALT+A` instead of `sa`. With the idle requirement, fast-typed sequences are always plain characters.

**Trade-off**: After typing fast, you must pause 150ms before a home row mod hold will register. For most users this is imperceptible because you naturally pause before shortcuts.

### `quick-tap-ms` — Double-Tap to Repeat

```c
quick-tap-ms = <175>;
```

If a hold-tap key is tapped and then tapped again within `quick-tap-ms`, the second tap activates the tap behavior regardless of how long it's held. This enables key repeat: tap `A` twice quickly → `aa` keeps repeating as long as held.

Without this, holding a home row mod key after a quick prior tap would trigger the modifier instead of repeat. This setting makes `aaaa...` work naturally.

### Tuning Home Row Mods

Common pain points and solutions:

| Problem | Symptom | Fix |
|---|---|---|
| Accidental modifiers while typing | `LGUI` fires when typing fast | Increase `require-prior-idle-ms` (try 200ms) |
| Modifiers too slow to activate | Have to hold a long time | Decrease `tapping-term-ms` (try 150ms) |
| Key repeat not working | Can't hold for repeat | Decrease `quick-tap-ms` or set to 0 |
| Only some HRM keys cause problems | Pinky home row worst | Per-key configuration (see below) |

For per-key tuning, you can define separate `mod-tap` behaviors:

```c
/ {
    behaviors {
        mt_pinky: mt_pinky {
            compatible = "zmk,behavior-hold-tap";
            flavor = "tap-preferred";
            tapping-term-ms = <250>;        // longer for pinky
            quick-tap-ms = <175>;
            require-prior-idle-ms = <200>;  // more idle time for pinky
            bindings = <&kp>, <&kp>;
            #binding-cells = <2>;
        };
    };

    keymap {
        base_layer {
            bindings = <
                // Use &mt_pinky for A and SQT positions:
                &mt_pinky LGUI A  ...
            >;
        };
    };
};
```

---

## 12. Combos in Your Config

You have 14 combos covering three tiers of utility.

### How ZMK Combos Work

A combo fires when all listed `key-positions` are pressed within `timeout-ms` of each other (or the first press within the timeout window). The individual key presses are consumed — you don't see the individual keycodes.

`require-prior-idle-ms` on combos is the same concept as on hold-tap: fast consecutive typing doesn't accidentally trigger combos.

### Your Combo Map

```
Key position reference:
Row 0: [ 0][ 1][ 2][ 3][ 4][ 5]   [ 6][ 7][ 8][ 9][10][11]
       [TAB][ Q][ W][ E][ R][ T]   [ Y][ U][ I][ O][ P][BSP]

Row 1: [12][13][14][15][16][17]   [18][19][20][21][22][23]
       [CTL][ A][ S][ D][ F][ G]   [ H][ J][ K][ L]['][ HYP]

Row 2: [24][25][26][27][28][29]   [30][31][32][33][34][35]
       [SHF][ Z][ X][ C][ V][ B]   [ N][ M][ ,][ .][ /][ESC]

Thumb: [36][37][38]               [39][40][41]
       [MED][NAV][MSE]            [SYM][NUM][FUN]
```

| Combo | Keys | Positions | Timeout | Output |
|---|---|---|---|---|
| Caps Word | F + J | 16 + 19 | 30ms | `&caps_word` |
| ESC | W + E | 2 + 3 | 30ms | `ESC` |
| BSPC | I + O | 8 + 9 | 30ms | `BSPC` |
| DEL | O + P | 9 + 10 | 30ms | `DEL` |
| TAB | S + D | 14 + 15 | 30ms | `TAB` |
| ENTER | K + L | 20 + 21 | 30ms | `RET` |
| Copy | X + C | 26 + 27 | 30ms | `⌘C` |
| Paste | C + V | 27 + 28 | 30ms | `⌘V` |
| Cut | X + V | 26 + 28 | 30ms | `⌘X` |
| Minus | J + M | 19 + 31 | 40ms | `-` |
| Underscore | H + N | 18 + 30 | 40ms | `_` |
| Equal | F + V | 16 + 28 | 40ms | `=` |
| Grave | S + X | 14 + 26 | 40ms | `` ` `` |
| Semicolon | L + ' | 21 + 22 | 30ms | `;` |

**Design notes:**
- Tier 1 (30ms, 150ms idle): high-frequency keys that appear nowhere else (ESC, BSPC, DEL, TAB, RET on layers but convenient on combos)
- Tier 2 (30ms, 150ms idle): clipboard operations on same-hand bottom row, natural rolling motion
- Tier 3 (40ms, 100ms idle): vertical pairs — these are physically harder to mis-fire accidentally, so slightly looser timing
- Cut uses X+V (skip C), requiring deliberate reach — prevents accidental cut while trying to copy or paste

---

## 13. Flashing Firmware

### The UF2 Format

ZMK firmware is delivered as `.uf2` files. UF2 (USB Flashing Format) was created by Microsoft for the MakeCode/micro:bit ecosystem and is now standard for many embedded platforms. The nice!nano bootloader (Adafruit nRF52 bootloader) implements a USB Mass Storage Device that accepts `.uf2` files.

### Flashing Process

**Both halves need to be flashed separately**, with their respective firmware files.

```
Step 1: Download firmware
  GitHub → Actions → latest run → Artifacts → download zip
  Extract: you get several .uf2 files

Step 2: Enter bootloader on left half
  Double-tap the reset button on the back of the left half
  ↓
  A USB drive appears: "NICENANO" (or similar)
  The RGB (if present) may pulse to indicate bootloader mode

Step 3: Flash left half
  Drag corne_left-nice_nano_v2-zmk.uf2 onto the "NICENANO" drive
  ↓
  The drive disappears (ejects) and the keyboard reboots with new firmware
  Takes 2-5 seconds

Step 4: Repeat for right half
  Double-tap reset on right half
  Drag corne_right-nice_nano_v2-zmk.uf2 onto its drive

Step 5: Verify
  Open a text editor, type — both halves should work
```

### Which .uf2 to Use?

From your `build.yaml`, you get four keyboard firmware files plus one reset:

| File | Use when |
|---|---|
| `corne_left-nice_nano_v2-zmk.uf2` | Left half, OLED display |
| `corne_right-nice_nano_v2-zmk.uf2` | Right half, OLED display |
| `corne_left_nice_view_adapter_nice_view-...uf2` | Left half, nice!view display |
| `corne_right_nice_view_adapter_nice_view-...uf2` | Right half, nice!view display |
| `settings_reset-nice_nano_v2-zmk.uf2` | Clear all bonds and settings (both halves) |

You probably have OLED displays, so use the first two.

### The Settings Reset Firmware

When both halves stop communicating or won't pair to a new computer:

1. Flash `settings_reset-nice_nano_v2-zmk.uf2` to the **left half**
2. Flash `settings_reset-nice_nano_v2-zmk.uf2` to the **right half**
3. Reflash both halves with their proper firmware
4. Power cycle both halves — they'll re-pair automatically

This clears all BLE bonds (stored pairings) and Kconfig settings, starting fresh.

### Bluetooth Profile Management

Your MEDIA layer has `&bt BT_SEL 0` through `&bt BT_SEL 3` — four Bluetooth profiles. Each profile stores one paired device. To pair a new device to a profile:

1. Activate MEDIA layer (hold ESC thumb key)
2. Press BT0–BT3 to select a profile
3. On your Mac/PC: System Preferences → Bluetooth → pair with "Corne"

To switch between paired devices: select the profile for that device on the MEDIA layer.

`&bt BT_CLR` clears the current profile's stored bond — useful if a device forgets your keyboard (after factory reset, new OS install, etc.).

`&out OUT_TOG` toggles between Bluetooth and USB output — when your keyboard is connected via USB cable, use this to force USB HID mode instead of BLE.

---

## 14. ZMK Studio — GUI Remapping

ZMK Studio is the in-progress answer to QMK's VIA. Your config already has it enabled:

```ini
CONFIG_ZMK_STUDIO=y
CONFIG_ZMK_STUDIO_LOCKING=n
CONFIG_ZMK_STUDIO_LOCK_ON_DISCONNECT=n
```

And your left half build includes `snippet: studio-rpc-usb-uart`, which adds the USB serial RPC protocol ZMK Studio uses.

### Current Status (as of 2025)

ZMK Studio can:
- Display your current keymap
- Remap basic keycodes live
- Store changes in flash (survive power cycle)

ZMK Studio cannot yet (roadmap):
- Edit hold-tap behaviors (tapping-term, flavor)
- Edit combos
- Edit macros
- Full parity with editing the `.keymap` file directly

### Using ZMK Studio

1. Connect left half via USB-C
2. Open https://zmk.studio in a Chromium-based browser (Chrome, Edge — Firefox not supported due to WebSerial API)
3. Click "Connect" → select your keyboard's serial port
4. Edit keycodes in the GUI — changes apply immediately and are stored in flash
5. To make changes permanent in your repo (so they survive a reflash), export the modified keymap and update `corne.keymap`

### The Unlock Flow

With `CONFIG_ZMK_STUDIO_LOCKING=n`, Studio connects without requiring a physical unlock sequence. If locking were enabled, you'd need to press a key combination on the keyboard to authorize the Studio connection (a security feature to prevent remote remapping).

---

## 15. Common Troubleshooting

### Left and Right Halves Not Syncing

**Symptom**: Only one half registers, or keystrokes are inconsistent.

**Causes and fixes**:

1. **BLE bond mismatch**: Both halves may have stale bond data. Flash `settings_reset` to both halves, then reflash proper firmware. They'll auto-pair fresh.

2. **Battery too low**: If either half drops below ~3.3V, BLE becomes unstable. Charge both halves.

3. **Distance**: BLE 5.0 range on nRF52840 is theoretically 50m open air, but metal desks, monitors, and nearby 2.4GHz WiFi can reduce effective range to a few meters between halves. Keep halves within 2m of each other.

4. **USB interference**: Some USB 3.0 ports emit 2.4GHz interference that disrupts BLE. Try a different USB port, or plug into a USB 2.0 hub.

### Home Row Mods Misfiring

**Symptom**: Modifier keys trigger unintentionally during normal typing.

**Fixes**:
- Increase `require-prior-idle-ms` from 150ms to 200ms
- Increase `tapping-term-ms` from 200ms to 250ms
- Both changes make HRM less sensitive to fast typists

**Symptom**: Modifiers don't activate when you want them to.

**Fixes**:
- Decrease `tapping-term-ms` from 200ms to 150ms
- Ensure you're pausing briefly before the intended shortcut

### Build Fails in GitHub Actions

**Common causes**:

1. **Syntax error in `.keymap`**: ZMK's Devicetree parser is strict. Missing `;`, mismatched `<>`, wrong indentation, undefined reference (using `&behavior_name` before defining it).

   Fix: check the Actions log → expand the failing step → look for "error:" lines pointing to line numbers.

2. **Invalid keycode**: Referencing `LG(Q)` with wrong syntax, or a keycode that doesn't exist in the version of ZMK you're using.

3. **west.yml pointing to broken ZMK commit**: Since you track `revision: main`, a ZMK regression can break your build. Fix: pin to the last working commit hash.

4. **Config option typo**: `CONFIG_ZMK_POINTNG=y` (missing 'I') silently fails or causes build errors.

### Key Not Registering on Mouse Layer

**Symptom**: `mmv` or `mkp` does nothing.

**Check**: Ensure `CONFIG_ZMK_POINTING=y` is in `corne.conf`. You have it, so this shouldn't be your issue, but if you ever strip the config down, this is the first thing to add back.

### Bluetooth Dropout / Reconnect Lag

**Symptom**: Occasional missed keystrokes or 1-2 second reconnect when waking the keyboard.

**Causes**:
- Deep sleep: when keyboard sleeps and you press a key, BLE reconnection takes 1-3 seconds. Normal behavior.
- macOS power management: macOS aggressively manages BLE connections. In System Preferences → Energy Saver, disable "Wake for network access" and ensure Bluetooth is always on.
- Profile mismatch: check you're on the right BT profile for the current device.

**Tune sleep timing** in `.conf`:
```ini
CONFIG_ZMK_IDLE_TIMEOUT=300000      # 5 min (shorter idle period)
CONFIG_ZMK_IDLE_SLEEP_TIMEOUT=1800000  # 30 min (longer before deep sleep)
```

### RGB Not Working

1. Check `CONFIG_ZMK_RGB_UNDERGLOW=y` in conf ✅ (you have it)
2. Check `CONFIG_ZMK_RGB_UNDERGLOW_EXT_POWER=n` — if this is `y`, RGB is tied to the external power rail which may not be enabled
3. On MEDIA layer: `&rgb_ug RGB_TOG` toggles RGB — make sure it's on
4. OLED display and RGB share GPIO — ensure no pin conflict in shield definition

---

## 16. Other Firmware Options

### KMK — Python on CircuitPython

**Website**: https://kmkfw.io  
**Language**: Python (MicroPython / CircuitPython)  
**Controllers**: RP2040 (Pi Pico), SAMD21 (Adafruit boards), STM32

KMK runs on top of CircuitPython, meaning your keyboard config is a `code.py` file you edit in a text editor and save directly to the keyboard's USB drive — no compilation. Just save and it reloads.

**Pros**: Extremely beginner-friendly, instant reload (no flash cycle), Python is readable.  
**Cons**: Python is slow — key scan rates are lower (200–500Hz vs 1000Hz), latency is higher, complex behaviors feel less snappy. Not designed for wireless. Limited battery support.

**Use KMK if**: You want to prototype layouts rapidly and don't care about wireless or top-tier performance.

### BlueMicro — Bluetooth on Pro Micro footprint

**Repository**: https://github.com/jpconstantineau/BlueMicro_BLE  
**Controllers**: nRF52832 boards (original Bluetooth Pro Micro clones)  
**Status**: Largely replaced by ZMK

BlueMicro predates ZMK and solved the same problem (wireless on Pro Micro footprint). It uses Arduino-style programming and targets older nRF52832 chips (less capable than nRF52840). ZMK is strictly superior in almost every way now; BlueMicro sees little active development.

### Kaleidoscope — Keyboardio's Firmware

**Website**: https://kaleidoscope.readthedocs.io  
**Controllers**: ATmega32U4 (Arduino Leonardo)  
**Used by**: Keyboardio Model 01, Model 100

Kaleidoscope is polished but closed-ecosystem — it's designed specifically for Keyboardio products. Rich plugin system, good documentation, but no real community expansion to other keyboards. Not relevant to the Corne.

### FAK — Firmware for Another Keyboard

**Repository**: https://github.com/semickolon/fak  
**Language**: Nickel (functional config language)  
**Controllers**: CH552 (ultra-cheap USB MCU)

An experimental firmware for extremely budget builds. The CH552 costs <$1. Interesting for budget projects but very limited feature set and tiny community.

### Firmata / Custom

Some keyboards run Firmata (Arduino) or entirely custom firmware for specialized use cases (MIDI keyboards, macro pads). Not relevant to a serious keyboard layout.

### Summary

| Firmware | Wireless | Config | Maturity | Best For |
|---|---|---|---|---|
| **ZMK** ✓ | Yes | Devicetree | Active | Wireless splits |
| **QMK** | No | C / JSON | Very mature | Wired + VIA |
| **KMK** | Partial | Python | Moderate | Prototyping |
| **BlueMicro** | Yes | Arduino | Unmaintained | Legacy boards |
| **Kaleidoscope** | No | C++ | Active | Keyboardio only |

---

## 17. Going Deeper

### Essential References

- **ZMK Documentation**: https://zmk.dev/docs — the authoritative reference for all behaviors, Kconfig options, and shield development
- **ZMK Keymap Behavior Reference**: https://zmk.dev/docs/keymaps/behaviors
- **ZMK Discord**: https://zmk.dev/community/discord — active, responsive community; the ZMK maintainers are present
- **QMK Documentation**: https://docs.qmk.fm — for when you buy a wired keyboard
- **Miryoku Layout**: https://github.com/manna-harbour/miryoku — the layout philosophy your config is based on; excellent documentation of the design decisions
- **nice!nano Documentation**: https://nicekeyboards.com/docs/nice-nano — pinout, battery specs, bootloader details
- **ZMK GitHub**: https://github.com/zmkfirmware/zmk — source code; reading the actual C source for behaviors is often the fastest way to understand edge cases

### Keymap Visualizers

- **keymap-drawer**: https://github.com/caksoylar/keymap-drawer — generates SVG/PNG diagrams from ZMK keymap files (your repo has `corne_keymap.svg` — likely generated by this)
- **Keyboard Layout Editor**: http://www.keyboard-layout-editor.com — web-based key layout visualization

### Learning Resources

- **Pascal Getreuer's QMK/ZMK articles**: https://getreuer.info/posts/keyboards/ — exceptionally detailed guides on home row mods, custom shift keys, word-at-a-time deletion, and more. Primarily QMK but concepts translate directly.
- **Precondition's HRM guide**: https://precondition.github.io/home-row-mods — the most cited guide on tuning home row mods
- **A Moist Keyboard Enthusiast's ZMK guide**: the ZMK community wiki has community-contributed guides on advanced topics

### Community

- **r/ErgoMechKeyboards**: Reddit community for ergonomic keyboard discussion
- **r/zmk**: Smaller, ZMK-specific subreddit
- **ZMK Discord**: Best place for real-time help; search before asking
- **40% Keyboards Discord**: Active community for small keyboards including Corne
- **Dactyl Discord**: Community around the Dactyl family, lots of ZMK users

### What to Learn Next

Given your current setup, the natural progression for firmware knowledge:

1. **Tune home row mods**: Adjust `tapping-term-ms` and `require-prior-idle-ms` to your typing speed — this is the highest-ROI change
2. **Add per-key behaviors**: Create `&mt_slow` / `&mt_fast` variants with different timings for different finger positions
3. **Explore mod-morph**: Different output when Shift is held — e.g., `,` → `;`, `.` → `:` without dedicated symbol layers
4. **ZMK Studio**: When it reaches feature parity, use it for rapid iteration
5. **Build locally**: Set up west + Zephyr SDK for fast iteration without push/wait cycles
6. **Custom shields**: If you ever build a board from scratch, learn shield development in ZMK
