# Keyboard Documentation

Everything you need to go from "I have a Corne" to knowing keyboards deeply — and buying more confidently.

---

## Corne Keyboard

Your keyboard. Start here if you want to understand what you have, modify it, or build another one.

| Document | What's inside |
|----------|--------------|
| [overview.md](corne/overview.md) | What the Corne is, why it exists, column stagger theory, controllers, OLED, community, where to buy, build costs |
| [versions.md](corne/versions.md) | Every Corne version (v1→v3, Corne-ish Zen, LP, Mini), MX vs Choc comparison, similar boards (Lily58, Sofle, Kyria, Dactyl, Moonlander, Glove80) |
| [layouts.md](corne/layouts.md) | Base layer alphabets (QWERTY, Colemak-DH, Dvorak, Workman, Canary), Miryoku layer strategy, home row mods deep dive, your 7 layers mapped, combos, thumb cluster, learning resources |
| [firmware.md](corne/firmware.md) | ZMK vs QMK, nice!nano v2 internals, how your GitHub Actions build works, every behavior explained, your `.keymap` and `.conf` line by line, flashing, ZMK Studio, troubleshooting |
| [build-guide.md](corne/build-guide.md) | Full parts list, tool guide, 9-step soldering order (diodes → switches → case), battery wiring, BLE pairing, testing checklist, common mistakes, cost breakdown |
| [accessories.md](corne/accessories.md) | Cases (acrylic, 3D print, aluminum), tenting, TRRS/USB-C cables, desk mats, wrist rests, batteries, sound mods (tape mod, PE foam, lubing), trackball mods, RGB upgrades, full vendor table |
| [switch-swapping.md](corne/switch-swapping.md) | How to change switches on your hot-swap Corne — tools needed, step-by-step removal and installation, testing, troubleshooting socket issues, experimentation workflow |
| [zmk-customization.md](corne/zmk-customization.md) | **How to actually edit your keymap** — change a key, add a combo, tune home row mod timing, add a new layer, write a macro, toggle features in .conf, common build errors, real paste-ready code recipes |

---

## Keyboard Research

General keyboard education — hardware, components, the whole market.

| Document | What's inside |
|----------|--------------|
| [switches-research.md](keyboard-research/switches-research.md) | Anatomy, linear/tactile/clicky types, Topre, Hall Effect (Wooting), optical, Alps, brand tiers, lubing, hot-swap vs soldered, switch testers, buying guide |
| [switches-buying-guide.md](keyboard-research/switches-buying-guide.md) | **What switches to actually buy** — feel decision tree, 6 curated picks with INR prices, Amazon India ASINs, Meckeys/Stickeys/StacksKB vendor guide, import cost calculator, lube sources India, what to avoid |
| [keys-research.md](keyboard-research/keys-research.md) | Keycap anatomy, ABS vs PBT vs POM, every profile (OEM/Cherry/SA/DSA/XDA/MT3/KAT/G20), legend methods (double-shot/dye-sub/laser), RGB shine-through, 40% buying tips, artisans, price ranges |
| [keycap-buying-guide.md](keyboard-research/keycap-buying-guide.md) | **What to actually buy** — uniform vs sculpted (why DSA/XDA only for Corne), ranked profiles, 6 curated picks with INR prices, Amazon India links, Indian vendor guide (Meckeys, Stickeys, Credkeys), import costs, what to avoid |
| [keyboard-types.md](keyboard-research/keyboard-types.md) | Every form factor (100%→40%), layout geometry (staggered/ortho/columnar), split vs unified, connection types, mount systems, case/plate materials, sound design, gaming vs enthusiast vs custom, budget tiers with specific board recommendations |
| [india-bangalore-buying-guide.md](keyboard-research/india-bangalore-buying-guide.md) | Physical stores in Bangalore (addresses + phones), Indian online vendors, Parix.in for pre-built Cornes, IMKC Discord, Bangalore keyboard meetup, import duty guide, price guide in INR, Bangalore makerspaces for DIY builds |

---

## Quick-Start Paths

**"I want to understand my Corne"** → `corne/overview.md` → `corne/firmware.md` → `corne/layouts.md`

**"I want to change my switches"** → `corne/switch-swapping.md` (how) → `keyboard-research/switches-buying-guide.md` (what to buy)

**"I want to buy another keyboard"** → `keyboard-research/keyboard-types.md` → `corne/versions.md`

**"I want to buy stuff in Bangalore"** → `keyboard-research/india-bangalore-buying-guide.md`

**"I want to build a second Corne"** → `corne/build-guide.md` → `corne/accessories.md`

**"I want different keycaps"** → `keyboard-research/keycap-buying-guide.md` (what to buy) then `keyboard-research/keys-research.md` (theory)

**"I want to change something in my keymap"** → `corne/zmk-customization.md`
