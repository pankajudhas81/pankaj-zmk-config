# The Corne Keyboard — Complete Overview

> "Once you go split, you never go back." — basically every Corne owner ever.

This document is your foundation. Whether you want to understand *why* your keyboard feels so different, what's inside it, how the community thinks about it, or how to buy another one (because you will), this is the place to start.

---

## Table of Contents

1. [What Is the Corne Keyboard?](#1-what-is-the-corne-keyboard)
2. [A Brief History](#2-a-brief-history)
3. [Why People Love It](#3-why-people-love-it)
4. [Physical Layout](#4-physical-layout)
5. [Column Stagger — The Core Insight](#5-column-stagger--the-core-insight)
6. [The Thumb Cluster](#6-the-thumb-cluster)
7. [Key Specifications](#7-key-specifications)
8. [Controller Options](#8-controller-options)
9. [OLED Displays](#9-oled-displays)
10. [The Community](#10-the-community)
11. [Where to Get One](#11-where-to-get-one)
12. [Typical Build Costs](#12-typical-build-costs)
13. [Your Build](#13-your-build)

---

## 1. What Is the Corne Keyboard?

The **Corne** (pronounced like "corn") is an open-source, split, column-staggered, 42-key (or 36-key) ergonomic keyboard. It was designed by a Japanese maker known as **foostan** (GitHub: [foostan](https://github.com/foostan)), whose real name is Kosuke Adachi. All PCB design files are published under open hardware licenses and available at [github.com/foostan/crkbd](https://github.com/foostan/crkbd).

What that opening sentence actually means:

| Term | What it means |
|---|---|
| **Open-source** | PCB design files, firmware configs, and BOM (bill of materials) are all freely available. Anyone can manufacture their own or order from a fab. |
| **Split** | The keyboard is two separate halves connected by a TRRS cable (wired) or wireless radio link. Left hand, right hand — completely independent. |
| **Column-staggered** | Each column of keys is offset vertically relative to its neighbors, following the natural length of your fingers. This is different from row-stagger (the angled keys on a standard keyboard) and from a flat ortholinear grid. |
| **42-key** | The default configuration has 42 keys total: 3 rows × 6 columns per half = 36 main keys, plus 3 thumb keys per half = 6 thumb keys. 36 + 6 = 42. |
| **Ergonomic** | Designed to reduce the unnatural wrist angles and finger travel that cause repetitive strain injury (RSI) on standard keyboards. |

The repository is called **crkbd** — a compressed form of "Corne Keyboard." You'll see both names used constantly. On GitHub, Reddit, build logs, and vendor listings, crkbd and Corne are used interchangeably.

### Open Hardware

Because foostan published the PCB files under open hardware terms, you have several options for acquiring one that don't exist with commercial keyboards:

- Order the PCBs directly from a fab (JLCPCB, PCBWay) using foostan's gerber files
- Buy a kit from a vendor who ordered PCBs in bulk and assembled a BOM
- Print the case yourself (many community designs exist on Printables and Thingiverse)
- Design your own case in aluminum, polycarbonate, brass, or wood
- Fork the design and modify it (many variants exist — Kyria, Lily58, Sofle all trace DNA back to this lineage)

This openness is a core part of the Corne's cultural identity. The keyboard community takes "build it yourself" seriously, and the Corne is the canonical beginner-to-intermediate DIY split keyboard.

---

## 2. A Brief History

### The Helidox Era (2018)

foostan's first public version was called the **Helidox** — a portmanteau of "Helix" (another popular split keyboard at the time) and "Dox" (the Ergodox, the pioneer of split ergonomic keyboards). The Helidox was a 42-key split with column stagger, released in late 2017 / early 2018.

The name didn't stick. The community began calling it the **Corne** keyboard — a transliteration/phonetic play that caught on organically. foostan eventually embraced the new name and the repository was renamed crkbd accordingly.

### Why "Corne"

There are different stories circulating about the name origin. The most cited explanation is that "corne" derives from Japanese phonetics: foostan is Japanese, and in Japanese, "corn" (コーン, *kōn*) is pronounced closer to "corne." The keyboard's shape has also been described as vaguely corn-cob-like — two halves, columnar. Whatever the etymology, the name stuck and the Corne is now one of the most recognizable keyboard names in the hobby.

### Rise to Prominence (2019–2022)

The Corne became one of the most-built keyboards in the mechanical keyboard community for several reasons:

1. **Perfect size** — 42 keys is small enough to be impressive, large enough to be practically usable with layers
2. **Beautiful aesthetic** — the column stagger, the OLED screens, the minimal footprint look stunning in build photos
3. **Strong firmware support** — both QMK (wired) and ZMK (wireless) provide excellent support
4. **Vendor ecosystem** — KBDfans, Keyhive, and others began stocking kits, lowering the barrier to entry
5. **Nice!nano arrival (2020)** — when the nice!nano controller landed, wireless split keyboards became truly practical, and the Corne was the immediate beneficiary

### Today

By 2024–2025, the crkbd repository has accumulated thousands of GitHub stars. r/crkbd has tens of thousands of members. Build logs exist on countless personal blogs, YouTube channels, and Reddit posts. The Corne is to the split keyboard hobby what the Raspberry Pi is to single-board computers — the thing everyone knows, references, and builds from.

---

## 3. Why People Love It

### Ergonomics That Actually Work

The standard keyboard was designed in the 1870s for mechanical typewriters. The QWERTY layout was chosen partly to slow typists down (to prevent key jams), and the physical key grid was a flat matrix tilted at a slight angle — because that's what fit the mechanical constraints. We've been using the same shape for 150 years.

The Corne throws all of that away:

**Column stagger vs. row stagger**: On a standard keyboard, the rows of keys are offset horizontally — each row is shifted slightly left compared to the one below it. This doesn't match your finger anatomy at all. Your fingers move forward/backward, not diagonally. Column stagger shifts each column *vertically* to match the natural reach of each finger. Your index finger has a longer column; your pinky has a shorter one.

**Split eliminates ulnar deviation**: When you type on a standard keyboard with your hands together in front of you, your wrists are bent outward (ulnar deviation) to align your fingers with the keys. Over years of typing, this contributes to RSI. A split keyboard lets you place each half at shoulder width, keeping your wrists straight and neutral.

**42 keys forces discipline**: It sounds like a limitation, but it's actually a superpower. Every key you need is within 1–2 key presses from home row. You stop reaching for function keys, numpad, arrow keys, or any key more than one key from home position. Instead, you use layers — held thumb keys activate entire alternate layouts. After a few weeks of adaptation, you move *less* than on a standard keyboard, not more.

### Wireless Freedom

With nice!nano controllers (what you have), there are no cables. The two halves talk to each other via Bluetooth Low Energy, and the keyboard itself connects to your computer via BLE. This matters more than you'd think:

- Move the halves to exactly where your hands rest — no cable forcing a fixed relationship
- Use it on a couch, in bed, with a laptop on your lap
- No cable clutter on your desk
- Works with phones, tablets, iPads — any BLE device

### Complete Customization

No commercial keyboard gives you this level of control:

| Layer | What you customize |
|---|---|
| **Switches** | Linear, tactile, or clicky; light or heavy actuation |
| **Keycaps** | Profile, material, legends, colors — or blank |
| **Case** | Acrylic sandwich, aluminum, 3D printed, FR4, brass weight |
| **Controller** | Pro Micro, Elite-C, nice!nano, RP2040 |
| **Firmware** | QMK (wired), ZMK (wireless), Vial (QMK variant with GUI) |
| **Layout** | QWERTY, Colemak, Dvorak, Workman — or something you invent |
| **Layers** | As many as your firmware supports; typically 8–16 |

You own it completely. There's no vendor lock-in, no proprietary software, no cloud connectivity required.

### The Desk Presence

This is real. A split keyboard with quality switches, a nice keycap set, and a compact footprint looks exceptional on a desk. The two-halves aesthetic, the OLED screens glowing with layer info, the subtle RGB underglow — this is a keyboard people notice and ask about.

---

## 4. Physical Layout

### The Full 42-Key Layout

```
Left Half                                    Right Half
Col:  0    1    2    3    4    5              5    4    3    2    1    0
     ┌────┬────┬────┬────┬────┬────┐        ┌────┬────┬────┬────┬────┬────┐
Row0 │ Q  │ W  │ E  │ R  │ T  │    │        │    │ Y  │ U  │ I  │ O  │ P  │
     ├────┼────┼────┼────┼────┼────┤        ├────┼────┼────┼────┼────┼────┤
Row1 │ A  │ S  │ D  │ F  │ G  │    │        │    │ H  │ J  │ K  │ L  │ '  │
     ├────┼────┼────┼────┼────┼────┤        ├────┼────┼────┼────┼────┼────┤
Row2 │ Z  │ X  │ C  │ V  │ B  │    │        │    │ N  │ M  │ ,  │ .  │ /  │
     └────┴────┴────┴────┴────┴────┘        └────┴────┴────┴────┴────┴────┘
                        ┌────┬────┬────┐  ┌────┬────┬────┐
                        │ESC │SPC │TAB │  │RET │BSP │DEL │
                        └────┴────┴────┘  └────┴────┴────┘
                        (hold for layers)   (hold for layers)
```

> The outermost column (col 0 on each half, shaded above with empty cells) is the pinky column — present in the 42-key version, absent in the 36-key variant.

### Key Position Numbering

ZMK and QMK number the keys in a flat matrix. For a 42-key Corne, positions 0–41 map as follows:

```
Left half rows 0-2 (positions 0-17), then right half rows 0-2 (positions 18-35), then thumbs (positions 36-41):

 0   1   2   3   4   5   |  18  19  20  21  22  23   ← Row 0 (top)
 6   7   8   9  10  11   |  24  25  26  27  28  29   ← Row 1 (home)
12  13  14  15  16  17   |  30  31  32  33  34  35   ← Row 2 (bottom)
              36  37  38 | 39  40  41                ← Thumbs
```

This numbering matters when reading ZMK keymap files — each binding in a layer corresponds to a position in this sequence.

### The 36-Key Variant

Foostan also published a 36-key variant (sometimes called "Corne-ish Zen" or just "Corne mini") that removes the outermost pinky column entirely. Some builders prefer it because:

- The pinky is the weakest finger — fewer keys means less strain
- Fewer keys = more layer discipline, which many find liberating once adapted
- Slightly more compact

With a well-designed 7+ layer setup (like Miryoku), 36 keys is genuinely sufficient for everything.

---

## 5. Column Stagger — The Core Insight

This is arguably the most important ergonomic feature of the Corne, and it's worth understanding deeply.

### The Problem with Flat Row-Stagger

A standard keyboard looks like this from the side (roughly):

```
Standard keyboard — lateral offset (row stagger):

  Q W E R T Y ...       ← top row, offset LEFT
   A S D F G H ...      ← home row
    Z X C V B N ...     ← bottom row, offset RIGHT

Your fingers try to reach these, but they move forward/back,
not left/right. You compensate by bending your wrists sideways.
```

Row stagger was a mechanical necessity on typewriters (the key levers needed to nest). It serves no ergonomic purpose and actively causes harm: your wrists must angle outward (ulnar deviation) to align your fingers with the key positions.

### The Corne Solution — Column Stagger

The Corne aligns each column vertically with the natural reach of that finger:

```
Column stagger — vertical offset per finger:

         Index   Middle  Ring   Pinky
          ↓       ↓       ↓      ↓
         ┌───┐   ┌───┐
         │ R │   │ E │
    ┌───┐├───┤   ├───┤┌───┐
    │ F │├───┤   ├───┤│ W │┌───┐
    └───┘│ D │   │ S ││ Q ││ ← │
         └───┘   └───┘└───┘└───┘
              ↕
       Each column starts at a
       different height, matching
       the length of that finger
```

The actual stagger values on the Corne (in millimeters):

| Column | Finger | Vertical offset relative to index |
|---|---|---|
| 0 (outer) | Pinky | −12 mm (shortest finger) |
| 1 | Ring | −6 mm |
| 2 | Middle | +0 mm (reference — middle is longest) |
| 3 | Index | −3 mm |
| 4 | Index inner | −6 mm |
| 5 | (not used in home row) | varies |

> Note: exact values vary between PCB revisions and variants; these are approximate.

### Why This Changes Everything

When the columns are staggered correctly, your fingers move **straight forward and back** to hit keys. No lateral compensation needed. After your hands adapt (typically 2–6 weeks), typing feels more natural, and many users report that RSI symptoms decrease or disappear entirely.

The column stagger is also why the Corne looks "weird" at first glance — the rows aren't aligned horizontally. But they're perfectly aligned for your hands.

### A Note on "Splay"

Some advanced keyboards (like the Kyria or Dactyl-Manuform) add **splay** — each column is also slightly rotated outward to match the natural fan-spread of your fingers. The Corne does not have splay; all columns are parallel. This is a deliberate choice for simplicity. Splay adds another degree of ergonomic correctness but makes the keyboard harder to manufacture and adjust.

---

## 6. The Thumb Cluster

### Why Thumbs Matter

On a standard 100% keyboard, both of your thumbs — your strongest, most dexterous fingers — press exactly one key: **Space**. That's it. Meanwhile, your weakest finger (pinky) handles Shift, Enter, Backspace, Control, and sometimes Tab and Caps Lock. This is backwards.

The Corne gives each thumb **three keys**. In a well-configured layout, this completely changes the ergonomic profile:

```
Left thumb keys:          Right thumb keys:
┌─────────┬───────┬───────┐  ┌───────┬───────┬──────────┐
│   ESC   │  SPC  │  TAB  │  │  RET  │  BSP  │   DEL    │
│ (MEDIA) │ (NAV) │(MOUSE)│  │ (SYM) │ (NUM) │  (FUN)   │
└─────────┴───────┴───────┘  └───────┴───────┴──────────┘
  hold=layer   hold=layer        hold=layer
```

Each thumb key has **two behaviors**:
- **Tap**: sends the labeled key (ESC, Space, Tab, Enter, Backspace, Delete)
- **Hold**: activates a layer (MEDIA, NAV, MOUSE, SYM, NUM, FUN)

This is implemented via ZMK's **layer-tap** (`&lt`) behavior. The firmware distinguishes a tap (quick press and release) from a hold (press and hold, or press then roll to another key) and sends the appropriate action.

### The Power of Layered Thumbs

With 6 layer-activating thumbs (3 per side, using hold), and one base layer, you get direct access to 7 layers using only your thumbs — with no lost functionality on those keys, because tapping still sends useful keys.

This is why Miryoku-style layouts work so well on 36–42 key keyboards: the thumb cluster does the heavy lifting that modifiers and shift keys do on standard keyboards. Your index, middle, ring, and pinky fingers can stay on home row almost always.

### Thumb Reach Ergonomics

The three thumb keys per side are positioned in an arc that matches the natural sweep of your thumb. The middle key is closest to home position; the inner and outer keys require slight thumb extension or contraction. In practice:

- The innermost thumb key (closest to the split center) is easiest to reach
- The outermost thumb key requires thumb extension and is slightly harder
- Most layouts put the most-used function (Space, layer access) on the comfortable middle key

Some people find that only 2 of the 3 thumb keys are easily reachable, and assign the third to rarely-used functions. This is entirely personal and something you tune over time.

---

## 7. Key Specifications

### Official crkbd Specifications

| Specification | Value |
|---|---|
| **Total keys** | 42 (standard) or 36 (mini) |
| **Keys per half** | 21 (standard) or 18 (mini) |
| **Rows** | 3 rows of alpha keys + 1 thumb row |
| **Columns per half** | 6 (standard) or 5 (mini) |
| **Thumb keys per half** | 3 |
| **Layout type** | Column-staggered, split |
| **Switch type** | MX or Choc (depending on PCB version) |
| **Controller footprint** | Pro Micro compatible (24-pin) |
| **Controller connection** | USB (wired) or BLE radio (wireless) |
| **OLED support** | Yes — SSD1306 128×32 or 128×64 |
| **RGB underglow** | Yes — WS2812B LEDs under PCB |
| **Per-key RGB** | Yes — on some variants (requires SK6812MINI-E) |
| **Hotswap** | Optional — Mill-Max or Kailh hotswap sockets |
| **PCB color options** | Black or white (from most vendors) |
| **Case options** | Acrylic sandwich, FR4 plate, aluminum, 3D printed |
| **Halves connection** | TRRS cable (wired) or wireless BLE |
| **Firmware** | QMK (wired), ZMK (wireless), Vial |
| **Open source** | Yes — GPL-2.0 or later |

### PCB Versions

The Corne has gone through several PCB revisions since 2018. The most important distinction for builders is **MX vs. Choc**:

#### crkbd MX (Cherry MX compatible)
- Standard MX footprint (19mm × 19mm pitch)
- Compatible with the vast majority of switches and keycaps on the market
- Taller board profile (switch + keycap stack height)
- Works with any MX or MX-compatible switch (Gateron, Akko, Boba, Holy Panda, etc.)

#### crkbd Choc (Kailh low-profile)
- Kailh Choc v1 footprint (18mm × 17mm pitch — note: rectangular, not square!)
- Much lower profile — the whole keyboard is about half the height of an MX build
- Fewer keycap options (Choc has limited aftermarket keycap sets)
- Switch selection is narrower but growing (Choc Red, Brown, White, Sunset, Robin, etc.)
- The go-to choice for ultra-thin, travel-friendly builds

#### Notable variants
- **Corne-ish Zen**: wireless-first Choc build with a nice!nano footprint and batteries built into the case design
- **Corne LP**: another low-profile variant
- **Corne v3.x series**: current production version from foostan

Most kit vendors carry the MX version. Choc requires more intentional searching. The PCB you use determines your entire switch and keycap ecosystem, so choose carefully.

---

## 8. Controller Options

The Corne uses a **Pro Micro form factor** controller — a 24-pin DIP footprint that's become the standard for DIY keyboards. Many controllers share this footprint, giving you flexibility.

### Controller Comparison Table

| Controller | MCU | Connectivity | USB | Wireless | Battery | Firmware | Price (approx.) |
|---|---|---|---|---|---|---|---|
| **Pro Micro** | ATmega32u4 | USB Micro-B | ✓ | ✗ | ✗ | QMK | $4–10 |
| **Elite-C** | ATmega32u4 | USB-C | ✓ | ✗ | ✗ | QMK | $18–25 |
| **nice!nano v2** | nRF52840 | USB-C | ✓ | BLE 5.0 | Charging ✓ | ZMK | $25–35 |
| **Seeeduino Xiao BLE** | nRF52840 | USB-C | ✓ | BLE 5.0 | Charging ✓ | ZMK | $10–18 |
| **RP2040 Pro Micro** | RP2040 | USB-C | ✓ | ✗ | ✗ | QMK/KMK | $5–15 |
| **SparkFun Pro Micro RP2040** | RP2040 | USB-C | ✓ | ✗ | ✗ | QMK | $12–20 |

### Pro Micro (Original)

The original Arduino-based controller. Very well supported by QMK. Cheap, widely available, but:

- **Micro-B USB** — the connector most prone to breakage
- **32KB flash** — tight for complex keymaps with many features
- **No wireless** — requires TRRS cable between halves
- **No battery charging** — USB-only power

Still the most common choice in tutorials and build guides simply because it's been around longest. If you're building a wired Corne on a tight budget and don't care about wireless, the Pro Micro works fine.

### Elite-C

An upgraded Pro Micro from keeb.io. Same ATmega32u4 chip, same QMK support, but:

- **USB-C connector** — much more robust
- **More flash** — 32KB but better organized
- **Still no wireless**
- Costs 3–5× more than a Pro Micro for marginal improvements

Became popular in the 2019–2021 era before the nice!nano displaced it for most wireless builds.

### nice!nano v2 ★ (What You Have)

Made by nicekeyboards.com. The current gold standard for wireless split keyboards.

**The chip**: Nordic Semiconductor nRF52840
- ARM Cortex-M4 @ 64 MHz
- 1 MB flash, 256 KB RAM
- Bluetooth 5.0 + Bluetooth Low Energy
- USB Full-Speed

**What makes it special**:

```
┌────────────────────────────────────────────────────────┐
│                    nice!nano v2                        │
│                                                        │
│  ┌─────────────┐  • nRF52840 (BLE 5.0)                │
│  │  nRF52840   │  • 1MB flash — room for complex ZMK  │
│  │  (MCU)      │  • Li-Po battery charging (100mA)    │
│  └─────────────┘  • Battery voltage sensing           │
│                   • Deep sleep power management        │
│  USB-C ────────── • Works as USB HID (wired) OR       │
│                     BLE HID (wireless)                 │
│  Battery JST ───── • 2-pin JST connector for Li-Po    │
│                   • Built-in charge management IC      │
└────────────────────────────────────────────────────────┘
```

**Wireless split operation**: For a split keyboard, one half is the "central" (connects to your computer via BLE) and the other is the "peripheral" (connects to the central via BLE). The nice!nano handles this automatically via ZMK. The TRRS cable between halves is **not needed** — each half has its own battery and radio.

**Battery life**: Highly variable based on usage:
- Without RGB: weeks per charge (commonly 2–6 weeks on a 110mAh battery)
- With RGB underglow on: days per charge
- With OLED displays on: days to a week
- ZMK's deep sleep feature extends battery life dramatically when the board is idle

**Why ZMK instead of QMK**: The ATmega32u4 (used in Pro Micro and Elite-C) doesn't have Bluetooth hardware. The nRF52840 does, but QMK's support for nRF52840 is limited and unofficial. ZMK was purpose-built for nRF52840 and the wireless split keyboard use case, making it the natural firmware choice for nice!nano.

### Seeeduino Xiao BLE

A budget alternative to the nice!nano. Same nRF52840 chip, same BLE 5.0, works with ZMK. Differences:

- Smaller physical footprint (may require an adapter PCB for Pro Micro footprint keyboards)
- Less community documentation
- Cheaper ($10–18 vs. $25–35)
- Battery charging circuit present but sometimes inconsistent
- Fewer community-tested ZMK configs

Good choice if you want to save money and are willing to do more debugging. The nice!nano's price premium buys you a known-good quantity with extensive ZMK documentation.

### RP2040 Pro Micro

The Raspberry Pi RP2040 in a Pro Micro form factor. Dual-core ARM Cortex-M0+ at 133 MHz, 16 MB flash. Extremely capable for QMK. But:

- **No wireless** — RP2040 has no built-in radio
- QMK support is excellent and growing
- Cheap ($5–15)
- Good for wired builds where you want a powerful MCU

The RP2040 is increasingly popular in the hobby because it's cheap, fast, and QMK support is mature. But for wireless, nice!nano remains the choice.

---

## 9. OLED Displays

### What They Are

The Corne supports small **SSD1306 I2C OLED displays** — typically 128×32 pixels, monochrome (white or blue pixels on black). Some variants support 128×64. These displays are connected to the controller via the I2C bus (SCL/SDA lines), which the crkbd PCB routes to headers for this purpose.

```
┌──────────────────────────────────┐
│ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ │ ← 128 pixels wide
│ ░ LAYER: NAV               ░░░  │
│ ░ WPM: 87   ░░░░░░░░░░░░░  ░░░  │ ← 32 pixels tall
│ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ │
└──────────────────────────────────┘
         SSD1306 128×32 OLED
```

### What They Show

In ZMK, OLED display content is configured via display widgets. Common displays:

| Widget | What it shows |
|---|---|
| **Layer name** | The name of the currently active layer (BASE, NAV, NUM, etc.) |
| **WPM counter** | Words per minute, updated in real time |
| **Modifier status** | Whether Shift, Ctrl, Alt, GUI are currently held |
| **Battery level** | Remaining charge (nice!nano reports battery voltage) |
| **BLE connection** | Which BLE profile/device is active |
| **Keylogger** | Last few keys pressed (useful for debugging) |
| **Logo** | A small bitmap image (often shown on the peripheral/right half) |

The left half typically shows functional info (layer, mods, WPM); the right half often shows a static logo or a mirror of some data.

### ZMK OLED Support

ZMK's OLED support uses a custom display driver. Configuration is done in Devicetree overlays and Kconfig flags. Key things to know:

```
# In corne.conf:
CONFIG_ZMK_DISPLAY=y
CONFIG_ZMK_WIDGET_LAYER_STATUS=y
CONFIG_ZMK_WIDGET_WPM_STATUS=y
CONFIG_ZMK_WIDGET_BATTERY_STATUS=y
```

ZMK's display system is functional but historically a lower-priority area compared to QMK's mature OLED support. Most common displays work, but advanced customization requires writing C code (display widgets are not configurable via YAML/Kconfig alone).

### Battery Impact

OLED displays draw continuous power — typically 5–20 mA depending on pixel density. On a 110mAh battery this is significant:

- **OLED off**: battery lasts weeks
- **OLED on**: battery lasts days (rough estimate: 5–7 days with normal use patterns)

ZMK can put the display to sleep when the keyboard is idle, which helps. The display wakes on keypress.

### Are They Worth It?

Aesthetically: absolutely yes. The glow of OLED screens showing your current layer is a key part of the Corne aesthetic and makes the keyboard look professional and custom.

Practically: the layer name display is genuinely useful during the learning period when you're still building muscle memory for which layer has what. Once the layout is internalized, the display becomes more decorative.

Many advanced users turn the OLED off entirely to maximize battery life. The keyboard works identically without them.

---

## 10. The Community

### Where People Gather

#### Reddit
- **r/crkbd** — the dedicated Corne subreddit; build logs, firmware help, layout discussions, keycap suggestions
- **r/ErgoMechKeyboards** — broader ergonomic keyboard community, Corne is the most common board seen here
- **r/MechanicalKeyboards** — the general keyboard hobby subreddit; less Corne-specific but large

#### Discord
- **MechKeys** Discord (discord.gg/mechkeys) — enormous community with channels for split keyboards, ZMK, QMK
- **ZMK Discord** — official ZMK firmware Discord; best place for ZMK-specific help
- **nicekeyboards Discord** — for nice!nano specific questions

#### GitHub
- **foostan/crkbd** — the official repository; issues, discussions, and release notes
- **zmkfirmware/zmk** — ZMK firmware source; discussions and issues for firmware-level questions

#### Build Logs and Blogs
Searching "corne build log" on YouTube surfaces hundreds of first-person build walkthroughs. The format is remarkably consistent: unboxing, soldering documentation, firmware flashing, and a final typing demo. These are invaluable before your first build.

### Scale of Adoption

The Corne is legitimately one of the most popular open-source keyboard designs ever created. Data points:

- The foostan/crkbd repository has thousands of GitHub stars (check the current count at the repo)
- r/crkbd has tens of thousands of subscribers
- Major vendors (KBDfans, Keyhive, 42keebs) have been restocking Corne kits continuously for years — a sign of sustained demand
- Countless "inspired by Corne" designs exist (Lily58, Kyria, Sofle, Dao, Sweep) — the Corne's influence on the split keyboard lineage is enormous

### The Culture

The Corne community has a particular culture:

- **Build documentation is valued**: detailed build logs with photos are well-received and help future builders
- **Layout sharing is common**: people share their ZMK configs on GitHub and discuss them openly
- **Gatekeeping is minimal**: the community is welcoming to beginners because everyone remembers their first split keyboard
- **Rabbit hole is acknowledged and celebrated**: "welcome to the hobby, your wallet will never recover" is a common greeting to new members

---

## 11. Where to Get One

### Kit Vendors (PCBs + Components)

These vendors sell kits that typically include: left and right PCBs, acrylic or FR4 case pieces, TRRS jacks, reset buttons, OLED sockets, and sometimes diodes and hotswap sockets. You supply the controllers, switches, and keycaps.

| Vendor | Region | Notes | URL |
|---|---|---|---|
| **KBDfans** | Global (ships from China) | Reliable, good stock, competitive prices | kbdfans.com |
| **Keyhive** | USA | Fast US shipping, assembles on request | keyhive.xyz |
| **42keebs** | EU (Netherlands) | Best option for EU buyers; low import risk | 42keebs.eu |
| **Little Keyboards** | AU | Best for Australian buyers | littlekeyboards.com.au |
| **Boardsource** | USA | Quality kits, PCBs sometimes solderable hotswap | boardsource.xyz |
| **mechboards.co.uk** | UK | Good for UK/EU post-Brexit | mechboards.co.uk |
| **JLCPCB / PCBWay** | Global (China fab) | Order directly from foostan's gerbers if you want to source your own | jlcpcb.com |

### Pre-Built Options

If you want a Corne without soldering:

| Vendor | Notes |
|---|---|
| **Typeractive** | Sells assembled wireless Corne builds with nice!nano |
| **Keyhive** | Offers assembly service |
| **Local meetups / Group Buys** | Sometimes pre-builds appear on r/mechmarket |

Note: ZSA (makers of Moonlander, Ergodox EZ, Voyager) does not sell Corne keyboards. Their boards are proprietary designs.

### Direct From Fab (DIY Full Build)

The most involved but cheapest path to a Corne:

1. Download gerber files from [github.com/foostan/crkbd/releases](https://github.com/foostan/crkbd/releases)
2. Upload to JLCPCB or PCBWay; order 5 PCBs (minimum order) for ~$10–15
3. Source components from the BOM on the repository: diodes (1N4148W SOD-123), TRRS jacks, reset switches, OLED sockets, hotswap sockets
4. Order controllers, switches, keycaps separately
5. Assemble yourself

This path requires soldering SMD components (the diodes are small) and is recommended for your second Corne build, not your first.

### What to Buy If You Want Another

Given that you already have a working wireless Corne with nice!nano v2, for a second build:

1. **Corne MX kit** from Keyhive or 42keebs ($60–80): includes PCBs, case, and small components
2. **Two nice!nano v2** controllers ($25–35 each): same as your current setup
3. **Two 110mAh Li-Po batteries**: JST 2-pin connector, check vendor specifics
4. **Switches of choice** (see the Switches doc for recommendations)
5. **Keycaps** (see the Keycaps doc for recommendations)

---

## 12. Typical Build Costs

### Cost Breakdown by Component

| Component | Budget | Mid-Range | Premium |
|---|---|---|---|
| **PCB Kit** (PCBs + case + hardware) | $60–80 | $80–100 | $120–200 (aluminum) |
| **Controllers** (×2) | $10–20 (Pro Micro) | $50–70 (nice!nano ×2) | $70 (nice!nano ×2) |
| **Switches** (42) | $25–35 (Gateron Yellow, Akko) | $40–70 (Boba U4T, Gateron Oil King) | $80–150 (Topre-converted, Koalas, etc.) |
| **Keycaps** | $20–40 (blank PBT, KAM blanks) | $50–100 (GMK clone or Signature Plastics) | $120–300+ (GMK group buy) |
| **Batteries** (×2, for wireless) | $5–10 | $10–15 | $10–15 |
| **OLED displays** (×2, optional) | $5–10 | $5–10 | $5–10 |
| **Lube + tools** (if needed) | $10–20 | $20–40 | $30–60 |
| **TOTAL** | **~$135–215** | **~$255–405** | **$435–835+** |

### Total Build Scenarios

#### Budget Wireless Build (~$150–200)
- Corne MX kit from Keyhive: $75
- Two nice!nano v2: $60
- Gateron Yellow switches (linear, 45g, smooth): $28
- KAM Blank keycap set or NP PBT: $30
- Two 110mAh batteries: $10

*Result*: fully functional wireless Corne, feels good to type on, looks clean.

#### Mid-Range Build (~$250–350)
- Corne MX kit (with FR4 plate): $85
- Two nice!nano v2: $60
- Boba U4T switches (tactile, lubed): $55
- ePBT or Taro keycap set: $80
- Two 301mAh batteries: $15
- OLED displays: $10

*Result*: the "sweet spot" build. Premium feel, wireless, looks great on a desk, battery lasts 2–4 weeks.

#### Premium Build (~$400+)
- Aluminum sandwich case Corne kit: $150+
- Two nice!nano v2: $60
- Hand-lubed Topre-converted or Holy Panda switches: $100+
- GMK or SA keycap set: $150+
- Large LiPo batteries with custom JST harness: $20

*Result*: a board people take photos of. The kind of keyboard you show off.

### Notes on Costs

- Prices fluctuate significantly based on sales, group buys, and regional shipping
- Controllers and keycaps are the highest-variance costs — nice!nano occasionally goes out of stock; quality keycap sets have enormous price ranges
- EU buyers should add 20–25% for import duties on orders from outside the EU
- Australia/UK similarly add import costs
- Second-hand options (r/mechmarket, eBay) can cut costs 30–50%, especially for keycaps and switches

---

## 13. Your Build

You're already on the winning side of this. Here's how your build stacks up:

| Component | What You Have | Assessment |
|---|---|---|
| **Keyboard** | Corne (42-key MX) | The canonical ergonomic split |
| **Controllers** | nice!nano v2 × 2 | Best-in-class wireless; no compromises |
| **Firmware** | ZMK | Correct choice for nice!nano; active development |
| **Layout** | QWERTY base, 7 layers, Miryoku-inspired | Sophisticated; among the most efficient layouts on this form factor |
| **Home row mods** | GACS (GUI, Alt, Ctrl, Shift on A S D F) | The correct approach for 40% keyboards |
| **Vim arrows** | HJKL on NAV layer | Consistent with your muscle memory; transfers everywhere |
| **Mouse layer** | HJKL mmv + scroll + buttons | Full pointer control from home row |
| **Thumb layout** | Layer-tap on all 6 thumbs | Maximizes the thumb cluster |

### Your 7 Layers at a Glance

```
Thumb access pattern:
Left thumbs hold  →  MEDIA (ESC) | NAV (SPC) | MOUSE (TAB)
Right thumbs hold →    SYM (RET) | NUM (BSP) |   FUN (DEL)

  Layer 0 BASE  — QWERTY + GACS home row mods
  Layer 1 NAV   — HJKL arrows, clipboard, home/end/pgup/pgdn
  Layer 2 NUM   — Numpad-style 1–0, math operators
  Layer 3 MEDIA — Volume, play/pause, Bluetooth profiles, RGB
  Layer 4 SYM   — Symbols (!, @, #, brackets, etc.)
  Layer 5 FUN   — F1–F12 function keys
  Layer 6 MOUSE — HJKL mouse movement, scroll, click buttons
```

This structure follows the Miryoku philosophy: each layer is accessed via exactly one thumb, serves one purpose, and keeps all keys on or near home row. It's a well-proven design with an active community of practitioners.

### What to Explore Next

Now that you understand the hardware, you're positioned to go deeper in several directions:

- **Switches and sound**: your switch choice changes both feel and sound profile dramatically. See `docs/keyboard-research/switches.md`
- **Keycaps**: profile (SA, DSA, XDA, KAM, MT3), material (PBT vs. ABS), legends, and how to find group buys. See `docs/keyboard-research/keycaps.md`
- **ZMK firmware**: combos, conditional layers, mouse keys tuning, Bluetooth multi-device pairing. See `docs/corne/firmware.md`
- **Layout evolution**: how to tune your Miryoku layers; common modifications; whether to try Colemak-DH on top
- **Second board**: now that you're hooked, what would you build differently? A Choc version? A smaller 36-key? An aluminum case?

---

## Resources and Links

| Resource | URL |
|---|---|
| foostan's crkbd repository | https://github.com/foostan/crkbd |
| crkbd releases (gerber files) | https://github.com/foostan/crkbd/releases |
| ZMK firmware | https://zmk.dev |
| ZMK docs — behaviors | https://zmk.dev/docs/behaviors |
| ZMK mouse keys | https://zmk.dev/docs/behaviors/mouse-emulation |
| nicekeyboards (nice!nano) | https://nicekeyboards.com |
| QMK firmware | https://qmk.fm |
| r/crkbd | https://reddit.com/r/crkbd |
| r/ErgoMechKeyboards | https://reddit.com/r/ErgoMechKeyboards |
| Miryoku layout (reference) | https://github.com/manna-harbour/miryoku |
| KBDfans Corne kits | https://kbdfans.com |
| 42keebs (EU) | https://42keebs.eu |
| Keyhive | https://keyhive.xyz |
| Boardsource | https://boardsource.xyz |
| Keyswitch wiki | https://www.keyswitch.wiki |
| SwitchOddities database | https://github.com/switchoddities/switchdb |
| Keyboard layout editor | http://www.keyboard-layout-editor.com |
| ZMK Keymap Editor (GUI) | https://nickcoutsos.github.io/keymap-editor |

---

*Generated for the yuyudhan-zmk-config repository. For firmware-specific documentation, see `docs/corne/firmware.md`. For layout theory, see `docs/corne/layouts.md`.*
