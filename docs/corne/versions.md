# Corne Keyboard: Complete Version History & Variants Guide

> **Your Corne uses:** Corne v3 (crkbd v3) PCB · nice!nano v2 controllers · ZMK firmware  
> **This guide covers:** every version ever made, deep technical details, and what to buy next.

---

## Table of Contents

1. [The Corne Story — From Helidox to Today](#1-the-corne-story--from-helidox-to-today)
2. [Version Comparison at a Glance](#2-version-comparison-at-a-glance)
3. [Version History: Deep Dives](#3-version-history-deep-dives)
   - [Helidox (2018) — The Original](#31-helidox-2018--the-original)
   - [Corne v1 (2018–2019)](#32-corne-v1-20182019)
   - [Corne v2 (2019)](#33-corne-v2-2019)
   - [Corne v3 / crkbd v3 (2020–present)](#34-corne-v3--crkbd-v3-2020present)
   - [Corne LP — Low Profile Variant](#35-corne-lp--low-profile-variant)
   - [Corne Mini — 36-Key Variant](#36-corne-mini--36-key-variant)
4. [Corne v3 Deep Dive — What You Probably Built](#4-corne-v3-deep-dive--what-you-probably-built)
5. [Community Variants & Mods](#5-community-variants--mods)
   - [Corne-ish Zen (by Darryl Soo)](#51-corne-ish-zen-by-darryl-soo)
   - [Corne + Trackball Mods](#52-corne--trackball-mods)
   - [claw44 — The 44-Key Cousin](#53-claw44--the-44-key-cousin)
6. [MX vs. Choc: Full Comparison](#6-mx-vs-choc-full-comparison)
7. [Similar & Related Keyboards — What to Buy Next](#7-similar--related-keyboards--what-to-buy-next)
8. [Choosing Your Next Keyboard](#8-choosing-your-next-keyboard)
9. [Where to Get PCBs and Kits](#9-where-to-get-pcbs-and-kits)

---

## 1. The Corne Story — From Helidox to Today

The Corne keyboard was designed by **foostan** (a Japanese software engineer and mechanical keyboard enthusiast) and first published in 2018. It belongs to a class of keyboards called **split columnar-stagger 40% keyboards** — a form factor that prioritizes:

- **Ergonomics**: your hands sit at shoulder width, wrists stay straight
- **Minimalism**: every key is reachable without moving your hands
- **Hackability**: open-source PCBs, swap controllers, flash whatever firmware you want

The keyboard is officially named **crkbd** (Corne Keyboard), but nearly everyone calls it "Corne" (pronounced like the French word for horn, or just like the English word "corn"). The design proved so popular that it spawned a small ecosystem of variants, both official and community-made.

### Why the Corne Design Matters

Before the Corne, split ergonomic keyboards were either commercial products (expensive, limited) or hand-wired projects requiring significant electronics skill. The Corne hit a sweet spot:

```
┌─────────────────────────────────────────────────────────────────┐
│                   The Corne Design Philosophy                   │
├─────────────────┬───────────────────────────────────────────────┤
│ Open Source     │ Free Gerber files, MIT license, fork away     │
│ PCB-based       │ No hand-wiring; beginner-friendly build        │
│ Modular         │ Swap controllers, switches, cases              │
│ Ergonomic       │ Columnar stagger, split halves, thumb cluster  │
│ Minimal         │ 42 keys forces you to layer — and it works    │
│ Community       │ Massive QMK/ZMK support, huge Reddit presence  │
└─────────────────┴───────────────────────────────────────────────┘
```

foostan publishes everything at: **https://github.com/foostan/crkbd**

---

## 2. Version Comparison at a Glance

| Feature | Helidox | v1 | v2 | v3 (yours) | Corne LP | Corne Mini |
|---|---|---|---|---|---|---|
| **Keys** | 42 | 42 | 42 | 42 | 42 | 36 |
| **Switch support** | MX | MX | MX | MX + Choc | Choc only | MX or Choc |
| **Per-key RGB** | No | No | No | Yes (SK6812) | No | Yes |
| **RGB underglow** | No | Yes | Yes | Optional | No | Optional |
| **OLED** | Optional | Optional | Improved | Yes (top) | Yes | Yes |
| **Hot-swap** | No | No | Partial | Yes (sockets) | Yes | Yes |
| **PCB quality** | Prototype | Good | Better | Best | Best | Best |
| **Status** | Archived | Archived | Archived | Active ✓ | Active ✓ | Active ✓ |

---

## 3. Version History: Deep Dives

### 3.1 Helidox (2018) — The Original

The very first iteration of what would become the Corne. foostan posted it to the Japanese keyboard community under the name **Helidox** in early 2018.

**Historical significance:**
- First published: January 2018 on GitHub
- Name "Helidox" was a placeholder / early working name
- Design was inspired by the **Ergo42** (a 4×7 ortholinear split) but reduced to 3 rows
- Used standard through-hole components, no SMD experience required
- No RGB at all — bare bones PCB

**Technical specs (Helidox):**
- Controller: Pro Micro (5V, ATmega32U4)
- Switch support: MX only (no Choc)
- Connection between halves: TRRS cable
- Firmware: QMK (very early fork)
- PCB: two-layer, simple routing
- No OLED support
- No RGB (underglow or per-key)

The Helidox was shared on Twitter and the Japanese r/mechkeys equivalent, gaining immediate traction because split columnar boards were hard to find open-source at the time.

---

### 3.2 Corne v1 (2018–2019)

After the Helidox got community feedback, foostan redesigned and renamed it **Corne** (crkbd). v1 was a significant upgrade from the prototype Helidox.

**What changed from Helidox → v1:**
- Added **RGB underglow** (WS2812B LEDs on the bottom of the PCB)
- Improved PCB routing — cleaner traces, better ground plane
- Added optional **OLED header** (128×32 OLED module, I2C)
- Formalized the columnar stagger amounts (see below)
- Better documentation

**Corne v1 column stagger amounts** (how much each column is offset from its neighbor, in millimeters):

```
Pinky  Ring   Middle Index  Inner
  0    +6mm   +11mm  +9mm   +7mm
      ↑ each column is raised vs. its neighbor moving away from middle
```

This stagger is *less aggressive* than some boards (like Kyria) but enough to dramatically reduce ulnar deviation compared to row-stagger (traditional) keyboards.

**v1 limitations:**
- MX switches only (Choc PCBs didn't exist yet)
- No per-key RGB (just underglow strip)
- OLED placement was awkward — on the outer edge, partially obscured by case
- Diodes were through-hole (1N4148), which takes more space and build time

**Why v1 matters:**
This is the version that put the Corne on the map. The QMK PR was merged, r/ErgoMechKeyboards started talking about it, and Western keyboard enthusiasts discovered it through build logs.

---

### 3.3 Corne v2 (2019)

A refinement, not a redesign. v2 fixed pain points reported by v1 builders.

**Changes from v1 → v2:**
- **SMD diodes**: switched from through-hole 1N4148 to **1N4148W SOD-123** surface-mount diodes. Harder to solder for beginners, but much more space-efficient and the modern standard.
- **Improved OLED positioning**: OLED moved to sit above the controller, facing outward — a better viewing angle
- **Better ground plane**: reduced RF noise, more stable USB connection
- **Cleaner silkscreen**: component labels, version numbers, build guides
- PCB still MX-focused (Choc support was a separate community project at this point)
- Underglow LEDs (WS2812B) still present, still no per-key LEDs

**v2 build experience:**
v2 became the "standard" Corne in 2019–2020. Most build guides you'll find from that era refer to v2. If someone posts a Corne build on Reddit from 2019–2020 with nice OLEDs and RGB underglow but no per-key LEDs, it's almost certainly v2.

---

### 3.4 Corne v3 / crkbd v3 (2020–present)

This is the version you own. The **biggest redesign** in Corne history. foostan rebuilt the PCB from scratch to support modern components.

**Major changes from v2 → v3:**

#### Per-Key RGB (SK6812MINI-E)
The single biggest hardware addition. v3 replaces underglow strips with **SK6812MINI-E** reverse-mounted LEDs — one per key, 42 total per keyboard.

- SK6812MINI-E are the "E" (environmentally-friendly, lead-free) version of SK6812MINI
- They're **reverse-mounted**: the LED faces down through the PCB, shining up through the switch and keycap
- The "MINI" refers to their size: 3.5mm × 3.5mm — tiny
- They're WS2812B-compatible (same data protocol), so QMK/ZMK RGB Matrix config just works
- Each LED is individually addressable — you can light each key a different color

```
How per-key LEDs work (cross-section view):

  Keycap (translucent or clear stem)
     │
  Switch housing (transparent bottom on RGB-capable switches)
     │
  PCB (has cutout/hole for the LED)
     │
  ┌──▼──┐
  │ LED │  ← SK6812MINI-E faces DOWN, light goes UP through switch
  └─────┘
     │
  PCB backside (you solder to pads here)
```

Most switches have opaque housings that block LED light — for best RGB visibility, you want **transparent-bottom switches** (e.g., Gateron G Pro, Durock L7, Akko CS) or switches specifically sold as "RGB-compatible."

#### Dual Switch Support (MX and Choc)
v3 offers two separate PCB variants:
- **crkbd v3 MX**: Kailh MX hot-swap sockets — any Cherry MX-compatible switch
- **crkbd v3 Choc**: Kailh Choc hot-swap sockets — Kailh Choc v1 or v2 low-profile switches

These are **separate PCBs** — you order one or the other from JLCPCB (or buy a kit). The PCBs look almost identical but have different socket footprints.

#### Hot-Swap Sockets
v3 made hot-swap the default. You solder Kailh hot-swap sockets to the PCB, and switches just push in and pull out without soldering. Previously, switching switches meant a full desolder/resolder job. Now it's seconds.

#### Updated Controller Footprint
v3 maintains the Pro Micro pinout but improved the footprint to be more compatible with modern alternatives:
- **Elite-C** (USB-C Pro Micro, ATmega32U4)
- **nice!nano v2** (your controller — nRF52840, Bluetooth, wireless)
- **RP2040-based Pro Micros** (Sparkfun Pro Micro RP2040, WeAct RP2040)
- **Sea-Picro** (RP2040 in Pro Micro form factor)

#### OLED Position Refined Again
The OLED now sits cleanly above the controller with a dedicated header position. Standard 128×32 I2C OLED modules (the common cheap SSD1306 or SH1106 ones from Amazon/AliExpress) plug in directly.

---

### 3.5 Corne LP — Low Profile Variant

The "LP" stands for **Low Profile**, and this variant is specifically designed for **Kailh Choc switches** (both v1 and v2). It is NOT the same as the Choc variant of v3 — the Corne LP is a distinct design with a different PCB layout tuned for the thinner Choc form factor.

**Why a separate LP design?**

Regular Corne v3 (even the Choc variant) is designed with MX key spacing in mind (19.05mm × 19.05mm). Choc switches, being low-profile, naturally pair better with the tighter Choc spacing (18mm × 17mm). The Corne LP uses this tighter spacing, which:

1. Makes the keyboard physically smaller overall
2. Allows the column stagger amounts to be recalibrated for the different switch height and natural hand position when typing low
3. Is more comfortable for people who use Choc switches as their primary input

**Corne LP specs:**
- Switch support: Kailh Choc v1 / v2 only (no MX)
- Key spacing: 18mm × 17mm (tighter than standard 19.05mm)
- Total keyboard width: noticeably narrower than MX Corne
- No per-key RGB (Choc LEDs use different footprint — SK6812MINI, not MINI-E)
- Profile: extremely thin — about 10–12mm tall with Choc switches and flat keycaps

**Who is Corne LP for?**
- People who want the absolute thinnest possible keyboard
- Travel typists who need a laptop-adjacent experience
- Users who find even standard Corne too tall/bulky on the desk
- Fans of the "flat" typing experience

---

### 3.6 Corne Mini — 36-Key Variant

The Corne Mini removes the **outer pinky column** from each half, leaving 18 keys per half, 36 total. This is the most minimal Corne variant foostan officially supports.

```
Standard Corne (42 keys):           Corne Mini (36 keys):
┌─┬─┬─┬─┬─┬─┐                      ┌─┬─┬─┬─┬─┐
│Q│W│E│R│T│  │                      │W│E│R│T│  │
├─┼─┼─┼─┼─┤  │                      ├─┼─┼─┼─┤  │
│A│S│D│F│G│  │         →            │S│D│F│G│  │
├─┼─┼─┼─┼─┤  │                      ├─┼─┼─┼─┤  │
│Z│X│C│V│B│  │                      │X│C│V│B│  │
└─┴─┴─┴─┴─┴─┘                      └─┴─┴─┴─┴─┘
  ↑ outer pinky col                   ↑ removed
```

**Trade-off:**
- Less stretch for pinkies (which are naturally shorter fingers)
- Requires more aggressive layering — you've already lost 6 keys vs. the standard Corne
- Very popular among Miryoku users (your layout!) because Miryoku was designed for 34–36 key boards

**For Miryoku users specifically:**
The Miryoku layout was originally designed for the **Ferris Sweep** (34 keys) and scales naturally to 36. If you use the Corne Mini, your thumbs still have their 6-key cluster (unchanged), and the outer pinky positions (Q, A, Z on left; P, ;, / on right) are the keys you lose. Miryoku doesn't use those positions for anything critical — a good fit.

---

## 4. Corne v3 Deep Dive — What You Probably Built

Since v3 is the current standard and almost certainly what you have, here's the complete technical breakdown.

### PCB Dimensions

Each half of the Corne v3 PCB measures approximately:

```
┌─────────────────────────────────────────┐
│                                         │
│   130mm wide × 95mm tall (approx)      │
│                                         │
│   PCB thickness: 1.6mm (standard FR4)  │
│                                         │
└─────────────────────────────────────────┘
```

The PCB is reversible — left and right halves use the **same PCB**, flipped. This is intentional: it halves manufacturing cost (one PCB design, ordered twice), and it means if you damage one half, you can make another from the same batch.

### Complete Component List (One Half)

| Component | Type | Qty | Notes |
|---|---|---|---|
| Diodes | 1N4148W (SOD-123, SMD) | 21 | One per key; handles key matrix |
| TRRS Jack | PJ-320A or PJ-32J5 | 1 | 3.5mm TRS/TRRS audio jack; connects halves |
| Reset button | EVQPUL or 3×6mm SMD tactile | 1 | Puts controller in bootloader mode |
| SK6812MINI-E LEDs | 3.5×3.5mm SMD RGB | 21 | Per-key RGB; reverse-mounted |
| OLED display | 0.91" 128×32 I2C | 1 | SSD1306 or SH1106 controller |
| OLED header | 4-pin 2.54mm socket | 1 | OLED plugs into this |
| Kailh MX hotswap | CPG151101S11 | 21 | For MX build |
| *or* Kailh Choc hotswap | CPG135001S30 | 21 | For Choc build |
| Controller sockets | Mill-Max 315 or machined headers | 2 rows | Lets you swap controllers |
| nice!nano (your build) | nRF52840 Pro Micro | 1 | Wireless; sits in sockets |
| Battery connector | JST PH 2.0 | 1 | Wireless builds only |
| LiPo battery | 3.7V, 100–800mAh | 1 | Wireless builds only |
| Switches | MX or Choc | 21 | Snaps into hotswap sockets |
| Keycaps | Your choice | 21 | Per side |

**Total: 42 switches, 42 diodes, 42 LEDs across both halves.**

### The Diode: 1N4148W in SOD-123 Package

Every key in the matrix has a diode that prevents "ghosting" — the phenomenon where pressing 3+ keys simultaneously causes phantom keypresses to be registered.

```
SOD-123 Diode Orientation:
          Cathode (bar side)
               │
    ┌──────────┤
    │   1N4148W│──────────── Anode
    └──────────┤
               │
        marked with a line on PCB silkscreen
```

On the Corne v3 PCB, the cathode orientation is marked on the silkscreen. Getting this wrong means that key simply won't register.

**Why SMD diodes?**
Surface-mount SOD-123 diodes are about 2.5mm long — tiny. They sit flat on the PCB and take up almost no space vs. through-hole (which require drilling, stick out, and need legs bent). The trade-off: harder to solder with a standard iron tip. A fine conical tip, good flux, and tweezers make it manageable.

### TRRS: How the Two Halves Communicate

The two halves connect via a standard **3.5mm TRRS cable** (the same as old headphones-with-mic cables).

```
TRRS Plug Pin Layout:
  ┌─ TIP   → VCC (power)
  ├─ RING1 → GND (ground)
  ├─ RING2 → Data TX
  └─ SLEEVE → Data RX (or second data line for full-duplex)
```

One half is the "master" (connected to USB/Bluetooth host), the other is the "slave." The master reads the slave's key matrix over serial (UART), combines it with its own matrix scan, and sends the full keycode to the host.

**Important:** Always plug/unplug the TRRS cable when the keyboard is **powered off** (USB unplugged or powered down). Hot-plugging TRRS can cause short circuits across the GND/VCC pins as the plug partially inserts.

**For wireless builds (yours):** With nice!nano controllers, you can use the TRRS cable *or* go fully wireless. Your ZMK config likely uses Bluetooth on both halves, with the left half acting as the "central" and right as "peripheral." No cable needed — but battery life is shorter for the peripheral half since it's always advertising.

### Reset Button

The small tactile switch labeled "RESET" on the PCB. Pressing it once puts the controller in **bootloader mode** — required to flash new firmware.

- **QMK (Pro Micro, Elite-C):** double-tap reset to enter bootloader (on modern QMK). Single press on some older versions.
- **ZMK (nice!nano):** double-tap reset within 500ms to enter UF2 bootloader. The nice!nano appears as a USB drive (`NICENANO`) and you drag-drop a `.uf2` file to flash.

### SK6812MINI-E: Per-Key RGB Deep Dive

These tiny LEDs are the most difficult part of a Corne v3 build. Here's why:

**SK6812MINI-E specs:**
- Size: 3.5mm × 3.5mm × 1.4mm
- Forward voltage: ~3.3V (GND, VCC, Data In, Data Out)
- Protocol: WS2812B compatible (single-wire, 800kbps)
- Color depth: 8 bits per channel (16 million colors)
- Current: ~5mA per channel at full brightness → up to 15mA per LED at white

**Why they're tricky to solder:**
1. They're tiny — 3.5mm is about the width of your fingernail
2. They're **heat-sensitive** — sustained heat above 260°C for more than 10 seconds can kill them
3. They're reverse-mounted (face down), so you're soldering on the back and can't see the LED face to check orientation
4. The solder pads are on the edge of the LED, not the center

**Common build failure: dead or incorrect-color LED**
If one LED is wrong, all LEDs **after it in the chain** may also fail — they're daisy-chained in series (Data In → Data Out). Knowing which LED failed tells you which to replace.

**Orientation:** There's a cut corner on the SK6812MINI-E that marks the GND pin. The PCB silkscreen has a matching corner mark. Align these before soldering.

```
SK6812MINI-E pad layout (bottom view, as you solder):
  
  ┌──────────┐
  │ GND  DI  │  ← GND has the cut corner (chamfer)
  │          │
  │ VCC  DO  │
  └──────────┘
        ↑
   cut corner here = GND
```

---

## 5. Community Variants & Mods

### 5.1 Corne-ish Zen (by Darryl Soo)

The **Corne-ish Zen** (sometimes written "Corne-ish Zen" or just "Zen") is arguably the most beautiful and most polished Corne variant ever made. It was designed and sold by **Darryl Soo**, a Singapore-based keyboard designer.

> Store: **lowprokb.ca** and **store.kbd.news**  
> GitHub: **github.com/lowprokb.ca/ENGRAM**  
> Subreddit: r/ErgoMechKeyboards has constant Zen posts

**What makes the Zen special:**

#### E-Ink Display (Instead of OLED)

The Zen uses a **1.54-inch E-Ink display** instead of the standard OLED. E-Ink (electronic paper) has fundamentally different properties:

| Property | OLED (standard Corne) | E-Ink (Corne-ish Zen) |
|---|---|---|
| Refresh rate | Instant | ~2 seconds |
| Retains image when off | No (goes black) | **Yes — forever** |
| Power when idle | Draws power to maintain image | **Zero power** |
| Visibility in sunlight | Washes out | Excellent |
| Color | White on black (typical) | Black on white (like paper) |
| Coolness factor | High | **Extremely high** |

The E-Ink display shows the current layer name (Base, Nav, Num, etc.) and any custom art you want to display — and it keeps showing it even when the keyboard is completely off and batteries removed. Your layer indicator is essentially a persistent sticker that updates when you switch layers.

This is partly aesthetic (the display always showing "BASE" or your custom Pokémon art looks incredible), but it also means **zero display power draw** when idle — a major battery life win.

#### No RGB — By Design

Darryl made a deliberate decision: **no LEDs of any kind**. No per-key RGB, no underglow. Reasons:

1. **Battery life:** RGB LEDs are power-hungry. A single LED at full white draws ~15mA. 42 LEDs at full white = 630mA, which would drain a 500mAh battery in under an hour. Removing RGB entirely lets the Zen run for **weeks** on a single charge.
2. **Simplicity:** Fewer components = simpler build = fewer failure points.
3. **Aesthetics:** The Zen is meant to look premium and understated, not flashy.

Reported battery life: **several weeks** of daily use on a modest-sized LiPo (the case has room for a good-sized battery).

#### Premium Case Options

The Zen is sold as a complete kit with case options including:
- **FR4 plate + bottom** (PCB-based, same material as the board)
- **Aluminum case** — machined aluminum, feels extremely premium, available in multiple anodized colors

The aluminum case option turns the Zen into something that looks and feels like a commercial product, not a DIY build. This is unusual for the open-source keyboard world.

#### ZMK Exclusively

The Zen was designed wireless-first. It uses nice!nano v2 controllers (same as yours) and runs ZMK. There is no QMK support — ZMK's wireless-first architecture is essential to the Zen's long battery life.

#### Versions Available

- **Corne-ish Zen v1** — the original sold version
- **Corne-ish Zen v2** — refined, sold at lowprokb.ca
- **MX version** — standard Cherry MX switches
- **Choc version** — Kailh Choc, for a thinner profile

**Price:** Complete kits range from ~$80–$150+ depending on case option and region.

---

### 5.2 Corne + Trackball Mods

A popular community modification adds a **trackball** to one half of the Corne, typically replacing the inner thumb key or the top-row inner column.

**Why add a trackball?**

Your Corne already has a mouse layer (Layer 6, held via TAB) with HJKL movement — this is excellent for precision cursor work. But trackball lovers want hardware cursor control without holding a layer key. A trackball gives you:
- Instant cursor movement without switching layers
- Much faster pointer movement than key-based `mmv`
- Clicks without special layer access

**Common trackball options:**

#### Ploopy Nano
- **What it is:** An open-source trackball by Ploopy (Canadian maker), originally a standalone device
- **Size:** Small trackball, ~25mm ball diameter
- **How it mounts to Corne:** Community-designed mounts let you affix a Ploopy Nano to the outer column area of the right half
- **Connection:** USB to the Corne's controller (requires USB host support — not possible on stock nice!nano without extra hardware)
- **Source:** ploopy.co

#### Rollio
- **What it is:** A community design — a minimalist trackball PCB that can be integrated into a Corne build
- **Integration:** Some builds replace the inner thumb key or corner key with the trackball sensor
- **Works with:** QMK's built-in pointing device support; ZMK pointng (pointing device support is newer but available)

#### PMW3389 / PMW3360 Sensor Mods
Advanced builders add an optical sensor PCB (same sensor in many gaming mice) to a custom mount and wire it to a spare GPIO pin on the controller. This gives you:
- Very precise, high-DPI sensor
- Fully programmable behavior in firmware
- No commercial trackball dependency

**ZMK trackball support:** ZMK added pointing device support (including trackball/mouse move) relatively recently. Your keymap already uses `mmv` (mouse move via keys), so the ZMK infrastructure is there — physical trackball integration is the hardware challenge.

---

### 5.3 claw44 — The 44-Key Cousin

The **claw44** is a closely related keyboard designed by **yfuku**, inspired by the Corne. Key differences:

| Feature | Corne v3 | claw44 |
|---|---|---|
| Keys | 42 | 44 |
| Thumb cluster | 3 keys × 2 | 3 keys × 2 + 1 extra |
| Column stagger | Moderate | Slightly different |
| Split angle | Moderate | Similar |
| Firmware | QMK / ZMK | QMK / ZMK |
| Open source | Yes | Yes |

The 2 extra keys on the claw44 are typically additional thumb keys — giving you a 4th thumb key on one or both halves. Some users find 3 thumb keys sufficient (you do); others want an extra for convenience without adding a full pinky column.

- GitHub: **github.com/yfuku/claw44**

---

## 6. MX vs. Choc: Full Comparison

This is the most practical decision for anyone buying or building a Corne: **MX or Choc?**

| Feature | Corne MX | Corne Choc |
|---|---|---|
| **Switch type** | Cherry MX compatible (100s of options) | Kailh Choc v1 or v2 only |
| **Switch height** | ~18mm from plate to top of switch | ~8mm (Choc v1) or ~5mm (Choc v2) |
| **Keycap height** | ~7–9mm (profile dependent) | ~3mm (MBK) to ~5mm (Choc keycaps) |
| **Total keyboard height** | ~30–35mm (varies with case) | ~15–20mm (very thin) |
| **Key spacing** | 19.05mm × 19.05mm (standard) | 18mm × 17mm (Choc) or 19.05mm (Corne v3 Choc) |
| **Keycap compatibility** | All MX-stem keycaps (massive market) | Choc-specific only (smaller market) |
| **Keycap profile options** | Cherry, OEM, SA, DSA, XDA, GMK, MT3, etc. | MBK, Choc POM, LDSA, Choc-compat only |
| **Keycap price** | $20–$200+ (huge range) | $20–$60 (fewer options, less GB variety) |
| **Tactility/feel options** | Linear, tactile, clicky — 100s of options | Fewer options (Choc has fewer switch variants) |
| **Sound** | Varies by switch/case — can be very quiet or loud | Quieter by default (shorter travel = less sound) |
| **Typing speed** | Depends on switch and technique | Often faster for light typists (less travel) |
| **Portability** | Moderate | Excellent — fits in a laptop bag effortlessly |
| **Wrist position** | Higher off desk, may need wrist rest | Closer to desk level, more natural for some |
| **Best for** | Switch variety, community support, customization | Travel, desk space, thin profile, quieter offices |
| **RGB visibility** | Excellent with right switches | Limited — Choc RGB keycaps are rarer |
| **Recommendation** | If you love switch variety or already have switches | If you travel often or prefer ultra-low desk profile |

### MX Switch Height Diagram vs. Choc

```
Side profile comparison (approximate, not to scale):

MX build:
  Keycap ────────────────────┐
                             │  ~9mm
  Switch top ────────────────┘
                             │  ~9mm switch travel
  PCB  ──────────────────────┤
  Case ──────────────────────┘  ~5mm
  
  Total: ~35mm from desk to keycap top

Choc (low-profile) build:
  Keycap ───────────┐
                    │  ~3mm (MBK keycap)
  Switch top ───────┘
                    │  ~3mm switch travel
  PCB  ─────────────┤
  Case ─────────────┘  ~4mm
  
  Total: ~13–15mm from desk to keycap top
```

The difference is dramatic in practice. A Choc keyboard on a desk looks almost like PCB sitting flat — it's the "flat" keyboard experience. MX builds feel more like traditional mechanical keyboards in terms of height.

---

## 7. Similar & Related Keyboards — What to Buy Next

The Corne is your gateway drug. Here's the full landscape of where you can go next, organized from "most similar to Corne" to "most different."

### 7.1 Lily58 — "Corne with a Number Row"

**Keys:** 58 (6 columns × 4 rows + 4 thumb keys per half)  
**What's added vs. Corne:** A full top number row (1234567890-=) plus 2 extra thumb keys  
**Form factor:** Split, columnar stagger — looks very similar to Corne  
**Firmware:** QMK / ZMK  
**PCB:** Open source, JLCPCB-orderable  
**Controller:** Pro Micro compatible  
**Hot-swap:** Available

```
Lily58 layout sketch:

 Left half:            Right half:
 1  2  3  4  5  6      7  8  9  0  -  =
 [  Q  W  E  R  T      Y  U  I  O  P  ]
 [  A  S  D  F  G      H  J  K  L  ;  '
 [  Z  X  C  V  B      N  M  ,  .  /  ]
      [ T1 T2 T3 ]  [ T4 T5 T6 ]
```

**Who should buy it:** If your biggest frustration with the Corne is reaching numbers via layers (NUM layer), Lily58 solves that. Number row is instant. The trade-off: more finger travel to reach the top row.

**Resources:** github.com/kata0510/Lily58, lily58.com

---

### 7.2 Sofle v2 — The Most Popular Corne Alternative

**Keys:** 58  
**What's special:** **Rotary encoders** on each half (above the thumb cluster) — you can scroll, change volume, zoom, etc. by spinning a knob  
**Form factor:** Split, columnar stagger  
**Firmware:** QMK / ZMK  
**PCB:** Open source  
**Hot-swap:** Yes (v2 improved this significantly)

The Sofle is often described as "Lily58 with encoders." It was designed by **Josef Adamcik** and became enormously popular because encoders add utility without adding more keys. Spinning to scroll is satisfying in a way key-based scrolling isn't.

**Sofle v2 specific improvements:**
- Better PCB quality vs. v1
- RGB support (underglow and per-key)
- More stable OLED placement
- Improved USB-C positioning

**Sofle RGB:** A variant with per-key RGB throughout; very popular on r/MechanicalKeyboards build photos.

**Resources:** github.com/josefadamcik/SofleKeyboard, josefadamcik.github.io/SofleKeyboard/

---

### 7.3 Kyria (by splitkb.com)

**Keys:** 50 (base) — highly configurable  
**What's special:** **More aggressive column stagger** than Corne, trackball/encoder support built-in, premium PCB quality  
**Form factor:** Split, columnar stagger  
**Firmware:** QMK / ZMK  
**PCB:** Sold commercially by splitkb.com (not free Gerbers for sale)  
**Hot-swap:** Yes  
**Extra features:** Encoder spots (up to 2 per half), trackball mount option (Ploopy-compatible)

The Kyria has a notably more aggressive column stagger — the pinky and ring finger columns drop much further relative to the middle column. This is **more ergonomic** for people with shorter pinkies but takes more adaptation than the Corne's moderate stagger.

**Column stagger comparison:**

```
Corne stagger (moderate):     Kyria stagger (aggressive):
 ─────────────────────         ─────────────────────
 | Pi| Ri| Mi| In|             | Pi   | Ri| Mi| In|
 |   |   |   |   |             |      |   |   |   |
 |   |   |   |   |             |   ↓  |   |   |   |
                                | more  |
                                | drop  |
```

**Who should buy it:** If you want trackball integration as a first-class feature, or if you've found the Corne's stagger not aggressive enough for your pinky comfort.

**Price:** ~$50–80 for PCBs from splitkb.com (European-focused shop, ships internationally)

---

### 7.4 Ferris / Sweep — Extreme Minimalism (34 Keys)

**Keys:** 34 (3×5 columns, 2 thumbs per half — no number row, no inner column)  
**What's special:** No microcontroller onboard — the **nice!nano plugs in directly** without sockets. Extremely minimal. Miryoku was originally designed for this layout.  
**Firmware:** QMK / ZMK  
**PCB:** Open source (github.com/davidphilipbarr/Sweep)  
**Hot-swap:** Sweep has hot-swap sockets; original Ferris doesn't

```
Ferris Sweep layout (one half):

 Q  W  E  R  T
 A  S  D  F  G
 Z  X  C  V  B
          T1 T2
```

Compared to your Corne, the Sweep loses:
- The entire inner column (T, G, B / Y, H, N)
- The outer pinky column (Q, A, Z / P, ;, /)
- One thumb key per side

Miryoku, which you already use in spirit, was originally designed for exactly this footprint. Your current 7-layer Miryoku-style config would port almost 1:1 — the only keys you lose are positions you might already have as "none."

**Who should buy it:** Miryoku purists who want to minimize finger travel absolutely. Also popular for travel: 34 keys in a split layout is incredibly compact.

---

### 7.5 Dactyl Manuform — 3D-Printed Bowl Keyboard

**Keys:** Configurable (typically 62–72, but can be 36–70)  
**What's special:** 3D-printed shell shaped like a **bowl or saddle**. Keys curve to meet your fingers, rather than your fingers reaching flat. The most ergonomically "correct" keyboard shape you can build.  
**Firmware:** QMK (original) / ZMK (community ports)  
**Controller:** Pro Micro compatible (fits in the thumb cluster)  
**Hot-swap:** Optional (build-dependent)

```
Dactyl cross-section (side view):

   ────────────────────
  /                    \
 /  keys curve inward   \
│   to meet your fingers │
 \                      /
  ────────────────────
```

The Dactyl Manuform has two arcs — one for each finger column (deeper in the middle, shallower at the edges) and a slight tenting (the keyboard tilts inward, like a tent). This is as close as keyboards get to **anatomically shaped**.

**How to get one:**
- Print your own: github.com/carbonfet/dactyl-manuform (Python generator creates STL files)
- Buy from a builder: Etsy, local maker, or community Discord sales
- Commission: $150–400 depending on switches, case, print quality

**Trade-offs:**
- No standard keycaps — most use DSA or XDA (uniform profile) because the curve makes profile-specific keycaps mismatched
- Not portable — the bowl adds significant depth
- Building from scratch is a significant electronics project (hand-wiring required, no PCB)
- Each 3D print takes 10–20 hours

---

### 7.6 ZSA Moonlander Mark I — Commercial Split Ergo

**Keys:** 72 (6×4 + 8 thumb keys, each half)  
**Price:** $365 USD  
**What's special:** Commercial product with full support. Adjustable thumb cluster (rotates/tilts). Works with Oryx, ZSA's browser-based keymap editor (no coding needed).  
**Firmware:** QMK (modified ZSA fork), Oryx configurator  
**Hot-swap:** Yes (all switches)  
**Switch compatibility:** MX compatible  
**Tenting:** Column-by-column tenting legs included

**Why someone chooses Moonlander over Corne:**
- Zero technical skill required to configure
- Customer support from ZSA (known for excellent support)
- More keys → easier transition from traditional keyboards
- Physical tenting out-of-the-box
- USB-C center cable (looks cleaner on desk)

**Why Corne users don't switch to Moonlander:**
- Way more keys (if you've adapted to 42, 72 feels wasteful)
- Very expensive ($365 vs. ~$70 DIY Corne)
- Less community-driven customization
- ZMK/wireless not supported (wired only)

**ZSA's lineup:** Also includes the **Ergodox EZ** (76 keys, $270), **Voyager** (52 keys, $365, their most compact commercial offering).

---

### 7.7 Kinesis Advantage360

**Keys:** 88  
**Price:** $449 USD  
**What's special:** Bowl-shaped commercial keyboard — think Dactyl Manuform but manufactured at scale. The Advantage lineup is the gold standard for heavy-RSI recovery users.  
**Firmware:** SmartSet (proprietary) + some QMK support in newer variants  
**Hot-swap:** Yes (Advantage 360 Pro version)

The Kinesis Advantage has been around since the 1990s and has a devoted following in the programming community. People with serious RSI (carpal tunnel, tendinitis) often credit it with letting them continue typing. The bowl puts keys exactly where fingers rest naturally, with nearly zero lateral finger movement needed.

The **360** is their wireless, split version — the old Advantage was a single connected piece.

---

### 7.8 Dygma Defy — Commercial Hot-Swap Wireless Split

**Keys:** 78 + 6 thumb cluster keys  
**Price:** $329 USD (wireless version)  
**What's special:** Commercial split keyboard with **hot-swap**, **wireless**, and **software configurator** (Bazecor). Aimed at non-programmers who want a commercial ergonomic experience.  
**Firmware:** Custom (Defy-specific)  
**Tenting:** Tenting kit sold separately

The Dygma Defy is the "no programming required" split keyboard. If you want to recommend keyboards to a non-technical colleague who has wrist pain, Defy is the answer.

**Their older product:** Dygma Raise is a TKL-style ergonomic keyboard (still row-stagger, but split and with a programmable thumb cluster).

---

### 7.9 Totem — Ultra-Compact 38-Key

**Keys:** 38 (3×5 + 4 thumbs — similar to Corne Mini but even more aggressive)  
**What's special:** Community design by GEIST, extremely small footprint, no pinky columns at all  
**Firmware:** QMK / ZMK  
**PCB:** Open source (github.com/GEIGEIGEIST/TOTEM)  
**Case:** Simple case files included

The Totem pushes further than even the Corne Mini — it's designed around the principle that your pinkies should do minimal work. The outer "pinky" column is removed, and the remaining 3 columns per side use an aggressive stagger tuned for this reduced layout.

People who've used Ferris/Sweep and liked it but want 4 thumb keys often land on Totem.

---

### 7.10 Glove80 (by MoErgo) — Wireless Contoured 80-Key

**Keys:** 80  
**Price:** $399 USD  
**What's special:** The most accessible contoured (bowl-shaped) keyboard commercially available. Each key column is at a different height and angle. Wireless (Bluetooth). ZMK firmware.  
**Firmware:** ZMK (same as yours!)  
**Hot-swap:** Yes  
**Battery life:** Months on a single charge

The Glove80 is the "if you want Dactyl Manuform but don't want to 3D print" keyboard. It's injection-molded (not printed), comes with a warranty, and MoErgo provides configuration software.

**What 80 keys gets you:**
- Full number row
- Function keys (F1–F12) accessible
- Dedicated arrow cluster
- Media keys

**Who should buy it:** Programmers/writers who've suffered wrist pain, want contoured but aren't willing to build, and appreciate wireless. The price is steep but less than a standing desk riser.

**ZMK connection:** Since Glove80 uses ZMK (same as your Corne), your muscle memory for ZMK concepts (layers, combos, hold-tap) transfers directly. Your config patterns would port over.

---

## 8. Choosing Your Next Keyboard

Decision tree for Corne lovers:

```
You love the Corne and want...
│
├── MORE KEYS (tired of number layer)
│   ├── +Number row, keep columnar stagger → Lily58 or Sofle v2
│   └── +Number row + encoders → Sofle v2 (has both)
│
├── FEWER KEYS (love minimalism, want to go further)
│   ├── 36 keys, similar layout → Corne Mini
│   ├── 34 keys, pure Miryoku → Ferris Sweep
│   └── 38 keys, no pinkies → Totem
│
├── BETTER ERGONOMICS (wrist pain or want more comfort)
│   ├── More column stagger, keep flat → Kyria
│   ├── Contoured bowl, DIY → Dactyl Manuform
│   ├── Contoured bowl, buy commercial → Glove80
│   └── Maximum tenting, commercial support → ZSA Moonlander
│
├── WIRELESS / BEAUTIFUL OLED UPGRADE
│   └── Stay Corne-style, go wireless premium → Corne-ish Zen
│
├── TRACKBALL INTEGRATION
│   ├── Add to Corne → Ploopy Nano mount (community mod)
│   └── Buy with trackball support → Kyria + Ploopy
│
├── THINNER / LOWER PROFILE
│   ├── Keep Corne design, go Choc → Corne LP
│   └── More extreme thinness → Corne LP with Choc v2
│
├── COMMERCIAL SUPPORT (no DIY, just works)
│   ├── Most popular commercial → ZSA Moonlander
│   ├── Wireless commercial → Dygma Defy or Glove80
│   └── RSI recovery grade → Kinesis Advantage360
│
└── STAY WITH CORNE, UPGRADE THE BUILD
    ├── Better switches → hot-swap means just swap them
    ├── Better keycaps → any MX keycaps work
    ├── Better case → aluminum or acrylic aftermarket cases
    └── Better RGB → already SK6812 — try per-key glow with RGB switches
```

### Quick-Reference Recommendation Table

| If you want... | Recommended | Price range | Difficulty |
|---|---|---|---|
| Numbers row | Sofle v2 | $60–120 DIY | Moderate |
| Encoders | Sofle v2 | $60–120 DIY | Moderate |
| 34-key minimalism | Ferris Sweep | $30–60 DIY | Easy |
| Trackball | Kyria + Ploopy | $80–150 DIY | Moderate-Hard |
| 3D contoured | Dactyl Manuform | $100–200 DIY | Hard |
| Commercial + portable | ZSA Voyager | $365 | None (buy) |
| Commercial + contoured | Glove80 | $399 | None (buy) |
| Corne + E-ink | Corne-ish Zen | $80–150 kit | Easy (kit) |
| Ultra-thin | Corne LP + Choc | $50–100 DIY | Moderate |
| RSI-grade comfort | Kinesis Advantage360 | $449 | None (buy) |

---

## 9. Where to Get PCBs and Kits

### 9.1 Official Source: foostan's GitHub

Everything you need to build a Corne is free at:  
**https://github.com/foostan/crkbd**

- `corne-classic/` — older versions (v1, v2) for historical reference
- `corne-cherry/` — current MX build files (v3)
- `corne-light/` — the Choc-specific build
- Each folder contains Gerber files (PCB manufacturing files), BOM (bill of materials), and build guides

### 9.2 Ordering PCBs from JLCPCB

JLCPCB (jlcpcb.com) is the most popular PCB manufacturer for hobbyists. Process:

1. Download the Gerber ZIP from foostan's GitHub
2. Upload to jlcpcb.com
3. Choose options:
   - **Quantity:** 5 is the minimum (order 2 quantities minimum — you need 2 PCBs for one keyboard, but 5 per order, so 10 PCBs = 2.5 potential keyboards)
   - **Color:** Black is traditional. Also available in green, blue, red, white, yellow
   - **Thickness:** 1.6mm (standard)
   - **Surface finish:** HASL (lead-free) is cheapest; ENIG (gold) is more expensive but better for SMD soldering
4. **Cost:** ~$5–8 for 5 PCBs + $8–15 shipping = ~$15–25 total for a set of PCBs

**Lead time:** 2–5 business days manufacturing + shipping (DHL express available).

### 9.3 Pre-Built Kits and Parts Vendors

| Vendor | Location | What they sell |
|---|---|---|
| **Keyhive** (keyhive.xyz) | USA | Corne kits, parts, nice!nano |
| **Boardsource** (boardsource.xyz) | USA | Corne kits, many other boards |
| **42keebs** (42keebs.eu) | EU | European shipping, Corne-focused |
| **Little Keyboards** (littlekeyboards.com) | USA | Corne kits, Choc builds |
| **splitkb.com** | Netherlands | Kyria, components, Corne parts |
| **lowprokb.ca** | Canada | Corne-ish Zen, Choc keycaps |
| **Typeractive** (typeractive.xyz) | USA | nice!nano, parts, ZMK-focused |

### 9.4 What a Kit Typically Includes

When buying a "Corne kit" from a vendor:
- ✅ Both PCBs (left + right)
- ✅ Diodes (1N4148W, SMD)
- ✅ TRRS jacks
- ✅ Reset buttons
- ✅ OLED displays + headers
- ✅ SK6812MINI-E LEDs (for v3)
- ✅ Hot-swap sockets (MX or Choc)
- ❌ Controllers (nice!nano, Elite-C — order separately)
- ❌ Switches (you choose)
- ❌ Keycaps (you choose)
- ❌ Case (order separately or 3D print)
- ❌ Battery (for wireless builds — order separately)

**Typical total cost for a complete wireless Corne v3 build:**

| Component | Cost |
|---|---|
| PCB kit | $25–50 |
| 2× nice!nano v2 | $50 ($25 each) |
| Switches (42× budget) | $20–40 |
| Keycaps | $20–80 |
| Case | $0 (3D print) – $80 (acrylic or aluminum) |
| 2× LiPo batteries | $10–20 |
| TRRS cable | $5 |
| **Total** | **~$130–285** |

Compare to a Glove80 at $399 — you pay more for DIY knowledge, get more customization freedom.

---

## Quick Reference: Version Numbers and Identifiers

If you're reading about a Corne build and trying to identify the version, look for these tells:

| Clue | Likely version |
|---|---|
| No LEDs at all | Helidox or very early v1 |
| RGB underglow only (strip under PCB) | v1 or v2 |
| Per-key RGB + OLED above controller | v3 |
| E-ink display, no RGB | Corne-ish Zen |
| Choc switches, super thin | Corne LP or Corne-ish Zen Choc |
| 36 keys (3 per thumb cluster, no outer pinky col) | Corne Mini |
| Pronounced as "Korn" by Japanese builders | Any version — this is correct Japanese pronunciation |
| Pronounced "Corn" or "Corné" | Also valid — community is split |

---

## Further Reading

- **foostan's GitHub:** https://github.com/foostan/crkbd
- **crkbd Build Guide (official):** https://github.com/foostan/crkbd/blob/main/corne-cherry/doc/v3/buildguide_en.md
- **r/ErgoMechKeyboards:** reddit.com/r/ErgoMechKeyboards — the community hub
- **r/olkb:** reddit.com/r/olkb — QMK/ZMK-focused
- **ZMK Documentation:** zmk.dev — firmware you're running
- **KeyboardMap/Via:** keyboard.io/via — visual keymap editors
- **Keycaplendar** (keycaplendar.firebaseapp.com) — track Group Buys and find keycaps
- **Corne-ish Zen store:** lowprokb.ca
- **splitkb.com:** kyria, parts, and European shipping

---

*Document covers: Helidox · Corne v1 · v2 · v3 · Corne LP · Corne Mini · Corne-ish Zen · claw44 · Lily58 · Sofle v2 · Kyria · Ferris Sweep · Dactyl Manuform · ZSA Moonlander · Kinesis Advantage360 · Dygma Defy · Totem · Glove80*
