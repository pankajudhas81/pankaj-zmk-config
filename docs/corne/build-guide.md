# Corne Keyboard Build Guide

> **Who this is for:** You already have a working Corne (nice!nano v2, ZMK, wireless). This guide exists so you can build a second one, gift one to a friend, or deeply understand what's inside the keyboard sitting in front of you right now.

The Corne (crkbd) is one of the most-built custom keyboards in the world — not because it's easy to build, but because the payoff is proportional to the effort. You learn soldering, firmware, and ergonomics all at once. This guide covers the full build: from empty PCBs to a flashed, cased, wireless keyboard.

---

## Table of Contents

1. [Why Build Instead of Buy?](#why-build-instead-of-buy)
2. [Complete Parts List](#complete-parts-list)
3. [Tools](#tools)
4. [Build Order](#build-order)
   - [Step 1 — Diodes](#step-1--diodes-smd)
   - [Step 2 — Hotswap Sockets](#step-2--hotswap-sockets)
   - [Step 3 — RGB LEDs (optional)](#step-3--rgb-leds-optional)
   - [Step 4 — TRRS Jacks and Reset Buttons](#step-4--trrs-jacks-and-reset-buttons)
   - [Step 5 — Controller Sockets (Mill-Max)](#step-5--controller-sockets-mill-max)
   - [Step 6 — OLED Pin Headers](#step-6--oled-pin-headers)
   - [Step 7 — Flash Firmware Before Casing](#step-7--flash-firmware-before-casing)
   - [Step 8 — Install Switches](#step-8--install-switches)
   - [Step 9 — Case Assembly](#step-9--case-assembly)
5. [Battery Wiring (nice!nano)](#battery-wiring-nicenano)
6. [Wireless Setup and Pairing (ZMK)](#wireless-setup-and-pairing-zmk)
7. [Testing Every Key](#testing-every-key)
8. [Common Build Mistakes (and How to Fix Them)](#common-build-mistakes-and-how-to-fix-them)
9. [Soldering Primer](#soldering-primer)
10. [Cost Breakdown](#cost-breakdown)
11. [Where to Buy](#where-to-buy)
12. [Build Resources and Community](#build-resources-and-community)

---

## Why Build Instead of Buy?

You can't buy a Corne pre-assembled (at least not with the controller and options you want). That's the point. The custom keyboard hobby is fundamentally DIY — the design is open source, foostan released all the PCB schematics and firmware freely, and the community built everything else around it.

**What you get from a hand-built keyboard:**

- You know exactly what's inside it. When something breaks, you fix it.
- You choose every component: switches, stabilizers, controller, case material, LEDs.
- The process itself is valuable — you'll come out knowing how to solder SMD components, flash microcontrollers, and troubleshoot electronics.
- It's genuinely more satisfying to type on something you assembled.

**What it costs you:**

- 4–8 hours for a first build (longer if mistakes are made).
- ~$100–200 depending on your component choices.
- One afternoon of close attention and patience.

A second build takes about 2 hours. The skills compound.

---

## Complete Parts List

### PCB and Core Components

| Component | Qty | Notes | Approx. Cost |
|-----------|-----|-------|-------------|
| Corne v3 PCB kit | 1 kit (2 PCBs) | Left + right halves | $20–40 |
| Microcontrollers | 2× | **nice!nano v2** for ZMK wireless; Pro Micro for wired QMK | $25 each (nice!nano) |
| Diodes 1N4148W SOD-123 | 42 + spares | SMD, tiny. Buy 100 — they're $3 and you will lose some | $3–5 |
| Kailh hotswap sockets | 42× | MX or Choc depending on your switches. Strongly recommended | $5–8 |
| Mill-Max 315 sockets | 48× (2× 24-pin strips) | Makes controllers hot-swappable. 24 pins per controller × 2 halves | $8–12 |
| Mill-Max pins | 48× | Used to bridge controller to socket (solder to controller, press into socket) | $3–5 |
| Reset buttons | 2× | 3×6mm or 4×4mm tactile switch | $1–2 |
| TRRS jacks | 2× PJ-320A | Only needed if running wired between halves (QMK). Skip for wireless ZMK | $1–2 |
| LiPo batteries | 2× | **301230** (~110mAh, fits under nice!nano) or **401230** (~150mAh, slightly thicker) | $8–15 |
| OLED displays (optional) | 2× | 0.91" 128×32 SSD1306 I2C. Check that VCC/GND are in the right pin order | $5–10 |
| OLED pin headers | 2 sets | Low-profile female socket headers, 4-pin | $2–4 |
| RGB LEDs (optional) | 42× | SK6812MINI-E. Per-key underglow. Hard to solder, heat-sensitive | $8–15 |

> **nice!nano v2 vs. Pro Micro:** You have nice!nano v2. These are the superior choice for Corne if you want wireless. They're nRF52840-based (Bluetooth 5.0), have onboard LiPo charging, and run ZMK. Pro Micro is cheaper and wired-only — used with QMK.

### Switches and Keycaps

| Component | Notes |
|-----------|-------|
| 42 switches | MX-style (Cherry, Gateron, Boba, etc.) or low-profile Choc (Kailh). MX is more common and has more keycap options. |
| 42 keycaps | Must be compatible with your switches. For a 40% board you'll need 1u keycaps for every key except thumbs. |

> **MX vs. Choc:** Choc switches are flatter and feel snappier but have very limited keycap availability. MX has thousands of keycap options and is the default choice for most first builds.

### Case Options

| Type | Pros | Cons | Cost |
|------|------|------|------|
| Acrylic sandwich kit | Included in most kits. Clear or frosted layers look great with RGB. | Scratches easily. Less premium feel. | $0–15 (often included) |
| 3D printed case | Fully custom shape, any filament. Many files on [Printables](https://www.printables.com) and [Thingiverse](https://www.thingiverse.com). | Requires access to a printer. Layer lines visible unless sanded. | $5–20 in filament |
| Aluminum CNC case | Premium feel, excellent sound. | Expensive, limits LED visibility. | $50–150 |
| FR4 plate | PCB-material top plate. Stiff, good for sound. | Less flex than polycarbonate. | $10–20 |

### Hardware (usually included in kits)

- M2 screws (6mm and 10mm lengths)
- M2 brass standoffs (varies by case thickness)
- Rubber feet / bumpons

---

## Tools

### Required

| Tool | Why | Recommended |
|------|-----|-------------|
| Soldering iron | Everything. You'll be doing SMD and through-hole work. | Hakko FX-888D ($100), Pinecil ($25), TS101 ($30) |
| Solder | The material that makes joints | 63/37 tin-lead rosin core, 0.6mm diameter. Kester 63/37 is the gold standard. |
| Tweezers | Placing and holding SMD diodes (they're 2mm long) | Stainless, fine-tip, angled. ESD-safe preferred. |
| Flux pen | Makes solder flow cleanly onto pads | No-clean flux pen (Kester 186 or equivalent). No-clean means you don't *have* to remove it. |
| IPA 90%+ | Cleaning flux residue after soldering | 91% isopropyl from a pharmacy works fine |
| Solder wick | Removing solder from mistakes | 1.5mm or 2mm width Chemwick or equivalent |
| Solder pump (solder sucker) | Clearing through-holes filled with solder | Engineer SS-02 is widely praised |

### Strongly Recommended

| Tool | Why |
|------|-----|
| PCB holder / helping hands | Holds the PCB steady while you work both hands |
| Multimeter | Continuity testing — verify diodes are oriented correctly before moving on |
| Brass wire tip cleaner | Keeps iron tip clean without thermal shock (vs. wet sponge) |
| Fine-tip cotton swabs | Cleaning tight spots with IPA |

### Iron Temperature Guide

| Task | Temperature |
|------|------------|
| SMD diodes (1N4148W) | 320–340°C |
| Hotswap sockets | 330–350°C |
| RGB LEDs (SK6812MINI-E) | 300–310°C (heat-sensitive!) |
| Through-hole (TRRS, reset) | 330–360°C |
| Mill-Max sockets | 330–350°C |
| Controller pins | 300–320°C |

> **Lead-free solder requires ~30°C higher temperatures** than 63/37. If you're using lead-free, bump everything up 20–30°C. 63/37 tin-lead is easier to work with, has better flow, and is the recommendation for first builds (wash your hands after handling).

---

## Build Order

Order matters. SMD components go before through-hole. Firmware goes before case. Switches go last. Doing things out of order is the number one source of beginner frustration.

```
Diodes → Hotswap sockets → RGB LEDs → TRRS/Reset → Mill-Max sockets
→ OLED headers → FLASH FIRMWARE → Switches → Case assembly
```

### Step 1 — Diodes (SMD)

**This is the hardest step. Do it first while you're fresh.**

Diodes are polarized — they only let current flow one way. Install them backwards and that key won't register. Identify orientation before touching the iron.

**The SOD-123 diode:**

```
   ┌─────────┐
───┤  1N4148W├─── cathode (line/band)
   └─────────┘
     anode
```

The PCB has two pads for each diode position. One pad is **square** (cathode/line side) and one is **round** (anode side). The line on the diode must go to the square pad.

```
PCB markings:
  ○ ——[=|>|=]—— □
  round        square
  (anode)      (cathode = stripe side)
```

**SMD soldering technique — "tack and solder":**

1. Add a small blob of solder to the **square pad** (cathode side) using just the iron tip and a tiny amount of solder. This is called "tinning" the pad.
2. With tweezers in your non-dominant hand, pick up one diode. Orient it with the line (cathode) toward the square pad.
3. Reheat the tinned pad with your iron while pressing the diode gently into it with tweezers. The solder will reflow and grab the diode.
4. Let cool 2–3 seconds, then solder the other (round) pad normally.
5. The joint should be shiny, slightly concave, with no cold spots or bridges.

**Pace:** Do all 42 diodes per PCB before moving on. Get into a rhythm. Check orientation twice before reflowing.

**Verification:** Use a multimeter in diode-test mode (the diode symbol). Touch probes to both pads. You should get a reading in one direction and no reading in the other. A reading in both directions = solder bridge. No reading in either direction = cold joint or wrong orientation.

> **Common diode mistakes:**
> - Orientation reversed: will cause the key to not register, or to ghost
> - Cold joint (dull, grainy solder): reflow with fresh flux
> - Solder bridge between pads: wick it off and redo

---

### Step 2 — Hotswap Sockets

Hotswap sockets let you swap switches without soldering. A beginner's best friend — if a switch feels wrong, pull it and plug in another.

**Kailh hotswap sockets:**

```
      ┌───────┐
  ────┤       ├────
      │  [ ]  │     ← switch pin enters here
  ────┤       ├────
      └───────┘
```

The socket snaps into the PCB footprint with a satisfying click. It can only go in one way.

**Technique:**

1. Place the socket into its footprint — it will seat flat against the PCB.
2. Hold it in place with a finger or blunt tool (pressing from the top of the PCB).
3. Touch iron to the metal tab of the socket while feeding solder in from the side. The solder should flow under the tab and onto the PCB pad.
4. Repeat for the other pin.
5. Good joints look like a small fillet of solder — the tab is clearly bonded to the pad.

> Do not apply too much heat — the plastic housing can warp and prevent the switch from seating.

---

### Step 3 — RGB LEDs (Optional)

**Skip this if it's your first build.** RGB adds color and looks great, but SK6812MINI-E LEDs are the most heat-sensitive component on the board. One overheated LED breaks the entire chain from that point onward.

If you're doing it:

**SK6812MINI-E orientation:**

```
    ┌────────┐
    │  ████  │
    │  ████  │ ← notch/flat corner = GND pin
    └──┘  └──┘
       GND
```

One corner of the LED package has a notch or a flat edge. This is the GND pin. Match it to the GND marking on the PCB silkscreen.

**Technique:**

- Set iron to 300–310°C (cooler than normal — these are heat-sensitive)
- Tin one pad, place LED, reflow to tack it, solder remaining three pads
- Move to the next LED with a few seconds gap — don't heat adjacent LEDs in quick succession
- Clean flux residue between LEDs with IPA to inspect solder quality

**Pro tip:** Test the LED chain after every 5–6 LEDs by briefly flashing firmware and powering on. Finding a bad LED at LED #40 of 42 is heartbreaking.

---

### Step 4 — TRRS Jacks and Reset Buttons

**Through-hole — the easiest soldering of the build.**

**TRRS jacks** (PJ-320A): These connect left and right halves with a 3.5mm TRRS cable when running wired. If you're using nice!nano with ZMK in fully wireless mode, you may skip these — the halves communicate over Bluetooth.

**Reset buttons** (3×6mm or 4×4mm tactile): These are used to enter bootloader mode (double-tap = .uf2 drive appears). They sit on the top of the PCB.

**Technique for both:**

1. Insert from the top of the PCB (component faces up).
2. Flip PCB over. The pins poke through from the bottom.
3. Hold component flush against the PCB (tape or Blu-Tack helps).
4. Solder each pin from the bottom. Through-hole joints are forgiving — fill the hole, create a small cone of solder around the pin.
5. Clip excess pin length with flush cutters.

---

### Step 5 — Controller Sockets (Mill-Max)

**This is the most important mod you can make.** Mill-Max machined sockets let you remove the nice!nano if it breaks, needs firmware reflashing, or you want to reuse it in another build. Direct-soldering the controller is permanent.

**Parts:**
- Mill-Max 315-43 series machined sockets (or equivalent low-profile)
- Mill-Max pins (or round-pin male headers) that solder to the controller

**Two-part system:**
```
PCB side:                Controller side:
  ┌────┐                   ┌──┐
  │    │ ← socket          │  │ ← pin (solders to controller pad)
  └────┘                   └──┘
   (stays in PCB)           (presses into socket)
```

**PCB-side technique:**

1. Drop sockets into the controller footprint holes. They sit flush.
2. Tape over the sockets to hold them while you flip the PCB.
3. Solder from the bottom — through-hole joints, one socket at a time.
4. Alternatively: insert all sockets, tape down, then solder a few to hold, remove tape, finish all.

**Controller-side technique:**

1. Insert pins into the sockets (to use them as alignment guides).
2. Place controller on top of the pins, component-side facing **away** from the PCB (this is critical — see Common Mistakes).
3. Solder pins to the controller pads while the pins are seated in the sockets. This ensures alignment.
4. Remove the controller from the sockets. It should slide in and out cleanly.

> **Critical orientation check:** On the Corne PCB, the controller sits component-side up on the *underside* of the left PCB, and component-side up on the *top* of the right PCB — or vice versa depending on the version. **Always double-check** the silkscreen. The nice!nano has a USB-C port that must align with the PCB cutout.

**If not using sockets (not recommended):**

Solder the controller directly with pin headers. The controller is now permanent. If it breaks, the PCB may be damaged in removal.

---

### Step 6 — OLED Pin Headers

OLEDs connect via 4-pin I2C headers (VCC, GND, SCL, SDA).

1. Solder 4-pin female socket headers into the OLED footprint on the PCB.
2. The OLED module plugs into these — removable without soldering.
3. Some OLEDs come with male pins pre-soldered. Check pin order: it must be VCC, GND, SCL, SDA in the same order as the PCB. **Some OLEDs ship with GND and VCC swapped** — check before plugging in.

> With ZMK on nice!nano, OLED support requires the OLED shield to be enabled in your config. OLEDs draw power and reduce battery life — a real consideration in wireless builds.

---

### Step 7 — Flash Firmware Before Casing

**Do this before you put the keyboard in its case. Non-negotiable.**

Once it's in the acrylic sandwich, accessing the reset button requires disassembly. Flash firmware now while the PCB is bare.

**Flashing ZMK on nice!nano:**

1. Build your firmware (GitHub Actions in your ZMK config repo) or download the pre-built `.uf2` files.
2. Connect the left half to your computer via USB-C.
3. Double-tap the reset button quickly. The nice!nano enters bootloader mode — it mounts as a USB drive called `NICENANO`.
4. Drag-and-drop the `corne_left-nice_nano_v2-zmk.uf2` file onto the drive.
5. It unmounts automatically when done. The keyboard resets.
6. Repeat for the right half with `corne_right-nice_nano_v2-zmk.uf2`.

**Test every key now:**

- Use [keyboard-test.com](https://www.keyboard-test.com) or [keyboardchecker.com](https://keyboardchecker.com)
- Connect left half via USB. It acts as the central (USB host) in ZMK.
- Press every key on the left half. Confirm they register.
- The right half connects wirelessly to the left as a peripheral — pair them by pressing a key on each half.
- Test all 42 keys before casing.

**If a key doesn't work:**

- Check that diode at that position with a multimeter (continuity test)
- Check that the hotswap socket is properly soldered
- Check that the switch is seated fully (if you've plugged switches in for testing)

---

### Step 8 — Install Switches

With hotswap sockets, this is the most satisfying step.

1. Align the switch pins with the hotswap socket holes — two small metal pins on the bottom of the switch.
2. Press straight down firmly until you feel/hear a click. Do not tilt.
3. If a pin bends, straighten it with tweezers before re-inserting.
4. Press each switch once more to ensure it's fully seated.

**Without hotswap (direct-solder):**

1. Insert the switch through the plate and into the PCB.
2. Ensure the switch is seated flat — plate and PCB are parallel.
3. Solder both pins. Do a few first, check they're flat, then do the rest.

---

### Step 9 — Case Assembly

**Acrylic sandwich (most common kit):**

```
Layer order (top to bottom):
  ┌─────────────────────────────┐  ← Top cover plate (OLED window)
  ├─────────────────────────────┤  ← Switch plate (switches snap through this)
  ├─────────────────────────────┤  ← PCB (with soldered components)
  ├─────────────────────────────┤  ← Middle spacer layer(s)
  ├─────────────────────────────┤  ← Bottom plate
  └─────────────────────────────┘
           ↕ M2 screws + standoffs
```

Assembly:

1. Install standoffs in the bottom plate first.
2. Place the PCB onto the standoffs.
3. Layer the middle spacers (these create clearance for the hotswap sockets and components underneath).
4. Place the switch plate on top of the PCB.
5. Insert switches through the plate into the PCB/sockets.
6. Add the top cover plate. If you have OLED windows, ensure they're aligned with the OLEDs.
7. Screw everything down with M2 screws. Don't over-torque acrylic — it cracks.
8. Apply rubber bumpons to the bottom plate corners (and optionally center).

**Screw sizes (typical):**

| Location | Screw Length |
|----------|-------------|
| Bottom plate → standoff | 6mm |
| Top plate → standoff | 6mm |
| Standoff length (plate + PCB) | 10–12mm |

> Acrylic has a protective film on both sides. Peel it off before assembly — the keyboard looks dramatically better without the cloudy film.

---

## Battery Wiring (nice!nano)

The nice!nano v2 has a JST PH 2.0 connector and two through-hole pads labeled **B+** and **B-** for battery connection.

**JST connector (easiest):**

If your battery has a JST PH 2.0 connector, it simply plugs into the JST port on the bottom of the nice!nano. Polarity: **red = positive, black = negative**.

**Direct solder (no JST):**

1. Identify the **B+** and **B-** pads near the bottom of the nice!nano PCB.
2. Strip ~2mm of wire insulation.
3. Solder red wire to B+, black wire to B-.
4. **Polarity is critical.** Reversed polarity can damage or destroy the controller.

**Battery sizing and placement:**

| Battery | Size (mm) | Capacity | Fits under nice!nano? |
|---------|-----------|----------|----------------------|
| 301230 | 3×12×30mm | ~100mAh | Yes (tight, standard) |
| 401230 | 4×12×30mm | ~150mAh | With 4mm standoffs or tenting legs |
| 602030 | 6×20×30mm | ~300mAh | No — too thick for sandwich case |

The battery sits under the nice!nano, between the controller and the PCB. Secure it with double-sided tape. Do not let it touch bare metal pads on the PCB's underside.

**nice!nano charging:**

The nice!nano charges the LiPo automatically when USB is connected. No external charger needed. Charge current is approximately 100mA (so ~1 hour per 100mAh of capacity).

**Battery life:**

With ZMK's power management:
- Without OLED, without RGB: weeks to months of typical use
- With OLED: days to ~1 week
- With RGB enabled: hours to 1–2 days (RGB is extremely power-hungry)

---

## Wireless Setup and Pairing (ZMK)

ZMK handles all Bluetooth logic in firmware. Unlike QMK, there is no Bluetooth HID configuration step — the firmware does it.

### Central and Peripheral

In ZMK split keyboard terminology:

- **Central (left half):** Connects to the computer via Bluetooth (or USB). Collects key events from both halves.
- **Peripheral (right half):** Connects only to the central (left half) via Bluetooth. Never connects directly to the computer.

```
Computer ←── BLE ──→ Left Half (Central)
                            ↑
                           BLE
                            ↓
                     Right Half (Peripheral)
```

### Flashing

The firmware builds produce two files:

```
corne_left-nice_nano_v2-zmk.uf2    → flash to LEFT half
corne_right-nice_nano_v2-zmk.uf2   → flash to RIGHT half
```

Flash each separately via USB (double-tap reset → drag .uf2 file to NICENANO drive).

### Pairing Halves to Each Other

On first boot after flashing, the halves will discover each other automatically. This takes 10–30 seconds. You don't need to do anything — ZMK handles internal pairing automatically.

If they don't pair within a minute:
- Power-cycle both halves (disconnect USB, flip power switches off/on if you have them)
- Check that both have fresh firmware

### Pairing to Computer

1. On your computer, open Bluetooth settings.
2. The keyboard will appear as "Corne" (or whatever the ZMK build is named).
3. Click to pair. Done.

### ZMK's 5 Bluetooth Profiles

ZMK supports pairing to 5 different devices. Profile switching is done via key bindings — in your keymap, the MEDIA layer has BT controls:

```
BT_SEL 0  →  Profile 1 (first paired device)
BT_SEL 1  →  Profile 2
BT_SEL 2  →  Profile 3
BT_SEL 3  →  Profile 4
BT_SEL 4  →  Profile 5
BT_CLR    →  Clear current profile (for re-pairing)
```

### Re-pairing to a New Computer

On the MEDIA layer, navigate to the Bluetooth profile you want to reset, then press `BT_CLR`. The profile is cleared. Then pair the keyboard from the new computer's Bluetooth settings.

### USB vs. Wireless Priority

ZMK prefers USB when a cable is connected. Plug in → keyboard acts wired. Unplug → falls back to Bluetooth automatically. No configuration needed.

---

## Testing Every Key

### Before Casing (Bare PCB)

1. Flash firmware (Step 7 above).
2. Connect left half via USB.
3. Open [keyboard-test.com](https://www.keyboard-test.com) or any text editor.
4. Press every key on the left half. Watch for registration.
5. Pair right half (it should connect wirelessly within 30 seconds).
6. Press every key on the right half.
7. Test layer access: hold each thumb key and verify the layer activates (try a few keys from that layer).

### Layer verification for your keymap:

| Thumb Hold | Layer | Quick Test |
|------------|-------|------------|
| ESC (hold) | MEDIA | Should produce media keys / BT controls |
| SPACE (hold) | NAV | H/J/K/L should produce Left/Down/Up/Right |
| TAB (hold) | MOUSE | H/J/K/L should move cursor |
| RET (hold) | SYM | Should produce symbols |
| BSPC (hold) | NUM | Home-row keys should produce numbers |
| DEL (hold) | FUN | Should produce F1–F12 |

### After Casing

Switches can sometimes shift slightly during casing. Re-test all keys once everything is assembled. A poorly seated switch won't register until pressed harder than normal.

### Home Row Mod Testing

Your home row mods (hold A/S/D/F for GUI/Alt/Ctrl/Shift) need tap-vs-hold timing to feel right. Test:

- Quick tap of A → produces 'a'
- Long hold of A → activates LGUI (Cmd on macOS)
- Tap A quickly while already holding NAV layer → produces 'a' (not modifier)

If mods trigger accidentally on fast typing, adjust `tapping-term-ms` in your ZMK config.

---

## Common Build Mistakes (and How to Fix Them)

### 1. Diode Installed Backwards

**Symptom:** Key does not register. Pressing that key produces nothing.

**Diagnosis:** Multimeter in diode-test mode across both pads. You'll get a reading in the wrong direction.

**Fix:** Heat both pads, remove diode with tweezers, clean pads with solder wick, re-solder with correct orientation.

---

### 2. Solder Bridge Between Pads

**Symptom:** Key always held, ghost keys, multiple keys triggering at once.

**Diagnosis:** Visually inspect the pads under magnification (a phone camera zoomed in works). You'll see a blob connecting pads that shouldn't be connected.

**Fix:**
1. Apply fresh flux to the bridged area.
2. Drag the iron tip across the bridge — sometimes it breaks apart on its own.
3. If not: place solder wick over the bridge, apply iron, let wick absorb the excess solder.
4. Clean with IPA, inspect again.

---

### 3. Controller Installed Backwards

**Symptom:** Nothing works. No keys register. Controller may get warm.

**Prevention:** Before soldering, verify: the USB-C port on the nice!nano aligns with the USB cutout on the PCB. The component side of the nice!nano faces the correct direction per the PCB silkscreen.

**Fix:** This is the most painful fix. Carefully desolder all pins with a solder pump or hot air station. The Mill-Max socket approach makes this much less catastrophic — just flip the controller and re-seat it.

---

### 4. Cold Solder Joint

**Symptom:** Key works intermittently — sometimes registers, sometimes doesn't. Gets worse as the keyboard warms up.

**Diagnosis:** Dull, grainy, or lumpy solder joint (vs. the smooth, shiny cone of a good joint).

**Fix:** Add a tiny amount of flux, reheat the joint with the iron for 2–3 seconds to reflow. The solder should re-wet the pad and pin, becoming shiny.

---

### 5. Forgetting to Flash Before Casing

**Symptom:** Keyboard is fully assembled, nothing works, and you realize you never put firmware on it.

**Fix:** Disassemble the case (remove all screws, separate layers), access the PCB, double-tap reset, flash firmware. Reassemble.

**Prevention:** Always flash and test before case assembly. This is non-negotiable.

---

### 6. Battery Polarity Reversed

**Symptom:** Controller doesn't power on when disconnected from USB, or worse — controller is permanently damaged.

**Prevention:** Double-check red=B+, black=B− before connecting. If using a JST connector, verify the battery manufacturer's wiring matches nice!nano's JST pinout. Some batteries have swapped polarity — measure with a multimeter first.

**Fix:** If reversed for more than a few seconds, the LiPo protection circuit may have triggered (no permanent damage). Disconnect, correct polarity, reconnect. If the controller is damaged (gets hot, shows unusual behavior), it may need replacement.

---

### 7. OLED GND/VCC Pins Swapped

**Symptom:** OLED doesn't light up, or controller behaves erratically.

**Prevention:** Before plugging in an OLED module, read its pinout. Some OLEDs label left-to-right as VCC, GND, SCL, SDA while the Corne PCB expects GND, VCC, SCL, SDA (or vice versa). Compare before connecting.

**Fix:** If the module has the wrong order, desolder its pin header and re-solder it in the correct order, or buy a module with the correct pinout.

---

### 8. Hotswap Socket Not Bonded

**Symptom:** Switch presses intermittently, or the socket physically pulls off when removing a switch.

**Diagnosis:** The socket feels loose. One or both pins isn't bonded to the PCB pad.

**Fix:** Remove the switch. Add flux, reheat both socket pins, apply a little more solder. The socket should now be firmly anchored.

---

## Soldering Primer

If you've never soldered before, these fundamentals will prevent 80% of problems.

### Good vs. Bad Joints

```
Good joint:         Bad (cold) joint:    Bridge:
    ╱╲                  ○                ██
   ╱  ╲                ◌               ██ ██
  ╱____╲             (grainy)         (connected)

Shiny, concave      Dull, lumpy        Two pads
cone shape          doesn't wet pad    connected — bad
```

### The Iron Does Not Push Solder — Heat Does

Common beginner mistake: melting solder onto the iron tip and trying to deposit it. Instead:

1. Touch the iron to both the pad AND the component pin simultaneously (about 1 second).
2. Touch solder to the junction of pad + pin + iron tip (not the iron tip alone).
3. The solder flows into the joint by capillary action.
4. Remove solder, then remove iron.
5. Don't move the joint for 2–3 seconds while it solidifies.

### Tip Maintenance

A clean iron tip is essential. Tin your tip (coat it with solder) before and after every use:

1. Before use: wipe on brass wire cleaner, apply fresh solder to the tip.
2. After use: tin the tip heavily, then turn off the iron.

A blackened, oxidized tip won't transfer heat. Replace or re-tin aggressively.

### When to Use Flux

- Always when soldering SMD components (diodes, RGB LEDs)
- When a joint isn't flowing properly — add flux and reflow
- When removing solder bridges
- Flux is a chemical that removes oxidation and helps solder wet the pad. More flux = easier soldering.

### IPA Cleanup

After soldering a section, clean with IPA and a cotton swab or brush. This removes flux residue (which can be mildly corrosive long-term and looks ugly). "No-clean" flux technically doesn't need removal, but cleaning anyway gives you a cleaner visual inspection of your joints.

---

## Cost Breakdown

### Budget Build (wired, QMK, no extras)

| Component | Cost |
|-----------|------|
| Corne v3 PCB kit | $25 |
| 2× Pro Micro (Elite-C for USB-C) | $20 |
| 42× 1N4148W diodes | $3 |
| 42× Kailh hotswap sockets | $5 |
| 2× Reset buttons | $1 |
| 2× TRRS jacks + TRRS cable | $3 |
| Acrylic sandwich case (kit) | Included |
| 42× Gateron Yellow switches | $15 |
| Budget XDA keycap set | $20 |
| M2 hardware | $3 |
| **Total** | **~$95** |

### Your Build (wireless, ZMK, nice!nano)

| Component | Cost |
|-----------|------|
| Corne v3 PCB kit | $30 |
| 2× nice!nano v2 | $50 |
| Mill-Max sockets + pins | $15 |
| 42× 1N4148W diodes | $3 |
| 42× Kailh hotswap sockets | $6 |
| 2× Reset buttons | $1 |
| 2× LiPo batteries (301230) | $10 |
| Acrylic sandwich case | $15 |
| 42× switches (mid-range) | $30–60 |
| Keycap set | $30–80 |
| **Total** | **~$190–250** |

### Premium Build (wireless + OLED + RGB + aluminum case)

| Component | Cost |
|-----------|------|
| Corne v3 PCB kit | $35 |
| 2× nice!nano v2 | $50 |
| Mill-Max sockets | $15 |
| 42× 1N4148W diodes | $3 |
| 42× Kailh hotswap sockets | $6 |
| 42× SK6812MINI-E RGB LEDs | $12 |
| 2× OLED displays | $10 |
| 2× LiPo batteries | $12 |
| Aluminum CNC case | $100–150 |
| 42× premium switches (Boba U4T, etc.) | $60 |
| GMK or PBT keycap set | $80–200 |
| **Total** | **~$380–550** |

---

## Where to Buy

### PCBs and Full Kits

| Vendor | Region | Notes |
|--------|--------|-------|
| [Keyhive](https://keyhive.xyz) | US | Popular, good kits, video guides |
| [Boardsource](https://boardsource.xyz) | US | Wide selection, builds available too |
| [Little Keyboards](https://littlekeyboards.com) | US | Good for Canadian buyers |
| [FalbaTech](https://falba.tech) | EU | EU shipping, custom cases |
| [Typeractive](https://typeractive.xyz) | US | ZMK-focused, nice!nano bundles |
| [Kraken Keyboards](https://krakenkeyboards.com) | US | Pre-built and DIY options |

### Controllers

| Vendor | Product | Notes |
|--------|---------|-------|
| [Nice Keyboards](https://nicekeyboards.com) | nice!nano v2 | Official source |
| [Boardsource](https://boardsource.xyz) | nice!nano v2 | Often bundled with kits |
| [Typeractive](https://typeractive.xyz) | nice!nano v2 | |
| [SparkFun](https://sparkfun.com) | Pro Micro | For QMK/wired builds |

### Switches

| Vendor | Notes |
|--------|-------|
| [Divinikey](https://divinikey.com) | US-based, fast shipping, wide selection |
| [Novelkeys](https://novelkeys.com) | Own-brand switches, good house switches |
| [KBDFans](https://kbdfans.com) | Large selection, ships from CN |
| [ThocStock](https://thocstock.com) | Aggregates switch availability across vendors |

### Keycaps

| Vendor | Notes |
|--------|-------|
| [KBDFans](https://kbdfans.com) | Large PBT and GMK selection |
| [Drop](https://drop.com) | Group buys, premium sets |
| [WASD Keyboards](https://wasdkeyboards.com) | Custom printed caps |
| [ErgoDox EZ shop](https://ergodox-ez.com) | OEM profile 40% caps |

---

## Build Resources and Community

### Official Documentation

- **foostan's official build guide:** [github.com/foostan/crkbd/blob/main/docs/corne-cherry/buildguide_en.md](https://github.com/foostan/crkbd/blob/main/docs/corne-cherry/buildguide_en.md)
  The canonical reference. Written by the keyboard's creator. Has photos of every step.

- **foostan's crkbd repository:** [github.com/foostan/crkbd](https://github.com/foostan/crkbd)
  PCB files, schematics, BOM, all open source.

### Video Guides

- **Keyhive YouTube channel:** Search "Keyhive Corne build" — step-by-step video walkthroughs
- **Ben Vallack's keyboard content:** Philosophy-heavy, but his Corne/Ferris content is excellent for understanding minimalist layout philosophy
- **Joe Scotto YouTube:** Mechanical keyboard education from first principles, excellent for beginners

### Community

- **r/ErgoMechKeyboards** ([reddit.com/r/ErgoMechKeyboards](https://reddit.com/r/ErgoMechKeyboards))
  The primary community for ergonomic keyboards. Build logs, layout discussions, help threads. Everyone there has built at least one Corne.

- **r/MechanicalKeyboards** ([reddit.com/r/MechanicalKeyboards](https://reddit.com/r/MechanicalKeyboards))
  Larger community, less ergo-focused. Good for switch comparisons, keycap group buys.

- **ZMK Discord:** [discord.gg/8cfMkQksSB](https://discord.gg/8cfMkQksSB)
  Official ZMK community. If you have firmware questions, this is where the developers hang out.

- **40percent.club** ([40percent.club](https://www.40percent.club))
  Blog dedicated to 40% keyboards. Historical build logs, switch reviews, layout discussions.

- **Keyboard University** ([keyboard.university](https://keyboard.university))
  Reference site for beginners — switch types, stabilizers, acoustics.

### Firmware References

- **ZMK Docs:** [zmk.dev/docs](https://zmk.dev/docs) — Official ZMK documentation
- **ZMK Keymap Editor:** [nickcoutsos.github.io/keymap-editor](https://nickcoutsos.github.io/keymap-editor) — GUI for editing ZMK keymaps
- **QMK Docs:** [docs.qmk.fm](https://docs.qmk.fm) — For wired builds with QMK

### Soldering Resources

- **Adafruit Guide to Excellent Soldering:** [learn.adafruit.com/adafruit-guide-excellent-soldering](https://learn.adafruit.com/adafruit-guide-excellent-soldering)
  Considered the best free soldering guide on the internet. Photos of good vs. bad joints.

- **EEVblog SMD Soldering Tutorial (YouTube):** Dave Jones demonstrates SMD technique with a microscope — overkill but illustrative.

---

## What to Build Next

Once you've built one Corne, the second build takes half the time and you'll probably tweak things:

| Upgrade | Why |
|---------|-----|
| Aluminum case | Dramatically changes sound profile — more solid, less hollow |
| Different switches | Linear vs. tactile vs. clicky changes the feel entirely. Try Boba U4 for silent tactile. |
| Choc low-profile version | Flatter keyboard, more portable. Requires Choc-specific keycaps. |
| Ferris Sweep | Even smaller (34 keys), no number row. Next step down the minimalist path. |
| Kyria / Kyria rev3 | More keys, encoder support, tenting options. Good if you miss thumb cluster. |
| Dactyl Manuform | 3D-printed sculpted layout. Requires more build skill but is the pinnacle of ergonomics. |

The hobby has a gravity to it. A second Corne is nearly inevitable.

---

*Build guide written for Corne v3 with nice!nano v2 and ZMK. Component availability and pricing are approximate as of 2024 — check vendors for current stock and pricing.*
