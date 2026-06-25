# Switch Swapping on the Corne (Hot-Swap Guide)

Your Corne uses **Kailh MX hot-swap sockets** — which means changing switches requires zero soldering, zero heat, zero risk to the PCB (when done correctly), and takes about 20 minutes once you know what you're doing. This guide gets you there from scratch.

---

## 1. What Hot-Swap Actually Means

Traditional mechanical keyboards require soldering switches to the PCB — a permanent join that takes a heat gun and desoldering wick to undo. Hot-swap sockets change that entirely.

**Kailh hot-swap sockets** are small spring-loaded metal contacts that are soldered *once* to your PCB by the keyboard builder (or factory). The socket has two holes that accept the switch's metal pins. Push a switch in — the spring contacts grip the pins and make electrical contact. Pull a switch out — the pins release cleanly. No heat, no tools other than a switch puller.

```
SOCKET CROSS-SECTION (side view)
─────────────────────────────────

  Switch pin
      │
      ▼
  ┌───┴───┐
  │  pin  │   ← switch pin slides in here
  │       │
  │ ╔═══╗ │   ← spring contact (grips the pin)
  │ ║   ║ │
  │ ╚═╤═╝ │
  │   │   │
  └───┼───┘   ← Kailh socket body (soldered to PCB)
      │
   PCB trace
```

The spring contact grips the pin firmly enough to make reliable electrical connection, but releases cleanly when you pull straight up. Kailh rates these sockets for a minimum of 100 insertions — enthusiasts routinely hit 200–500+ cycles without failure.

**Key point:** hot-swap sockets are robust. Treat them right and they will outlast your interest in any individual switch.

---

## 2. What You Need

### Essential (you cannot do this without it)

**A wire-type switch puller** — a small metal tool with two wire prongs bent into hooks. Costs $2–8. Every keyboard vendor sells them. This is the *only* tool that matters.

Do not attempt this without one. The improvised alternatives (fingernails, tweezers, screwdrivers) either cannot generate the right force or will damage your switches, your sockets, or both.

### Optional but genuinely helpful

| Item | Why it helps |
|---|---|
| Tweezers | Retrieving dropped switches from inside the case |
| Small flashlight or phone torch | Seeing pin holes and socket contacts clearly |
| Small bowl or container | Holds removed switches — they roll off tables |
| Switch tester | Try a few candidates before swapping all 42 |
| Isopropyl alcohol (90%+) | Cleaning debris from sockets if needed |

### Do NOT use

- Screwdrivers (prying will bend socket contacts)
- Fingernails (cannot engage the clip notches properly)
- Knives or scissors (obvious)
- Keycap pullers with the plastic fork style (designed for keycaps, wrong geometry for switches)
- Anything asymmetric that would push the switch sideways on exit

---

## 3. Before You Start — Safety for Your Wireless Corne

Your Corne runs a **nice!nano v2** controller on battery with ZMK firmware. A few precautions before touching anything:

1. **Turn off the keyboard.** If your case has a physical power switch or slide switch, flip it off. If not (some builds omit it), proceed to step 2.
2. **Unplug USB** if the keyboard is connected to anything.
3. **Leave the battery alone.** You do not need to disconnect it, discharge it, or worry about it for a switch swap. The switch contacts carry key signals through the PCB matrix — they are not connected to battery voltage. It is safe.
4. **No ESD precautions needed.** ESD matters when handling bare ICs or the controller itself. Switch swapping only touches the switch mechanical housing and pins — no ESD sensitivity here.

---

## 4. Remove Keycaps First

Always. No exceptions.

Attempting to pull a switch with a keycap on it is harder (the keycap blocks the puller) and can crack the keycap stem or pull the switch stem out of its housing rather than the switch out of the socket.

**How to remove keycaps:**

Use a **wire-type keycap puller** (two bent wire loops). Slide the loops under two opposing sides of the keycap, center the puller over the stem, and pull **straight up**. No rocking, no twisting.

The Corne has 42 keys, all 1u (same size). This is the easy case — no stabilizers, no awkward large keys. It takes about 3–5 minutes to remove all keycaps.

Set keycaps aside in a container where they won't scatter. They are small and love to hide under furniture.

---

## 5. Removing a Switch — Step by Step

### Step 1: Find the notches

Every MX-style switch has two small notch indentations built into the sides of its housing — one on the north face and one on the south face. These are the only attachment points the puller engages.

```
SWITCH — TOP VIEW
─────────────────────────────────

        ┌─────────────────────┐
        │                     │
        │      TOP VIEW       │
        │                     │
  ◄notch┤  □           □  ├notch►
        │                     │
        │       ┌─────┐       │
        │       │ stem│       │
        │       └─────┘       │
        │                     │
        └─────────────────────┘
              │         │
           LED side   pin side
           (front)    (back)
```

```
SWITCH — SIDE VIEW (showing clip notches)
─────────────────────────────────

  ┌────────────────────────────┐
  │        switch top          │
  ├──┐                      ┌──┤ ← housing clips (snap into plate holes)
  │  └──────────────────────┘  │
  │  ┌──────────────────────┐  │
  │  │                      │  │
  └──┘                      └──┘ ← notch slots (where puller prongs go)
       │                  │
     pin 1              pin 2
```

### Step 2: Seat the puller prongs

Hold the switch puller like a pair of tweezers. Spread the prongs slightly and slide them into the **side notches** — north notch and south notch simultaneously.

The prongs should sit *in* the notches, not resting on the switch body surface. If they keep sliding off, you're not in the notches yet. Look carefully — the notches are small but unambiguous once you see them.

### Step 3: Squeeze gently and pull straight up

With the prongs seated:

1. Squeeze the puller handle with light pressure — enough to hold the notches engaged.
2. Pull **straight up**. Vertical. Not toward you, not at an angle.
3. The switch will release with a soft pop.

The force required is small. If you're straining, stop — the prongs are not properly seated. Re-seat and try again.

```
CORRECT PULL DIRECTION
─────────────────────────────────

        ↑ pull straight up
        │
    ┌───┴───┐
    │switch │
    │       │
  ──┤  pcb  ├──   ← plate level
    │       │
    └───────┘
        ✓

WRONG — pulls pin sideways, damages socket
        ↗ angle
       /
    ┌─/─────┐
    │switch │
    │       │
  ──┤  pcb  ├──
    │       │
    └───────┘
        ✗
```

### Step 4: Inspect the socket after removal

Before installing anything new, look at the two pin holes in the PCB. You should see metal contacts on both sides of each hole. Both contacts should be open (not crushed closed), intact, and symmetrical.

If something looks wrong — see the troubleshooting section at the end.

---

## 6. Installing a New Switch — Step by Step

### Step 1: Inspect the switch pins

MX switches have two metal pins (and sometimes a larger center plastic pin — ignore that one, it's just a keying pin and not always present). Look at both metal pins before doing anything else.

They must be **perfectly straight**. A bent pin will not enter the socket cleanly and can crush the socket contact on the way in.

```
GOOD PINS           BAD PIN (bent)
─────────────────────────────────

  ┌─────┐             ┌─────┐
  │     │             │     │
  │     │             │     │
  ││   ││             ││   /│  ← bent
  ││   ││             ││  / │
  │└   ┘│             │└  ─ ┘
  └─────┘             └─────┘
    ✓                    ✗
```

If a pin is bent, straighten it with your fingernail or tweezers before attempting insertion. A gentle bend back to vertical is all that's needed.

### Step 2: Orient the switch correctly

Switches have a defined orientation. The LED window (a transparent rectangle in the switch housing) faces a specific direction, and your plate's LED cutouts are oriented to match.

On the Corne: look at an adjacent switch that's already installed. Your new switch should match its orientation exactly — LED window facing the same direction.

The two metal pins and optional center plastic pin must align with the three corresponding holes visible in the socket/PCB.

### Step 3: Push straight down

1. Hold the switch between thumb and index finger.
2. Position it directly above the socket, pins aligned with holes.
3. Press straight down with your thumb — even pressure across the top of the switch.
4. You will feel (and may hear) two small clicks as the housing clips engage the plate holes.
5. The switch should now sit **flush with the plate** — no gap, no tilt, no wobble.

```
CORRECT INSERTION
─────────────────────────────────

   push ↓ straight down
        │
    ┌───┴───┐
    │switch │
    │       │
  ──┼───────┼──   ← plate (flush when done)
    │  pcb  │
    │ ┌───┐ │   ← socket contacts grip pins here
    │ └───┘ │
    └───────┘
        ✓
```

Do not rock, press one side down first, or insert at an angle. If the switch doesn't go in smoothly with moderate thumb pressure, stop. Remove it, re-inspect pins, re-align, try again.

### Step 4: Verify seating

Give the switch a gentle wiggle side to side and front to back. A properly seated switch barely moves — it's held by both the plate clips and the socket pin grip. If it rocks noticeably, it's not fully seated. Push down again, more firmly.

Look from the side: the bottom of the switch housing should be flush against the plate surface. Any visible gap means it's not seated.

---

## 7. Test Every Switch Before Reinstalling Keycaps

This step saves you the frustration of noticing a dead key after you've put all 42 keycaps back on.

1. Connect the keyboard (USB cable, or turn it on for Bluetooth — give it 5–10 seconds to connect).
2. Open a key tester: [keyboard-test.com](https://keyboard-test.com) or [keyboardtester.com](https://keyboardtester.com), or simply open a text editor.
3. Press each swapped switch with your fingertip.
4. Confirm it registers.

**If a key doesn't register:**
- Press down harder on the switch — it's probably not fully seated.
- If that doesn't work: remove the switch with the puller, inspect pins, re-insert.
- If still nothing: see troubleshooting below.

Only after every switch tests clean should you reinstall keycaps.

---

## 8. Reinstalling Keycaps

Push each keycap straight down onto the switch stem. You'll feel it click into place.

1u keycaps have no stabilizer orientation to worry about. They go on one way and click home.

If your keycaps have legends, make sure they're oriented the right direction before pressing them on — it's awkward to remove a keycap you just installed, and repeatedly pulling keycaps off the same switch stem is unnecessary wear.

---

## 9. Full Swap — All 42 Switches

If you're changing the entire set:

**Estimated time:** 25–40 minutes for a first timer, 10–15 minutes once you've done it before.

**Recommended order:**
1. Remove all keycaps first.
2. Remove all switches from one half before moving to the other. This prevents accidentally mixing up left and right half switches if they differ.
3. Keep removed switches in a container, sorted if you might reuse them.
4. Install new switches in batches of 10–15, testing each batch before continuing.
5. Thumb cluster first — it's the most accessible and easiest to reach with the puller.
6. Then top row, home row, bottom row.

**Testing strategy:** Rather than testing all 42 at the end, test each batch of 10 as you go. Finding a problem is much easier when you've only just installed 10 switches, not 42.

---

## 10. Partial Swap — Trying Before Committing

You absolutely do not have to swap all 42 switches to evaluate new ones. This is one of the main advantages of hot-swap.

**Home row test:** Swap the 8 home row keys (A S D F J K L ; on a standard layout, or whatever sits there on your Corne layout). Type normally for a day or two. This is enough typing volume to know whether you love or hate the switch feel, sound, and actuation.

If you like them: buy 42, do the full swap.
If you don't: pull the 8 out, try something else. Cost: 5 minutes.

---

## 11. Troubleshooting

### Switch won't come out

The puller prongs are not seated in the notches — they're pressing against the side of the switch housing and slipping. This is the most common beginner mistake.

- Remove the puller completely.
- Look closely at the switch. Find the notch indentations on the north and south sides.
- Slide prongs in so they are *inside* the notch, not resting on the surface.
- Try rotating the puller 90° and approaching from a different angle if the geometry feels awkward.
- Squeeze and pull straight up.

Never pry, lever, or use any tool except the puller.

### One pin stayed in the socket

This happens if a pin was already slightly bent and sheared off during removal — or if you pulled at an angle.

1. Use tweezers to grip the pin and extract it from the socket carefully.
2. Inspect the socket contacts after — they may have been pushed aside.
3. Use tweezers to gently re-center any displaced contact metal.
4. Test with a known-good switch before installing the intended replacement.

### Key doesn't register after swap

In order of likelihood:

1. **Switch not fully seated.** Push down harder. You should feel/hear the plate clips engage. This fixes the problem 80% of the time.
2. **Bent pin didn't align properly.** Remove the switch, look at pins (one may be bent or folded back). Straighten, re-insert.
3. **Socket contact displaced.** If rough handling moved a spring contact, use tweezers to carefully re-open the contact gap. Test with a known-good switch.
4. **Switch is defective.** Rare but real. Try a different switch in the same socket. If the socket works with a different switch, the original is faulty.

### Switch is wobbly after installation

- Not fully clipped into plate: push straight down until you hear/feel both clips engage.
- Switch plate clips worn after many cycles: happens eventually. The switch still works electrically — just less mechanically secure. Acceptable.

### Socket contact crushed (worst case)

If you inadvertently crushed a socket contact closed (usually from inserting a badly bent pin with force), the socket won't make electrical contact.

- Use a pin, thin screwdriver tip, or stiff wire to gently pry the crushed contact back open.
- Work slowly — socket contact metal is thin.
- If the socket is completely dead after attempts to restore it: the Corne PCB is open-source hardware. Replacement PCBs cost $10–25 from Keyhive or Boardsource. Individual sockets can also be reflowed by someone with a soldering iron.

This outcome is rare. It requires both a badly bent pin *and* forceful insertion. Following the pin inspection step prevents it entirely.

---

## 12. Socket Lifespan

Kailh hot-swap sockets are rated for **100 insertion cycles minimum** by the manufacturer. In practice, keyboard enthusiasts regularly report 200–500+ cycles on the same sockets without degradation, provided they:

- Always pull straight up (no lateral force on pins)
- Never insert bent pins forcefully
- Keep sockets free of debris

If you swap once a month experimentally, these sockets will outlast any keyboard-related interest you develop. Don't treat them as fragile.

**Keeping sockets clean:** If debris (dust, solder flux, skin oils) accumulates in a socket over time, a toothpick dipped in isopropyl alcohol (90%+) inserted and gently rotated in the socket hole will clean it. Let it dry completely before inserting a switch.

---

## 13. Switch Pullers Worth Buying

| Puller | Approx. price | Where to buy | Notes |
|---|---|---|---|
| Durock wire puller | ~$5 | NovelKeys, KBDfans | Comfortable grip, widely considered best value |
| KBDfans wire puller | ~$4 | KBDfans | Simple, effective |
| Generic wire puller | ~$2–3 | AliExpress, Amazon | Fine for occasional use |
| Keychron switch puller (bundled) | Free (came with keyboard) | — | Works; acceptable if you have it |
| Glorious switch puller | ~$5 | Glorious | Good quality, easy to find |

Avoid plastic fork-style pullers — designed for keycaps, wrong geometry for switches and can crack housings.

---

## 14. Workflow for Switch Experimentation

Hot-swap keyboards are built for this. Here's the most efficient way to find your ideal switch:

1. **Order a switch sampler pack.** NovelKeys, Divinikey, and KBDfans all sell samplers of 10 switches each across multiple candidates. Expect to spend $5–15 to try 5–8 different switches.
2. **Swap just the home row** (the 8 keys your fingers rest on) with Candidate A. Type normally for 1–2 days. This is enough real-world volume to have an opinion.
3. **Swap to Candidate B.** Repeat.
4. **Pick the winner.** Buy 42 + a few spares. Do the full swap.
5. **Keep the losers.** They're useful for future experiments or selling/trading in the community.

**Indian vendors with reasonable selection:**
- mechkeys.in — growing switch selection
- thockeys.in — switches and accessories
- Community swaps: r/MechanicalKeyboardsIndia, local Discord servers

**International vendors (ship to India):**
- NovelKeys (novelkeys.com) — switch tester packs, excellent selection
- Divinikey (divinikey.com) — individual switches, low minimums, no bulk required
- KBDfans (kbdfans.com) — broad catalog, often cheaper on common switches

---

## 15. Lube and Films (Optional — Before Installing New Switches)

If you want to maximize the quality of your new switches, do this *before* inserting them into the keyboard. It's optional, but the improvement is real.

### Lubing

Lubing switch internals reduces friction, improves smoothness, and changes (usually improves) sound. It takes 30–60 minutes to do 42 switches.

| Switch type | Lube | Where to apply |
|---|---|---|
| Linear (e.g. Gateron Yellow, Akko CS) | Krytox 205g0 | Stem rails (4 sides), spring bag-lubed with 105 |
| Tactile (e.g. Boba U4, Topre) | Tribosys 3204 | Housing legs and rails only — avoid tactile legs |
| Clicky (e.g. Kailh Box White) | Do not lube | Lubing kills the click mechanism |

A thin, even coat is better than too much. Over-lubing a linear makes it feel mushy. Over-lubing a tactile kills the tactile bump.

### Switch Films

Thin films (mylar or polycarbonate, 0.1–0.3mm) inserted between the top and bottom housing halves reduce housing wobble and can affect sound. The improvement is minor compared to lubing but popular with enthusiasts chasing the last 10%.

### If you don't want to do any of this

Install stock. A fresh set of unlubed switches on a hot-swap Corne sounds and feels perfectly fine. Lubing is enhancement, not a prerequisite.

---

## 16. Quick Reference Card

```
╔══════════════════════════════════════════╗
║       SWITCH SWAP — QUICK GUIDE         ║
╠══════════════════════════════════════════╣
║ BEFORE                                   ║
║  □ Keyboard off / USB unplugged          ║
║  □ Keycap puller → remove all keycaps   ║
║                                          ║
║ REMOVING A SWITCH                        ║
║  □ Wire puller prongs → side notches     ║
║     (north + south faces, not LED/pin)   ║
║  □ Squeeze gently                        ║
║  □ Pull STRAIGHT UP — no angle           ║
║  □ Check socket contacts after           ║
║                                          ║
║ INSTALLING A SWITCH                      ║
║  □ Inspect both metal pins — straight?   ║
║  □ Orient to match neighbors             ║
║  □ Push STRAIGHT DOWN until click        ║
║  □ Verify flush, no wobble               ║
║                                          ║
║ AFTER                                    ║
║  □ Test every key on keyboard-test.com   ║
║  □ Reinstall keycaps                     ║
╠══════════════════════════════════════════╣
║ Time: ~25 min first swap, 10 min after  ║
║ Tools: wire switch puller, keycap puller ║
╚══════════════════════════════════════════╝
```

---

## Frequently Asked Questions

**Q: Can I damage the PCB doing this?**
A: Not by following this guide. The risks are bent pins (your fault) or lateral force on the socket (use the puller correctly and pull straight up). Both are preventable.

**Q: Do I need to flash new firmware after changing switches?**
A: No. Switches are hardware — they make or break a circuit. Firmware doesn't know or care what switch is installed. No reflashing needed.

**Q: Can I mix switch types? (e.g. tactile on home row, linear everywhere else)**
A: Yes. Each socket is independent. Put whatever you want where you want it.

**Q: My new switches feel scratchy compared to my old ones. Is something wrong?**
A: No — some switches (especially budget linears) feel rough out of the box and break in after 1–4 weeks of normal typing. Lubing eliminates this immediately if you prefer. It's not a defect.

**Q: The switch feels loose after inserting. Did I break the socket?**
A: Probably not. Push down harder — the plate clips usually need firm pressure to engage. If the switch still wobbles after firm even pressure, remove and re-inspect. A dead socket is rare and has a distinctive symptom: the switch falls right out with no resistance at all.

**Q: How many times can I swap before I need to worry about socket wear?**
A: Realistically, far more times than you will want to swap switches. 100 is the rated minimum; 300+ is common in practice. Don't track it.
