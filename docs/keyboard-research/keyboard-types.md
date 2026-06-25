# Keyboard Types: The Complete Guide

> **Context:** You built a Corne — a 42-key, columnar-staggered, wireless split mechanical keyboard running ZMK. That places you at the absolute frontier of keyboard design. Everything in this guide connects back to understanding what choices you made and what else exists. Welcome to the rabbit hole.

---

## Table of Contents

1. [What Makes a Keyboard "Mechanical"?](#1-what-makes-a-keyboard-mechanical)
2. [Switch Technology Types](#2-switch-technology-types)
3. [Form Factors by Size](#3-form-factors-by-size)
4. [Layout Geometry](#4-layout-geometry)
5. [Split vs Unified](#5-split-vs-unified)
6. [Connection Types](#6-connection-types)
7. [Build / Mount Construction](#7-build--mount-construction)
8. [Case Materials](#8-case-materials)
9. [Plate Materials](#9-plate-materials)
10. [PCB Types](#10-pcb-types)
11. [Sound Profile and Acoustics](#11-sound-profile-and-acoustics)
12. [Gaming vs Enthusiast vs Custom](#12-gaming-vs-enthusiast-vs-custom)
13. [Wireless and Battery Considerations](#13-wireless-and-battery-considerations)
14. [Ergonomic Considerations](#14-ergonomic-considerations)
15. [Budget Tiers with Recommendations](#15-budget-tiers-with-recommendations)
16. [What to Buy Next If You Love Your Corne](#16-what-to-buy-next-if-you-love-your-corne)

---

## 1. What Makes a Keyboard "Mechanical"?

The term "mechanical keyboard" is used loosely in marketing, but it has a precise engineering meaning.

A **mechanical keyboard** is one where each key has its own **discrete electromechanical switch** — a self-contained assembly with a spring, a stem (the part you push), a housing, and electrical contacts. When you press a key, the stem travels down, the spring compresses, and the contacts close (or in optical/Hall Effect variants, a sensor triggers). Each key has its own tactile and acoustic behavior, and each switch is independently replaceable.

This is contrasted with:

- **Membrane keyboards**: a rubber dome sheet sits between the keycaps and a membrane circuit. You deform the dome, it bottoms out on the membrane, a circuit completes. All domes share one large membrane sheet — you can't replace one key independently. Mushy, imprecise, cheap to manufacture.
- **Scissor-switch keyboards**: like membrane but with a plastic scissor mechanism that stabilizes the key travel. Found in most laptop keyboards. Still membrane at heart but better than raw rubber dome.

The practical consequences of discrete switches:
- Each key has **consistent actuation force** and **actuation point** across its entire lifespan (50–100 million keystrokes on quality switches).
- You can **tune** your board: swap out switches without buying a new keyboard.
- Sound and feel characteristics are **controllable** and **customizable**.
- Tactile or clicky feedback is **crisp** and **repeatable** — not the vague mushiness of a rubber dome.

### The Market Today

The keyboard market spans an extraordinary range:

| Tier | Price Range | Example | What you get |
|------|------------|---------|--------------|
| Budget membrane | $5–$25 | Logitech K120 | Functional, disposable, mushy |
| Budget "mechanical" | $25–$50 | Redragon K552, RK61 | Real switches (usually Outemu), but cheap case/PCB |
| Mid-range enthusiast | $50–$150 | Keychron K/V series, Akko | Quality switches, hotswap, good build |
| Premium enthusiast | $150–$350 | Keychron Q, GMMK Pro, Glorious | Gasket mount, premium materials, fully assembled |
| Custom / Group Buy | $200–$600+ | CannonKeys, Salvation, Rainy75 | Hand-tuned, limited run, high precision machining |
| Ultra-premium | $500–$1,000+ | THINK6.5, Satisfaction75 | Collector-grade, machined aluminum, brass weights |
| DIY ergo | $50–$200 | Corne, Sofle, Lily58 (kit) | Soldering required, maximum customization |
| Assembled ergo | $300–$450 | ZSA Moonlander, Dygma Defy | Pre-built split ergonomic, high quality |

The enthusiast hobby has exploded since ~2018. Group buys (where a designer takes pre-orders for a custom board, manufactures once, ships 6–18 months later) have become a distinct segment. At the top end, keyboards appreciate like limited-edition sneakers.

---

## 2. Switch Technology Types

> For deep coverage of individual switch models, see `switches-research.md`. This section covers the fundamental technology categories.

### 2.1 Mechanical Switches (Spring + Stem + Housing)

The dominant switch type. A plastic stem rides inside a housing; a coil spring provides return force. Two metal contacts close when the stem reaches the actuation point.

**Subtypes by feel:**
- **Linear**: smooth consistent travel, no tactile bump. Quiet or clickable variants. Examples: Cherry MX Red, Gateron Yellow, Akko CS Matcha Green.
- **Tactile**: a physical bump mid-travel signals actuation without a click sound. Examples: Cherry MX Brown (weak bump), Holy Pandas, Boba U4 (silent tactile), Topre (different mechanism).
- **Clicky**: a tactile bump accompanied by an audible click from a physical click mechanism (click jacket or click bar). Examples: Cherry MX Blue, Kailh Box White, Kailh Box Jade.

**Key manufacturers:** Cherry (Germany, the original), Gateron (China, smoother than Cherry), Kailh (China, innovative designs), Durock, Akko, Tecsee, JWK/Durock, NovelKeys, TTC.

**Lifespan:** 50M–100M keystrokes per switch for quality options.

### 2.2 Membrane / Rubber Dome

A continuous sheet of rubber domes sits beneath the keycaps. Each dome, when depressed, pushes through a hole in a polyester membrane, completing a circuit on the bottom membrane layer.

**Characteristics:**
- **Actuation force**: inconsistent across the travel — light at the top, suddenly very stiff at bottom-out.
- **Feel**: mushy, imprecise, no distinct actuation point.
- **Sound**: dull thud.
- **Cost to manufacture**: extremely cheap. A full membrane sheet costs pennies.
- **Lifespan**: ~5M keystrokes (domes fatigue and stop bouncing back).

Membrane keyboards dominate office environments purely due to cost. They are functionally adequate for casual typing but offer no customization.

### 2.3 Topre (Electrocapacitive Rubber Dome)

Topre is a Japanese design made by Topre Corporation, used in the Realforce and Happy Hacking Keyboard (HHKB) lines. It's simultaneously a rubber dome **and** a capacitive sensor — the dome compresses a coiled spring beneath it, and as the spring compresses, the capacitance of the circuit changes. No physical contacts close; actuation is triggered when capacitance crosses a threshold.

**Characteristics:**
- **Feel**: a smooth, deep, satisfying "thock." Often described as a "creamy" linear feel with a subtle soft tactile bump. Nothing else feels like Topre.
- **Sound**: deep and premium. The HHKB is famous for its sound profile.
- **Price**: Realforce and HHKB start at $200–$300. Topre is not cheap.
- **Customization**: limited compared to MX-ecosystem. Third-party keycap options exist but are restricted. Topre stems can be sleeved for a softer bottom-out.
- **Stem converter**: you can install MX-adapter sliders to use MX keycaps on a Topre board.

Topre has a cult following. Many heavy typists consider it the endgame. It is not a "mechanical switch" in the strict sense, but the keyboard community broadly accepts it as a premium typing experience.

**Who should buy Topre:** Typists who prioritize feel and sound over customization, and who type for hours daily. The HHKB Pro Hybrid Type-S is a worthy "endgame" board.

### 2.4 Hall Effect / Magnetic Switches

Instead of physical contacts, a Hall Effect switch uses a **permanent magnet embedded in the stem** and a **Hall Effect sensor** on the PCB beneath it. The sensor measures magnetic field strength continuously, providing an **analog position** for the key at every moment of its travel.

This unlocks a feature called **Rapid Trigger**: the actuation point and reset point can be set to as little as 0.1mm. Normal mechanical switches need to travel back ~2mm before they re-register — a limitation that causes "dead zones" in fast gaming. With Rapid Trigger, every micro-movement registers, eliminating that dead zone entirely.

**Key products:**
- **Wooting 60HE / 80HE**: the switches that defined the Rapid Trigger category. Analog Hall Effect with software control down to 0.1mm sensitivity.
- **SteelSeries Apex Pro**: adjustable actuation from 0.2mm–3.8mm, but not true analog sensing — it uses magnetic reed switches with software-set actuation points rather than continuous position tracking.
- **Gateron Magnetic Jade / KS-20**: newer Hall Effect switches appearing in third-party builds.

**Characteristics:**
- **No contact wear**: magnets never touch anything. Theoretically infinite lifespan.
- **Analog input**: possible in games that support it (limited game support today).
- **Rapid Trigger**: the main reason competitive FPS players buy these. Counter-Strike, Valorant players use it to gain microsecond advantages.
- **No hotswap ecosystem**: most Hall Effect boards are proprietary PCBs.

**Who should buy Hall Effect:** Competitive FPS/rhythm game players. The Wooting 80HE is the clear recommendation.

### 2.5 Optical Switches

An optical switch replaces metal contacts with an infrared light beam and sensor. When the stem descends, it interrupts (or passes through, depending on design) the IR beam, triggering actuation.

**Characteristics:**
- **No contact bounce**: mechanical contacts have a brief electrical bounce when they close; debounce firmware logic compensates. Optical switches have no bounce, so actuation can be registered faster (0.2ms vs ~5ms).
- **Lifespan**: no contacts to wear out. 100M+ keystrokes.
- **Feel**: determined by the switch mechanism (linear/tactile/clicky), same as mechanical. The optical sensing is invisible to the typist.
- **Ecosystem**: Razer's optical (Razer Optical) and Gateron's optical (Gateron Optical) are the main players. Not cross-compatible with MX-footprint boards.

**Products:** Razer Huntsman V3 Pro (optical linear/analog), various Gateron optical boards.

**Who should buy Optical:** Gamers who want the lowest latency with familiar switch feel, without the price of Hall Effect. Less compelling for typists.

### 2.6 Which to Buy and Why

| Type | Buy if... | Avoid if... |
|------|-----------|-------------|
| **Mechanical** | You want maximum customization, a wide ecosystem, and community support | You need analog input for gaming |
| **Membrane** | You need a spare cheap keyboard and don't care about feel | You type more than 2 hours a day |
| **Topre** | You want an endgame typing feel and care more about feel than customization | You're on a budget or love swapping switches |
| **Hall Effect** | You play competitive FPS and want Rapid Trigger | You primarily type, not game |
| **Optical** | You want low-latency gaming with a familiar feel at lower cost than HE | You want to swap keycaps from the MX ecosystem freely |

---

## 3. Form Factors by Size

Form factor is arguably the most important purchasing decision you make. It determines what fits on your desk, what workflow you can achieve, and how often you reach for a mouse.

### 3.1 Full Size / 100% (~104 keys on ANSI)

```
┌────────────────────────────────────────────────────────────────────────┐
│ Esc  F1 F2 F3 F4  F5 F6 F7 F8  F9 F10 F11 F12  │PrtSc ScrLk Pause│
│                                                   └─────────────────┘  │
│ `  1  2  3  4  5  6  7  8  9  0  -  =  Backspace │ Ins  Home PgUp │   │
│ Tab Q  W  E  R  T  Y  U  I  O  P  [  ]  \        │ Del  End  PgDn │   │
│ Caps A  S  D  F  G  H  J  K  L  ;  '  Enter      └──────────────── │   │
│ Shift  Z  X  C  V  B  N  M  ,  .  /  Shift       │      Up         │ 7 8 9│
│ Ctrl Win Alt      Space       Alt Win Menu Ctrl   │Left Down Right  │ 4 5 6│
│                                                   │                 │ 1 2 3│
│                                                   │                 │ 0   .│
└────────────────────────────────────────────────────────────────────────┘
```

**Key count:** ~104 (ANSI), ~105 (ISO)
**Dimensions:** ~440mm × 135mm

**Includes:** Alphas + number row + function row + dedicated arrow cluster + navigation cluster (Insert/Delete/Home/End/PgUp/PgDn) + numpad

**Pros:**
- Every key is labeled and accessible without layers.
- Perfect for accounting, data entry, and spreadsheet work (numpad essential).
- Familiar to anyone who learned to type on a PC.
- Huge selection of keycap sets designed for it.
- Lowest learning curve of any form factor.

**Cons:**
- Wide footprint pushes the mouse far to the right, causing shoulder abduction and repetitive strain over time.
- Numpad is used rarely by most people yet takes significant desk space.
- Physically heavy (often 800g–1.2kg for premium boards).
- Fewer premium custom options (group buys rarely do full-size due to manufacturing cost).

**Best for:** Data entry professionals, Excel power users, people who cannot tolerate any learning curve, office workers upgrading from the standard keyboard they were given.

**Representative boards:** Leopold FC900R, Ducky One 3 (Full), Varmilo VA108M

---

### 3.2 1800 / 96% (~96 keys)

```
┌──────────────────────────────────────────────────────────────────┐
│ Esc F1..F12  │PrtSc ScrLk Pause│                                 │
│ `  1..=  Bksp│ Ins  Home PgUp  │ NumLk / * -                     │
│ Tab Q..  \   │ Del  End  PgDn  │  7    8  9  +                   │
│ Caps A..  Ent│   Left↑Right    │  4    5  6  +                   │
│ Shft Z.. Shft│       ↓         │  1    2  3  Ent                 │
│ Ctrl Alt  Sp  Alt  Ctrl        │  0       .  Ent                 │
└──────────────────────────────────────────────────────────────────┘
```

**Key count:** ~96–98
**Dimensions:** ~390mm × 135mm (10–15% shorter than full-size)

This layout compresses the navigation cluster and numpad into a more compact arrangement by eliminating the gaps between clusters. Functionally identical to full-size but physically smaller.

**Pros:**
- Keeps numpad (critical for data entry).
- Significantly narrower than full-size.
- Mouse closer to the keyboard centerline.
- Still has all keys labeled.

**Cons:**
- Condensed layout feels cramped. The nav cluster and numpad are tight.
- Still a large keyboard by enthusiast standards.
- Fewer keycap set options (the condensed nav cluster can be hard to fill with aftermarket keycap sets).

**Best for:** Excel/data entry users who work at a small desk and want numpad without full-size sprawl.

**Representative boards:** Leopold FC980M (excellent), Keychron Q6, GMMK 96%

---

### 3.3 TKL / 80% (~87 keys)

```
┌────────────────────────────────────────────────────────┐
│ Esc  F1 F2 F3 F4  F5 F6 F7 F8  F9 F10 F11 F12 │PrtSc ScrLk Pause│
│ `  1  2  3  4  5  6  7  8  9  0  -  =  Backspace│ Ins  Home PgUp │
│ Tab Q  W  E  R  T  Y  U  I  O  P  [  ]  \       │ Del  End  PgDn │
│ Caps A  S  D  F  G  H  J  K  L  ;  '  Enter     └────────────────┘
│ Shift  Z  X  C  V  B  N  M  ,  .  /  Shift       │ Up              │
│ Ctrl Win Alt      Space       Alt Win Menu Ctrl   │Left Down Right  │
└────────────────────────────────────────────────────────────────────┘
```

**Key count:** ~87 (ANSI), ~88 (ISO)
**Dimensions:** ~360mm × 135mm

TKL = TenKeyLess. Removes the numpad. Everything else stays.

**Pros:**
- Mouse is ~80mm closer to the centerline. Immediately noticeable ergonomic benefit.
- Retains dedicated function row, navigation cluster, and arrow keys — minimal relearning.
- Widest selection of premium custom options: the dominant enthusiast size for group buys.
- Good balance of functionality vs footprint.
- Mature ecosystem: enormous variety of cases, PCBs, plates, keycap sets.

**Cons:**
- Still fairly wide (navigation cluster adds ~60mm right of the arrows).
- No numpad (obvious).
- Not dramatically smaller than full-size in the vertical dimension.

**Best for:** The first step from full-size into the enthusiast hobby. The safest recommendation for someone upgrading from a full-size who doesn't use the numpad. Excellent for gaming (mouse placement) and general work.

**Representative boards:** Keychron Q3 (gasket mount TKL, incredible value), Leopold FC750R, Ducky One 3 TKL, RAMA M65-B, Varmilo VA87M, Filco Majestouch 2

---

### 3.4 75% (~84 keys)

```
┌────────────────────────────────────────────────────────────┐
│ Esc F1 F2 F3 F4 F5 F6 F7 F8 F9 F10 F11 F12 │Del PrtSc │
│ `  1  2  3  4  5  6  7  8  9  0  -  =  Bksp│Ins Home  │
│ Tab Q  W  E  R  T  Y  U  I  O  P  [  ]  \  │Del PgUp  │
│ Caps A  S  D  F  G  H  J  K  L  ;  '  Ent  │    PgDn  │
│ Shift  Z  X  C  V  B  N  M  ,  .  /   Shft │ Up  End  │
│ Ctrl Alt         Space          Alt Fn  │Lt  Dn  Rt  │
└────────────────────────────────────────────────────────────┘
```

**Key count:** ~84
**Dimensions:** ~315mm × 110mm

The 75% retains the function row but compresses it directly against the number row (no gap). The navigation cluster is reduced to a single column of keys on the right side. Arrow keys are retained but may be smaller (often half-height).

**Pros:**
- **Best balance** of size and functionality for most users. Function keys and arrows present, everything else is a layer away.
- Significantly smaller footprint than TKL — closer to 65% width.
- Strong enthusiast ecosystem. Many excellent custom options.
- Growing popularity: manufacturers are releasing more 75% options.

**Cons:**
- Function row feels crowded (no gap between F-row and number row).
- Navigation cluster is limited (often just PgUp, PgDn, Del; sometimes Insert, End, Home).
- Arrow keys can feel crowded (may share space with Shift or /).

**Best for:** People who frequently use function keys (developers using IDE shortcuts, gamers using F-keys) and still want a compact board. A great "one board for everything" size.

**Representative boards:** Keychron Q1 Pro (75%, popular recommendation), Keychron V1, Akko 5075B, Glorious GMMK 2, GMMK Pro (75%), Nuphy Air75, Varmilo VA82M

---

### 3.5 65% (~68 keys)

```
┌─────────────────────────────────────────────────────────┐
│ `  1  2  3  4  5  6  7  8  9  0  -  =  Backspace│Del│
│ Tab Q  W  E  R  T  Y  U  I  O  P  [  ]  \       │PgUp│
│ Caps A  S  D  F  G  H  J  K  L  ;  '   Enter    │PgDn│
│ Shift  Z  X  C  V  B  N  M  ,  .  /  Shift│ Up  │End │
│ Ctrl Win Alt         Space     Alt  Fn  │Lt  Dn  Rt│
└─────────────────────────────────────────────────────────┘
```

**Key count:** ~65–68
**Dimensions:** ~315mm × 110mm (similar to 75% but shorter vertically without function row)

The 65% removes the function row entirely. Arrow keys are retained in a standard cluster. A small navigation column (Del, PgUp, PgDn, End) is often present on the right.

**Pros:**
- Arrow keys make this accessible without layer learning.
- More compact than 75% in height.
- Extremely popular in the enthusiast market — huge variety of options.
- Function keys accessible via Fn layer (many find this fine after adjustment).

**Cons:**
- No dedicated function row. IDE debugging shortcuts (F5, F8, F9), gaming F-keys all require a layer.
- Minor learning period for function key layer.

**Best for:** Anyone who rarely uses function keys directly and wants a compact board with arrow keys. Excellent gaming board (smaller footprint, arrows present, mouse nearby). The sweet spot for many enthusiasts.

**Representative boards:** Keychron K6 Pro, Tofu65, KBD67 Lite R4, Satisfaction75 (yes, despite the name it's 75% layout in a 65% footprint), Keychron V4, Drop ALT, Glorious GMMK Compact

---

### 3.6 60% (~61 keys)

```
┌──────────────────────────────────────────────────────┐
│ `  1  2  3  4  5  6  7  8  9  0  -  =  Backspace    │
│ Tab Q  W  E  R  T  Y  U  I  O  P  [  ]  \           │
│ Caps A  S  D  F  G  H  J  K  L  ;  '   Enter        │
│ Shift  Z  X  C  V  B  N  M  ,  .  /  Shift (no arrows)│
│ Ctrl Win Alt              Space    Alt  Win  Fn  Ctrl │
└──────────────────────────────────────────────────────┘
```

**Key count:** ~61
**Dimensions:** ~290mm × 100mm

The 60% removes function row, navigation cluster, and arrow keys. Everything is accessed via layers. This is the **classic enduring form factor** — the Poker, the Anne Pro, the GH60 defined this category.

**Pros:**
- Smallest "full alpha" keyboard. Every letter and symbol is on the main layer.
- Maximizes desk space. Gaming: mouse has enormous range.
- Deep enthusiast pedigree. Enormous variety of custom cases (aluminum, polycarbonate, brass).
- Timeless aesthetic — rectangular, uniform, minimal.
- Strong secondary market. 60% cases and PCBs hold value.

**Cons:**
- **No arrow keys** is the biggest barrier. Many people find this intolerable long-term.
- No function keys without a layer (same as 65%).
- Navigation keys (Home, End, PgUp, PgDn) require layers.
- Learning investment is real.

**Best for:** Enthusiasts who have already adjusted to layers (Corne users are natural 60% appreciators), minimalists, desk-space-constrained setups, collectors (60% cases are the richest ecosystem). A beautiful desk object.

**Representative boards:** Poker III, GH60 (DIY, historic), Tofu60, Keychron C1 (budget), Drop CTRL (TKL actually, ignore), KBD67 Lite, Discipline65, Anne Pro 2, Ducky One 2 Mini, Vortex Pok3r, Happy Hacking Keyboard (HHKB — the iconic 60%er with Topre switches)

---

### 3.7 65% with Numpad (Niche)

Some designers create hybrid layouts that keep the numpad while removing the function row, resulting in a wide but relatively compact board. Also called "compact 1800" variants.

These are unusual enough that off-the-shelf options are rare. Custom PCBs and specific group buys have explored this space. The Keychron Q6 (96%) is the closest mainstream equivalent.

---

### 3.8 40% (~40–42 keys)

```
  Your Corne lives here.

┌──────────────────────────────────────────────────────┐
│ Q   W   E   R   T   |   Y   U   I   O   P           │
│ A   S   D   F   G   |   H   J   K   L   ;           │
│ Z   X   C   V   B   |   N   M   ,   .   /           │
│         Esc Spc Tab | Ret Bsp Del                    │
└──────────────────────────────────────────────────────┘
  (Corne layout — 42 keys, columnar stagger, split)
```

**Key count:** 36–48 depending on specific variant
**Examples:** Corne (42), Planck (47, ortho), Preonic (60, ortho but 5 rows), Kyria (50), Ferris (34)

The 40% removes the number row. Numbers, symbols, function keys, and navigation all live on layers. For the Corne specifically, you have:
- 3 rows × 6 columns per half = 36 alpha/symbol keys
- 3 thumb keys per half = 6 more
- Total: 42 keys

**How it works:** You live on layers. Your Miryoku-style setup with 7 layers is the canonical approach to making a 40% actually productive. Home row mods (GACS) replace modifier keys. Thumb clusters are the primary layer access mechanism. It sounds insane; it works.

**Pros:**
- Absolute minimum hand movement. Fingers barely leave the home position.
- Ergonomic summit — combined with columnar stagger and split, finger fatigue is minimal.
- Tiny footprint. The keyboard disappears on the desk.
- Forces deliberate, optimized keymap design.
- Powerful: once learned, you never lack a key — it's one or two thumb-taps away.

**Cons:**
- Steep learning curve: typically 2–6 weeks to reach previous typing speed.
- Layer management overhead in your mental model (until it becomes muscle memory).
- No keycap legends help you (legends lie on a 40% — the key's printed letter isn't its layer action).
- Poor gaming compatibility without specific layer adjustments.
- Social friction: people who use your computer will be baffled.

**Best for:** You. People who type all day and care about ergonomics, efficiency, and deliberate design. The Corne is not a beginner board — it's a board you grow into and stay on.

**Other 40% variants:**
- **Planck** (Jack Humbert / Keyboard.io): 4×12 ortholinear grid, 47 or 48 keys, iconic entry point into 40% / ortho.
- **Preonic**: Planck + a number row = 60-key ortho.
- **Ferris/Sweep**: 34-key columnar split. Even more minimal than Corne.
- **Dao Choc**: 36 keys, low-profile Choc switches.
- **Kyria**: 50 keys, columnar stagger, per-key RGB, aggressive columnar offset.

---

### 3.9 Macropad / Specialty

**Macropad:** A small standalone keypad with 4–24 keys, typically programmable via QMK/KMK/ZMK. Used for:
- Streaming macros (Elgato Stream Deck equivalent but physical switches)
- Photoshop/Lightroom shortcut clusters
- Gaming auxiliary buttons
- Number entry when main board is compact
- DJ/music production triggers

**Numpad only:** A standalone 17–21 key numpad. Useful with compact boards when you occasionally need a numpad. Many enthusiast standalone numpads are available.

**Ortho macropads:** 4×4 or 5×5 ortholinear pads. Good for practicing ortholinear typing before committing to a full ortho board.

---

### Master Comparison Table

| Size | Keys | Numpad | F-Row | Arrows | Nav Cluster | Best For |
|------|------|--------|-------|--------|-------------|----------|
| 100% / Full | ~104 | ✅ | ✅ | ✅ | ✅ Full | Data entry, Excel, no layer learning |
| 1800 / 96% | ~96 | ✅ Compact | ✅ | ✅ | ✅ Compact | Small desk data entry |
| TKL / 80% | ~87 | ❌ | ✅ | ✅ | ✅ Full | First enthusiast upgrade, gaming |
| 75% | ~84 | ❌ | ✅ Tight | ✅ Tight | ✅ Minimal | Balance of function + compact |
| 65% | ~68 | ❌ | ❌ | ✅ | ✅ Mini | Compact gaming + work, popular |
| 60% | ~61 | ❌ | ❌ | ❌ | ❌ | Minimalist enthusiast, max desk space |
| 40% | ~40 | ❌ | ❌ | ❌ (layer) | ❌ (layer) | Heavy layer users, ergo enthusiasts |
| Macropad | 4–24 | — | — | — | — | Macro/media/specialty input |

---

## 4. Layout Geometry

Form factor (number of keys) and geometry (physical key arrangement) are orthogonal axes. The same key count can be arranged in very different ways.

### 4.1 Row-Staggered (Traditional)

```
Row 0 (number):  | ` | 1 | 2 | 3 | 4 | ...
Row 1 (QWERTY):    | Q | W | E | R | T | ...
Row 2 (home):        | A | S | D | F | G | ...
Row 3 (bottom):        | Z | X | C | V | B | ...
```

Each row is offset approximately 0.25u (quarter of a key unit, ~4.75mm) to the right relative to the row below it. This is the universal standard that everyone learns on.

**Why does row stagger exist?** It's a direct legacy of mechanical typewriters (1870s–1960s). The type bars for each letter were arranged radially around the platen. Adjacent keys needed their linkages to avoid mechanical interference, which caused the physical offset. This stagger has **nothing to do with human hand anatomy**. The rows aren't staggered to match your finger lengths — your fingers aren't 0.25u shorter as you go left. It's a historical accident that became the universal standard.

**Consequence:** On a row-staggered keyboard, reaching diagonally (e.g., right hand hitting B, or left hand hitting Y) feels more natural than it should because the stagger roughly compensates for the leftward angle you'd need otherwise. But vertical alignment is mismatched — your left pinky (A, Q, ~) travels differently than your right pinky (;, P, ]) because the keys aren't in a column.

**Most keyboards in existence are row-staggered.** If you're buying anything from a retail store or mainstream enthusiast brand, it's row-staggered.

---

### 4.2 Ortholinear

```
Row 0:  | Q | W | E | R | T | Y | U | I | O | P |
Row 1:  | A | S | D | F | G | H | J | K | L | ; |
Row 2:  | Z | X | C | V | B | N | M | , | . | / |
Row 3:  |   |   |Bsp|Spc|Ent|   |   |   |   |   |
```

Ortholinear keyboards place all keys in a **perfect orthogonal grid**. No row offset. Each column is a straight vertical line.

**Effect on typing:** Each finger is now responsible for exactly one column of keys. All keys in a column are directly above/below each other. This is geometrically cleaner than staggered, but note that it doesn't actually match finger anatomy either — fingers aren't perfectly aligned in a flat plane perpendicular to the hand axis.

**Learning curve:** Expect 1–3 weeks of relearning. The diagonal finger movements you learned for row-stagger need recalibration. Your B and Y keys are particularly affected.

**The pitch to ortho:** Proponents argue that ortho forces you to type "correctly" — clean column-based movements that reduce lateral finger extension. It's debatable whether ortho is more ergonomic than staggered, but many ortho users feel they type with less strain after adjustment.

**Notable ortho boards:**
- **Planck** (Jack Humbert, OLKB, now Keyboard.io): 4×12, 47–48 keys. The iconic intro to ortho/40%.
- **Preonic**: 5×12. Planck + a number row.
- **BM40**: budget ortho kit.
- **Kyria** (optional ortho variant), **Minivan**, various custom designs.

---

### 4.3 Columnar Stagger — Your Corne's Geometry

```
    Q  W  E  R  T        Y  U  I  O  P
   A  S  D  F  G        H  J  K  L  ;
    Z  X  C  V  B        N  M  ,  .  /
          Esc Spc Tab  Ret Bsp Del
```

*(Columns are staggered vertically; each column is offset up/down relative to neighbors to match finger lengths)*

Columnar stagger is the ergonomic evolution of ortholinear. Instead of rows being offset (staggered), **columns are offset vertically**. The offset matches the natural resting length of each finger:

| Finger | Relative column offset |
|--------|----------------------|
| Pinky | Lowest (shortest finger) |
| Ring | Slightly higher |
| Middle | Highest (longest finger) |
| Index | Slightly lower than middle |
| Thumb | Horizontal thumb arc |

This means your fingers travel **straight up and down their respective columns** with almost no lateral displacement. On a row-staggered board, reaching for the top row with your index finger requires a slight diagonal. On a columnar board, it's a straight upward reach — the way your finger naturally extends.

**Your Corne's specific column offsets (standard Corne v2 layout):**
- Pinky column: lowest
- Ring finger: +5mm
- Middle finger: +9mm
- Index inner: +5mm
- Index outer (the 2nd index column): 0mm

The aggressive middle-column offset means the E-D-C column (middle finger) is noticeably higher than the W-S-X column (ring finger). This feels strange coming from row-stagger but matches hand anatomy perfectly once you adjust.

**Combined with split design:** The Corne's split form means each half can be angled inward (tent) and placed at shoulder width, further reducing ulnar deviation (the wrist bend you experience with a unified keyboard placed at the center of your body).

**Is columnar stagger better?** Yes, measurably: studies on RSI and keyboard geometry consistently show that finger travel distance is reduced and lateral strain is lower on columnar layouts. But there's a real adaptation cost. Most people who switch to columnar stagger report that returning to a row-staggered board feels "wrong" after a few months.

---

### 4.4 Alice / Arisu Layout

```
        ┌────────────────────────────────────────────────────────────┐
        │   ` 1 2 3 4 5  [split angle]  6 7 8 9 0 - =  Backspace    │
        │   Tab Q W E R T [angle]   Y U I O P [ ] \                  │
        │   Caps A S D F G [angle]  H J K L ; '  Enter               │
        │   Shift Z X C V B [angle] B N M , . /  Shift   Up          │
        │   Ctrl Win Alt   [Space]     [Space] Alt  Fn  Lt Dn Rt      │
        └────────────────────────────────────────────────────────────┘
```

The Alice layout (designed by Yuktsi, popularized by KBDfans' Alice kit) is a **unified keyboard** with a **split-angle** built in. The two halves are angled toward the user (roughly 5–10°) so the keyboard forms a slight V-shape, reducing ulnar deviation — without requiring two separate pieces.

**Arisu** is similar but typically adds arrow keys and slightly different column placement.

**Characteristics:**
- Row-staggered (traditional stagger, not columnar).
- One-piece board — no halves to lose or cable to manage.
- The angled keywells look striking. Alice is an aesthetic statement as much as an ergonomic one.
- No learning curve beyond normal 60% / 65% adjustment.
- Often paired with TKL or 60% key counts.

**Notable Alice boards:**
- **Alice** (KBDfans): the original. Often group buy.
- **Arisu**: community design, many derivatives.
- **TGR Alice**: high-end original design.
- **Keychron Q8**: Alice layout in Keychron's mainstream hotswap line. Excellent value for Alice format.
- **Mode Tempo**: premium Alice format custom.

**Who should buy Alice:** People who want ergonomic improvement over a standard unified board but aren't ready to commit to a split/columnar setup. The Keychron Q8 is an easy recommendation.

---

## 5. Split vs Unified

### 5.1 Unified Keyboards

A single piece of hardware. The two halves of the key matrix are on one PCB, in one case. This is the traditional form factor for all keyboards described above except split designs.

**Advantages:**
- Simple: one cable, one receiver, no pairing between halves.
- Works on any surface (nothing to slide apart).
- Portable: easier to carry one piece.
- Universally compatible with keycap sets.

**Disadvantages:**
- Fixed hand position: your hands must be where the keyboard is, which is usually at the center of your body. This causes **ulnar deviation** — the inward wrist bend required to place fingers on a keyboard that's narrower than shoulder width. Over years, this contributes to wrist and forearm strain.
- Shoulder position: on a unified keyboard, both hands point inward slightly; your shoulders unconsciously roll forward. Over an 8-hour workday, this matters.

---

### 5.2 Split Keyboards

Two separate halves, each with their own PCB. You place them at **shoulder width** — allowing your hands to rest in a natural position with **straight wrists** and **neutral shoulders**.

```
       Left half                    Right half
   ┌─────────────┐              ┌─────────────┐
   │  Q  W  E  R │              │  Y  U  I  O │
   │  A  S  D  F │              │  H  J  K  L │
   │  Z  X  C  V │              │  N  M  ,  . │
   │    Esc Sp  ──────TRRS──────── Ret Bsp    │
   └─────────────┘              └─────────────┘

        ← ~40cm shoulder-width gap →
```

**Posture benefits:**
- **No ulnar deviation**: wrists align naturally with forearms.
- **Neutral shoulder position**: arms extend forward rather than inward.
- **Optional tenting**: raise the inner edges so the hands are in a "handshake" position (thumbs up), further reducing pronation (forearm rotation that happens when typing flat).

**Split keyboard types:**

#### Wired Split (TRRS/TRS cable)
One half is the "main" (connected to the computer via USB), the other is the "secondary" (connected to main via a 3.5mm TRRS or TRS cable). A single USB connection to the host.

- **Pros**: Simple, reliable, no battery management, no pairing.
- **Cons**: The TRRS cable between halves needs to stay connected. The cable length limits how far apart the halves can be.
- **Examples**: Corne (when wired), Ergodox EZ, Lily58, Sofle.

#### Wireless Split (each half fully independent)
Each half has its own microcontroller and battery. No cable between halves. This is your Corne's mode with nice!nano v2 controllers.

How it works (ZMK):
- Left half is the "central" — it connects to the computer via Bluetooth.
- Right half is the "peripheral" — it connects to the left half via Bluetooth.
- The right half sends keypress events to the left half, which aggregates them and sends to the host.
- Battery life is managed independently per half.

**Pros:**
- Total freedom of placement — put the halves exactly where your arms want to be.
- Can use anywhere (battery-powered, BT-connected).
- Clean desk: no cables at all.

**Cons:**
- Battery management: two batteries to charge.
- Latency: peripheral-to-central Bluetooth add a small (imperceptible for typing, potentially relevant for gaming) hop.
- Reconnection: sometimes one half doesn't reconnect immediately after sleep.
- Firmware complexity: ZMK's split wireless support is excellent but it's a more complex system than a wired keyboard.

**Your Corne runs ZMK's split wireless architecture**: left half as central (BT to Mac), right half as peripheral (BT to left). The nice!nano v2 on each half has its own nRF52840 chip, antenna, and 500mAh LiPo.

---

## 6. Connection Types

### 6.1 Wired USB

The oldest and most reliable. USB-A or USB-C connection from keyboard to host.

**USB-A**: the rectangular connector, still common on budget and older premium boards.
**USB-C**: the new standard. Reversible, more durable with proper use, supports faster data transfer (not that keyboards need it).

**Characteristics:**
- Zero latency: hardwired connection, keypress events arrive within the USB polling interval.
- USB polling rate: standard keyboards poll at 1000Hz (1ms). Gaming keyboards often advertise this. Budget boards may poll at 125Hz (8ms). 1ms vs 8ms is imperceptible for typing but theoretically matters at extreme competitive gaming.
- No battery management.
- Reliable: no dropouts, no pairing issues.

**Best for**: Desktop workstation use. Gaming, where any wireless latency concern is eliminated. Typists who prefer simplicity.

### 6.2 2.4GHz Wireless (Dongle)

A USB dongle receiver creates a proprietary 2.4GHz wireless link with the keyboard. The dongle is always "paired" to that keyboard specifically.

**Characteristics:**
- **Near-zero latency**: 2.4GHz dongle connections from quality manufacturers (Logitech, Corsair, some enthusiast boards) achieve latency essentially identical to wired. Often <1ms over the air.
- **Reliability**: dedicated frequency, custom protocol — more reliable than Bluetooth in crowded RF environments (offices with 20 BT devices nearby).
- **Single-device**: the dongle is dedicated to one keyboard. No multi-device pairing.
- **Requires dongle**: you need a USB-A port for the dongle. If you lose the dongle, the keyboard is wired-only or useless depending on the board.

**Notable products**: Logitech G Pro X Wireless, some SteelSeries boards, Keychron's newer wireless boards include 2.4GHz dongles alongside BT.

**Best for**: Wireless gaming, office single-computer use, when you don't need multi-device switching.

### 6.3 Bluetooth

Keyboard pairs directly with host computer via standard Bluetooth (BT 4.0, 4.2, 5.0).

**Characteristics:**
- **Multi-device pairing**: most BT keyboards support 3–5 device profiles. Tap a key to switch between Mac, iPad, phone. ZMK supports multiple BT profiles natively.
- **No dongle needed**: works with any BT-equipped device. Great for tablets, phones, and computers without spare USB ports.
- **Latency**: BT 5.0 achieves ~6–10ms round-trip latency. Imperceptible for typing. Potentially relevant for extreme gaming reaction times (usually not).
- **Range**: 10m typical. Connection stability in RF-noisy environments can be worse than 2.4GHz dongle.
- **Power**: BT keyboards need batteries or internal rechargeable cells.

**Your Corne**: Uses ZMK's BT stack on nRF52840 (BT 5.0). Supports up to 5 BT profiles. You can be paired to your Mac, iPad, and phone simultaneously and switch with BT profile keys on your MEDIA layer.

**Best for**: Multi-device users, tablet/phone users, clean desk setups.

### 6.4 Combined (Dongle + BT)

Some keyboards support both 2.4GHz dongle and Bluetooth simultaneously or switchably.

**Examples**: Logitech MX Keys (BT + Unifying receiver), Keychron K3 Pro (BT + USB wired), some newer Keychron models with 2.4GHz dongle option.

**Best for**: Power users who want dongle reliability at the desktop and BT flexibility on the go.

---

## 7. Build / Mount Construction

The mount system determines how the PCB and plate are attached to the case. This has enormous consequences for typing feel, sound, and flex.

### 7.1 Tray Mount

```
      ┌──────────────────┐
      │    Top Case      │
      ├──────────────────┤
      │ PCB  ━━━━━━━━━  │ ← PCB screws directly into bottom case standoffs
      │ Plate            │
      ├──────────────────┤
      │   Bottom Case    │   ← screws go through PCB into bottom
      └──────────────────┘
```

The PCB screws directly into standoffs molded into the bottom case (a "tray"). The case wraps around but the PCB's connection is to the bottom.

**Sound**: Hollow and reverberant. The direct bottom contact creates a large air chamber that resonates. Often sounds "clacky" or even "pingy."

**Feel**: Stiff. The PCB is rigid against the case with no flex.

**Cost**: Cheap to manufacture. Most budget keyboards under $50 are tray mount.

**Examples**: Keychron C1, most budget Redragon/Tecware boards, many compact gaming keyboards.

**Modification potential**: Tray mount boards can be improved significantly with case foam (to reduce resonance), switch films, and lubing switches.

---

### 7.2 Top Mount

```
      ┌──────────────────┐
      │ Top Case  ┌──────┤ ← Plate/PCB attaches to top case
      │           │ PCB  │
      │           │Plate │
      └───────────┴──────┘
         Bottom case is a
         separate piece below
```

The plate (and PCB attached to it) is screwed into the top piece of the case. The bottom is just a cover.

**Sound**: Can sound "poppy" or "clacky" due to the direct contact with the top case. Less hollow than tray mount.

**Feel**: Still relatively stiff, though the PCB is only connected at the top and hangs somewhat free at the bottom.

**Examples**: Some older custom designs, Filco boards (indirect variation), Leopold FC750R.

---

### 7.3 Bottom Mount

The inverse of top mount: the PCB/plate attaches to the bottom case half. The top is a cover.

Less common as a distinct design. Varies in feel depending on how tightly the PCB contacts the case material.

---

### 7.4 Gasket Mount

```
      ┌──────────────────────────────┐
      │     Top Case                 │
      │  ╔══════════════════╗        │
      │  ║  GASKET material ║  ←─── soft silicone/poron strips
      │  ║                  ║        │
      │  ║   PLATE+PCB      ║        │
      │  ║  (floating)      ║        │
      │  ╚══════════════════╝        │
      │  ╔══════════════════╗        │
      │  ║  GASKET material ║        │
      │  ║                  ║        │
      └──┴──────────────────┴────────┘
         Bottom Case
```

The plate/PCB assembly floats on **gasket material** (silicone strips, Poron foam, IXPE foam, or similar elastomers) that sit between the plate/PCB edges and the case. The plate is not rigidly fastened — it rests on these gaskets.

**Sound**: The gaskets absorb high-frequency vibrations. Result: a deep, thocky, "full" sound with reduced "pingy" metallic resonance. Generally considered the most pleasing sound profile.

**Feel**: **Bouncy and soft**. When you bottom out a key, the entire plate/PCB assembly deflects slightly downward against the gaskets, then springs back. This "flex" is part of the tactile experience. Some typists love it; others find it disorienting.

**Cost**: More complex to manufacture. Gasket mount boards typically start at $150.

**Examples**: Keychron Q series (excellent value gasket), GMMK Pro, Drop Sense75, KBD67 Lite R4 (budget semi-gasket), Tofu65, most premium custom group buys.

**Who should get gasket mount**: Anyone who wants the best sound and a bouncy, premium typing feel. The Keychron Q1 Pro is a gasket mount 75% that delivers genuine premium feel at $180.

---

### 7.5 Leaf Spring Mount

A more complex variant where the PCB/plate assembly rests on metal leaf springs. The springs allow the entire typing surface to deflect downward when you type, then snap back.

The flex is more dramatic than gasket mount. Some typists describe it as "springy" in a satisfying way; others find it too much.

**Examples**: TX-87, some custom one-off designs.

---

### Mount Comparison Table

| Mount | Flex | Sound | Typical Cost | Notes |
|-------|------|-------|-------------|-------|
| Tray mount | None | Hollow, reverberant | Budget ($25–$80) | Foam mods help significantly |
| Top mount | Low | Poppy/clacky | Mid ($60–$150) | Depends on case material |
| Bottom mount | Low | Variable | Mid | Less common |
| Gasket mount | Medium | Thocky, deep, pleasant | $150–$400+ | Current gold standard |
| Leaf spring | High | Springy, deep | $200–$500 | Polarizing, niche |

---

## 8. Case Materials

The case material determines weight, feel, acoustics, and aesthetics.

### 8.1 Plastic (ABS / Polycarbonate)

**ABS (Acrylonitrile Butadiene Styrene):**
- The most common budget case material.
- Lightweight (a full ABS TKL case weighs ~300g before PCB/plate/switches).
- Matte or textured surface typical.
- Sound: can be hollow and "clacky" in a budget board; can be tuned to sound good with proper foam.
- Flex: relatively flex, which can result in a softer feel than expected.
- Cost: cheapest to manufacture.

**Polycarbonate (PC):**
- Harder and clearer than ABS. Can be made fully transparent.
- Beloved for **RGB keyboards**: a transparent PC case glows beautifully with per-key RGB.
- Sound: slightly different from ABS — some say "creamy" or "muted."
- Excellent for gasket-mount designs where case stiffness is less critical.
- Examples: KBD67 Lite (PC top), Bakeneko60 (PC), numerous custom designs.

---

### 8.2 Aluminum

**6061 Aluminum** (standard): the dominant premium case material. Found in most keyboards over $150. Machined from a solid aluminum block (CNC machined) or die-cast.
- Weight: significant. A full CNC aluminum TKL case is typically 600g–900g before components.
- Sound: dense, "clacky" or "thocky" depending on mounting system. The material itself rings less than plastic.
- Feel: cold to the touch. High-quality.
- Surface: typically anodized (Type II or Type III hard anodize). Colors: black, silver, navy, olive, etc.
- Cost: the majority of the keyboard's BOM cost in a premium board.

**7075 Aluminum** (aerospace grade): slightly harder and stronger than 6061. Marginally better machining result. Mostly marketing in the keyboard context — the difference in typing feel is negligible.

**Aluminum extrusion** (cheaper alternative): some boards use aluminum that's been extruded (pushed through a die) rather than CNC machined. Lower precision, less premium feel, but much cheaper.

---

### 8.3 Brass

The heaviest common keyboard material. A full brass-weight TKL can reach 2–3kg.

Brass is used two ways:
1. **Full brass cases**: extremely rare, extremely heavy, extremely expensive. Used in ultra-premium group buys as a flex item.
2. **Brass weight/plate**: a thick brass bottom plate or internal weight added to an aluminum case for additional mass and sound dampening. The brass weight inside the Satisfaction75 is famous.

Sound: brass adds a deep resonance that modifies the acoustic signature. The combination of aluminum case + brass weight or plate produces a heavier "clack" with controlled sustain.

---

### 8.4 Wood

Rare and niche. Used in custom one-off designs and a handful of commercial boards.

- Weight: similar to plastic.
- Sound: warm and natural. Wood absorbs high frequencies.
- Aesthetic: striking and unique. Often used for tenting bases on split keyboards.
- Cons: humidity sensitivity (wood expands/contracts), manufacturing consistency challenges.

**Examples**: Corne kits sometimes use wood side pieces for tenting, KEBABcase (wood Corne case), custom walnut/maple cases for Corne and other splits.

---

### 8.5 Polycarbonate (Transparent) — see 8.1

Deserves re-emphasis for its unique role as an **RGB diffuser**. A clear PC case combined with south-facing per-key RGB switches and RGB-transparent keycaps creates a dramatic light show effect. The case literally glows.

---

### Case Material Comparison

| Material | Weight | Sound character | Cost tier | Notes |
|----------|--------|----------------|-----------|-------|
| ABS Plastic | Light | Hollow to clacky | Budget | Widely available, tunable |
| Polycarbonate | Medium | Muted to creamy | Budget–Mid | Great for RGB diffusion |
| 6061 Aluminum | Heavy | Dense clack/thock | Mid–High | Premium standard |
| 7075 Aluminum | Heavy | Same as 6061 | High | Marginal improvement over 6061 |
| Brass | Very heavy | Deep, resonant | Very high | Usually internal weight only |
| Wood | Light–Med | Warm, absorbed | Variable | Aesthetic, niche |

---

## 9. Plate Materials

The plate is the structural layer between the PCB and the keycaps. Switches snap into the plate (or into the PCB directly if plateless). The plate material strongly influences how sound and vibration from the switch travel up to your fingers.

### 9.1 Aluminum

Stiff, non-flex. Sound is bright and sharp. Vibration transfers efficiently up the switch stem to the fingers.

Most common plate material in mid-range boards. Anodized aluminum plates come in various colors.

**Effect**: firm typing feel, bright acoustic signature. Switches feel "stable" and solid.

---

### 9.2 Brass

Stiffer than aluminum, heavier, and with a different resonance character. Brass plates produce a slightly deeper, more muted sound than aluminum.

Used in premium group buy designs for enhanced acoustics. A Brass plate + gasket mount = considered a very refined combination.

**Examples**: Tofu65 brass plate option, many group buys offer brass plate as an upgrade tier.

---

### 9.3 FR4 (PCB Material / Fiberglass)

FR4 is the material printed circuit boards are made from — glass fiber reinforced epoxy resin. Using the same material for the plate is clever: it has **moderate stiffness and slight flex**, it machines predictably, and it's cheap.

Sound: slightly softer than aluminum, a gentle "clack" with reduced metallic ring.

Very popular in budget and mid-range enthusiast boards. KBD67 Lite uses FR4 plates.

---

### 9.4 Polycarbonate (PC Plate)

Polycarbonate plates introduce **significant flex** into the typing surface. The plate bends slightly on keystroke, absorbing vibration.

Sound: muted and "thocky." The flex converts what would be a bright clack into a softer, more dampened stroke.

Feel: softer. Some describe typing on a PC plate as "squishy" compared to the firm feel of aluminum.

**Popular in gasket-mount boards**: the combination of gasket mount + PC plate can be very "pillowy" — either delightful or too soft, depending on preference.

---

### 9.5 Carbon Fiber

Very stiff, extremely light. Sound is crisp and dry.

Rarely used due to cost. Appreciated in enthusiast custom builds for weight savings. **Expensive** — carbon fiber plates cost ~$40–$80 per plate vs ~$10 for FR4.

---

### 9.6 POM (Polyoxymethylene / Delrin / Acetal)

POM is an engineering plastic with a distinctive slightly "hollow" acoustic character. It's denser than polycarbonate but has its own resonance.

Sound: smooth, slightly hollow, with less ring than aluminum. Often described as having a "poppy" sound — short, defined, soft.

POM switches like POM housing switches and POM plates have a growing following because POM has self-lubricating properties.

---

### 9.7 Plateless

Some PCBs support **plateless mounting**: switches are soldered or socketed directly into the PCB without a plate holding them. The PCB provides all lateral stability.

Sound: very soft and cushioned. The switch stem has the most flex possible since there's no plate clamping the sides.

Feel: "mushy" to some, "pillowy" to others. The furthest thing from a stiff aluminum plate.

Used in: Bakeneko (famous for plateless option), some custom builds. The Bakeneko's plateless mounting with a PC case and gasket design is a well-known "extremely soft" typing build.

---

### Plate Material Comparison

| Material | Flex | Sound | Weight | Cost | Notes |
|----------|------|-------|--------|------|-------|
| Aluminum | None | Bright, metallic | Heavy | Low–Mid | Standard, firm, bright |
| Brass | None | Deep, dense | Very heavy | Mid | Premium sound character |
| FR4 | Low | Medium clack | Light | Low | Budget-friendly, balanced |
| Polycarbonate | High | Thocky, muted | Light | Low–Mid | Soft feel, great with gasket |
| Carbon fiber | None | Dry, crisp | Very light | High | Stiff + light, niche |
| POM | Medium | Poppy, hollow | Medium | Mid | Smooth, self-lubricating character |
| Plateless | N/A | Very soft | None | — | Maximum softness, no plate rigidity |

---

## 10. PCB Types

### 10.1 Hotswap PCBs

Hotswap PCBs have **switch sockets** (typically Kailh, Millmax, or Gateron hotswap sockets) soldered onto the board. Switches push into the sockets with no solder. You can **remove and replace switches in 10 seconds** with a switch puller.

**Always recommended for new keyboard builders.** You can:
- Try multiple switch types without desoldering.
- Replace a broken switch instantly.
- Change the feel of your board as your preferences evolve.

**Types of hotswap sockets:**
- **Kailh hotswap socket**: the most common. Spring-loaded clips. Rated for ~100 swap cycles. The standard for mainstream hotswap boards.
- **Millmax sockets (0305 / 7305)**: brass machined sockets soldered into PCB holes. Extremely durable (1,000+ swap cycles). Tighter fit — switches are very secure. Used in some high-end builds.

**Compatibility note**: Hotswap sockets are MX-footprint (5-pin or 3-pin). Kailh Choc switches require dedicated Choc hotswap sockets (different footprint). Low-profile and Choc PCBs are not interchangeable with MX.

---

### 10.2 Soldered PCBs

The traditional method. Switches are soldered directly to the PCB. **Permanent.**

**Pros:**
- Cheaper PCB to manufacture.
- Switch stability is slightly better (fully anchored vs socket).
- Used in nearly all vintage/classic boards (Filco, Leopold original designs).

**Cons:**
- To change switches, you must desolder each switch (25–87+ switches on a full board). Desoldering is slow, requires a solder pump or wick, and risks PCB damage.
- Not beginner-friendly for experimentation.

**When soldered is fine:** If you know exactly what switch you want and you're not planning to change. Many experienced builders deliberately choose solder to feel connected to their board.

---

### 10.3 Flexible PCBs

Used primarily in split keyboards with curved or unusual geometries. The PCB itself is made from a flexible substrate (polyimide film, like Kapton tape) that allows bending.

Your Corne uses small PCBs per half, connected by a TRRS cable in wired mode. The PCB itself isn't flexible, but the split architecture achieves the same geometric goal: each PCB is small enough to be positioned freely.

True flex PCBs appear in:
- Some dactyl/manuform keyboards with curved keywells.
- Wrist-worn/ultra-compact experimental designs.

---

## 11. Sound Profile and Acoustics

The "sound" of a keyboard is one of the most discussed aspects in the hobby — and also one of the most complex, because it's the result of a **system** of interacting components.

### The Signal Chain of Keyboard Sound

```
Finger → Switch stem → Switch housing → Plate → PCB → Foam/dampener
  → Case walls → Air column inside case → Desk surface → Room acoustics
```

Every layer modifies the sound. You can tune each layer.

### Key Sound Terms

**Thock**: A deep, low-frequency, somewhat muffled sound. Associated with:
- Heavy case (aluminum, brass weight)
- Gasket mount (absorbs high frequencies)
- PC or POM plate (flex absorbs bright attack)
- Dense foam dampening
- Linear or silent tactile switches
- PBT keycaps (denser than ABS)

**Clack**: A brighter, crisper, higher-frequency sound. Associated with:
- Tray or top mount (less dampening)
- Aluminum or brass plate (stiff, transmits vibration)
- Minimal foam
- Lighter switches
- ABS keycaps (thinner walls, more resonant)

**Click**: The intentional sound of a clicky switch mechanism (Cherry MX Blue, Kailh Box Navy, etc.). A sharper, more percussive sound on the downstroke caused by a physical click mechanism inside the switch.

**Ping**: Unwanted metallic resonance. Usually comes from the plate or PCB vibrating at a frequency that creates a ringing sound after keystroke. Associated with metal plates without dampening. **Bad.** Solved by:
- PE foam mod
- Tape mod
- Tempest mod
- Case foam
- Switch films

**Poppy**: Short, defined, somewhat hollow. POM plate/switches. Dry.

**Creamy**: Smooth sound without sharp attack. Associated with lubed linear switches, gasket mount, PC plate.

---

### Modifications to Tune Sound

**Case foam**: A layer of foam cut to the interior of the case, placed beneath the PCB. Eliminates hollow resonance inside the case. One of the cheapest and most effective mods. Available from various vendors, or cut from craft store foam sheets.

**Plate foam**: Foam layer between the plate and PCB. Fills the switch void area. Reduces vibration transfer.

**Switch foam (switch films)**: Thin PC, POM, or foam films placed between the switch top housing and bottom housing. Eliminates housing wobble, subtly mutes sound. Cost: ~$0.10/switch.

**PE foam mod**: A layer of polyethylene foam placed between PCB and plate, holes cut for each switch pin. Creates a subtle air cushion. One of the most popular mods — adds a "poppy" character many people find pleasant.

**Tape mod**: Several layers of painter's tape applied to the back of the PCB. Creates a slight flex in the PCB, changes acoustic character. Free. Easily reversible.

**Tempest mod**: Paper layers on PCB bottom. Similar to tape mod.

**Lube**: Applying thin lubricant (Krytox 205g0 for linears, 3203 for tactiles) to the switch internals. Smooths the keystroke, eliminates scratchiness, subtly changes sound character toward "creamy" or "thocky." One of the highest-impact modifications.

**Stabs (stabilizers) lube**: Large keys (Spacebar, Shift, Enter, Backspace) use a stabilizer wire system. Lubing and tuning stabilizers (with Dielectric grease or 205g0) eliminates wire ping and rattle. **Stabilizer rattle is the most annoying keyboard sound problem.** Always lube stabs.

---

### Sound Design Recipes

| Target sound | Mount | Case | Plate | Switches | Extras |
|-------------|-------|------|-------|---------|--------|
| Maximum thock | Gasket | Aluminum | PC or POM | Lubed linear | Case foam + PE foam mod |
| Crisp typist clack | Top/tray | Aluminum | Aluminum | Light tactile | Minimal foam |
| Premium creamy | Gasket | Aluminum | Brass | Lubed linear | Switch films, tape mod |
| Budget-optimized thock | Tray | Plastic | FR4 | Lubed linear | Case foam, tape mod, stab lube |
| Click heaven | Any | Any | Aluminum | Clicky (Box Navy) | Acoustic desk mat |

---

## 12. Gaming Keyboards vs Enthusiast Keyboards

The keyboard market bifurcated in the 2010s into two distinct segments with overlapping but distinct priorities.

### 12.1 Gaming Keyboard Brands

**Razer**: Focus on aesthetics (Chroma RGB), fast switches, software ecosystem (Synapse). Proprietary switches (Razer Green/Yellow/Orange/Optical). High marketing spend. Build quality has improved significantly since 2020. The Razer Huntsman V3 Pro (analog optical) is genuinely impressive for gaming.

**Corsair**: Heavy metal construction, macro keys, complex RGB. iCUE software. Corsair MX-compatible switches and some proprietary. Mainstream gaming brand.

**Logitech**: Best wireless gaming keyboards (Lightspeed 2.4GHz protocol is industry-leading for wireless latency). Romer-G switches (proprietary) in older boards; newer boards use Kailh or standard MX. Logitech G Pro X TKL is well-regarded.

**SteelSeries**: Apex Pro with adjustable actuation (Hall Effect adjacent). Good balance of gaming features and build quality.

**HyperX**: Budget-friendly gaming boards, acquired by HP. Good value. Standard switches.

**What gaming brands optimize for:**
- RGB customization and per-key lighting
- Software macros and per-profile configs
- Anti-ghosting / n-key rollover (all keys register simultaneously)
- Speed switches (low actuation force, short pre-travel)
- Durability for intense button-mashing
- Marketing

**What gaming brands often sacrifice:**
- Build quality of case (often plastic tray mount)
- Switch quality (proprietary or budget options)
- Sound profile (not prioritized)
- Customization for typists (keycap compatibility, hotswap often absent on budget models)

---

### 12.2 Enthusiast Brands

**Keychron**: The gateway drug for keyboard enthusiasts. Started with low-profile keyboards, now makes an extensive lineup from budget to premium. The **Q series** (aluminum, gasket mount, hotswap, south-facing RGB) offers remarkable value. The **K series** (ABS/aluminum frame, hotswap) is excellent value. **Highly recommended for most buyers.**

**GMMK / Glorious**: GMMK Pro (75%, gasket, modular) is a strong platform. GMMK 2 is a more budget offering. Glorious also sells switches, stabs, and foam — a full ecosystem.

**Ducky**: Long-standing enthusiast brand from Taiwan. Double-shot PBT keycaps standard. Consistent build quality. Less flashy than gaming brands but trusted. The Ducky One 3 line is excellent.

**Leopold**: Japanese/Korean brand known for exceptional build quality, conservative design, and PBT keycaps standard. No RGB, no software required — what you see is what you get. Leopold FC750R (TKL) and FC900R (full) are frequently cited as near-perfect daily drivers.

**Varmilo**: Chinese brand making high-quality boards. Famous for custom theme designs (seasonal limited runs with unique color schemes and artisan keycaps). Uses EC (electrocapacitive) switches in some lines — similar to Topre but less expensive.

**KBDfans**: Chinese manufacturer/retailer that manufactures many community-designed keyboards. The Tofu series, KBD67 series, and others are widely used in the community.

**Drop (formerly MassDrop)**: Community-driven platform that popularized group buying for keyboards. Drop's own designs (CTRL, ALT, SHIFT) are well-regarded. The Drop/Halo collaboration brought Holy Panda switches to the community.

---

### 12.3 Custom / Artisan Keyboards

Beyond enthusiast brands lies the world of **group buys** and **custom keyboards**:

**How group buys work:**
1. A designer creates a keyboard design (CAD renders, prototypes).
2. An Interest Check (IC) gathers community feedback.
3. A Group Buy opens: buyers pay upfront (months before delivery).
4. Designer works with manufacturers (usually in China or Taiwan) to produce a limited run.
5. Keyboards ship 6–18 months after GB closes.
6. Limited extras sometimes sold via "extras" rounds afterward.

**Risk**: Group buys can fail (designer drama, manufacturer issues, quality problems, rare fraud). The community has become better at vetting designers and manufacturers.

**Vendors**: CannonKeys (US, trustworthy), Mekanisk (EU), Proto[Typist], Switchkeys, Zeal PC (Canada, Zealio switches).

**Examples of legendary group buy boards:**
- **Satisfaction75** (geekhack): 75% aluminum, brass weight, considered endgame. ~$400 in original GB.
- **THINK6.5** (ai03): 65%, ludicrously over-engineered, famous for sound signature. ~$350–$500.
- **Keycult No. 2**: machined aluminum TKL, literally treated like a collectable. Resells for $1,000+.
- **Duck Lightsaver V3**: legendary for build quality. Extremely limited.

---

### 12.4 Hall Effect Gaming (Wooting) — Why Competitive Players Are Switching

The **Wooting 60HE** and **80HE** have reshaped competitive gaming keyboards since 2022.

**Rapid Trigger** explained:

Normal mechanical switches:
```
Press:   key actuates at 2.0mm
Release: key resets at ~1.8mm (0.2mm hysteresis minimum)
Dead zone: the key must travel past 1.8mm upward before it re-registers
```

This dead zone causes a problem in competitive FPS: if you release a movement key (say W for forward) and immediately press it again, the game doesn't register the second press until the key has traveled past the 1.8mm reset point. This slows your counter-strafing.

**Rapid Trigger** (Wooting):
```
Actuation distance: configurable, as low as 0.1mm
Rapid Trigger sensitivity: as low as 0.1mm
Dead zone: essentially eliminated
```

With 0.1mm Rapid Trigger, the key registers a "release" the instant it moves 0.1mm upward from its lowest point, and re-actuates the instant it moves 0.1mm downward. This enables counter-strafing that's mechanically as fast as humanly possible.

**Why pro players care**: In Counter-Strike 2, Valorant, and rhythm games, the fastest players now use Wootings. The latency advantage is real and measurable at the frame level.

**The catch**: Wooting boards are gaming keyboards. They're not customizable in the enthusiast sense, don't have gasket mounts, and are 60% or TKL only. The sound and feel are fine for gaming but not focused on the typist experience.

**Recommendation**: If you play competitive FPS at a high level, the Wooting 80HE is the clear recommendation. For typing or casual gaming, the benefit disappears.

---

## 13. Wireless and Battery Considerations

### Li-Po Battery Chemistry

Split wireless keyboards use **lithium polymer (Li-Po)** batteries — flat, flexible, high energy density cells.

**Your Corne's setup**: Each nice!nano v2 controller is paired with a small Li-Po battery (common sizes: 301230 / 300mAh, 401230 / 400mAh, or 601230 / 500mAh). The nice!nano has a built-in charging circuit and battery protection (overcharge, over-discharge, short-circuit protection).

**Charging**: via USB-C on the nice!nano. When plugged into USB, the battery charges at a safe rate (typically 100mA for small cells). **Never use a fast charger** expecting fast charge on these small cells — the nice!nano's charge circuit limits current appropriately regardless.

**Battery life on split wireless ZMK boards:**

ZMK is specifically optimized for power efficiency, unlike QMK which was not designed for wireless. ZMK implements Bluetooth LE power management aggressively:

| Condition | Approximate battery life (500mAh cell) |
|-----------|----------------------------------------|
| Active typing, RGB off | 3–6 months |
| Active typing, RGB on (full brightness) | 1–3 weeks |
| Idle (ZMK sleep mode triggered) | Many months (deep sleep current draw <1µA) |
| Peripheral half (right side, BT to left) | Slightly shorter than central left |

**Key insight**: ZMK's power optimization is what makes long wireless battery life on split keyboards possible. QMK on wireless keyboards (like the Bluetooth-capable Ferris Sweep with Pro Micro BT) achieves much shorter life.

**Turn off RGB to maximize battery life.** RGB LEDs consume 20–60mA per key, which is orders of magnitude more than the idle controller (~0.01mA in sleep). RGB and long battery life are mutually exclusive on small cells.

---

### ZMK Power Features

**Deep sleep**: ZMK automatically enters deep sleep after a configurable idle timeout. The controller draws minimal current. A key press wakes it in ~100–200ms.

**Split sleep**: The peripheral (right) half sleeps independently when not communicating with the central. The central wakes the peripheral when needed.

**Battery reporting**: ZMK reports battery percentage via Bluetooth to the OS. macOS, iPadOS, and Windows show battery levels for paired BT devices.

**Multiple BT profiles**: Your MEDIA layer has BT profile keys. ZMK supports up to 5 simultaneous Bluetooth bonds. You can be paired to Mac, iPad, iPhone, and two other devices simultaneously and switch with a key tap.

---

## 14. Ergonomic Considerations

Keyboard ergonomics are frequently undervalued until something starts to hurt. Here's the full picture.

### Wrist Position

**The ideal wrist position** for typing:
- Wrists **neutral**: neither bent up (extension) nor down (flexion).
- Forearms roughly **parallel to the floor** (slight downward angle acceptable).
- No **ulnar deviation** (bending wrists outward toward the pinky side).

How keyboards affect wrist position:
- **Standard unified keyboard**: often causes ulnar deviation because the shoulder-width hand position doesn't match the keyboard width. Your wrists bend outward to reach the keys.
- **Wrist rest**: can help with neutral wrist height but can also encourage wrist resting during typing, which creates pressure on the carpal tunnel. Wrist rests are for pausing, not active typing.
- **Split keyboard with shoulder-width separation**: eliminates ulnar deviation entirely.

---

### Tenting

Tenting means raising the inner edge of each keyboard half so the keyboard is angled like a tent (thumbs higher than pinkies). This reduces **pronation** — the forearm rotation that happens when you type on a flat keyboard.

```
Without tenting:  flat keyboard, hands rotate fully pronated
   ┌──────────┐
   │ keyboard  │ ← seen from above, hand is palm-down
   └──────────┘

With tenting:     inner edge raised
     /keyboard/  ← hand is in a more natural "handshake" position
```

**Optimal tenting angle**: Most people find 5–15° comfortable. Some find 30–45° (near-vertical keyboard) best. This is highly individual.

**Corne tenting options:**
- Small rubber feet under inner corners (simple, cheap).
- Commercial tenting kit (Splitkb tent kit for Corne-compatible boards).
- 3D printed tenting legs (printable files available on Printables/Thingiverse).
- Custom bent metal brackets.
- The Ergodox EZ and ZSA Moonlander have integrated tenting mechanisms.

---

### Negative Tilt

Most desks and keyboard rests have a **positive tilt**: the back of the keyboard is higher than the front. This causes wrist extension (bending upward) during typing, which is biomechanically unfavorable.

**Negative tilt** means the back of the keyboard is **lower** than the front. This keeps the wrist in a more neutral position.

Negative tilt is achieved with:
- Legs folded forward under the keyboard (some keyboards have this option).
- Keyboard tray mounted below desk height (traditional ergonomic desk setup).
- Keyboard stand designed for negative tilt (3M Adjustable Keyboard Tray).

---

### Split Distance

How far apart should the halves be? There's no single answer — it depends on your shoulder width and arm length.

The **scientific recommendation**: place the halves so your forearms are parallel and pointing straight ahead of your shoulders. This means the inner edge of each half aligns roughly with your shoulder joint.

For most adults, this means the halves are ~40–50cm apart (center to center).

Starting too wide can strain shoulders; start narrow and gradually widen. The Corne has no cable between halves when wireless, so you can experiment freely.

---

### Layout Pairing with Alternative Base Layouts

The ergonomic argument for the Corne extends to base layouts. You're currently on QWERTY. But:

**Dvorak**: Designed by August Dvorak in the 1930s to reduce finger travel. Vowels on the left home row (AOEUI), most common consonants on the right. Studies show reduced finger travel but the learning curve is significant and modern QWERTY users are already fast enough that the switch rarely yields productivity gains.

**Colemak**: A modern redesign of QWERTY maintaining similar letter positions for Z, X, C, V (copy/paste shortcuts). Home row retains A and several others. Far less finger travel than QWERTY, easier to learn than Dvorak. Popular in the ergonomic community.

**Colemak-DH**: A Colemak variant that moves D and H off the center column to more accessible positions. Considered superior to Colemak by most ergonomic analysts.

**Workman**: Another QWERTY evolution, less popular than Colemak.

**BEAKL**: More radical optimization, niche.

**For Corne users**: Colemak-DH is the natural complement to a Corne. The combination of columnar stagger + Colemak-DH + home row mods gives maximum ergonomic efficiency. The learning investment is ~2–3 months to regain full QWERTY speed, then ongoing gains.

**Practical note**: You can run QWERTY hardware (labels on keycaps) with any software layout — the keys send the same codes; the OS maps them. On a blank/Corne board with no legends, the software layout matters more than any label.

---

## 15. Budget Tiers with Recommendations

### Under $50: Budget Mechanical Keyboards

**Best picks:**
- **Keychron C1** ($45, TKL, tray mount, Gateron hotswap): The best $45 keyboard. Uses Gateron switches (notably smoother than Outemu). Hotswap is a major bonus at this price.
- **Royal Kludge RK61** ($35, 60%, BT+wired): Surprisingly capable BT 60%. Switches are mediocre but swappable. Good for learning 60%.
- **Redragon K552** ($30, TKL, Outemu switches): Classic budget recommendation. Decent build quality, works fine.
- **Akko 3068B** (occasional sale under $50): normally $65–$80 but often on sale. Genuine mechanical, BT + wired.

**What to expect at this tier:** real mechanical switches, basic case quality, no gasket mount, no premium materials. Perfectly functional for most users.

---

### $50–$100: Entry Enthusiast

- **Keychron K series** (K2, K6, K8): the most recommended boards in this tier. BT + wired, hotswap, compact sizes. K2 (75%), K6 (65%), K8 (TKL). Good build quality. Aluminum frame option adds ~$20.
- **Akko 3068B** ($65–$80): excellent wireless value.
- **Nuphy Air75** ($80): low-profile 75%, wireless, stylish aesthetic. Not for everyone (low-profile is different from normal key travel) but excellent for laptop replacement.
- **Epomaker TH80** (~$70): budget 75% with gasket-like sound. Okay value.

**What to expect**: solid daily drivers, real hotswap, decent sound. Not premium, but genuinely good.

---

### $100–$200: Mid-Range Enthusiast / First Premium

This is where the hobby gets interesting.

- **Keychron Q series** ($150–$200): CNC aluminum, gasket mount, hotswap, south-facing RGB. The Q1 (75%), Q2 (65%), Q3 (TKL), Q5 (full), Q6 (96%). Outstanding value. The Q1 Pro ($200) adds wireless.
- **GMMK Pro** ($170): aluminum, gasket mount, 75%. The GMMK Pro was the catalyst for the "affordable gasket mount" revolution. Still excellent.
- **Glorious GMMK 2** ($100–$120): lighter and cheaper than GMMK Pro. Good value.
- **Varmilo VA88M / VA108M** ($130–$160): Japanese aesthetics, custom theme designs, Cherry MX switches. Well-built, no software required.
- **KBD67 Lite R4** (~$90): incredible budget gasket mount 65%. Uses FR4 plate. Beloved by the community.
- **Epomaker EP84** (~$90): solid TKL option.
- **Ducky One 3** ($100–$140): consistent quality, double-shot PBT standard.

**What to expect**: real gasket mount (Keychron Q, GMMK Pro, KBD67 Lite), premium switches, long-term durability.

---

### $200–$400: Premium and Entry Custom

- **Keychron Q series with switch upgrade + lube job**: take the Q1 ($150), add Gateron G Pro 3.0 linears ($25), lube them yourself (brush + 205g0, ~$15 for supplies) = premium end-to-end board for ~$200.
- **Group Buy boards (Salvation, Rainy75, Monsgeek M1)**: aluminum, various mounts, designed by community members. Wait required for GB; "extras" often available immediately.
- **Drop CTRL / ALT**: hotswap TKL/65% with RGB underglow, aluminum, decent build.
- **KBD67 Lite + aluminum case** (as a platform): the 67 PCB/plate drops into third-party cases.
- **Tofu65 / Tofu60** (KBDfans): aluminum 65%/60% cases with good switch and plate combinations available.

**What to expect**: premium materials, deeper sound tuning, group buy access, custom keycap sets compatibility.

---

### $400+: High-End Customs

- **Satisfaction75** (~$400 new, $300–$500 secondhand): 75%, aluminum, brass weight. Mechanical volume knob. Considered an endgame daily driver by many.
- **THINK6.5** (ai03, ~$350–$500): 65%, extremely refined engineering, legendary sound.
- **Mode Eighty TKL** (~$350+): high-quality custom TKL.
- **Keycult No. 2** ($1,000+ resale): TKL, machined aluminum, collector's item.
- **Cannonkeys Satisfaction75 variants**: CannonKeys produces high-quality custom designs.

**What to expect**: machined precision, collector-grade build quality, resale value, a specific "endgame" experience.

---

### Split Ergonomic Keyboards

This category is special and deserves its own tier breakdown.

| Board | Price | Type | Keys | Form | Notes |
|-------|-------|------|------|------|-------|
| **Corne** (your board) | $50–$100 kit + $60–$80 nice!nanos | DIY kit | 42 | Columnar split 40% | Best ergonomics, max customization, soldering required |
| **Lily58 Pro** | $80–$120 kit | DIY kit | 58 | Columnar split 60% | Like Corne but with number row, easier transition |
| **Sofle** | $80–$120 kit | DIY kit | 58 | Columnar split 60% | Lily58 with encoder + rotary |
| **Kyria** | $100–$150 kit | DIY kit | 50 | Columnar split, per-key RGB option | Aggressive columnar stagger |
| **Ergodox EZ** | $270 | Assembled | 76 | Columnar split, MX | Plug-and-play ergonomic, good software. Slightly outdated design. |
| **ZSA Moonlander** | $365 | Assembled | 64 | Columnar split | ZSA's flagship. Beautiful, well-supported, Oryx configurator. No soldering. |
| **Dygma Defy** | $329+ | Assembled | ~80 | Columnar split, wireless option | Beautiful, wireless, underglow, per-key RGB. Expensive for what it is. |
| **Kinesis Advantage360** | $449 | Assembled | 64 | Concave dactyl | 3D concave keywells, deepest ergonomics. Very different feel. |
| **HHKB Hybrid** | $300 | Assembled | 60 | Unified, traditional | Topre switches, wireless, BT. Different philosophy but beloved. |

**Recommendation progression**: Start with the Corne you have. The next natural step is the **ZSA Moonlander** if you want a pre-assembled columnar split with professional polish, or the **Lily58** if you want more keys in a similar DIY format.

---

## 16. What to Buy Next If You Love Your Corne

You have a 42-key, columnar split, wireless ZMK board. You've optimized your keymap. You want more keyboards. Here's how to think about expansion.

### The Horizontal Expansion: More Keys, Same Philosophy

You're already at the ergonomic extreme. Moving up in key count while keeping the philosophy means:

**Lily58** (~$80–$120 kit): 58 keys, columnar split. Adds a number row above your current 3 rows. Same column stagger philosophy. Good if you feel the Corne's lack of dedicated number row is a friction point for you.

**Sofle v2** (~$100–$150 kit): 58 keys + rotary encoders. Adds a scroll wheel or volume knob per half. Extremely satisfying for media control or scrolling.

**Kyria** (~$120–$150 kit): 50 keys, pronounced columnar stagger, optional per-key RGB. More keys than Corne, more aggressive stagger.

---

### The Contrast Purchase: A Big Traditional Board

After the Corne, many users purchase a full-featured traditional board for **contrast** — to appreciate when you want it and to share with others.

**Best single recommendation**: **Keychron Q1 Pro** ($200): 75% layout, aluminum, gasket mount, wireless. Everything the Corne isn't (traditional stagger, lots of labeled keys, gasket thock). A beautiful daily driver when you're away from your Corne setup.

**If you want TKL**: **Keychron Q3** ($150): gasket mount TKL. The safest recommendation in the hobby for a first premium non-split keyboard.

---

### The Classic 60%: The Collector's Base

Every serious enthusiast owns at least one 60%. It's the most customizable form factor, with the deepest ecosystem.

**Recommendation**: **HHKB Pro Hybrid Type-S** ($300): Topre switches (45g, silenced), 60% layout, BT + USB. The single most iconic "endgame typing" keyboard. After the Corne's MX-ecosystem, Topre will feel completely alien in the best possible way. No LEDs, no software required.

Alternatively: **Tofu60 with Brass Plate** (KBDfans, ~$150–$200 built): MX ecosystem, 60%, aluminum case, tinkerable platform. Complements your Corne well.

---

### The Gaming Board: Hall Effect

If you play competitive games: **Wooting 80HE** ($175): TKL, Hall Effect (Lekker switches), Rapid Trigger. Everything the enthusiast ecosystem doesn't do — analog actuation, gaming-optimized features.

---

### The Endgame Trifecta

If you must choose three boards for maximum satisfaction:

1. **Your Corne**: daily driver, ergonomic work mode, ZMK wireless. Keeps your fingers healthy.
2. **Keychron Q1 Pro or Q3**: traditional layout for heavy lifting, elegant desk object, brings guests back to normal use.
3. **HHKB Pro Hybrid Type-S**: Topre tactile for a completely different experience, the legendary keystroke.

---

### What to Look for Next: Decision Framework

```
Do you want:  ergonomic improvement? → Stay in split/columnar camp (Lily58, Sofle, Moonlander)
              a different feel?       → HHKB (Topre) or Wooting (Hall Effect)
              traditional + premium?  → Keychron Q series, Satisfaction75
              a sound project?        → Tofu60/65 kit + lube project + gasket mod
              a collector's piece?    → Group buy, Satisfaction75, THINK6.5
              gaming edge?            → Wooting 80HE
              low-profile?            → Nuphy Air75, Keychron K3 Pro
```

---

## Reference Resources

- **[ZMK Documentation](https://zmk.dev/docs)** — firmware reference for your Corne
- **[Keyboard University](https://www.keyboard.university)** — keebs101 for beginners
- **[r/MechanicalKeyboards](https://www.reddit.com/r/MechanicalKeyboards/)** — community, daily drivers, advice
- **[Keycaps.info](https://www.keycaps.info)** — keycap set tracker
- **[KBD.news](https://kbd.news)** — group buy news
- **[Geekhack](https://geekhack.org)** — original community forum for group buys
- **[Deskthority](https://deskthority.net)** — vintage and technical keyboard community
- **[CannonKeys](https://cannonkeys.com)** — trusted group buy vendor (US)
- **[KBDfans](https://kbdfans.com)** — Chinese manufacturer/vendor, wide selection
- **[Keychron](https://www.keychron.com)** — best mainstream value keyboards
- **[ZSA](https://www.zsa.io)** — Moonlander and Voyager assembled ergonomic boards

---

*This document covers the full landscape of keyboard hardware. For switch-specific research, see `switches-research.md`. For Corne-specific firmware and keymap documentation, see the `docs/corne/` directory.*
