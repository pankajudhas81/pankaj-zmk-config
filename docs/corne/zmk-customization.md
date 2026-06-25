# ZMK Keymap Customization Guide

> **This is your "I want to change X" reference.** All examples use your actual `config/corne.keymap` and `config/corne.conf`. Nothing here is theoretical — every code snippet is ready to paste.
>
> For ZMK internals, behaviors, and firmware concepts, see `docs/corne/firmware.md`.

---

## 1. The Edit → Build → Flash Loop

Every change to your keyboard goes through three steps. There are no exceptions.

### Step 1 — Edit the file

Open `config/corne.keymap` (for key changes) or `config/corne.conf` (for feature toggles). Make your edit, save.

### Step 2 — Commit and push

```bash
git add config/corne.keymap
git commit -m "Change: describe what you did"
git push
```

GitHub Actions automatically starts a build. You do not need to run anything locally.

### Step 3 — Download and flash

1. Go to `https://github.com/pankajudhas81/pankaj-zmk-config/actions`
2. Click the most recent workflow run (the one with your commit message)
3. Scroll to the bottom — click **Artifacts** → download the zip
4. Unzip it. You will find files for each build target. The ones you need are named after `corne_left` and `corne_right` (the OLED builds, first two entries in `build.yaml`)

**Flashing each half:**

1. Plug the **left** half into USB
2. Double-tap the reset button on the nice!nano (the small button on the controller, not the keyboard's reset). A USB drive called `NICENANO` appears on your Mac
3. Drag the `corne_left` `.uf2` file onto the drive. It disappears immediately — that is normal
4. Unplug left, plug in **right** half
5. Repeat with the `corne_right` `.uf2` file

> **Build time:** ~2–3 minutes. The first build after a dependency change can take 5–10 minutes.

> **Left vs right matters.** Do not flash the wrong file to the wrong half. The left half runs ZMK and connects to your computer; the right half is a peripheral that connects to the left half over Bluetooth. Each has different firmware.

> **settings_reset:** The `build.yaml` also builds a `settings_reset` firmware. Use this only if your halves won't pair to each other — flash it to both halves, then reflash normal firmware. It wipes all stored BT bonds.

---

## 2. The Keymap File Structure — Quick Reference

Here is the skeleton of `config/corne.keymap` with every section annotated. Line numbers match the current file.

```c
// Lines 1–25: copyright + includes
#include <behaviors.dtsi>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/keys.h>
// ... more includes for RGB, pointing, etc.

// Lines 27–33: layer number constants
#define BASE  0
#define NAV   1
#define NUM   2
#define MEDIA 3
#define SYM   4
#define FUN   5
#define MOUSE 6

// Lines 35–39: key position map (refer to this constantly — it's your map)
// Row 0:  0  1  2  3  4  5    6  7  8  9  10  11
// Row 1: 12 13 14 15 16 17   18 19 20 21  22  23
// Row 2: 24 25 26 27 28 29   30 31 32 33  34  35
// Thumb:          36 37 38   39 40 41

// Lines 41–46: global &mt (hold-tap for home row mods) config
&mt {
    flavor = "tap-preferred";
    tapping-term-ms = <200>;
    // ...
};

// Lines 48–52: global &lt (layer-tap for thumb keys) config
&lt {
    flavor = "balanced";
    tapping-term-ms = <200>;
    // ...
};

/ {
    // Lines 55–161: combos (two-key shortcuts)
    combos { ... };

    // Lines 163–172: macros (multi-key sequences)
    macros { ... };

    // Lines 174–246: the actual keymap
    keymap {
        compatible = "zmk,keymap";

        base_layer { ... };   // layer 0
        nav_layer { ... };    // layer 1
        num_layer { ... };    // layer 2
        media_layer { ... };  // layer 3
        sym_layer { ... };    // layer 4
        fun_layer { ... };    // layer 5
        mouse_layer { ... };  // layer 6
    };
};
```

**The rule:** layers are just arrays of 42 bindings. Position 0 is always the top-left key. Position 41 is the rightmost thumb key. Order in the file = order on the keyboard.

---

## 3. How to Change a Key Binding

### The position map

Your keymap file (lines 35–39) contains this comment — burn it into your memory:

```
Row 0:  0  1  2  3  4  5    6  7  8  9  10  11
Row 1: 12 13 14 15 16 17   18 19 20 21  22  23
Row 2: 24 25 26 27 28 29   30 31 32 33  34  35
Thumb:          36 37 38   39 40 41
```

Mapped to your physical keys on BASE layer:

```
 0:TAB    1:Q    2:W    3:E    4:R    5:T  |   6:Y    7:U    8:I    9:O   10:P   11:BSPC
12:CTL   13:A   14:S   15:D   16:F   17:G  |  18:H   19:J   20:K   21:L   22:'   23:HYPER
        ESC   GUI   ALT  CTL  SHF            SHF   CTL   ALT   GUI
24:SHF  25:Z   26:X   27:C   28:V   29:B  |  30:N   31:M   32:,   33:.   34:/   35:ESC
                      36:MEDIA 37:NAV 38:MOUSE | 39:SYM 40:NUM 41:FUN
                         ESC    SPC    TAB   |   RET   BSPC   DEL
```

Row 0 is the top row (where Q, W, E… live). Row 1 is home row (A, S, D…). Row 2 is bottom row (Z, X, C…). Positions 0, 12, 24 and 11, 23, 35 are the Corne's extra outer column.

### Finding the right line

Each layer's bindings are a flat list of 42 entries, written across 4 lines in your file:

- **Line 1 of bindings** = positions 0–11 (top row, left to right)
- **Line 2 of bindings** = positions 12–23 (home row)
- **Line 3 of bindings** = positions 24–35 (bottom row)
- **Line 4 of bindings** = positions 36–41 (thumb row)

For the BASE layer, these are file lines 180–183.

### Binding syntax

```
&kp KEY          — tap to send a keycode (most common)
&mt MOD KEY      — hold for modifier, tap for key (home row mods)
&lt LAYER KEY    — hold to activate layer, tap for key (thumb keys)
&trans           — transparent: fall through to the layer below
&none            — blocked: do nothing
&mo LAYER        — hold to momentarily activate layer (no tap action)
&tog LAYER       — toggle layer on/off
```

### Real example: change position 0 from TAB to ESC

**Current** (line 180 of corne.keymap):
```c
&kp TAB        &kp Q       &kp W       &kp E       ...
```

**After:**
```c
&kp ESC        &kp Q       &kp W       &kp E       ...
```

That is the entire change. The key at position 0 (top-left of the left half) now sends ESC.

### Key code reference

Full list: **https://zmk.dev/docs/codes**

Common ones not obvious from the name:

| You want         | ZMK code        |
|------------------|-----------------|
| Backspace        | `BSPC`          |
| Delete           | `DEL`           |
| Enter            | `RET`           |
| Escape           | `ESC`           |
| Tab              | `TAB`           |
| Caps Lock        | `CAPS`          |
| Print Screen     | `PSCRN`         |
| `[`              | `LBKT`          |
| `]`              | `RBKT`          |
| `;`              | `SEMI`          |
| `'`              | `SQT`           |
| `` ` ``          | `GRAVE`         |
| `-`              | `MINUS`         |
| `=`              | `EQUAL`         |
| `\`              | `BSLH`          |
| `/`              | `FSLH`          |
| Left GUI (⌘/Win) | `LGUI`          |
| Right GUI        | `RGUI`          |
| Left Alt / Opt   | `LALT`          |
| Cmd+C (macOS)    | `LG(C)`         |
| Cmd+Shift+Z      | `LG(LS(Z))`     |

---

## 4. How to Add or Change a Combo

Combos are defined in the `combos { }` block (lines 55–161 of your file). Each combo fires when you press two keys within a time window.

### Combo syntax

```c
combo_name {
    bindings = <&kp KEY>;          // what gets sent
    key-positions = <N M>;         // which two positions (from the map above)
    timeout-ms = <30>;             // how many ms you have to press both
    require-prior-idle-ms = <150>; // key must be idle this long first
};
```

### Your existing combos

| Combo name       | Key positions | Physical keys   | Output             | Timeout |
|------------------|---------------|-----------------|--------------------|---------|
| combo_caps_word  | 16 + 19       | F + J           | Caps Word toggle   | 30ms    |
| combo_esc        | 2 + 3         | W + E           | Escape             | 30ms    |
| combo_bspc       | 8 + 9         | I + O           | Backspace          | 30ms    |
| combo_del        | 9 + 10        | O + P           | Delete             | 30ms    |
| combo_tab        | 14 + 15       | S + D           | Tab                | 30ms    |
| combo_enter      | 20 + 21       | K + L           | Enter              | 30ms    |
| combo_copy       | 26 + 27       | X + C           | ⌘C (copy)          | 30ms    |
| combo_paste      | 27 + 28       | C + V           | ⌘V (paste)         | 30ms    |
| combo_cut        | 26 + 28       | X + V (skip C)  | ⌘X (cut)           | 30ms    |
| combo_minus      | 19 + 31       | J + M (vertical)| `-`                | 40ms    |
| combo_underscore | 18 + 30       | H + N (vertical)| `_`                | 40ms    |
| combo_equal      | 16 + 28       | F + V (vertical)| `=`                | 40ms    |
| combo_grave      | 14 + 26       | S + X (vertical)| `` ` ``            | 40ms    |
| combo_semi       | 21 + 22       | L + '           | `;`                | 30ms    |

### `timeout-ms` vs `require-prior-idle-ms`

- **`timeout-ms`**: the window to hit both keys. 30ms = you have 30 milliseconds from the first keypress to hit the second. Too low and combos don't fire. Too high and they fire accidentally.
- **`require-prior-idle-ms`**: the keyboard must have been idle for this long before a combo can register. This is the main guard against accidental combos while typing. 150ms means if you typed a key in the last 150ms, the combo won't fire.

Vertical combos (J+M, H+N, etc.) use `timeout-ms = <40>` and `require-prior-idle-ms = <100>` because vertical finger movement is slower.

### Real example: add a combo for `[` using E+R (positions 3+4)

Add this block inside `combos { }`, before the closing `};` on line 161:

```c
combo_lbkt {
    bindings = <&kp LBKT>;
    key-positions = <3 4>;              // E + R
    timeout-ms = <30>;
    require-prior-idle-ms = <150>;
};
```

To also add `]` on a nearby pair, use positions 7+8 (U+I):

```c
combo_rbkt {
    bindings = <&kp RBKT>;
    key-positions = <7 8>;              // U + I
    timeout-ms = <30>;
    require-prior-idle-ms = <150>;
};
```

### Testing a combo

After flashing: open any text editor and type the two keys simultaneously. If the output appears, it works. If it doesn't fire, try pressing faster or increase `timeout-ms` by 10ms.

---

## 5. How to Adjust Home Row Mods

This is the most tuned part of your keymap. Your current settings (lines 41–46):

```c
&mt {
    flavor = "tap-preferred";
    tapping-term-ms = <200>;
    quick-tap-ms = <175>;
    require-prior-idle-ms = <150>;
};
```

### What each setting does

**`tapping-term-ms = <200>`**
The hold/tap decision threshold in milliseconds. If you release within 200ms → tap (letter). If you hold past 200ms → hold (modifier). This is the primary dial.

- Too low (< 150ms) → modifiers fire while typing normally
- Too high (> 300ms) → you consciously feel the delay before modifiers engage

**`require-prior-idle-ms = <150>`**
Before a hold can register as a modifier, the keyboard must have been idle for 150ms. This single setting prevents most accidental mod firings during normal typing. If you're getting modifiers while typing fast, raise this first.

**`quick-tap-ms = <175>`**
If you tap a home row key and then tap it again within 175ms, the second tap always produces the letter (never a hold). This fixes double-letter problems: typing `ss` won't produce `Shift+s` because the second `s` comes quickly after the first.

**`flavor = "tap-preferred"`**
How ZMK resolves ambiguity. `"tap-preferred"` means: when in doubt, produce the letter. You must deliberately hold past `tapping-term-ms` to get a modifier. This is good for home row keys. Your `&lt` thumb keys use `"balanced"` instead — they decide based on whether another key was pressed while held.

### Your home row layout

Left hand (positions 13–16, line 181):
```
&mt LGUI A   &mt LALT S   &mt LCTRL D   &mt LSHFT F
```

Right hand (positions 19–22, line 181):
```
&mt RSHFT J   &mt RCTRL K   &mt RALT L   &mt RGUI SQT
```

GACS order (GUI, Alt, Ctrl, Shift — weakest to strongest from pinky to index).

### Troubleshooting table

| Symptom | Most likely cause | Fix |
|---|---|---|
| Modifiers fire when typing quickly | `require-prior-idle-ms` too low | Raise from 150 → 200 |
| Modifiers fire even slowly | `tapping-term-ms` too low | Raise from 200 → 250 |
| Mods feel laggy or delayed | `tapping-term-ms` too high | Lower toward 180 |
| Double letters (`ss`, `ll`) trigger mod | `quick-tap-ms` too low | Raise to 200 |
| Home row mod works on one hand, not other | Wrong modifier on right hand | Verify `RSHFT`/`RCTRL`/`RALT`/`RGUI` — not `LSHFT`/etc. |
| Layer key activates when tapping thumb | `&lt` `tapping-term-ms` too low | Raise `&lt` block tapping-term to 220 |

### How to change the settings

Edit the `&mt { }` block (lines 41–46). For example, to raise `require-prior-idle-ms` to 200:

```c
&mt {
    flavor = "tap-preferred";
    tapping-term-ms = <200>;
    quick-tap-ms = <175>;
    require-prior-idle-ms = <200>;   // was 150
};
```

This change affects every `&mt` in your keymap.

---

## 6. How to Add a New Layer

Your keymap currently uses layers 0–6. Layer 7 is free.

### Step 1 — Add the define

After line 33 (`#define MOUSE 6`), add:

```c
#define GAME  7
```

### Step 2 — Add the layer block

Inside `keymap { }`, after the closing `};` of `mouse_layer` (line 245), add:

```c
game_layer {
    display-name = "GAME";
    bindings = <
&kp TAB    &kp Q    &kp W    &kp E    &kp R    &kp T    &kp Y    &kp U    &kp I     &kp O    &kp P     &kp BSPC
&kp ESC    &kp A    &kp S    &kp D    &kp F    &kp G    &kp H    &kp J    &kp K     &kp L    &kp SQT   &kp RET
&kp LSHFT  &kp Z    &kp X    &kp C    &kp V    &kp B    &kp N    &kp M    &kp COMMA &kp DOT  &kp FSLH  &kp LSHFT
                             &kp LALT &kp SPACE &kp LCTRL &kp ESC &trans  &trans
    >;
};
```

Note: this layer uses plain `&kp` on every key — no home row mods. `ASDF` produces letters, not modifiers.

### Step 3 — Add a way to activate it

`&trans` falls through to the layer below. `&none` blocks a key entirely. For layer activation, common options:

- `&mo GAME` — hold to activate (momentary)
- `&tog GAME` — tap to toggle on/off

A good place to put `&tog GAME` is on your MEDIA layer. Position 5 on MEDIA is currently `&none`. Open `media_layer` (lines 208–215) and change that `&none` to `&tog GAME`.

Line 210 of your file currently reads:
```c
&none          &none       &none       &none         &none         &none          &rgb_ug RGB_TOG ...
```

The sixth `&none` (position 5, the T key) can become `&tog GAME`:
```c
&none          &none       &none       &none         &none         &tog GAME      &rgb_ug RGB_TOG ...
```

To return to BASE from GAME: press `&tog GAME` again (same key).

---

## 7. How to Create a Macro

Your `hyper` macro (lines 164–171) is a perfect template for hold-style macros:

```c
hyper: hyper {
    compatible = "zmk,behavior-macro";
    #binding-cells = <0>;
    bindings =
        <&macro_press &kp LGUI &kp LALT &kp LCTRL &kp LSHFT>,
        <&macro_pause_for_release>,
        <&macro_release &kp LGUI &kp LALT &kp LCTRL &kp LSHFT>;
};
```

The three macro actions:
- `&macro_press` — press keys down and hold
- `&macro_pause_for_release` — wait until the macro key is released before continuing
- `&macro_release` — release the held keys

This pattern is for "hold the macro key to hold a chord." For tap-and-type macros, you do not need `pause_for_release`.

### Example: em dash macro (macOS)

On macOS, em dash (—) is Option+Shift+Minus. Add this inside `macros { }` (after line 171, before the closing `};`):

```c
em_dash: em_dash {
    compatible = "zmk,behavior-macro";
    #binding-cells = <0>;
    bindings =
        <&macro_press &kp LALT &kp LSHFT>,
        <&macro_tap &kp MINUS>,
        <&macro_release &kp LALT &kp LSHFT>;
};
```

### Example: type an email address

```c
my_email: my_email {
    compatible = "zmk,behavior-macro";
    #binding-cells = <0>;
    bindings = <
        &kp P &kp A &kp N &kp K &kp A &kp J
        &kp AT
        &kp G &kp M &kp A &kp I &kp L
        &kp DOT
        &kp C &kp O &kp M
    >;
};
```

Replace the key sequence with your actual email address letters.

### Binding a macro to a key

After declaring the macro, reference it by name as a binding anywhere in your keymap:

```c
&em_dash
```

For example, to put `&em_dash` on the SYM layer at position 11 (currently `&none`), find line 220 and replace the last `&none` on that line.

To put it on a thumb key: `&lt SYM RET` → you could add a layer with `&em_dash` at a convenient position.

---

## 8. How to Change Bluetooth Profiles

### Your current BT setup

Your MEDIA layer (line 212) already has:

```
Position 31: &bt BT_SEL 0    — pair/switch to profile 0
Position 32: &bt BT_SEL 1    — pair/switch to profile 1
Position 33: &bt BT_SEL 2    — pair/switch to profile 2
Position 34: &bt BT_SEL 3    — pair/switch to profile 3
Position 35: &bt BT_CLR      — clear current profile's bond
Position 30: &out OUT_TOG    — toggle between USB and Bluetooth output
```

On the MEDIA layer physical layout, these fall on the M, comma, dot, slash keys (row 2 right side) and N.

### How to switch devices

1. Hold the left thumb key `&lt MEDIA ESC` (position 36) to activate MEDIA layer
2. Tap the BT_SEL key for the profile you want
3. Release — keyboard switches to that Bluetooth profile
4. If connecting for the first time, put your device in pairing mode

Profiles are numbered 0–3. Each profile remembers one device. Switching profiles is instant; pairing a new device takes a few seconds.

### Adding BT_SEL 4

You have profiles 0–3. ZMK supports up to 5 (0–4) by default. To add profile 4, find a free position on MEDIA layer. Position 6 (currently `&rgb_ug RGB_TOG` on line 210) is not ideal, but the left side of MEDIA row 2 (positions 24–29, all `&none`) is free. 

In `media_layer` bindings, line 212:
```c
&none          &none       &none       &none         &none         &none          ...
```
Change position 25 (second `&none`, the Z key) to:
```c
&none          &bt BT_SEL 4  &none    &none         &none         &none          ...
```

### Clear all bonds and start fresh

If your halves won't connect to each other or to your computer:

1. Flash `settings_reset.uf2` to the **left** half (from the build artifacts)
2. Flash `settings_reset.uf2` to the **right** half
3. Flash normal `corne_left.uf2` to the left half
4. Flash normal `corne_right.uf2` to the right half
5. Put the halves next to each other — they should auto-pair within 30 seconds

### OUT_TOG (USB vs Bluetooth)

`&out OUT_TOG` at position 30 on MEDIA layer switches the output. When connected by USB, the keyboard defaults to USB. Toggle to force Bluetooth output even when the cable is plugged in. Useful for charging while using wirelessly.

---

## 9. How to Enable/Disable Features via .conf

Your `config/corne.conf` controls firmware features. Each line is either active or commented out (starts with `#`). Changing a value requires a build + flash cycle just like the keymap.

### Current state of your corne.conf

```
CONFIG_ZMK_BATTERY_REPORT_INTERVAL=60      # battery % reported every 60s
CONFIG_ZMK_KSCAN_DEBOUNCE_PRESS_MS=5       # 5ms debounce (switch timing)
CONFIG_ZMK_KEYBOARD_NAME="Corne"           # Bluetooth device name
CONFIG_BT_GATT_ENFORCE_SUBSCRIPTION=n      # Windows battery fix

CONFIG_ZMK_DISPLAY=y                       # OLED display on
CONFIG_ZMK_DISPLAY_WORK_QUEUE_DEDICATED=y  # dedicated work queue for display

CONFIG_ZMK_IDLE_TIMEOUT=600000             # idle after 10 minutes
CONFIG_ZMK_SLEEP=y                         # deep sleep enabled
CONFIG_ZMK_IDLE_SLEEP_TIMEOUT=900000       # deep sleep after 15 minutes

CONFIG_ZMK_POINTING=y                      # mouse/pointing layer active
CONFIG_ZMK_STUDIO=y                        # ZMK Studio enabled
CONFIG_ZMK_STUDIO_LOCKING=n               # Studio unlocked (no lock on USB disconnect)

CONFIG_ZMK_RGB_UNDERGLOW=y                 # RGB enabled
CONFIG_ZMK_RGB_UNDERGLOW_AUTO_OFF_IDLE=y   # RGB off when keyboard sleeps
CONFIG_ZMK_RGB_UNDERGLOW_EFF_START=3       # effect preset 3 on boot
CONFIG_ZMK_RGB_UNDERGLOW_BRT_MAX=60        # max brightness 60%
```

### Common toggles

**Disable mouse emulation** (removes the MOUSE layer behavior and saves firmware space):
```
CONFIG_ZMK_POINTING=n
```
Note: the MOUSE layer still exists in your keymap, but `&mmv` and `&msc` bindings will not work.

**Disable RGB underglow** (saves ~2mA of battery draw):
```
CONFIG_ZMK_RGB_UNDERGLOW=n
```

**Disable OLED display** (saves battery, speeds up firmware, reduces complexity):
```
CONFIG_ZMK_DISPLAY=n
```

**Adjust deep sleep timing** (in milliseconds):
```
CONFIG_ZMK_IDLE_TIMEOUT=300000          # idle after 5 minutes (was 10)
CONFIG_ZMK_IDLE_SLEEP_TIMEOUT=600000    # deep sleep after 10 minutes (was 15)
```

**Disable deep sleep** (keyboard wakes faster; uses more battery):
```
CONFIG_ZMK_SLEEP=n
```

**Disable ZMK Studio** (if you don't use it; slightly reduces firmware size):
```
CONFIG_ZMK_STUDIO=n
```
Also remove `snippet: studio-rpc-usb-uart` from the relevant build.yaml entries.

**Enable bongo cat animation** (uncomment the existing commented line, then rebuild):
```
CONFIG_ZMK_WIDGET_BONGO_CAT=y
```

**Change keyboard Bluetooth name** (what shows up on your Mac/phone):
```
CONFIG_ZMK_KEYBOARD_NAME="MyKeyboard"
```

---

## 10. Real Customization Recipes

### Recipe A — Move Escape from the W+E combo to a dedicated key

The combo `combo_esc` (lines 67–72) fires ESC when you press W+E simultaneously. You can add ESC as a permanent key on, say, position 0 (currently `&kp TAB`) and keep the combo too, or remove the combo and use the dedicated key alone.

**Add ESC at position 0 (top-left key), keep TAB accessible via combo:**

In `base_layer` bindings, line 180, change:
```c
&kp TAB        &kp Q       ...
```
to:
```c
&kp ESC        &kp Q       ...
```

Then add a TAB combo somewhere, for example positions 1+2 (Q+W):
```c
combo_tab_qw {
    bindings = <&kp TAB>;
    key-positions = <1 2>;              // Q + W
    timeout-ms = <30>;
    require-prior-idle-ms = <150>;
};
```

**Alternatively, just remove the W+E combo** and put nothing at position 0 if you prefer using the NAV layer ESC (the left thumb `&lt MEDIA ESC` already gives ESC on tap):

Delete lines 67–72 from `combos { }` entirely, leaving the other combos intact.

---

### Recipe B — Make Caps Lock more accessible

Caps Lock is already on your NAV layer at position 22 (the `'` key location). Activate NAV (hold SPACE thumb key), then tap the apostrophe position.

If you want it somewhere easier — say the right thumb ESC-tap position — note that `&lt MEDIA ESC` (position 36) gives ESC on tap and MEDIA on hold. You cannot easily move that without changing your thumb layout.

A better option: add it to MEDIA layer at a free position. Position 13 on MEDIA (the A key) is `&kp LGUI`. Position 1 is `&none`. In `media_layer`, line 210:

```c
&none          &none       &none       &none         &none         &none          ...
```

Change the second `&none` (position 1, the Q key) to `&kp CAPS`:
```c
&none          &kp CAPS    &none       &none         &none         &none          ...
```

Now: hold left thumb ESC → tap Q → Caps Lock toggles.

---

### Recipe C — Add a gaming layer (no home row mods, WASD accessible)

Gaming layers work better without hold-tap mods because games need instant keypresses.

**Step 1:** Add `#define GAME 7` after line 33.

**Step 2:** Add the layer block after `mouse_layer`:

```c
game_layer {
    display-name = "GAME";
    bindings = <
&kp TAB    &kp Q    &kp W    &kp E    &kp R    &kp T    &kp Y    &kp U    &kp I     &kp O    &kp P     &kp BSPC
&kp ESC    &kp A    &kp S    &kp D    &kp F    &kp G    &kp H    &kp J    &kp K     &kp L    &kp SQT   &kp RET
&kp LSHFT  &kp Z    &kp X    &kp C    &kp V    &kp B    &kp N    &kp M    &kp COMMA &kp DOT  &kp FSLH  &kp LSHFT
                             &kp LALT &kp SPACE &kp LCTRL &tog GAME &trans &trans
    >;
};
```

Note: position 39 (right thumb 1, normally `&lt SYM RET`) is `&tog GAME` here — press it to exit the gaming layer.

**Step 3:** Add `&tog GAME` somewhere on MEDIA layer (as described in Section 6) so you can enter the gaming layer.

When in GAME layer: WASD works normally, no modifiers fire accidentally, SPACE is just SPACE.

---

### Recipe D — Change the tapping term for just one key

The global `&mt` config affects all home row mods. For a per-key override, define a custom behavior. Add this block anywhere before `/ {` in your keymap (e.g., after line 52):

```c
/ {
    behaviors {
        mt_slow: mt_slow {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            flavor = "tap-preferred";
            tapping-term-ms = <350>;
            quick-tap-ms = <175>;
            require-prior-idle-ms = <200>;
            bindings = <&kp>, <&kp>;
        };
    };
};
```

Then use `&mt_slow` exactly like `&mt` for any specific key. For example, to give the LGUI/A key a longer hold time (pinky GUI mods are often the hardest to tune):

In `base_layer` line 181, change:
```c
&mt LGUI A
```
to:
```c
&mt_slow LGUI A
```

The right GUI (`&mt RGUI SQT`) can be similarly changed to `&mt_slow RGUI SQT` if the apostrophe key is misfiring as GUI.

---

### Recipe E — Add a unicode macro (em dash — on macOS)

On macOS, em dash is typed with Option+Shift+Minus. Add this macro inside `macros { }` (lines 163–172), before the closing `};`:

```c
em_dash: em_dash {
    compatible = "zmk,behavior-macro";
    #binding-cells = <0>;
    bindings =
        <&macro_press &kp LALT &kp LSHFT>,
        <&macro_tap &kp MINUS>,
        <&macro_release &kp LALT &kp LSHFT>;
};
```

Then place `&em_dash` on a convenient layer position. The SYM layer has several `&none` slots on the right side. For example, position 7 on SYM (the U key) is `&none`. In `sym_layer` line 220:

```c
&none          &kp LBRC    &kp AMPS    &kp ASTRK     &kp LPAR      &kp RBRC       &none       &none  ...
```

Change position 7 (`&none` after `&kp RBRC`) to `&em_dash`:
```c
&none          &kp LBRC    &kp AMPS    &kp ASTRK     &kp LPAR      &kp RBRC       &none       &em_dash ...
```

Now: hold right thumb RET → tap U → em dash appears.

For en dash (–), macOS uses Option+Minus:
```c
en_dash: en_dash {
    compatible = "zmk,behavior-macro";
    #binding-cells = <0>;
    bindings =
        <&macro_press &kp LALT>,
        <&macro_tap &kp MINUS>,
        <&macro_release &kp LALT>;
};
```

---

## 11. Testing Without Flashing

You cannot run the keymap in a simulator before flashing — ZMK firmware must be compiled and run on hardware. But you can reduce wasted flash cycles:

### Validate syntax before pushing

Read through the change you made and check:
- Every `{` has a matching `}`
- Every `<` has a matching `>`
- Every `&behavior` reference matches a declared behavior name
- Layer bindings have exactly 42 entries (count them: 12 + 12 + 12 + 6)

After pushing, the GitHub Actions log shows build errors within ~30 seconds. Scroll to the failing step — it will show the exact file and line number.

### After flashing: keyboard-test.com

Go to [keyboard-test.com](https://keyboard-test.com) in a browser. Press each key. It highlights in the UI. This confirms every key sends the right keycode.

### ZMK Studio (already enabled in your .conf)

ZMK Studio (`CONFIG_ZMK_STUDIO=y`) allows making some keymap changes through a GUI without reflashing. Connect via USB, open [zmk.studio](https://zmk.studio) in Chrome or Edge (requires WebSerial). Note: not all behaviors are editable in Studio, and Studio changes are temporary until you push them as a proper .keymap edit.

Your `build.yaml` already includes the `studio-rpc-usb-uart` snippet for left half builds — Studio will work over USB on the left half.

### Before any big change: note your current state

Write down what you're changing and what the original was. Git history is your safety net:

```bash
git log --oneline config/corne.keymap   # see all changes
git diff HEAD~1 config/corne.keymap     # see what changed last commit
git show HEAD~2:config/corne.keymap     # view the file as it was 2 commits ago
```

To revert a single file to its last committed state:
```bash
git checkout HEAD -- config/corne.keymap
```

---

## 12. Common Errors and What They Mean

These appear in the GitHub Actions build log. Click on the failed job → expand the failing step.

| Error message | What it means | How to fix |
|---|---|---|
| `expected ';'` or `expected '}'` | Syntax error in .keymap — missing delimiter | Find the indicated line; check all `{`, `<`, `;` are balanced |
| `undeclared identifier 'MYKEY'` | Wrong key code name | Check exact spelling at zmk.dev/docs/codes |
| `macro 'BASE' passed N arguments, but takes just 0` | Using a `#define` as if it were a function | Remove the parentheses: `BASE` not `BASE()` |
| `#binding-cells mismatch` | Wrong number of parameters to a behavior | `&kp` takes 1, `&mt` takes 2, `&lt` takes 2, `&none`/`&trans` take 0 |
| `Could not find shield 'corne_left'` | Typo in build.yaml shield name | Shield names are lowercase with underscores |
| `undefined reference to 'my_macro'` | Macro declared but name differs from reference | Check macro identifier matches exactly: `my_macro: my_macro {` |
| `duplicate node name` | Two combos or behaviors with the same name | Rename one |
| `out of range` for key-positions | Position number ≥ 42 | Positions are 0–41; recount from the map |
| `ZMK_KEYMAP_LAYERS_LEN exceeds` | Too many layers | ZMK supports up to 16 layers |
| `Invalid escape sequence` | Special character in a `CONFIG_ZMK_KEYBOARD_NAME` | Stick to letters and spaces in the name |

---

## 13. Quick Reference Card

| Resource | URL |
|---|---|
| ZMK key codes | https://zmk.dev/docs/codes |
| ZMK behaviors | https://zmk.dev/docs/behaviors/key-press |
| Hold-tap behavior (mt/lt) | https://zmk.dev/docs/behaviors/hold-tap |
| Combos | https://zmk.dev/docs/features/combos |
| Macros | https://zmk.dev/docs/behaviors/macros |
| ZMK Studio | https://zmk.studio |
| ZMK Discord (best help) | https://discord.gg/zmk |
| Your GitHub repo | https://github.com/pankajudhas81/pankaj-zmk-config |

### Files you edit

| File | What it controls |
|---|---|
| `config/corne.keymap` | Everything about which keys do what |
| `config/corne.conf` | Which firmware features are compiled in |
| `build.yaml` | Which board+shield combinations get built |
| `config/west.yml` | Which ZMK version to use (`revision: main` = latest) |

### Golden rules

1. **One change at a time.** When something breaks, you know exactly what caused it.
2. **Count to 42.** Every layer binding must have exactly 42 entries. Missing or extra entries cause cryptic errors.
3. **Layer order in the file = layer number.** The first layer block is 0, second is 1, etc. Do not rely on `display-name` for ordering — the `#define` constants are what matter.
4. **`&trans` is your friend.** When adding a new layer, fill it with `&trans` and only change the positions you need. Every other key falls through to the layer below.
5. **Left half gets flashed first.** The left half is the primary controller. If in doubt about pairing issues, reflash left first.
6. **The build takes 2–3 minutes.** Push, make a cup of tea, come back.
