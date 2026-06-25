# Corne Keyboard Accessories & Customization Guide

Your Corne is a blank canvas. The split, 42-key form factor opens a world of customization that full-size keyboards can't touch — every component is swappable, every angle adjustable, every surface moddable. This guide covers everything from $0 DIY mods to $200 premium upgrades.

---

## Table of Contents

1. [Cases](#1-cases)
   - [Acrylic Sandwich](#acrylic-sandwich-cases)
   - [3D Printed](#3d-printed-cases)
   - [Aluminum & Brass](#aluminum--brass-cases)
   - [Low-Profile](#low-profile-cases)
2. [Tenting](#2-tenting)
3. [OLED Covers & Acrylic Windows](#3-oled-covers--acrylic-windows)
4. [Cables](#4-cables)
   - [USB-C Cables](#usb-c-cables)
   - [TRRS Cables](#trrs-cables-wired-split)
5. [Switches](#5-switches)
6. [Keycap Sets](#6-keycap-sets)
7. [Stabilizers](#7-stabilizers)
8. [Desk Mats](#8-desk-mats)
9. [Wrist Rests](#9-wrist-rests)
10. [Carrying Cases & Travel](#10-carrying-cases--travel)
11. [Batteries (nice!nano Builds)](#11-batteries-nicenano-builds)
12. [Sound Modding](#12-sound-modding)
13. [Trackball & Trackpad Mods](#13-trackball--trackpad-mods)
14. [RGB Upgrades](#14-rgb-upgrades)
15. [Where to Shop](#15-where-to-shop)

---

## 1. Cases

The case is the single biggest visual statement your Corne can make. Unlike a standard keyboard where the case is integral to the PCB design, the Corne separates them entirely — you can and should change the case independently. Every case category has a wildly different look, feel, weight, and price.

### Acrylic Sandwich Cases

The most common case style shipped with Corne kits. Understand the construction and you can source or design your own.

**Construction:**
```
┌─────────────────────────────┐  ← Top acrylic plate (1.5–3mm)
│  ○   ○   ○   ○   ○   ○      │
├─────────────────────────────┤  ← Switch plate (1.5mm, holds switches)
│                             │
│  [M2 standoffs, 4–6mm tall] │  ← Open middle layer (or stacked layers)
│                             │
├─────────────────────────────┤  ← PCB
├─────────────────────────────┤  ← Bottom plate (3mm, usually black or opaque)
└─────────────────────────────┘
       │         │
    M2 screws pass through all layers
```

**Materials and colors:**
- **Clear acrylic**: Lets you see the PCB, components, and underglow LEDs directly. Best for RGB.
- **Frosted acrylic**: Diffuses RGB into a soft glowing halo. More professional look than clear.
- **Black acrylic**: Sleek, hides components. RGB still bleeds out the sides and bottom.
- **Colored acrylic**: Red, blue, green, purple — match your keycaps. Tinted but partially translucent.
- **Multi-layer stacking**: Some designs use 3–5 stacked layers to create different height profiles and add OLED windows.

**Hardware:**
- **M2 screws**: Usually M2×4mm (top) and M2×8–12mm (bottom, through PCB). Phillips or hex socket.
- **M2 standoffs**: Hex brass or aluminum. 4mm for low-profile, 6–8mm for standard height.
- **Rubber feet**: Stick-on bumpons (usually 3M SJ5302), four per half, placed at corners.

**Pros:**
- Cheap — $10–20 included with most kits, or $15–30 standalone
- RGB underglow looks spectacular through clear/frosted layers
- Easy to disassemble and reassemble (just M2 screws)
- Light (under 200g per half)
- Many layer heights and designs available

**Cons:**
- Acrylic is brittle — cracks if over-torqued or dropped at the right angle
- Sounds hollow (resonates, amplifies switch noise)
- Less premium feel than machined metal
- Standoffs can strip with repeated assembly/disassembly

**Where to get them:**
- Included in kits from Keyhive, Boardsource, 42keebs
- Standalone from Keyhive (~$15/pair): https://keyhive.xyz
- Custom laser cutting: send DXF files to Ponoko, JLCPCB, or your local makerspace
- Files: crkbd plate files are open source on the official GitHub (github.com/foostan/crkbd)

**Tip:** When assembling, tighten M2 screws finger-tight plus a quarter turn — no more. Acrylic cracks under hex key torque. Use thread-lock (blue Loctite 243) if standoffs keep loosening.

---

### 3D Printed Cases

The most customizable option and the best entry point for tinkerers. You don't need a printer — services will print and ship for less than many commercial cases.

**Printing yourself:**
- Any FDM printer with a ~200×200mm bed can fit one Corne half
- Recommended settings: 0.2mm layer height, 4 walls, 40% infill for strength, no supports needed for most designs
- Print time: 2–5 hours per half depending on design complexity

**Materials:**
| Material | Durability | Sound | Feel | Notes |
|----------|-----------|-------|------|-------|
| PLA | Good | Slightly resonant | Matte, light | Easiest to print, not great in heat (car dashboards) |
| PETG | Better | More solid | Slightly flexible | Great all-rounder, slightly glossy |
| ABS | Good | Solid | Can be sanded/painted | Harder to print, warps; use enclosure |
| ASA | Great | Solid | UV-resistant | Good outdoor/desk use; like ABS but better |
| Resin (SLA/MSLA) | Excellent | Dense | Smooth, premium | Much smoother surface; brittle at thin sections |

**Print services (no printer needed):**
- **JLCPCB** (jlcpcb.com): Upload STL, get FDM or resin parts in 5–10 days, very affordable ($5–20)
- **Craftcloud** (craftcloud3d.com): Aggregates multiple services, lets you compare prices
- **Shapeways** (shapeways.com): More material options including nylon (SLS) and metals
- **Local libraries**: Many public libraries have Ultimaker/Prusa printers available free or cheap

**Where to find designs:**
- **Printables.com**: Search `crkbd case` or `corne keyboard` — dozens of designs, rated by community
  - https://www.printables.com/search/models?q=crkbd
- **Thingiverse.com**: Older designs, many still excellent
  - https://www.thingiverse.com/search?q=crkbd+corne
- **GitHub**: Many designers publish on GitHub alongside their build logs

**Notable designs to look for:**
- **Rimless/low-pro cases**: Minimal lip around PCB, very sleek
- **Tent cases**: Case with integrated tenting legs, adjustable angle
- **OLED window designs**: Cutout or clear inset for the display
- **Columnar stagger guides**: Cases that visually exaggerate the column stagger with ridges
- **Travel/carry cases**: Clam-shell designs with snap closures

**Finishing printed cases:**
- Sand with 220 → 400 → 800 grit for smooth surface
- Spray paint with Rustoleum 2X or similar — primer first
- Acetone vapor smoothing for ABS (removes layer lines entirely)
- Hydro-dip for pattern effects

---

### Aluminum & Brass Cases

Premium machined metal cases transform the Corne from a hobbyist build into a desk artifact. The weight, the sound, the feel — completely different class.

**Construction methods:**
- **CNC milled aluminum (6061)**: Most common, silver or anodized colors. Light, stiff, excellent sound.
- **CNC milled brass**: Significantly heavier (~3× aluminum). Won't move on your desk even without feet. Warmer sound.
- **Anodized finishes**: Black, silver, grey, gold, red, blue — hard coating fused to the aluminum surface.
- **Bead-blasted**: Matte texture, hides fingerprints better than polished.

**Typical construction:**
```
Top case  → CNC machined, contains the switch plate integrated or floating
Bottom    → CNC machined bottom plate, often with weight insert
Screws    → M2 or M3, typically socket head (hex key)
Gaskets   → Optional: silicone or foam between plate and case for isolation
```

**Weight comparison:**
| Case Type | Per Half (approx) | Total Setup |
|-----------|------------------|-------------|
| Acrylic sandwich | ~80g | ~160g |
| 3D printed PLA | ~100g | ~200g |
| Aluminum | ~300–500g | ~600g–1kg |
| Brass | ~800g–1.2kg | ~1.6–2.4kg |

A heavy keyboard that won't slide is a genuine ergonomic benefit — you stop bracing against the keyboard.

**Vendors:**
- **Keyhive** (keyhive.xyz): Sells Corne-compatible aluminum cases and bottom plates
- **42keebs** (42keebs.eu): European vendor, excellent quality aluminum options
- **Little Keyboards** (littlekeyboards.com): Various cases for compact boards including Corne
- **Group buys**: Periodically run on Geekhack (geekhack.org) — wait months but get premium custom designs

**Cost range:**
- Budget aluminum: $40–70/pair
- Mid-range aluminum with weight: $80–120/pair
- Brass or premium machined: $100–200+/pair

**Group buys to watch:**
- Check r/mechkeys (reddit.com/r/MechanicalKeyboards) for active GBs
- Geekhack Interest Checks (ICs) appear before buys open
- Keycult, Qwertykeys, and other premium makers occasionally do split keyboard cases

---

### Low-Profile Cases

Designed for Choc (low-profile) switches specifically. Ultra-slim, sits nearly flush with the desk surface.

**What makes it "low-profile":**
- Works with Kailh Choc V1/V2 switches (3.5mm travel vs MX's 4mm)
- Total keyboard height from desk: 14–18mm vs 30–35mm for standard MX
- Keycaps: Choc-specific caps (MBK, Worklouder Ergo, etc.) — cannot use MX keycaps

**Benefits:**
- Wrist extension angle dramatically reduced at low height
- Very portable and thin
- Unique, minimalist aesthetic
- Lighter than standard cases

**Caveats:**
- Your current build uses MX-footprint hotswap — low-profile Choc cases won't fit without a different PCB
- Future build option if you want to go ultra-slim

---

## 2. Tenting

Tenting is arguably more important than the case. It addresses the fundamental ergonomic problem that split keyboards solve: **forearm pronation**.

### Why Tenting Matters

When your keyboard sits flat on your desk and your hands are on it, your forearms rotate inward (pronate) to bring your palms parallel to the desk. This rotation is unnatural — your forearms naturally rest at a slight angle when hanging. Sustained pronation loads the tendons and muscles of the forearm asymmetrically.

```
Flat keyboard:
  Forearm: ████████████▼
  Wrist:            ╔══════╗  ← Pronated (rotated inward)
  Desk:       ──────╚══════╝────

Tented keyboard (15°):
  Forearm: ████████████▼
  Wrist:          ╱══════╗  ← More neutral rotation
  Desk:       ────╱══════╝────
```

Tenting 10–15° is enough to significantly reduce pronation. Beyond 20–25°, most people find diminishing returns unless they've specifically trained for extreme tent.

### Recommended Progression

**Week 1–2:** Start at 5–10°. Your wrists need to adapt — too much tent too fast causes strain.
**Week 3–4:** Increase to 10–15° if comfortable.
**Month 2+:** Try 15–20°. Many Corne users settle here permanently.

Some users go 30°+ (nearly vertical). This requires arm adaptation and a different typing technique.

### Tenting Methods

#### Rubber Feet at Different Heights

The free, simplest approach. Replace standard flat bumpons with feet of varying heights.

- **3M SJ5302 bumpons**: Standard ~2mm self-adhesive feet. For slight tenting: 2mm outer edge, 8–10mm inner edge.
- **Adhesive rubber bumpers**: Available in different heights (2mm, 4mm, 6mm, 8mm) on Amazon
- **Bolt heads**: Some people screw bolts of different lengths into the case as feet

**How to do it:**
Place taller feet on the inner edge (toward center of your body) and shorter feet on the outer edge. The difference in height creates the tent angle. Math: for 10° over a 60mm half-width, the height difference is `60 × sin(10°) ≈ 10mm`.

**Cost:** $5–10 for a pack of assorted rubber feet on Amazon
**Angle:** Fixed once placed
**Best for:** People who want to try tenting before investing

---

#### 3D Printed Tenting Legs & Stands

Hundreds of community-designed tenting legs exist. Most clip or screw onto the case.

**Types:**
- **Fold-out legs**: Hinged legs that fold under the case, angle locked with friction or a screw
- **Adjustable angle stands**: Notched or ratcheted angle adjustment, 0°–45° range
- **Integrated tenting case**: The case itself has fixed-angle legs built in
- **Desk clamps**: Rare, but some designs clamp to a desk edge for extreme angles

**Finding designs:**
- Printables: https://www.printables.com/search/models?q=keyboard+tenting
- Thingiverse: https://www.thingiverse.com/search?q=keyboard+tenting

**Notable designs:**
- **Tenting Bracket for Corne/CRKBD** by various authors — search "crkbd tent" on Printables
- **Universal tenting puck clone** — open-source copies of the Splitkb tenting puck

---

#### Tenting Puck (splitkb.com)

The most polished commercial solution. A precision-machined disc that attaches to the case via screws and uses a standard 1/4"-20 camera mount thread.

- **How it works**: Attach puck to bottom of keyboard → screw any compatible ball head, gorillapod arm, or tripod into the 1/4-20 thread → infinite angle adjustment
- **Flexibility**: Flat to nearly vertical; also controls yaw (rotation) and position
- **Materials**: Aluminum disc with rubber bottom
- **Cost**: ~$40–50/pair from https://splitkb.com
- **Compatibility**: Requires M2 screws in specific positions — check your case compatibility

This is the option serious ergonomics enthusiasts use. Once you have the puck, you can try a ball-head mount (very adjustable, ~$15), a gorillapod (flexible positioning, ~$20), or a traditional tripod for standing desk use.

---

#### Vendor Tent Kits

Keyhive and Boardsource sell tenting accessories alongside their Corne kits. Usually simpler than the Splitkb puck — fixed or limited adjustment — but nicely matched to their cases.

---

#### DIY & Improvised Tenting

- **Cork sheet**: Cut strips, stack under the inner edge. Cheap, quiet, effective.
- **Books**: Tent literally one half on the edge of a book. Free.
- **Foam**: High-density foam cut to shape, glued under the case.
- **Keyboard risers**: Standard keyboard tilt legs adapted to split keyboards.

---

### Negative Tilt

**Negative tilt** means tilting the keyboard so the top of the keyboard (the far/function key row) is *lower* than the bottom (number/modifier row). This is the opposite of the traditional positive tilt most standard keyboards default to.

Why it matters ergonomically:
- Standard desks position your hands below elbow height. With positive tilt, your wrists extend upward (dorsiflexion) to reach the top row. With negative tilt, wrist extension is reduced.
- Combined with tenting, negative tilt + tent is the gold standard ergonomic configuration.
- Achievable with adjustable tenting stands by tilting "forward" instead of "up."

The Splitkb tenting puck + a ball head supports negative tilt natively — just adjust the angle beyond level.

---

## 3. OLED Covers & Acrylic Windows

Your Corne has OLED displays on both halves (if your build included them). The display is exposed by default — some cases protect it, frame it, or diffuse it for aesthetics.

### What the OLED Shows

Out of the box with ZMK, the OLED can show:
- Current layer name
- Modifier key status (Ctrl, Shift, Alt, GUI)
- Battery percentage (left half: main, right half: peripheral)
- WPM counter (with appropriate ZMK configuration)
- Custom logos/animations (with custom ZMK code)

### Case Options for OLEDs

**Standard acrylic sandwich with OLED cutout:**
The most common configuration. The top acrylic plate has a rectangular hole over the OLED. The display is visible but exposed. Fine for home use, risk of damage in travel.

**OLED window plate:**
A separate 1–2mm acrylic or polycarbonate piece cut to fit over the OLED hole. Acts as a protective cover. Some kits include these.

**Holographic/prism acrylic:**
Cut a piece of holographic acrylic (rainbow-diffracting, available on Amazon/AliExpress in sheets) to fit over the OLED window. The text shows through but with an iridescent border effect. Very distinctive look.

**No cover:**
Many people run their Corne OLED uncovered indefinitely with no issues. The OLED panel itself is quite robust — just avoid pressing hard objects onto it.

### Sourcing Acrylic Covers

- **Cut your own**: 1.5mm clear acrylic + a craft knife or scissors for simple rectangular covers
- **Laser cut to order**: Ponoko (ponoko.com), SendCutSend (sendcutsend.com) — upload SVG/DXF
- **Holographic film/acrylic**: Amazon search "holographic acrylic sheet" — $10–15 for a large sheet you'll cut from for years
- **From vendor**: Splitkb, Boardsource sometimes sell windowed top plates

---

## 4. Cables

Cables matter more on split keyboards than on standard keyboards because you have two connections to manage instead of one. Getting nice cables is a meaningful quality-of-life upgrade.

### USB-C Cables

Connects the "central" half (your left half, as configured in ZMK) to your computer. This is the only cable that goes to the computer.

**What to look for:**
- **USB-C to USB-C or USB-A to USB-C**: Depends on your computer ports
- **Length**: 1–1.5m is typical for desktop use. Too long = messy cables. Too short = limited placement.
- **Charging compatibility**: For nice!nano, you'll charge via the same USB-C port. Confirm the cable supports charging (all standard USB-C cables do, some charge-only cables omit data lines).
- **Build quality**: Braided nylon sleeves last much longer than rubber-coated cables

**Coiled cables:**

The keyboard community's obsession with coiled cables is real, and for good reason. A coiled cable:
- Retracts when not pulled (stays tidy)
- Has a pleasing spring resistance
- Stays off the desk surface
- Looks great in photos

Coiled cable anatomy:
```
[USB-C plug]──[aviator connector]~~[coil]~~[straight segment]──[USB-A or USB-C plug]
                     ↑
         Detachable connector, popular for
         clean desk routing
```

The **aviator connector** (also called a GX16 or aviation connector) is a detachable barrel connector mid-cable. You plug the short end into the keyboard, run the coil neatly, and leave the long end at the computer. Very clean aesthetic.

**Coiled cable vendors:**
| Vendor | Price Range | Notes |
|--------|------------|-------|
| Zap Cables (zapcables.com) | $35–60 | Many color options, fast lead time |
| Clark Kable (clarkkable.com) | $50–90 | Premium quality, paracord options |
| Mechcables (mechcables.com) | $40–75 | Custom configurator, good quality |
| Yoku Cables (yokucables.com) | $45–80 | Excellent build, clean connectors |
| AliExpress | $10–25 | Hit or miss quality, often decent for the price |

**Tip:** When buying a coiled cable, pick your keycap colorway first, then match the cable. A violet cable against purple/gray keycaps looks intentional. A random black cable with any set is fine but wastes an aesthetic opportunity.

**Straight cables:**
For those who don't care about the coil aesthetic, any quality braided USB-C cable works fine. Anker, Belkin, and Cable Matters make durable braided cables for $10–15. Tape the excess to the desk/monitor arm.

---

### TRRS Cables (Wired Split)

**Important for nice!nano users:** You do not need a TRRS cable. Your two halves communicate wirelessly over BLE. This section applies only if you build a wired version or if you have a Pro Micro-based Corne.

For reference (applicable to wired Corne builds):

**TRRS vs TRS:**
- **TRS** (Tip-Ring-Sleeve): Stereo audio connector. Two signals + ground.
- **TRRS** (Tip-Ring-Ring-Sleeve): Four-conductor. Two signals + two grounds. Required for split keyboard data.

Standard 3.5mm TRRS connectors are identical to headphone/microphone combo jacks. Any TRRS cable will work.

**What to buy:**
- Length: 20–40cm for desktop side-by-side placement. 50cm if you place the halves far apart.
- Any cheap TRRS cable works — the data signal is simple serial, not audio-grade.
- Coiled TRRS cables exist and look great matching a coiled USB-C cable.

**Sources:**
- Amazon: Search "TRRS cable 3.5mm" — $5–10
- Switchcraft makes premium TRRS cables for pro audio use — complete overkill, but they're bulletproof
- Coiled TRRS: Search "coiled aux cable" — same TRRS standard

---

## 5. Switches

Your Corne uses hotswap sockets — this is the single biggest gift a board can give you. No soldering to change switches. Pull the old switch out, press the new one in, done in seconds.

### Building a Switch Collection

Many enthusiasts treat switches like a collection. This sounds extravagant but is actually reasonable — a full set of 42 switches costs $20–50, and rotating between them gives you meaningfully different typing experiences tuned to context:

| Context | Recommended Switch Character |
|---------|------------------------------|
| Late night, others sleeping | Silent linear (Gateron Silent Yellow, Boba U4) |
| Open office | Silent tactile (Boba U4, Topre-like Runt tactile) |
| Home office, alone | Tactile (Holy Pandas, Boba U4T, Akko CS Jelly Pom) |
| Creative work (feels good to type) | Clicky (Gateron G Pro Blue, Kailh Box Jade) |
| Gaming | Light linear (Gateron Yellow, Akko CS Silver) |

**How to swap without tools:** Hotswap sockets only need finger force. However, a **switch puller** (a small wire tool) makes it much easier — $3–5 on Amazon, comes with most switch testers.

**Switch testing before buying 42:**
- **Switch testers**: Sample boards with 4–70 switches in different stems/springs. $15–40. Lets you feel switches before committing to 42.
- **NovelKeys tester** (novelkeys.com): Carries well-curated testers
- **KBDfans tester**: Popular, many options

See `switches-research.md` for full deep-dive on switch types, stems, springs, and lubing.

---

## 6. Keycap Sets

The Corne's 42-key layout gives you a unique advantage in keycap shopping: you need far fewer keys than anyone else, so you have options others don't.

### Why 42 Keys Changes the Shopping Math

- A standard 104-key set comes with ~130+ keys. You need 42.
- This means 88+ "spare" keys. Enthusiasts use the spares to mix and match colors.
- Budget sets that "only" cover base layout alphas often still cover everything you need.
- You can run a keycap set that's "incomplete" by standard-keyboard standards but perfect for Corne.

### Keycap Profiles on Corne

The Corne's column-staggered layout means the keys are not all at the same angle from your fingers. Uniform-height profiles work best.

**Recommended profiles:**
| Profile | Type | Corne Rating | Notes |
|---------|------|-------------|-------|
| DSA | Uniform | ★★★★★ | Spherical, same height in all rows. Perfect. |
| XDA | Uniform | ★★★★★ | Slightly taller than DSA, also spherical. Excellent. |
| MT3 | Sculpted (deep dish) | ★★★★☆ | Normally sculpted but many sets are uniform |
| MDA | Uniform | ★★★★☆ | Similar to XDA. Less common. |
| OEM | Sculpted | ★★★☆☆ | Can work but row heights vary — use same-row keys |
| Cherry | Sculpted | ★★★☆☆ | Same caveat as OEM |
| SA | Sculpted (tall) | ★★★☆☆ | Can work, but tall and heavy; uniform SA exists |

See `keys-research.md` for full profile deep-dive with diagrams.

### Buying Strategy for Corne

**Blanks:** A popular option for 40% keyboard users who have their layouts memorized. Blank DSA or XDA keycaps look incredibly clean and force you to internalize your layout. PBT blanks in your color of choice are $15–25 for a full set.

**Multiple sets for mixing:**
- Buy a base set and a modifier set in a contrasting color
- Run home row mods (A/S/D/F) in a different color from regular alphas
- Run thumb cluster keys in accent color

**Where to shop:**
- Drop (drop.com): Best selection of enthusiast sets; group buys and in-stock
- NovelKeys (novelkeys.com): Carries many sets, faster shipping within US
- KBDfans (kbdfans.com): Wide selection, competitive pricing, China warehouse
- Cannonkeys (cannonkeys.com): Boutique sets, well-curated

---

## 7. Stabilizers

**The Corne does not use stabilizers. Skip this entirely.**

Stabilizers (stabs) are used on keys wider than 1u (spacebar, shift, backspace, enter). The Corne uses exclusively 1u keys — all 42 of them. There is nothing to stabilize.

This is actually a feature: no stab rattle, no stab tuning, no lube-the-stabs ritual. One less thing to worry about.

---

## 8. Desk Mats

A large desk mat (extended mousepad) under your entire keyboard setup solves several problems at once:

**What it does:**
- Prevents keyboard halves from sliding during typing
- Dampens the sound that transfers from switches → keyboard → hard desk surface (desk resonance is a significant component of keyboard sound)
- Protects your desk surface from scratches
- Unifies the aesthetic of your desk — two keyboard halves on matching material look intentional

**Size recommendations:**
- For split keyboards with the halves spread apart: **900mm × 400mm** minimum
- Comfortable with screen + split + mouse: **1200mm × 400mm** (the "XL" standard)
- Desk coverage: **1400–1800mm** for full desk coverage

**Thickness:**
- 2–3mm: Standard, good for most. Firm enough to type on, enough dampening.
- 4–5mm: Noticeably softer under wrists. Some people love this, others find it unstable.

**Materials:**
- **Cloth top, rubber bottom**: Standard. Smooth or textured cloth surface. Best for mouse tracking.
- **Leather/synthetic leather top**: Looks premium, very smooth, some people hate the feel.
- **Microfiber**: Soft, comfortable, slightly different mouse tracking.

**Vendors:**
| Vendor | Specialty | Price |
|--------|-----------|-------|
| Zap Cables (zapcables.com) | Custom designs, keyboard community | $30–60 |
| Hiney (hiney.io) | Premium, community designs | $40–80 |
| Grovemade (grovemade.com) | Premium, desk-matching aesthetics | $60–120 |
| Glorious (pcgaming.com) | Budget to mid-range, large sizes | $20–50 |
| Amazon basics | Cheap, functional, no character | $10–20 |
| Custom on Artisan Keycaps | Commission custom mat art | $50–100+ |

---

## 9. Wrist Rests

Wrist rests are a nuanced topic. The ergonomics community is divided on their benefit.

### The Ergonomics Debate

**The case for wrist rests:**
- Provides a comfortable place to rest during pauses in typing
- Reduces wrist extension angle if placed correctly
- Comfortable for many people

**The case against:**
- The carpal tunnel is on the underside of the wrist. Resting weight on a hard edge compresses it.
- Resting while typing (vs. resting during pauses) encourages awkward wrist angles.
- Some ergonomists argue wrists should hover while actively typing, with rest only during pauses.

**The consensus:** Use wrist rests for **resting between bursts of typing**, not for support while fingers are actively moving. With that framing, a good wrist rest helps.

### Types for Split Keyboards

**Two small wrist rests (one per half):**
The natural configuration for a split keyboard. Place one under each half. Allows you to position each independently.

- Best approach: match the width and height of your keyboard halves
- The Corne is compact — a 4"×3" or 5"×4" wrist rest per half is plenty

**One long wrist rest:**
A single wide rest that spans the gap. Works if you keep your halves in a fixed position. Less flexible.

### Materials

| Material | Feel | Durability | Notes |
|----------|------|-----------|-------|
| Memory foam + fabric | Soft, conforms | 1–3 years (foam compresses) | Most common, comfortable |
| Solid wood | Firm, warm | Indefinite | Grovemade favorite; looks incredible |
| Leather-wrapped wood | Firm with texture | Long | Premium feel |
| Silicone gel | Cool, slightly squishy | Long | Good for warm climates |
| Cork | Medium-firm, natural | Good | Eco-friendly, matches many aesthetics |

### Vendors

| Vendor | Notable Products | Price |
|--------|-----------------|-------|
| Grovemade (grovemade.com) | Walnut and maple wood rests | $50–90/pair |
| Glorious (pcgaming.com) | Memory foam, polyleather cover | $20–35 |
| Drop (drop.com) | Various, including collab designs | $25–60 |
| Deltahub (deltahub.io) | Desk Pad + Carpio wrist support | $30–50 |
| Kinesis | Gel wrist rests for split keyboards | $25–40 |
| Amazon generics | Budget options, highly variable quality | $10–20 |

**Tip:** For the Corne specifically, look for "keyboard wrist rests for 40%" or measure your half's footprint and get a custom-sized piece of memory foam from a fabric store, then wrap it in fabric.

---

## 10. Carrying Cases & Travel

The Corne is genuinely portable — two small halves, a short USB-C cable, and you're carrying a world-class keyboard in a jacket pocket. Protect it in transit.

### Options

**Hard-shell cases:**
- **Pelican 1010 or 1050**: Waterproof, crushproof, military-spec cases. Add custom foam inserts.
  - One Pelican 1050 (or equivalent) can fit one Corne half perfectly.
  - Order two for a matching pair.
  - Cost: $20–30 each from Pelican (pelican.com) or Amazon
  - Cut foam to shape using the keyboard as a template

- **Generic hard EVA cases**: Amazon has endless options for small electronics — search "small electronics hard case" or "SD card case" sizes. Many fit Corne halves with foam packing.

**Keyboard-specific bags:**
- Many 60% keyboard carrying cases (for boards like the Anne Pro or Vortex Race) are slightly oversized for a single Corne half. Pack both halves with padding.
- Vendors: Glorious, KBDfans carry keyboard bags

**Soft pouches:**
- A glasses case or small padded pouch per half works for low-risk transit (bag in a backpack, not checked luggage).
- Velvet/microfiber pouches protect against scratches. Not crushproof.

**3D printed travel stands:**
- Print a small kickstand that props the keyboard halves at a comfortable angle at a café or meeting room
- Search "keyboard stand" on Printables — many compact designs fold flat for travel

### Tips for Travel

- Disconnect any cables and coil carefully before packing
- Remove keycaps if traveling by air (pressure changes theoretically fine; mostly to prevent keycap loss if case opens)
- Battery: nice!nano batteries are LiPo — technically airline-regulated at >100Wh, but at 100–300mAh they're far below limits. No practical restriction.
- A small USB-C cable (0.5–1m, coiled) is worth having in your travel bag permanently

---

## 11. Batteries (nice!nano Builds)

Your Corne runs on nice!nano v2 controllers, each powered by a LiPo (lithium polymer) battery. Managing batteries well extends the life of your keyboard and keeps it safe.

### Battery Sizing

LiPo batteries for keyboards use a 4-digit code: first two digits = thickness in tenths of mm, last four = dimensions in mm (width × height).

Common sizes used in Corne/nice!nano builds:

| Part Number | Dimensions (mm) | Capacity | Thickness | Fit Notes |
|-------------|----------------|----------|-----------|-----------|
| 301230 | 3.0 × 12 × 30 | ~100–110mAh | Very thin | Fits under low-profile cases easily |
| 401230 | 4.0 × 12 × 30 | ~150mAh | Thin | Good balance of capacity and fit |
| 401535 | 4.0 × 15 × 35 | ~200mAh | Thin | Slightly wider |
| 502030 | 5.0 × 20 × 30 | ~250mAh | Medium | Good capacity for standard cases |
| 602530 | 6.0 × 25 × 30 | ~400mAh | Thicker | Requires taller case/standoffs |

**Practical battery life estimates:**
- 100mAh: 1–3 weeks typical use (OLED on, BLE active)
- 250mAh: 4–8 weeks
- 400mAh+: 2–4 months

ZMK's power management aggressively sleeps the keyboard after inactivity, so larger batteries give dramatically extended real-world life. The controller itself draws only ~0.5mA in deep sleep.

### Where to Buy

| Source | Quality | Notes |
|--------|---------|-------|
| Adafruit (adafruit.com) | High | Reputable supplier, UL-certified cells |
| Splitkb (splitkb.com) | High | Ships from EU, pre-sized for split keyboards |
| Typeractive (typeractive.xyz) | High | Carries nice!nano compatible batteries |
| Amazon | Variable | Buy from established sellers; check reviews carefully |
| AliExpress | Variable | Capacity often exaggerated; buy from sellers with many reviews |

**Recommended starting point:** 301230 or 401230 from Adafruit or Splitkb. They're confirmed to fit the standard Corne acrylic sandwich case profile.

### LiPo Safety

LiPo batteries are energy-dense and, if mishandled, can vent, catch fire, or in rare cases explode. The risk is real but manageable:

**Do:**
- Store at partial charge (~50%) if not using for weeks
- Charge at room temperature (15–25°C / 60–77°F)
- Use only the nice!nano's onboard charging circuit — never external chargers on bare cells
- Dispose of swollen (puffy) batteries immediately — do not use; take to electronics recycling

**Never:**
- Puncture a LiPo battery (ever, for any reason)
- Bend a LiPo battery more than a few degrees
- Charge in a hot environment or in direct sunlight
- Charge unattended overnight repeatedly (occasional is fine; a habit is risky)
- Short-circuit the leads — tape over exposed terminals before discarding

**Storage:** A small fireproof LiPo bag ($8–15 on Amazon) lets you store spare batteries safely. Used by RC car enthusiasts; total overkill for keyboard batteries but cheap peace of mind.

---

## 12. Sound Modding

Sound is a huge part of the keyboard hobby. The Corne's small acrylic case can sound hollow and clacky without modification. These mods progressively improve the sound profile — from cheap to involved.

### The Sound Stack

Understanding what contributes to keyboard sound helps you know which mods matter:

```
Finger impact
     ↓
Keycap resonance   ← Keycap material (PBT vs ABS), profile (thick vs thin)
     ↓
Switch sound       ← Switch type, lube, films
     ↓
Plate resonance    ← Plate material (acrylic vs aluminum vs FR4 vs polycarbonate)
     ↓
PCB resonance      ← PCB thickness, FR4 vs flex cuts
     ↓
Case resonance     ← Case material, case foam
     ↓
Desk surface       ← Desk mat, desk material
```

Most mods target one layer. The best results come from addressing multiple layers.

---

### Case Foam

**What it does:** Fills the air gap inside the case bottom, eliminating the hollow resonance that acrylic cases produce.

**How to do it:**
1. Disassemble the case (remove M2 screws, lift PCB)
2. Cut a piece of craft foam (EVA foam, ~3–5mm) or Poron foam to match the case interior
3. Place it in the bottom of the case
4. Reassemble

**Material options:**
- **EVA foam** (craft store foam sheets): $3–5 for a pack. Works well.
- **Poron foam**: Better, more consistent density. Buy from mechanical keyboard vendors ($10–20 per sheet).
- **Sorbothane**: Very dense, absorbs vibration extremely well. Overkill but excellent. $20+.
- **Memory foam**: Can work in a pinch. Less consistent than Poron.

**Effect:** Transforms hollow, ringy sound to a muted, solid thud. One of the highest-impact mods for acrylic cases.

---

### PCB Foam

Foam between the PCB and bottom case plate. Addresses PCB-level resonance separately from case resonance.

**How:** Cut foam to PCB outline, cut holes for components (USB-C port, battery header, hotswap sockets on underside). Place under PCB before reassembling.

**Material:** 1–2mm Poron or EVA foam. Thinner than case foam to avoid compressing components.

**Effect:** Additional dampening, particularly for bottom-out sound that travels into the PCB.

---

### Tape Mod

Extremely popular, completely free, reversible. Multiple layers of painter's tape applied to the back of the PCB.

**How:**
1. Remove PCB from case
2. Apply 2–4 layers of standard painter's tape (Scotch Blue or equivalent) to the back of the PCB
3. Reassemble

**Effect:** Significantly changes the sound character — reduces the high "clack" frequency, adds a subtle warmth and cushion to the keypress feel. Works especially well with acrylic cases.

**Cost:** $0 (use tape you have). Painter's tape only — don't use packing tape (too stiff) or masking tape (similar but inconsistent).

---

### PE Foam Mod

Thin polyethylene foam placed between the switch and the PCB (inside the hotswap socket layer).

**How:**
1. Remove all switches (pull with switch puller)
2. Cut thin PE foam (0.5–1mm) to PCB dimensions
3. Punch or poke holes at each switch position (aligned with switch pins and hotswap sockets)
4. Lay foam over PCB, insert switches through the holes
5. Reinstall switches

**Effect:** Dramatically changes sound — adds a unique "poppy" or "thocky" character depending on switches. Very popular currently in the enthusiast community. Some people love it, some find it changes the feel too much.

**Cost:** Polyethylene foam sheets: $5–10 on Amazon. Search "PE foam 0.5mm sheet."

**Caution:** Aligning the holes with 42 positions is tedious. Use a template or print a guide. Misaligned holes can damage hotswap socket pins.

---

### Tempest Mod

A piece of paper (literally: standard printer paper) placed under the PCB inside the case. Similar in concept to tape mod but for the bottom plate.

**Effect:** Subtle dampening of the plate resonance. Less impactful than tape mod but stackable with it.

**Cost:** Free.

---

### Switch Films

Thin mylar (or POM, or silicone) films that fit between the top housing and bottom housing of a switch. Fill the manufacturing tolerance gap between the two halves.

**What they address:** Switch wobble. Most switches have slight play between top and bottom housing. Films eliminate this, tightening the tolerance and changing how sound transfers.

**Effect:** Makes switches sound and feel more consistent. Reduces the "scratchy" feeling in lower-budget switches. Often combined with lubing.

**How:** Open each switch (requires a switch opener tool, $5–10), place film over bottom housing, close switch. Repeat for all 42. Yes, 42 times.

**Sources:**
- TX Films (from TX Keyboards): Most popular, multiple thicknesses
- Deskeys Films: Alternative option
- KBDfans carries both
- ~$5–10 for a pack of 110 (enough for your 42 with spares)

---

### Lubing

The most impactful single mod for switch feel and sound. Lubricant applied to switch internals reduces friction between moving parts.

**Lubricants:**
| Lube | Best For | Viscosity | Notes |
|------|----------|-----------|-------|
| Krytox 205g0 | Linear switches | Thick | Industry standard for linears. Do NOT use on tactiles — kills the bump. |
| Tribosys 3203 | Tactile switches | Thin | Light lube that preserves tactile bump |
| Tribosys 3204 | Tactile or linear | Medium | Good all-rounder; slightly heavier than 3203 |
| Krytox 105 oil | Springs | Liquid | Eliminates spring ping (metallic twang) |
| Superlube 51010 | Budget option | Thick | PTFE-based, similar to 205g0, much cheaper |
| Dielectric grease | Stabilizer stems | Very thick | NOT for switches. Used on stabs (which Corne doesn't have). |

**What to lube on each switch:**
```
Switch internals:
  Stem legs (rails that slide in housing) → lube
  Stem pole (the center post) → NO (affects tactile bump) for tactiles
  Housing rails → lube
  Spring → bag lube or paint with oil
  Top housing (inside, where stem top travels) → skip for tactiles, light for linears
```

**Tools:**
- Small paint brushes (0 or 00 size) for stem and housing
- Switch opener ($5–10)
- Lube station (small tray that holds stems) — or improvise with tape
- Tweezers

**Time investment:** ~3–5 minutes per switch × 42 switches = 2–4 hours. Meditative once you get a rhythm. Put on a long podcast.

**Vendors:**
- NovelKeys (novelkeys.com): Best selection, good prices
- Switcharound (switcharound.co): Specialist lubricant vendor
- KBDfans (kbdfans.com): Competitive pricing

---

## 13. Trackball & Trackpad Mods

Your Layer 6 (MOUSE) provides mouse emulation via ZMK's pointing module, but hardware pointing devices alongside the keyboard offer native precision.

### Ploopy Nano Trackball

The Ploopy Nano (ploopy.co) is an open-source trackball designed to be placed beside a keyboard. It connects via USB and works as a standard HID device.

- **Size**: Tiny — designed to nestle against a keyboard half
- **Cost**: ~$35 kit, ~$55 assembled
- **Ball size**: 34mm standard billiard ball (replaceable with any 34mm ball)
- **Open source**: Hardware and firmware fully open, community modifications common
- **QMK-compatible**: The Ploopy Nano runs QMK; if you want trackball control from ZMK layer switching, it requires separate config

**Placement with Corne:**
Place the Ploopy Nano on the right side of the right half, or in the space between halves. Your right thumb manages it while fingers stay on home row — similar motion to a mouse but without lifting your hand.

### Integrated Trackball Mods (Advanced)

Community members have replaced corner switch positions on split keyboards with Pixart PMW3360 or PMW3389 optical sensors, adding a direct trackball to the keyboard PCB.

The Corne PCB doesn't natively support this, but:
- Hand-wired modifications exist on community forums
- Some Corne-adjacent boards (like the Charybdis from Bastard Keyboards: bastardkb.com) include integrated trackball as a design feature
- The Charybdis is spiritually close to the Corne — similar column stagger, split design, hotswap — but with an integrated PMW3610 trackball

**ZMK + Trackball:**
ZMK's pointing module supports mouse position reports from external sensors. If you're considering building a trackball-equipped split board, ZMK can handle it with the right driver config.

### Cirque Trackpad

Cirque makes circular and rectangular trackpad modules (40mm GlidePoint) used in some split keyboard builds. Soft-pressing the surface registers click. Can be mounted in thumb cluster area.

- Available from Mouser, DigiKey: search "Cirque GlidePoint"
- Community firmware support exists for both QMK and ZMK
- Requires SPI or I2C connection — typically a handwired modification

---

## 14. RGB Upgrades

Your Corne may have underglow LEDs (SK6812MINI-E or WS2812B on the PCB underside) and possibly per-key LEDs. RGB is a surprisingly deep rabbit hole.

### Underglow LEDs

Underglow LEDs face downward from the PCB, illuminating the desk surface and the sides of the case. The effect depends heavily on case material:

| Case Material | Underglow Effect |
|---------------|-----------------|
| Clear acrylic | Bright, distinct LEDs visible. Very vivid. |
| Frosted acrylic | Soft, diffused glow. Halo effect on desk. Beautiful. |
| White acrylic | Maximally diffused. Almost like a light panel. |
| Colored acrylic | Color mixing effect. Green LEDs through blue acrylic → teal. |
| Black acrylic | No underglow through case, only bleeds to sides and desk below. |
| Aluminum | No underglow visible through case. Desk glow only. |

**White diffuser layer:**
Adding a thin white acrylic layer between the PCB and the transparent case layers creates a diffusion effect — harsh point-source LEDs become a smooth glow. Laser-cut from 2mm white acrylic.

**LED strips (external):**
Some builders add adhesive RGB LED strips (WS2812B or similar) to the outside of the case or underneath for a "floating" glow effect. These connect to a separate controller (Arduino Nano, etc.) or the nice!nano's GPIO pins with appropriate firmware support.

### Per-Key RGB

If your Corne PCB has per-key RGB LEDs (typically WS2812B or SK6812MINI-E beneath each switch, shining through the switch housing and keycap legend):

- This requires switches with transparent or translucent housing bottoms
- Requires keycaps with legends or transparent legends
- ZMK supports per-key RGB with appropriate LED driver configuration
- Shine-through keycap sets: Glorious GPBT, HyperX Pudding, Akko keycaps — many options
- The effect through a split keyboard is stunning if aligned correctly

### RGB-Aware Keycap Choices

For underglow only (most common Corne setup): any keycap works, the light is underneath.
For per-key shine-through: you need specifically shine-through keycaps with translucent legends or fully clear caps.

---

## 15. Where to Shop

Consolidated shopping reference for the Corne keyboard ecosystem.

### Primary Vendors

| What You're Buying | Best Sources | Notes |
|-------------------|-------------|-------|
| **Corne kits** (PCB, plate, hardware) | Keyhive (keyhive.xyz), Boardsource (boardsource.xyz), 42keebs (42keebs.eu), Little Keyboards (littlekeyboards.com) | 42keebs is European, good for EU buyers. All sell similar kits. |
| **nice!nano v2 controllers** | nicekeyboards.com (official), Splitkb (splitkb.com), Typeractive (typeractive.xyz) | Buy from official or reputable resellers — counterfeits exist |
| **Mechanical switches** | NovelKeys (novelkeys.com), KBDfans (kbdfans.com), Divinikey (divinikey.com), Cannonkeys (cannonkeys.com) | NovelKeys best for US; KBDfans has broadest selection |
| **Keycap sets** | Drop (drop.com), NovelKeys, KBDfans, Cannonkeys, Milkyway Keys | Drop for group buys; others for in-stock |
| **Coiled USB-C cables** | Zap Cables (zapcables.com), Clark Kable (clarkkable.com), Mechcables (mechcables.com), Yoku Cables (yokucables.com) | All do custom colors; Zap is fastest |
| **Cases (acrylic/aluminum)** | Keyhive, 42keebs, Boardsource | Often bundled with kits |
| **3D printed cases (STL files)** | Printables (printables.com), Thingiverse (thingiverse.com) | Search "crkbd" or "corne" |
| **Print service (no printer)** | JLCPCB (jlcpcb.com), Craftcloud (craftcloud3d.com) | JLCPCB is cheapest for simple FDM |
| **Tenting puck** | Splitkb (splitkb.com) | Also sells Corne kits and accessories |
| **Desk mats** | Zap Cables, Hiney (hiney.io), Grovemade (grovemade.com) | Zap often has keyboard-themed designs |
| **Lube + switch tools** | NovelKeys, Switcharound (switcharound.co), KBDfans | Switcharound specializes in lubing supplies |
| **LiPo batteries** | Adafruit (adafruit.com), Splitkb, Typeractive | Adafruit most reputable; Splitkb convenient |
| **Wrist rests** | Grovemade (wood), Glorious (foam), Deltahub, Drop | Grovemade for premium; Glorious for budget |
| **Switch films** | TX Keyboards, KBDfans, NovelKeys | TX Films most popular |
| **Ploopy Nano trackball** | ploopy.co | Kit or assembled |
| **Charybdis (trackball Corne-like)** | Bastard Keyboards (bastardkb.com) | If you want integrated trackball |

### Community Resources

| Resource | URL | What It's For |
|----------|-----|---------------|
| r/MechanicalKeyboards | reddit.com/r/MechanicalKeyboards | Main community, market, reviews |
| r/ErgoMechKeyboards | reddit.com/r/ErgoMechKeyboards | Split/ergonomic specific |
| r/crkbd | reddit.com/r/crkbd | Corne-specific builds and help |
| Geekhack | geekhack.org | Group buy announcements, interest checks |
| Keyboard University | keyboard.university | Beginner-friendly reference wiki |
| Corne GitHub | github.com/foostan/crkbd | Official design files, PCB sources |
| ZMK Docs | zmk.dev | Firmware documentation |
| MechMap | mechmap.info | Find local vendors by region |

### Budget Breakdown

A realistic budget for common accessory purchases after your initial build:

| Level | What You Get | Budget |
|-------|-------------|--------|
| **Free** | Tape mod, improvised tenting with books/cork | $0 |
| **Starter ($30–50)** | Rubber feet variety pack, painter's tape mod, desk mat (generic) | $30–50 |
| **Enthusiast ($100–150)** | Coiled USB-C cable, decent desk mat, switch lube kit, one extra switch set | $100–150 |
| **Committed ($200–350)** | Tenting puck or adjustable stand, premium wrist rest, second keycap set, carrying case | $200–350 |
| **Deep End ($400+)** | Aluminum case, premium cables, trackball, multiple switch sets, large desk mat, custom mods | $400–$∞ |

---

## Quick-Reference: Upgrade Priority Order

If you're starting from a stock Corne kit build and want to know what to buy first:

1. **Desk mat** — immediate ergonomic and aesthetic improvement, relatively cheap
2. **Tenting** — start free (books/cork), then invest in adjustable solution once you know your preferred angle
3. **Tape mod + case foam** — free to $10, massive sound improvement on acrylic case
4. **Coiled USB-C cable** — aesthetics + quality-of-life, $35–60
5. **Switch lube** — transforms the feel, $30 in supplies for a much nicer typing experience
6. **Second switch set** — enables context-based switch swapping, $20–40
7. **Wrist rest pair** — comfort for long sessions, $20–100
8. **Case upgrade** — if you want a premium look/feel, $40–200
9. **Tenting puck** — if you're serious about ergonomics and settled on a tent angle
10. **Trackball** — if MOUSE layer emulation isn't quite cutting it for pointer precision

The keyboard hobby has no finish line. Every component is upgradeable, every choice reversible. That's exactly the point.
