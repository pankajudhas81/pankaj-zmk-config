# Keyboard Layouts on the Corne — A Complete Guide

> **Your setup at a glance:** QWERTY base · GACS home row mods · 7 Miryoku-style layers  
> accessed via 6 thumb holds · 14 combos · ZMK firmware on nice!nano v2

This guide covers everything about *software* layout: what characters your keys produce, how
layers are organized, and how the decisions behind each approach affect typing comfort, speed,
and portability. Physical key positions (switches, PCB, case) are covered in the build docs.

---

## Table of Contents

1. [Why Layout Matters on a 42-Key Board](#1-why-layout-matters-on-a-42-key-board)
2. [Base Layer Layouts — The Alphabets](#2-base-layer-layouts--the-alphabets)
   - QWERTY · Dvorak · Colemak · Colemak-DH · Workman · RSTHD · Hands Down · Canary
3. [Layout Comparison Table](#3-layout-comparison-table)
4. [Layer Organization Strategies](#4-layer-organization-strategies)
   - Miryoku · 3×5+3 vs 3×6+3 · Callum-style · Seniply · Traditional 40%
5. [Home Row Mods — Deep Dive](#5-home-row-mods--deep-dive)
6. [Combos on the Corne](#6-combos-on-the-corne)
7. [Thumb Cluster Usage](#7-thumb-cluster-usage)
8. [Your Full Layout — All 7 Layers Mapped](#8-your-full-layout--all-7-layers-mapped)
9. [Layout Analysis Tools & Learning Resources](#9-layout-analysis-tools--learning-resources)
10. [Should You Switch From QWERTY?](#10-should-you-switch-from-qwerty)

---

## 1. Why Layout Matters on a 42-Key Board

A full-size keyboard has ~104 keys. A Corne has 42. That 60% reduction means everything that
*isn't* the alphabet needs a different strategy. Here's the breakdown of what's gone and how
you recover it:

| Key category | Full-size count | Corne count | Recovery strategy |
|---|---|---|---|
| Alphabet (A–Z) | 26 | 26 | Present on base layer |
| Numbers 0–9 | 10 | 0 on top row | Layer (NUM) or combos |
| Function keys F1–F12 | 12 | 0 | Layer (FUN) |
| Symbols (`!@#$%^&*()…`) | ~30 | 0 dedicated | Layer (SYM) |
| Navigation (arrows, PgUp…) | ~17 | 0 dedicated | Layer (NAV) |
| Modifiers (Ctrl, Shift…) | 4–8 | Reduced | Home row mods + thumbs |
| Punctuation (`,./;'`) | ~9 | 6 on base | Rest on layers or combos |

**The cascading consequence:** because numbers, symbols, and function keys all live on layers,
your *base layout* choice determines which letters are fastest to type, and your *layer
organization* determines how quickly you can escape the base layer to reach everything else.

On a 42-key board, you are no longer fighting the keyboard's physical constraints — you're
making deliberate architectural decisions about information access. That's what makes this
interesting.

### The Two Axes of Layout Design

```
AXIS 1 — BASE LAYER (alphabet arrangement)
  Comfort of typing prose ←─────────────────────────────────────→ Ergonomic optimization
  QWERTY (historical)        Colemak (balanced)        Colemak-DH (optimized)

AXIS 2 — LAYER STRATEGY (how you access everything else)
  Simple (Raise/Lower)  ←─────────────────────────────────────→  Comprehensive
  Traditional 40%            Callum-style                Miryoku
```

Your Corne sits near the optimized end of both axes — QWERTY base with Miryoku layer strategy.
Many users start here and either stay (QWERTY is fine) or switch the base layer later while
keeping the Miryoku layer structure intact, since ZMK makes that a trivial change.

### Columnar Stagger — Why It Changes Everything

Before comparing layouts, understand what makes the Corne physically different from a standard
keyboard:

```
Standard row-stagger (what QWERTY was designed for):

  [Q][W][E][R][T]...
   [A][S][D][F][G]...      ← Each row offset ~0.5u to the right
    [Z][X][C][V][B]...

Corne columnar stagger (what your board uses):

  [Q][W][E][R][T]       Middle and ring columns raised
   ↑  ↑  ↑              to match longer fingers
  [A][S][D][F][G]
  [Z][X][C][V][B]       Each column is VERTICAL — no horizontal offset
```

On a row-stagger board, hitting the key "above" your finger requires a diagonal movement. On a
columnar board, you move straight up and down — matching natural finger anatomy. This has real
consequences for which alt-layouts are most comfortable, as we'll explore.

---

## 2. Base Layer Layouts — The Alphabets

### QWERTY

**Invented:** 1873 by Christopher Sholes for the Sholes & Glidden typewriter.  
**Design goal:** Prevent mechanical type-bar jams by separating commonly paired letters.

The layout was *not* designed for typing speed or ergonomics. It was a mechanical engineering
solution to a mechanical problem that hasn't existed since the 1970s. Despite this, QWERTY
became universal through decades of network effects, and that ubiquity is its greatest strength.

**On the Corne:**

```
QWERTY on Corne (your current BASE layer)
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ TAB │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │BKSP │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│CTL/ │  A  │  S  │  D  │  F  │  G  │   │  H  │  J  │  K  │  L  │  '  │HYPR │
│ ESC │[GUI]│[ALT]│[CTL]│[SHF]│     │   │     │[SHF]│[CTL]│[ALT]│[GUI]│     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│SHFT │  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │ ESC │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
                    ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
                    │[MED]│[NAV]│[MOU]│   │[SYM]│[NUM]│[FUN]│
                    │ ESC │ SPC │ TAB │   │ RET │BKSP │ DEL │
                    └─────┴─────┴─────┘   └─────┴─────┴─────┘

  [X] = hold for modifier X      [MED] = hold for MEDIA layer
```

**Alpha positions only (ignoring modifiers):**
```
  Q   W   E   R   T       Y   U   I   O   P
  A   S   D   F   G       H   J   K   L   '
  Z   X   C   V   B       N   M   ,   .   /
```

**Strengths:**
- Universal. Every computer, phone, library terminal uses it. Zero portability cost.
- You already know it. Fastest time to proficiency on a new 42-key layout.
- Vim arrows (HJKL) land on the right home row in a natural cluster — no relearning needed.
- Shortcuts (Cmd+Z, X, C, V) cluster on the left bottom row under your left hand — ergonomic
  for one-handed shortcuts.

**Weaknesses (on any board):**
- Same-finger bigram (SFB) rate ~6.6% — two consecutive letters typed by the same finger.
  Example: "ed", "lo", "un" all share a finger in QWERTY.
- E and R are typed with the same finger (middle). E is the most common letter in English.
- Heavy right-hand load: most vowels are on the right.
- On a *columnar* stagger specifically: "B" sits in the left-index inner column, requiring an
  inward stretch that's somewhat uncomfortable on a board without the traditional row offset.

**Verdict for Corne:** Works great. The Miryoku layer strategy is layout-agnostic, and most
Corne users start with QWERTY. The SFB disadvantage is real but only matters at 80+ WPM.

---

### Dvorak

**Invented:** 1936 by August Dvorak and William Dealey.  
**Design goal:** Maximize typing efficiency based on English letter frequency analysis.

**Core philosophy:**
- All vowels on the left home row (A O E U I)
- Most common consonants on the right home row (D H T N S)
- Common letters should alternate between hands (reduces same-hand runs)
- Frequent letters on home row, infrequent on bottom row

**Alpha positions:**
```
  '   ,   .   P   Y       F   G   C   R   L
  A   O   E   U   I       D   H   T   N   S
  ;   Q   J   K   X       B   M   W   V   Z
```

**On Corne (42-key):**
```
DVORAK on Corne (hypothetical)
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ TAB │  '  │  ,  │  .  │  P  │  Y  │   │  F  │  G  │  C  │  R  │  L  │BKSP │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│CTL/ │  A  │  O  │  E  │  U  │  I  │   │  D  │  H  │  T  │  N  │  S  │  /  │
│ ESC │[GUI]│[ALT]│[CTL]│[SHF]│     │   │     │[SHF]│[CTL]│[ALT]│[GUI]│     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│SHFT │  ;  │  Q  │  J  │  K  │  X  │   │  B  │  M  │  W  │  V  │  Z  │ ESC │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
                    ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
                    │[MED]│[NAV]│[MOU]│   │[SYM]│[NUM]│[FUN]│
                    │ ESC │ SPC │ TAB │   │ RET │BKSP │ DEL │
                    └─────┴─────┴─────┘   └─────┴─────┴─────┘
```

**Strengths:**
- SFB rate ~2.6% — significant improvement over QWERTY.
- Strong hand alternation encourages rhythm.
- All vowels clustered on left home row: vowels account for ~38% of English text, all at the
  fingertips.
- Lower total finger travel distance than QWERTY.

**Weaknesses:**
- Very high portability cost. 33 keys move from QWERTY. You'll feel like you can't type anywhere else.
- Common shortcuts (Cmd+Z, X, C, V) scatter across the keyboard — these are no longer on the
  left-bottom cluster.
- Vim shortcuts (HJKL) move to completely different positions — if you use vim or vim-style
  navigation, this matters.
- The learning curve is steep: essentially a full re-wiring of motor memory.
- Smaller enthusiast community than Colemak.

**Home row mod synergy:** AOEUI on left home row means your mods (GACS: A=GUI, O=ALT, E=CTL,
U=SHF) bind to vowels. This is workable but some find it slightly odd to hold 'O' for Alt.

**Verdict for Corne:** A serious option for typists who work primarily on their own machine and
are willing to invest 3–6 months. The SFB improvement is real. However, Colemak-DH achieves
similar efficiency with a gentler transition and larger community support.

---

### Colemak

**Invented:** 2006 by Shai Coleman (username "colemak").  
**Design goal:** Achieve Dvorak-class efficiency with a gentler transition from QWERTY.

**Core decisions:**
- Keep 10 keys in QWERTY positions (Z, X, C, V, B — shortcuts cluster; also Q, W, G, H, M)
- Move only 17 keys total (vs Dvorak's 33)
- Put the most frequent letters on the home row
- Eliminate E–D and U–R same-finger pairs that plague QWERTY

**Alpha positions:**
```
  Q   W   F   P   G       J   L   U   Y   ;
  A   R   S   T   D       H   N   E   I   O
  Z   X   C   V   B       K   M   ,   .   /
```

**On Corne (42-key):**
```
COLEMAK on Corne
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ TAB │  Q  │  W  │  F  │  P  │  G  │   │  J  │  L  │  U  │  Y  │  ;  │BKSP │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│CTL/ │  A  │  R  │  S  │  T  │  D  │   │  H  │  N  │  E  │  I  │  O  │  '  │
│ ESC │[GUI]│[ALT]│[CTL]│[SHF]│     │   │     │[SHF]│[CTL]│[ALT]│[GUI]│     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│SHFT │  Z  │  X  │  C  │  V  │  B  │   │  K  │  M  │  ,  │  .  │  /  │ ESC │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
                    ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
                    │[MED]│[NAV]│[MOU]│   │[SYM]│[NUM]│[FUN]│
                    │ ESC │ SPC │ TAB │   │ RET │BKSP │ DEL │
                    └─────┴─────┴─────┘   └─────┴─────┴─────┘
```

**Notable changes from QWERTY:**
- `E` moves to right home row (was upper-right). E is the most common English letter.
- `N` moves to right home row index (was bottom row right).
- `S` moves to left middle finger home row (was left ring). Enables ARST home row.
- `T` moves to left index home row (was top row). Very common letter.
- `D` moves to right middle — inward of home row (inner column).
- Semicolon position is vacated by moving `;` to top row, making room for `O` on right pinky home.

**Strengths:**
- SFB rate ~1.5% — excellent, comparable to Colemak-DH.
- ZXCV shortcuts preserved in their QWERTY positions.
- 10 keys unchanged from QWERTY — genuinely gentler transition.
- Very large community, extensive documentation, many learning resources.
- Compatible with vim navigation — HJKL stays on right home row (H stays, others move but HJ
  are adjacent right-hand).

**Weaknesses:**
- D is on the inner column (between G and H on row-stagger; between B and J on columnar).
  On the Corne's columnar stagger, reaching inward is slightly awkward for the index finger.
- H is also on an awkward position (similar inner index stretch on right hand).
- The D–H lateral index stretch issue motivated the Colemak-DH modification.

---

### Colemak-DH (Colemak Mod-DH)

**Invented:** 2014 by Steve P (username "stevep99").  
**Design goal:** Fix Colemak's uncomfortable D and H positions for columnar keyboards.

**The problem with standard Colemak on columnar boards:**

On a row-stagger keyboard, the "B" key and "Y" key are outer index keys, but the stagger means
they're actually somewhat inward. On a columnar stagger board like the Corne, there is no such
offset — the inner column is a genuine inward reach that fights finger anatomy.

In standard Colemak, `D` sits at position `QWERTY-G` (left index inner column) and `H` sits at
`QWERTY-H` (right index inner column). On a row-stagger keyboard, these are acceptable.  
On a **columnar** keyboard, these positions require the index fingers to curl inward —  
uncomfortable for extended sessions.

Colemak-DH solves this by:
- Moving `D` from the inner column to the bottom row left index: `QWERTY-V` position
- Moving `H` from the inner column to the left index home row: `QWERTY-M` position  
- Swapping `M` and `B` (minor adjustment to accommodate)

**Alpha positions:**
```
  Q   W   F   P   B       J   L   U   Y   ;
  A   R   S   T   G       M   N   E   I   O
  Z   X   C   D   V       K   H   ,   .   /
```

**On Corne (42-key) — considered the ideal pairing:**
```
COLEMAK-DH on Corne (community's current recommendation)
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ TAB │  Q  │  W  │  F  │  P  │  B  │   │  J  │  L  │  U  │  Y  │  ;  │BKSP │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│CTL/ │  A  │  R  │  S  │  T  │  G  │   │  M  │  N  │  E  │  I  │  O  │  '  │
│ ESC │[GUI]│[ALT]│[CTL]│[SHF]│     │   │     │[SHF]│[CTL]│[ALT]│[GUI]│     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│SHFT │  Z  │  X  │  C  │  D  │  V  │   │  K  │  H  │  ,  │  .  │  /  │ ESC │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
                    ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
                    │[MED]│[NAV]│[MOU]│   │[SYM]│[NUM]│[FUN]│
                    │ ESC │ SPC │ TAB │   │ RET │BKSP │ DEL │
                    └─────┴─────┴─────┘   └─────┴─────┴─────┘
```

**Why Colemak-DH is the current community favorite for split columnar boards:**
- SFB rate ~1.5% (same as Colemak) — very efficient.
- Eliminates the uncomfortable lateral index stretch (D and H moved to natural positions).
- Works with the Corne's column stagger rather than against it.
- ZXCV preserved. Transition from QWERTY requires 19 key relearns (2 more than Colemak).
- The Miryoku layout explicitly supports Colemak-DH as a first-class option.
- Huge and growing community — r/KeyboardLayouts, Colemak Discord, Typing Club.

**Home row mods:** ARST on left, MNEI on right. `A=GUI, R=ALT, S=CTL, T=SHF` and mirrored.
Note the GACS names shift slightly — you'd use ARST instead of ASDF, but the modifier *order*
(GUI, Alt, Ctrl, Shift from pinky to index) stays identical.

**Verdict for Corne:** If you're going to switch at all, this is the layout to switch to.
The Corne's columnar stagger is *literally designed* to make Colemak-DH comfortable.

---

### Workman

**Invented:** 2010 by OJ Bucao.  
**Design goal:** Reduce lateral finger movement (side-to-side) in favor of vertical movement.

Workman's designer argued that vertical movement (up/down columns) is more natural than
horizontal movement, and that Colemak still required too much lateral reach. Workman also
specifically considers the row-stagger geometry of standard keyboards.

**Alpha positions:**
```
  Q   D   R   W   B       J   F   U   P   ;
  A   S   H   T   G       Y   N   E   O   I
  Z   X   M   C   V       K   L   ,   .   /
```

**Strengths:**
- Low lateral movement index.
- Comfortable feel for many typists who tried Colemak and found certain bigrams still awkward.
- Active community at https://workmanlayout.org

**Weaknesses:**
- SFB rate ~2.0% — worse than Colemak.
- ZXCV shortcuts less preserved than Colemak.
- Smaller community than Colemak.
- On columnar boards, some of Workman's design assumptions (based on row-stagger geometry)
  don't apply the same way — Colemak-DH was designed *for* columnar boards; Workman was not.

---

### RSTHD

**Invented:** 2020 by Derek Chen.  
**Design goal:** One-handed typing patterns and heavy thumb use.

RSTHD puts the most common English letters under the strongest fingers and on the home row.
The name comes from the right-hand home row: R S T H D. The E key is moved to the thumb
(a defining feature — the most common English letter lives on the thumb).

**Alpha positions (simplified):**
```
  J   C   Y   F   K       Z   L   ,   U   Q
  R   S   T   H   D       M   N   A   I   O
  /   V   G   P   B       X   W   .   ;   '
  [thumb: E]                  [thumb: space]
```

**Relevance to Corne:** Highly niche. The idea of putting E on the thumb is interesting
(and the Corne has a proper thumb cluster to accommodate it), but the community is tiny
and the learning curve extreme.

---

### Hands Down Neu / Hands Down Gold

**Invented:** 2021–2023 by Alan Reiser (reddit: u/Alan_Reiser).  
**Designed specifically for:** 34–42 key split columnar keyboards.

Hands Down is a family of layouts (there are several variants: Neu, Gold, Silver, Platinum)
designed from scratch with modern ergonomic keyboards in mind. Unlike QWERTY or even Colemak,
these were never a row-stagger compromise.

**Key design principles:**
- Minimize same-finger bigrams (target <1%)
- Optimize for columnar stagger (no row-stagger assumptions)
- Use thumb cluster for common keys (Space, E, or similar)
- Minimize lateral index finger movement
- Balance hand load

**Hands Down Neu (one variant):**
```
  W   F   M   P   V       /   .   Q   "   '
  R   S   N   T   G       ,   A   E   I   H
  X   C   L   D   B       -   U   O   Y   K
  [thumb: Z/J]  [space]       [backspace]
```

**Hands Down Gold:**
```
  J   G   M   P   V       ;   .   /   "   '
  R   S   N   D   B       ,   A   E   I   H
  X   F   L   C   W       -   U   O   Y   K
```

**Strengths:**
- SFB rate <1% on well-tested variants — best in class.
- Designed for split columnar — the Corne is its natural habitat.
- Active development with corpus analysis backing each change.
- Growing community at r/KeyboardLayouts and the Hands Down Discord.

**Weaknesses:**
- No QWERTY overlap — full relearn required.
- Shortcuts (ZXCV) completely scattered.
- Smaller community than Colemak.
- Multiple variants create confusion — which one is "right"?

**Worth watching:** As of 2024–2025, Hands Down variants are gaining traction among people who
buy a split columnar keyboard *first* and learn to type from scratch on it.

---

### Canary

**Invented:** 2023 by the Canary layout team (community project).  
**Design goal:** Minimize same-finger bigrams and lateral stretch, specifically for modern
ergonomic keyboards.

Canary emerged from the competitive layout analysis community (people who run Monte Carlo
simulations over large English corpora to find optimal letter arrangements).

**Alpha positions:**
```
  W   L   Y   P   B       Z   F   O   U   '
  C   R   S   T   G       M   N   E   I   A
  Q   J   V   D   K       X   H   /   ,   .
```

**Why it's notable:**
- SFB rate around 0.9–1.1% on English corpora — competitive with Hands Down.
- Strong community analysis and data backing.
- Good hand alternation score.
- Designed from day one with columnar keyboards in mind.

**Weaknesses:**
- 2023 release — very small community, limited learning resources.
- All shortcuts need to be remapped.
- No real-world veteran typists yet (layout too new for 10-year veterans).

---

## 3. Layout Comparison Table

| Layout | Year | Keys changed from QWERTY | Home row (L→R) | SFB rate | ZXCV shortcuts | Learning curve | Community |
|---|---|---|---|---|---|---|---|
| QWERTY | 1873 | 0 | ASDF / HJK;L | ~6.6% | ✅ Intact | None | Universal |
| Dvorak | 1936 | 33 | AOEU I / DHTNS | ~2.6% | ❌ Scattered | Very steep | Medium |
| Colemak | 2006 | 17 | ARST / HNEIO | ~1.5% | ✅ Intact | Moderate | Large |
| Colemak-DH | 2014 | 19 | ARST / MNEI O | ~1.5% | ✅ Intact | Moderate | Very large |
| Workman | 2010 | 21 | ASHT / YNEOI | ~2.0% | ⚠️ Partial | Moderate | Medium |
| RSTHD | 2020 | ~32 | RSTHD / MNAIO | ~1.1% | ❌ Scattered | Steep | Small |
| Hands Down Neu | 2021 | ~32 | RSNTG / AEIH | ~0.9% | ❌ Scattered | Steep | Growing |
| Canary | 2023 | ~28 | CRST / MNEIA | ~1.0% | ❌ Scattered | Steep | Very small |

**Notes on "SFB rate":** These numbers vary by corpus and counting methodology. Numbers above
are approximate for English text. Any alt layout below 2% is a meaningful improvement over
QWERTY. Below 1.5%, you're in the diminishing returns zone for most people.

**Notes on "Learning curve":** All ratings assume you're already a fluent QWERTY typist. Starting
with no existing muscle memory (rare for adults) changes all the curves significantly.

---

## 4. Layer Organization Strategies

A "layer strategy" is the architecture of how you organize access to the ~100 keys that don't
fit on 42 physical positions. This is independent of your base alpha layout — you can run
Colemak-DH with Miryoku layers or QWERTY with Miryoku layers; the alpha arrangement doesn't
affect the layer organization at all.

### Miryoku — What You Run

**Author:** Manna Harbour (GitHub: [manna-harbour](https://github.com/manna-harbour))  
**Reference:** https://github.com/manna-harbour/miryoku  
**Minimum keys:** 36 (3×5+3 — no pinky columns)

Miryoku is the most influential layer strategy in the modern 40% community. It proved that
you could access a complete keyboard — all symbols, numbers, function keys, nav, mouse, and
media — from a 36-key board without any compromises, purely through thoughtful layer design.

**Core philosophy:**
1. Every useful key is accessible from the home row, with at most one thumb hold.
2. Layers are accessed by holding a thumb key, not toggling.
3. Home row mods provide all modifiers without dedicated modifier keys.
4. Each layer focuses on one function domain (nav, numbers, symbols, etc.).
5. Mirror structure: left-hand modifiers available when right-hand navigates, and vice versa.

**Miryoku's 6-layer structure (standard):**

```
Left thumb holds:        Right thumb holds:
  Outer  → Media           Outer  → Fun
  Middle → Nav             Middle → Num
  Inner  → Mouse           Inner  → Sym
```

**Your 7-layer implementation (Miryoku-inspired):**

You faithfully implement this structure with the layer-to-thumb mapping:

```
Left Thumb:     [MED/ESC]   [NAV/SPC]   [MOU/TAB]
                  hold↑       hold↑        hold↑

Right Thumb:    [SYM/RET]   [NUM/BKSP]  [FUN/DEL]
                  hold↑       hold↑        hold↑
```

**Why this mapping is ergonomically intelligent:**
- **Space** activates NAV: you press Space (most common key) and HJKL to navigate. Space is held
  where your strongest thumb naturally rests.
- **Backspace** activates NUM: your right thumb's strongest position, used frequently in forms
  and code where numbers appear.
- **Tab** activates MOUSE: less common, so assigned to the outer (less comfortable) left thumb.
- **Enter** activates SYM: symbols often follow expressions/words where you'd logically hit
  Enter — ergonomic grouping.
- **Delete** activates FUN: function keys are the rarest, assigned to the outermost right thumb.

**The "mirror modifier" pattern:** When you hold `NAV/SPC` (right hand navigates with HJKL),
your left hand home row produces modifiers (GUI, ALT, CTL, SHF). This means you can do
Shift+Arrow, Ctrl+Arrow (word-jump), Cmd+Shift+Arrow (select to word/line end) entirely on
the keyboard — the left hand holds the modifier, the right hand hits the arrow. This pattern
appears on every layer: the idle hand's home row always produces modifiers.

---

### 3×5+3 vs 3×6+3 — The Pinky Column Question

**Pure Miryoku:** 3×5+3 = 36 keys (no pinky column)

```
Pure Miryoku (36 keys):
┌─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
│  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │
├─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┤
│  A  │  S  │  D  │  F  │  G  │   │  H  │  J  │  K  │  L  │  '  │
├─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┤
│  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │
└─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
                    ┌───┬───┬───┐   ┌───┬───┬───┐
                    │MED│NAV│MOU│   │SYM│NUM│FUN│
                    └───┴───┴───┘   └───┴───┴───┘
```

**Your Corne:** 3×6+3 = 42 keys (has pinky columns)

The extra 6 keys (3 per pinky) are a gift from the Corne's design. Common uses:

```
Pinky column typical assignments:
Left pinky col:          Right pinky col:
  Row 0: TAB               Row 0: BKSP
  Row 1: CTL/ESC           Row 1: GUI or HYPR
  Row 2: SHIFT             Row 2: ESC
```

Having these keys on the pinky columns means your thumb cluster doesn't need to handle Tab,
Backspace, or Escape as tap keys — your thumbs can focus on layer activation and Enter/Space.
This reduces thumb fatigue and thumb key "collisions" (where you have too many important tap
keys fighting for thumb real estate).

**Your implementation:** You use the extra pinky keys for exactly this — TAB, CTRL/ESC, SHIFT
on the left; BKSP, HYPR, ESC on the right — giving your thumbs a cleaner job.

---

### Callum-Style Mods

**Author:** Callum Oakley (GitHub: [callum-oakley/qmk_firmware](https://github.com/callum-oakley/qmk_firmware))

An alternative to Miryoku's hold-tap home row mods. Instead of *holding* a letter to produce
a modifier, you use **one-shot modifiers** (OSM): tap the modifier key, then tap the letter.
The modifier stays active for exactly one subsequent keypress.

**How it works:**
- Dedicated modifier keys on a layer (not on home row letters)
- Tap Shift → next key is shifted → Shift deactivates automatically
- Can stack: tap Ctrl, tap Shift, tap letter → sends Ctrl+Shift+letter

**Advantages over home row mods:**
- Zero timing issues — no tapping-term to tune, no misfires
- Modifier intent is unambiguous
- Faster for single modified keypresses

**Disadvantages:**
- Requires separate modifier keys on a layer — more keystrokes for common combos
- Held modifiers (for drag-selecting, etc.) require a different approach
- Loses the elegance of Miryoku's home-row-is-always-modifiers design

**Who chooses Callum-style:** People who type fast (80+ WPM) and find home row mod misfires
intolerable even after tuning. If you find yourself fighting your tapping-term, Callum-style
is worth investigating.

---

### Seniply

**Author:** Colin Lam (seniply.net / GitHub)  
**Minimum keys:** 34 (3×5+2 — only 2 thumb keys per hand)

Seniply is a compact layer strategy designed for boards with even fewer thumb keys than Miryoku
(e.g., Ferris/Sweep with only 2 thumb keys per hand). It uses 5 layers and combos more
aggressively to compensate.

**Relevance to your Corne:** Seniply would technically work on a Corne (you have 3 thumb keys
per side — more than Seniply needs). Some people prefer Seniply's simpler mental model: fewer
layers with more combos. If you find Miryoku's 7 layers conceptually heavy, Seniply is a
simpler alternative to explore.

---

### Traditional 40% (Raise/Lower)

The oldest and most common approach to 40% keyboards, predating Miryoku. Two dedicated thumb
keys labeled "Lower" and "Raise" (or "Layer 1" and "Layer 2"), no home row mods.

**Structure:**
```
          [LOWER held]   → Numbers and symbols on the alpha keys
          [RAISE held]   → More symbols and function keys
          [LOWER+RAISE]  → Adjust layer (RGB, Bluetooth, etc.)
```

**Example (typical QMK default for Let's Split, Planck, etc.):**
```
BASE:    Q  W  E  R  T  │  Y  U  I  O  P
         A  S  D  F  G  │  H  J  K  L  ;
         Z  X  C  V  B  │  N  M  ,  .  /
              [SHF][LWR][SPC] [ENT][RSE][DEL]

LOWER:   !  @  #  $  %  │  ^  &  *  (  )
         ...
RAISE:   1  2  3  4  5  │  6  7  8  9  0
         ...
```

**Strengths:**
- Conceptually simple — two layers, two dedicated keys.
- Well-documented. Every entry-level QMK keyboard uses this.
- No timing issues — no hold-tap behavior.
- Familiar to new users.

**Weaknesses:**
- Thumb keys can't do tap-vs-hold, so Space, Enter, Tab need separate positions or combos.
- Only two layer keys means layer access is less granular.
- Accessing modifier+layer+key combos is awkward.
- Doesn't scale well when you need 6+ layers.

**Why you're not using this:** The Miryoku approach is strictly superior for a 6-layer setup.
Traditional Raise/Lower exists because it predates Miryoku and is the default for most QMK
keyboards with stock firmware. You have ZMK and a clean slate — Miryoku is the right call.

---

## 5. Home Row Mods — Deep Dive

Home row mods (HRM) are the defining feature of modern minimalist keyboards. The idea: instead
of having dedicated modifier keys (or having your thumbs do modifier duty), you make your home
row letters dual-function:

- **Tap** the key → produces the letter.
- **Hold** the key → produces the modifier.

You can type any letter, modifier combo, or layer access without moving your hands off the
home row.

### GACS — The Modifier Order

GACS stands for: **G**UI, **A**lt, **C**trl, **S**hift — from pinky to index finger on each hand.

```
Left hand:                Right hand (mirrored):
  Pinky  A → GUI (Cmd/Win)   Pinky  ' → RGUI
  Ring   S → ALT             Ring   L → RALT
  Middle D → CTRL            Middle K → RCTRL
  Index  F → SHIFT           Index  J → RSHIFT
```

**Why this order?**

The logic is frequency-based:

| Modifier | How often held alone | Why at this position |
|---|---|---|
| Shift | Most frequent (every capital letter) | Index finger — strongest |
| Ctrl | Second most (many shortcuts) | Middle finger — second strongest |
| Alt | Less common | Ring finger |
| GUI | Rarest in combos | Pinky — weakest, but GUI is rarely held long |

**Shift on the index finger** is the critical insight. You hold Shift constantly for capitalization.
Putting it on the strongest finger makes this comfortable. Older layouts put Shift on pinky
(dedicated Shift key position) — a weaker finger that fatigues faster.

### SCGA — The Alternative Order

Some layouts (notably, some Miryoku forks) use SCGA: Shift, Ctrl, GUI, Alt from pinky to index.

```
Pinky  → SHIFT  (most used mod on the weakest finger)
Ring   → CTRL
Middle → GUI
Index  → ALT
```

SCGA was motivated by the idea that the pinky key on home row (A in QWERTY) is a very frequent
letter — having it be the Shift hold means you accidentally trigger Shift when typing fast "as",
"that", etc. By putting Alt there instead (less common in combos), misfires matter less.

**The community consensus:** GACS has won. Most Miryoku users, the Miryoku documentation itself,
and most community resources recommend GACS. Your setup uses GACS. Stick with it.

### The Core Problem: Misfires

Home row mods have one significant challenge: **misfires**. When you type fast, you hold letters
longer than their tapping-term without intending to produce a modifier. Examples:

- Typing "as" fast: you might not release `A` before tapping `S`, triggering `GUI+S` (Save)
  instead of "as".
- Typing "the": holding `T` while hitting `H` might trigger `SHF+H` instead of "th".

This isn't theoretical — it's the main reason some typists abandon home row mods. The good news:
ZMK has mature solutions.

### ZMK's Home Row Mod Parameters

Your config (`&mt` behavior in `corne.keymap`):

```c
&mt {
    flavor = "tap-preferred";
    tapping-term-ms = <200>;
    quick-tap-ms = <175>;
    require-prior-idle-ms = <150>;
};
```

Let's break down each parameter:

#### `tapping-term-ms = <200>`

The decision boundary. If you hold a key for **less than 200ms**, it's a tap (letter). More
than 200ms, it's a hold (modifier). 

- **Too short (100ms):** Misfires constantly. You'll trigger modifiers mid-word.
- **Too long (400ms):** Modifier combos feel sluggish and deliberate. Layer activation is slow.
- **200ms:** Community consensus for most typists. Tune upward if misfires persist.

For reference: a typical typing speed of 60 WPM averages about 100ms per character. At 80 WPM,
around 75ms. The 200ms threshold is safely above normal typing speed, which is why it works.

#### `flavor = "tap-preferred"`

Determines what wins when there's ambiguity — when you hold the key and also tap another key
before the tapping-term expires.

Three flavors:

```
hold-preferred:   Any overlap → modifier wins.
                  A held while S pressed → GUI+S.
                  Fast typers: constant misfires.

balanced:         If the overlap key is released before the tapping-term,
                  tap wins. Otherwise hold.
                  Good middle ground, most widely recommended.

tap-preferred:    Only hold if the tapping-term expires alone (no other key pressed,
                  OR held past tapping-term regardless of other keys).
                  Safest for fast typists. Mods require deliberate hold.
```

Your `tap-preferred` setting means the letter wins in ambiguous situations — you'd only trigger
a modifier by deliberately holding past 200ms. This virtually eliminates accidental misfires
during normal typing rolls.

#### `require-prior-idle-ms = <150>`

This is the most powerful misfire prevention tool in ZMK. It says:

> "This hold-tap will only trigger its HOLD behavior if the keyboard was idle (no key pressed)
> for at least 150ms before this key was pressed."

In practice: if you're actively typing and press a home row mod key in the middle of a word,
it **cannot** trigger as a modifier. The modifier only activates if you paused typing for at
least 150ms first (i.e., you're intentionally reaching for a shortcut, not mid-word).

This single setting eliminates the majority of home row mod misfires for fast typists.

| Setting | Without `require-prior-idle` | With `require-prior-idle-ms = 150` |
|---|---|---|
| Typing "asdf" fast | Risk of GUI+S, GUI+D misfires | All register as letters |
| Pressing Cmd+Z after pause | Works | Works |
| Holding F while typing fast | Risk of SHIFT+next | Registers as letters |
| Holding F after 150ms pause | Produces SHIFT | Produces SHIFT |

#### `quick-tap-ms = <175>`

If you tap a home row key twice within 175ms (i.e., you typed that letter once and immediately
again), ZMK treats the second press as a repeat-tap, bypassing hold detection entirely.

This prevents the frustrating situation where typing "aa" (double-A) might be interpreted as
a modifier hold. With `quick-tap-ms`, the second tap within 175ms is always a letter.

### Practical Home Row Mod Tuning Guide

If you're experiencing misfires (letters being replaced by shortcuts), adjust in this order:

```
Step 1: Increase require-prior-idle-ms
  Try 150 → 175 → 200ms
  This fixes 80% of misfires for most typists.

Step 2: Increase tapping-term-ms
  Try 200 → 220 → 250ms
  Makes modifiers slightly more deliberate.

Step 3: Switch to tap-preferred flavor (if not already)
  Most conservative option. You're already using this.

Step 4: Consider per-key tapping-term
  Some people set a longer tapping-term for weaker fingers:
  Pinky (A, GUI): 250ms
  Ring (S, Alt): 230ms
  Middle (D, Ctrl): 200ms
  Index (F, Shift): 200ms
  (Weaker fingers hold letters longer naturally.)
```

If you're experiencing *missed* modifiers (intending a modifier but getting a letter):

```
Step 1: Decrease tapping-term-ms
  Try 200 → 180ms (but don't go below 150ms without require-prior-idle protection)

Step 2: Use hold-preferred or balanced flavor
  More aggressive modifier detection. Risks misfires for fast typists.
```

---

## 6. Combos on the Corne

A **combo** is a chord: pressing two (or more) keys *simultaneously* (within a timeout window)
produces a different output than either key alone. Combos let you access common keys without
leaving the home row or activating a layer.

Your Corne has 14 combos configured across three tiers:

### Combo Timeout Parameters

Your combo config uses:
- `timeout-ms = <30>` (horizontal combos) — very tight window: must be pressed within 30ms
- `timeout-ms = <40>` (vertical symbol combos) — slightly looser
- `require-prior-idle-ms = <150>` — same idle requirement as home row mods (prevents combos
  from firing mid-word)

The short timeout is intentional: you want combos to require a deliberate chord, not fire
accidentally during fast typing.

### Tier 1 — Essential Combos

These recover the most critical "missing" keys:

| Combo keys | Positions | Output | Rationale |
|---|---|---|---|
| `F` + `J` | 16 + 19 (index home, both hands) | Caps Word | Both index fingers simultaneously = unlikely during normal typing |
| `W` + `E` | 2 + 3 (top row, left middle+ring) | Escape | ⊕ Easy reach, natural for vim exit |
| `I` + `O` | 8 + 9 (top row, right ring+middle) | Backspace | Rightward mirror of WE combo |
| `O` + `P` | 9 + 10 (top row, right ring+pinky) | Delete | Adjacent to backspace combo |

```
Combo map — top section (positions 0-11):
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│  0  │  1  │  2  │  3  │  4  │  5  │   │  6  │  7  │  8  │  9  │ 10  │ 11  │
│     │  Q  │[W+E=ESC]  │  R  │  T  │   │  Y  │  U  │[I+O=BS][O+P=DEL]│BKSP │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
```

**Caps Word** is particularly useful: when activated, the next word is typed in all caps,
then automatically deactivates when you hit space, enter, or any non-letter. Perfect for
typing `MY_CONSTANT_NAME` without holding Shift.

### Tier 2 — High-Value Combos

These add frequently-needed keys without layer access:

| Combo keys | Positions | Output | Rationale |
|---|---|---|---|
| `S` + `D` | 14 + 15 (home row, left ring+middle) | Tab | Common in terminal/browser; natural chord |
| `K` + `L` | 20 + 21 (home row, right middle+ring) | Enter | Mirror of Tab on right hand |
| `X` + `C` | 26 + 27 (bottom row, left ring+middle) | Cmd+C (Copy) | Under shortcut fingers |
| `C` + `V` | 27 + 28 (bottom row, left middle+index) | Cmd+V (Paste) | Adjacent to copy |
| `X` + `V` | 26 + 28 (bottom row, skip middle) | Cmd+X (Cut) | Spans copy + paste positions |

```
Home row combos (positions 12-23):
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ 12  │ 13  │ 14  │ 15  │ 16  │ 17  │   │ 18  │ 19  │ 20  │ 21  │ 22  │ 23  │
│CTL/ │ A   │[S+D=TAB]  │  F  │  G  │   │  H  │  J  │[K+L=ENT]  │  '  │HYPR │
│ ESC │[GUI]│[ALT]│[CTL]│[SHF]│     │   │     │[SHF]│[CTL]│[ALT]│[GUI]│     │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
```

The **clipboard combos** (X+C=Copy, C+V=Paste, X+V=Cut) are beautiful ergonomics: the three
common clipboard operations share one finger cluster, all accessible without Cmd held since the
combo itself sends Cmd+key. Your left hand can copy, cut, and paste without ever moving off
the bottom row.

### Tier 3 — Vertical Symbol Combos

These are the most creative combos: adjacent keys in the *same column*, pressed together.
Because your fingers naturally rest in columns on a columnar board, vertical chords feel
natural:

| Combo keys | Positions | Output | Logic |
|---|---|---|---|
| `J` + `M` | 19 + 31 (right index column, home→bottom) | `-` (minus) | Right index vertical |
| `H` + `N` | 18 + 30 (right inner column, home→bottom) | `_` (underscore) | Minus's companion |
| `F` + `V` | 16 + 28 (left index column, home→bottom) | `=` (equal) | Left index vertical |
| `S` + `X` | 14 + 26 (left ring column, home→bottom) | `` ` `` (grave/backtick) | Left ring vertical |
| `L` + `'` | 21 + 22 (right ring+pinky home row) | `;` (semicolon) | Adjacent home row pair |

```
Vertical combo visualization (right hand):
     Home row:  ...  H    J    K    L    '   ...
                    ↕col ↕col
     Bot row:   ...  N    M    ,    .    /   ...

     H↕N = _     J↕M = -
     (underscore)  (minus)
```

**Why these symbols?** Minus, underscore, equal, and backtick are among the most common
punctuation in code. By putting them on vertical combos, they're accessible faster than
activating the SYM layer.

### The Full Combo Map

```
Position numbers (42 keys):
┌────┬────┬────┬────┬────┬────┐   ┌────┬────┬────┬────┬────┬────┐
│  0 │  1 │  2 │  3 │  4 │  5 │   │  6 │  7 │  8 │  9 │ 10 │ 11 │
├────┼────┼────┼────┼────┼────┤   ├────┼────┼────┼────┼────┼────┤
│ 12 │ 13 │ 14 │ 15 │ 16 │ 17 │   │ 18 │ 19 │ 20 │ 21 │ 22 │ 23 │
├────┼────┼────┼────┼────┼────┤   ├────┼────┼────┼────┼────┼────┤
│ 24 │ 25 │ 26 │ 27 │ 28 │ 29 │   │ 30 │ 31 │ 32 │ 33 │ 34 │ 35 │
└────┴────┴────┴────┴────┴────┘   └────┴────┴────┴────┴────┴────┘
                   ┌────┬────┬────┐  ┌────┬────┬────┐
                   │ 36 │ 37 │ 38 │  │ 39 │ 40 │ 41 │
                   └────┴────┴────┘  └────┴────┴────┘

Combos:
  Horizontal (timeout 30ms):   Vertical (timeout 40ms):
  2+3  = ESC                   16+28 = = (equal)
  8+9  = BKSP                  14+26 = ` (grave)
  9+10 = DEL                   19+31 = - (minus)
  14+15= TAB                   18+30 = _ (underscore)
  20+21= RET
  16+19= CAPS_WORD             Home-row horizontal (timeout 30ms):
  26+27= Cmd+C (copy)          21+22 = ; (semicolon)
  27+28= Cmd+V (paste)
  26+28= Cmd+X (cut)
```

---

## 7. Thumb Cluster Usage

The thumb cluster is the most powerful differentiator between a Corne and a traditional
keyboard. Human thumbs are under-utilized on standard keyboards — they handle only one key
(Space) despite being strong, dexterous digits.

### Thumb Key Philosophy

```
                    ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
                    │Outer│Inner│Inner│   │Inner│Inner│Outer│
                    │ (3) │ (2) │ (1) │   │ (1) │ (2) │ (3) │
                    └─────┴─────┴─────┘   └─────┴─────┴─────┘
                        ↑                           ↑
                    Less comfortable            Less comfortable
                    (requires rotation)         (requires rotation)
```

The innermost thumb keys (closest to each other, labeled (1) above) are the most comfortable —
your thumbs rest near them naturally. The outermost keys require your thumb to rotate or stretch.

**Rule:** Put your most frequent tap keys at (1), second-most frequent at (2), rarest at (3).

### Your Thumb Cluster

```
Left Thumb:                        Right Thumb:
┌──────────┬──────────┬──────────┐ ┌──────────┬──────────┬──────────┐
│ [MEDIA]  │  [NAV]   │ [MOUSE]  │ │  [SYM]   │  [NUM]   │  [FUN]   │
│   ESC    │  SPACE   │   TAB    │ │  ENTER   │ BACKSP   │  DELETE  │
└──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┘
  Outer(3)   Inner(1)   Inner(2)     Inner(2)   Inner(1)   Outer(3)

Tap = letter/control key
Hold = layer activation (shown in brackets)
```

**Frequency analysis of tap keys:**

| Key | Approximate frequency in text | Position | Correct? |
|---|---|---|---|
| Space | ~18% of all keystrokes | Left inner (1) | ✅ Most frequent → best position |
| Backspace | ~5% (editing) | Right inner (1) | ✅ Second most used delete action |
| Enter | ~3% | Right inner (2) | ✅ Frequent enough for inner position |
| Escape | ~2% (vim/apps) | Left outer (3) | ✅ Rare enough for outer position |
| Tab | ~2% | Left inner (2) | ✅ Reasonable, also activates MOUSE |
| Delete | ~1% | Right outer (3) | ✅ Rare, outer position appropriate |

**Layer frequency analysis:**

| Layer | How often accessed | Thumb position | Correct? |
|---|---|---|---|
| NAV | Very frequently (vim movement, selection) | Left inner (1) | ✅ |
| NUM | Frequently (code, forms) | Right inner (1) | ✅ |
| SYM | Frequently (code symbols) | Right inner (2) | ✅ |
| MEDIA | Occasionally (volume, BT) | Left outer (3) | ✅ |
| FUN | Rarely (function keys) | Right outer (3) | ✅ |
| MOUSE | Occasionally (GUI navigation) | Left inner (2) | ✅ |

Your thumb cluster design is well-optimized. The most frequent operations (Space, Backspace, NAV,
NUM) land on the strongest thumb positions.

### Quick-tap and Thumb Keys

Your `&lt` (layer-tap) behavior:

```c
&lt {
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <175>;
};
```

Note: your layer-tap uses `balanced` flavor (vs `tap-preferred` for home row mods). This is
intentional. For thumb keys, you want the hold to activate promptly when you intentionally hold
(e.g., holding Space to enter NAV layer). `balanced` is more responsive for layer access;
`tap-preferred` is safer for home row letters.

---

## 8. Your Full Layout — All 7 Layers Mapped

### Layer 0: BASE

```
BASE (QWERTY + GACS home row mods)
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ TAB │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │BKSP │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│CTL/ │  A  │  S  │  D  │  F  │  G  │   │  H  │  J  │  K  │  L  │  '  │HYPR │
│ ESC │[GUI]│[ALT]│[CTL]│[SHF]│     │   │     │[SHF]│[CTL]│[ALT]│[GUI]│     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│SHFT │  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │ ESC │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
                    ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
                    │[MED]│[NAV]│[MOU]│   │[SYM]│[NUM]│[FUN]│
                    │ ESC │ SPC │ TAB │   │ RET │BKSP │ DEL │
                    └─────┴─────┴─────┘   └─────┴─────┴─────┘
Notes:
  [X] = hold this key for modifier X
  HYPR = hold all four modifiers simultaneously (GUI+ALT+CTL+SHF) — useful for system shortcuts
  CTL/ESC = tap for ESC, hold for CTRL (using &mt LCTRL ESC behavior)
```

### Layer 1: NAV (hold Space)

```
NAV — Vim arrows, clipboard, navigation (hold SPACE on left thumb)
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │   │ REDO│PASTE│COPY │ CUT │UNDO │     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ GUI │ ALT │ CTL │ SHF │     │   │  ←  │  ↓  │  ↑  │  →  │CAPS │     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │   │HOME │PG_DN│PG_UP│ END │ INS │     │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
                    ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
                    │     │[NAV]│     │   │ RET │BKSP │ DEL │
                    │     │(held)│    │   │     │     │     │
                    └─────┴─────┴─────┘   └─────┴─────┴─────┘
Notes:
  REDO = Cmd+Shift+Z   PASTE = Cmd+V   COPY = Cmd+C   CUT = Cmd+X   UNDO = Cmd+Z
  Arrows follow HJKL vim positions (H=left, J=down, K=up, L=right)
  Left hand = modifiers — allows Shift+Arrow (select), Ctrl+Arrow (word-jump), etc.
  Thumb row = Enter, Backspace, Delete remain active while NAV is held
```

**Key workflow:** Hold Space → HJKL to navigate → release Space. For selecting text:
Hold Space + also hold F (SHIFT) → HJKL selects text character by character.
Ctrl+Shift+Arrow (word-select): Hold Space + D (CTRL) + F (SHF) + L (RIGHT arrow).

### Layer 2: NUM (hold Backspace)

```
NUM — Numpad layout for left hand (hold BKSP on right thumb)
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │  [  │  7  │  8  │  9  │  ]  │   │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  ;  │  4  │  5  │  6  │  =  │   │     │ SHF │ CTL │ ALT │ GUI │     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  ~  │  1  │  2  │  3  │  \  │   │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
                    ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
                    │  .  │  0  │  -  │   │     │[NUM]│     │
                    │     │     │     │   │     │(held)│    │
                    └─────┴─────┴─────┘   └─────┴─────┴─────┘
Notes:
  Numbers in numpad layout: 7-8-9 / 4-5-6 / 1-2-3 / 0 at thumb
  Bracket, semicolon, equals, tilde, backslash for coding convenience
  Dot and minus on thumb for decimal numbers and negative numbers
  Right hand = modifiers for Shift+Number (symbol combos without SYM layer)
```

**The numpad layout advantage:** 7-8-9 / 4-5-6 / 1-2-3 matches the numpad grid muscle memory.
After a few weeks, entering numbers without looking at your hands becomes natural.

### Layer 3: MEDIA (hold Escape)

```
MEDIA — Media control, Bluetooth, RGB (hold ESC on left thumb)
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │   │RGB  │RGB  │RGB  │RGB  │     │     │
│     │     │     │     │     │     │   │TOG  │EFF  │HUE+ │SAT+ │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ GUI │ ALT │ CTL │ SHF │     │   │ EP  │PREV │VOL- │VOL+ │NEXT │     │
│     │     │     │     │     │     │   │TOG  │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │   │OUT  │BT 0 │BT 1 │BT 2 │BT 3 │BTCLR│
│     │     │     │     │     │     │   │TOG  │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
                    ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
                    │[MED]│     │     │   │STOP │PLAY/│MUTE │
                    │(held)│    │     │   │     │PAUSE│     │
                    └─────┴─────┴─────┘   └─────┴─────┴─────┘
Notes:
  RGB: Toggle / next effect / hue+ / saturation+
  EP TOG = external power toggle (save battery on nice!nano)
  OUT TOG = toggle between USB and BLE output
  BT 0-3 = switch Bluetooth profile (4 device slots)
  BT CLR = clear current Bluetooth pairing
  Media: Stop / Play-Pause / Mute on right thumb
```

**Bluetooth workflow:** You have 4 BT profiles (devices 0–3). To switch from your Mac to iPad:
Hold Escape → tap BT 1. Done. The OUT TOG key lets you toggle USB vs Bluetooth.

### Layer 4: SYM (hold Enter)

```
SYM — Symbols (hold ENTER on right thumb)
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │  {  │  &  │  *  │  (  │  }  │   │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  :  │  $  │  %  │  ^  │  +  │   │     │ SHF │ CTL │ ALT │ GUI │     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  ~  │  !  │  @  │  #  │  |  │   │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
                    ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
                    │  (  │  )  │  _  │   │[SYM]│     │     │
                    │     │     │     │   │(held)│    │     │
                    └─────┴─────┴─────┘   └─────┴─────┴─────┘
Notes:
  Symbols organized in columns by category:
    Col 1 (pinky): { : ~ / ( )        — brackets and parens
    Col 2 (ring):  & $ !              — special: ampersand, dollar, bang
    Col 3 (middle):* % @              — Shift-number derivatives
    Col 4 (index): ( ^ # / ( )        — more parens, caret, hash
    Col 5 (inner): } + |              — closing bracket, plus, pipe
  Parentheses on thumb: ( and ) for wrapping expressions quickly
  Underscore on inner thumb (companion to minus on combos)
```

**SYM layer philosophy:** Symbols are grouped so related ones share a column. Shift-number
equivalents (!@#$%^&*) follow a left-to-right order with coding-relevant symbols scattered
in natural positions. The `{  }` opening and closing on the same hand is deliberate for typing
JavaScript/JSON object literals.

### Layer 5: FUN (hold Delete)

```
FUN — Function keys (hold DEL on right thumb)
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │ F12 │  F7 │  F8 │  F9 │PSCRN│   │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ F11 │  F4 │  F5 │  F6 │SLCK │   │     │ SHF │ CTL │ ALT │ GUI │     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ F10 │  F1 │  F2 │  F3 │PAUS │   │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
                    ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
                    │MENU │ SPC │ TAB │   │     │     │[FUN]│
                    │     │     │     │   │     │     │(held)│
                    └─────┴─────┴─────┘   └─────┴─────┴─────┘
Notes:
  F-keys in numpad layout: F7-F8-F9 / F4-F5-F6 / F1-F2-F3 / F10-F11-F12
  Matches the NUM layer layout — same hand positions = same muscle memory
  PSCRN = Print Screen, SLCK = Scroll Lock, PAUS = Pause/Break
  MENU = application menu key (right-click keyboard equivalent)
  Thumb: Space and Tab (for Shift+F5, Tab+F key combos in some apps)
```

### Layer 6: MOUSE (hold Tab)

```
MOUSE — Mouse movement, scrolling, buttons (hold TAB on left thumb)
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │DRG+ │DRG- │   │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ GUI │ ALT │ CTL │ SHF │     │   │ ←M  │ ↓M  │ ↑M  │ →M  │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │   │ ←SC │ ↓SC │ ↑SC │ →SC │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
                    ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
                    │     │     │[MOU]│   │LCLK │MCLK │RCLK │
                    │     │     │(held)│  │     │     │     │
                    └─────┴─────┴─────┘   └─────┴─────┴─────┘
Notes:
  M = mouse cursor movement (mmv MOVE_LEFT/DOWN/UP/RIGHT)
  SC = scroll (msc SCRL_LEFT/DOWN/UP/RIGHT)
  Mouse follows HJKL vim pattern — same finger positions as arrow keys on NAV
  LCLK = left click, RCLK = right click, MCLK = middle click
  DRG+ = drag_on macro (left-index R column, top row) — locks left button DOWN
  DRG- = drag_off macro (left-index T column, top row) — releases left button
```

**MOUSE layer insight:** Mouse and NAV layers mirror each other — HJKL in the same position
activates arrow keys on NAV and mouse movement on MOUSE. This means once you learn NAV
navigation, MOUSE navigation is automatic.

**Hold-drag workflow** (momentary — button held while key is held):
1. Hold TAB → MOUSE layer active
2. HJKL → move to target
3. Hold LCLK (right thumb inner) AND HJKL → cursor moves while button is held = drag
4. Release LCLK → drop. Release TAB → exit mouse layer.

**Drag-lock workflow** (hands-free — button stays down after key release):

The friction with hold-drag: your right thumb holds LCLK while your right fingers steer
HJKL — the same hand does two jobs simultaneously. For precision tasks (region screenshots,
multi-file selections), this is awkward. The drag-lock macros solve it:

```
Drag-lock is implemented via two press-only / release-only ZMK macros:

  drag_on  → &macro_press &mkp LCLK   (sends button-DOWN only; stays held after key release)
  drag_off → &macro_release &mkp LCLK (sends button-UP; releases the held button)

This uses ZMK's documented "press-only" macro mode — no &macro_pause_for_release means
the button does NOT release when the macro key is released. It stays held until drag_off fires.
```

**Region screenshot example** (the primary use case):
1. `Cmd+Shift+4` → macOS crosshair cursor appears
2. Hold TAB → MOUSE layer
3. HJKL → move crosshair to corner A
4. Left index taps **DRG+** (R column, top row) → left button locks DOWN
5. HJKL → move to corner B — button stays held the whole way (dragging the selection region)
6. Left index taps **DRG-** (T column, top row) → button releases → screenshot captured
7. Release TAB → exit mouse layer

**Why DRG+ and DRG- are on the left-index top row:** Left index locks/unlocks while the right
hand steers HJKL. The two hands do separate jobs with no overlap. Positions 4 and 5 (R and T
column) are directly above the left index home position — one key up, no lateral movement.

**Hold-drag vs Drag-lock comparison:**

| Technique | Keys involved | Best for |
|---|---|---|
| Hold-drag (LCLK) | Right thumb holds LCLK + right fingers steer HJKL | Quick one-move drags |
| Drag-lock (DRG+/DRG-) | Left index locks/unlocks, right fingers steer freely | Long-distance drags, screenshots |

Both techniques coexist — LCLK on the right thumb is unchanged and still works for normal
clicking and quick hold-drags. DRG+/DRG- add the hands-free option for extended precision work.
---

## 9. Layout Analysis Tools & Learning Resources

### Typing Trainers

**KeyBR** (https://keybr.com)
- Adaptive algorithm. Teaches you the hardest letters first.
- Tracks performance per key — identifies your weakest letters.
- Essential for learning a new alpha layout. Start here.
- Supports custom text import.

**Monkeytype** (https://monkeytype.com)
- Typing test and trainer with extensive customization.
- Can load custom word lists — useful for practicing programming vocabulary.
- Shows WPM, accuracy, and consistency graphs.
- Great for benchmarking progress against your old QWERTY WPM.

**TypeRacer** (https://typeracer.com)
- Competitive typing — race against others on book/movie quotes.
- Good motivation for pushing past plateaus.
- Tests real-world text (not just word lists).

**Colemak Academy** (https://www.colemak.academy)
- Specifically designed for the Colemak/Colemak-DH transition.
- Teaches incrementally — only introduces new letters when you've mastered prior ones.
- Recommended if you decide to switch.

### Layout Analysis Tools

**Keyboard Layout Analyzer** (https://patorjk.com/keyboard-layout-analyzer)
- Paste any text → compare layouts for finger travel distance, same-finger usage, hand balance.
- Lets you upload a custom layout definition.
- Use this to analyze your actual writing samples (code, emails, etc.).

**Cyanophage Layout Tool** (https://cyanophage.github.io/tool.html)
- More comprehensive than patorjk. Shows SFB, SFS, LSB, redirects, rolls.
- Modern analysis including metrics newer than just "finger travel."
- Compare any two layouts side-by-side.

**Oxeylyzer** (https://oxey.dev/oxeylyzer)  
- The analyzer used by the competitive layout community.
- Extremely detailed breakdown of every layout metric.
- Can analyze custom corpora (not just English).

**Ergodox Layout Analyzer** (https://configure.zsa.io/ergodox-ez/analyze)
- ZSA's tool. Visual heatmap of key usage.
- Good for visualizing which fingers are overworked.

### Learning Resources and Community

**r/KeyboardLayouts** (https://reddit.com/r/KeyboardLayouts)
- The best single forum for alt layout discussion.
- Comparison threads, people sharing WPM progress, layout analysis debates.
- New layout announcements (Canary, Hands Down variants announced here).

**Miryoku Documentation** (https://github.com/manna-harbour/miryoku)
- The definitive reference for the layer strategy you use.
- Covers every supported alpha layout (QWERTY, Colemak-DH, Dvorak, etc.) with full keymaps.
- Shows how Miryoku adapts to different keyboards and firmware.

**Miryoku ZMK Template** (https://github.com/manna-harbour/miryoku_zmk)
- ZMK-specific implementation. Useful for comparing your layout to the canonical Miryoku.

**Keyboard Layout Doc** (https://docs.google.com/document/d/1_a5Nzbkwyk1o0bvTctZrtgsee9jSP-6I0q3A0_9Mzm0)
- Community-maintained megadoc covering layout design theory.
- Explains SFB, alternation, rolls, redirects in depth.

**Dactyl/Corne/Split communities:**
- Discord: "ErgoMechKeys" server
- r/ErgoMechKeys subreddit
- r/olkb subreddit (QMK-centric but large)

### Benchmarking Your Progress

**Tracking your learning curve** when switching or tuning:

```
Week 1:    ~15-25 WPM (frustrating, hunt and peck phase)
Week 2-3:  ~30-40 WPM (muscle memory forming, still thinking about keys)
Month 1:   ~40-55 WPM (comfortable for short sessions)
Month 2:   ~55-70 WPM (approaching old QWERTY speed on simple text)
Month 3-6: ~70-90 WPM (matching or exceeding QWERTY baseline)
Month 6+:  90+ WPM (exceeding old QWERTY for optimized layouts)
```

These are rough estimates. 10-finger typists with strong existing motor memory may progress
faster; people who were never formally trained (2-finger typists) sometimes find the alt-layout
transition easier because they have less to un-learn.

---

## 10. Should You Switch From QWERTY?

The honest answer most enthusiasts won't give you: **probably not, and it's fine either way.**

Here's the full picture:

### The Case for Staying on QWERTY

**Portability is real.** Every guest at your desk, every public computer, every phone keyboard,
every pairing session with a colleague — all QWERTY. If you use your Corne to type exclusively
on your own machine and never share a keyboard, this doesn't matter. But if you regularly type
on other keyboards, the dissonance of having two separate motor memories is real cognitive load.

**The efficiency gains are overstated for most users.** Studies on typing speed show that QWERTY
typists regularly hit 100+ WPM. The bottleneck past ~70 WPM isn't usually your layout — it's
your thinking speed and the rate you generate text. A programmer spending 6 hours a day typing
and 2 hours of that in actual typing (vs. reading, thinking, debugging) would gain perhaps
20-30 minutes of "faster keystrokes" daily from switching. The ROI calculation matters.

**The Miryoku layer strategy already eliminated the biggest efficiency problem.** By having nav,
numbers, and symbols all on home-row-accessible layers, you've already done the most impactful
ergonomic optimization. Switching from QWERTY to Colemak-DH adds maybe 15-20% efficiency on
pure alpha typing but changes nothing about layer access.

**The Corne itself is already an ergonomic win.** Split layout, columnar stagger, and thumb
clusters reduce strain substantially. You might not need the additional alpha optimization.

### The Case for Switching to Colemak-DH

**Fewer same-finger bigrams reduce strain.** If you type 6+ hours a day, the difference between
6.6% SFB (QWERTY) and 1.5% SFB (Colemak-DH) adds up to fewer repeated-finger motions per
hour. Over months and years, this may matter for RSI prevention.

**The Corne's columnar stagger was designed for this.** Colemak-DH was specifically created for
boards where lateral index movement is uncomfortable — exactly what the Corne is. QWERTY was
designed for row-stagger typewriters. You're running 1873 software on 2024 hardware.

**ZMK makes the transition cost-free.** You can:
1. Keep QWERTY as Layer 0.
2. Add Colemak-DH as Layer 1 (just change the alpha keys; keep all other layers identical).
3. Practice Colemak-DH on your Corne, QWERTY everywhere else.
4. Gradually shift until Colemak-DH is your default.
5. Delete QWERTY when you're ready.

This means zero risk. You don't have to commit.

### How to Run Two Layouts in ZMK (No Commitment Required)

ZMK's layer system makes it trivial to keep QWERTY and Colemak-DH simultaneously in your
firmware. Here's the exact technique: add Colemak-DH as a second base layer, and bind a
toggle key on your MEDIA layer to switch between them.

**Step 1 — Add the layer constant** (top of `config/corne.keymap`, alongside existing defines):

```c
#define BASE   0
#define CDH    1    // Colemak-DH — new base layer
#define NAV    2    // (shift all non-base layers up by 1)
#define NUM    3
#define MEDIA  4
#define SYM    5
#define FUN    6
#define MOUSE  7
```

**Step 2 — Add the Colemak-DH base layer** (full bindings, identical to BASE except alpha keys):

```c
cdh_layer {
    display-name = "CDH";
    bindings = <
&kp TAB        &kp Q       &kp W       &kp F         &kp P         &kp B          &kp J       &kp L         &kp U         &kp Y        &kp SEMI     &kp BSPC
&mt LCTRL ESC  &mt LGUI A  &mt LALT R  &mt LCTRL S   &mt LSHFT T   &kp G          &kp M       &mt RSHFT N   &mt RCTRL E   &mt RALT I   &mt RGUI O   &kp SQT
&kp LSHFT      &kp Z       &kp X       &kp C         &kp D         &kp V          &kp K       &kp H         &kp COMMA     &kp DOT      &kp FSLH     &kp ESC
                                        &lt MEDIA ESC &lt NAV SPACE &lt MOUSE TAB  &lt SYM RET &lt NUM BSPC  &lt FUN DEL
    >;
};
```

Key differences from QWERTY BASE: `W→F, E→P, R→B, T→G` on top left; `Y→J, U→L, I→U, O→Y,
P→;` on top right; `S→R, D→S, F→T` home left; `H→M, J→N, K→E, L→I, '→O` home right;
`C→C, V→D, B→V` bottom left; `N→K, M→H` bottom right. All modifiers (`[GUI]`, `[ALT]`,
`[CTL]`, `[SHF]`) stay on the same fingers — GACS order is preserved. Only the letter under
each finger changes.

**Step 3 — Add toggle keys on MEDIA layer.** In your MEDIA layer bindings, replace two `&none`
entries with base-layer toggles:

```c
// In media_layer, left top row (currently all &none):
// Position 1 = toggle to QWERTY base, position 2 = toggle to Colemak-DH base
&to BASE   &to CDH   &none  ...
```

`&to N` (to-layer) switches the *default* active layer to N — unlike `&mo` (momentary) or
`&lt` (layer-tap), `&to` persists until you press another `&to`. This is how you permanently
switch your base layout on-keyboard without reflashing.

**The full workflow:**

```
Boot → QWERTY active (Layer 0 is default)

Hold ESC (MEDIA layer) → tap "to QWERTY" key → QWERTY from now on
Hold ESC (MEDIA layer) → tap "to CDH" key    → Colemak-DH from now on

The choice persists across power cycles (ZMK saves it to flash).
```

**Why this matters for learning:** You can practice Colemak-DH exclusively on your Corne —
switch to CDH at home, switch back to QWERTY when pairing or using a shared machine. Your
laptop's built-in keyboard (QWERTY) stays unaffected. After a few months when Colemak-DH
exceeds your QWERTY speed, make it your permanent default and remove the QWERTY layer entirely.

**Time to proficiency (realistic expectations):**

| Milestone | Time estimate | Notes |
|---|---|---|
| Comfortable typing simple words | 2–4 weeks | Hunt-and-peck phase; frustrating but normal |
| 40–50 WPM (basic fluency) | 4–8 weeks | Muscle memory forming |
| Match your QWERTY WPM | 1–3 months | Most typists hit their old baseline here |
| Exceed your QWERTY WPM | 4–6 months | Where the SFB reduction starts paying off |
| Peak efficiency | 12–18 months | Layout-optimized ceiling; most never reach QWERTY ceiling |

The 1–3 month window to match your old QWERTY speed is why the "keep both layers" strategy
works: you can be productive on day one (QWERTY layer), practice Colemak-DH incrementally,
and make the permanent switch when you're confident.

**The community support for Colemak-DH is excellent.** More resources, more trainers, more
comparison data than any other alternative. The online learning tools are mature.

### Recommended Strategy If You're Curious

```
Month 1: Do nothing. Get fluent with Miryoku layers and home row mods.
          Home row mods take time to become automatic — master those first.

Month 2: Run the QWERTY alphabet through an analyzer with your own text.
          See if same-finger bigrams actually appear in what you type.
          (Programmers using lots of symbols may care less; prose writers more.)

Month 3: If curious, add a Colemak-DH base layer in ZMK as Layer 1 (temporarily).
          Practice on keybr.com for 15 minutes a day.

Month 4-6: If you hit 50+ WPM on Colemak-DH and enjoy it, start using it for real.
            Keep QWERTY as a backup layer until you exceed your QWERTY speed.
```

### The Practical Verdict

| Situation | Recommendation |
|---|---|
| Type <4 hours/day | Stay on QWERTY. Gains don't justify the investment. |
| Type >6 hours/day, RSI concerns | Seriously consider Colemak-DH. SFB reduction matters. |
| Primarily a programmer | Colemak-DH slightly better (less "ed", "lo" SFB in code). |
| Share keyboard with others | Stay on QWERTY. Portability cost is real. |
| Use vim heavily | QWERTY has HJKL on the right home row; Colemak-DH moves them. Consider a vim-modified Colemak variant. |
| Just bought this Corne, excited | Learn Miryoku layers fully first. That's the bigger win. |

**The meta-point:** You already made the most impactful keyboard decision by buying a split
columnar ergonomic board and configuring Miryoku layers with home row mods. Whether the alpha
layer says QWERTY or Colemak-DH is a second-order optimization. Master what you have, then
re-evaluate.

---

## Quick Reference — Your Layout at a Glance

```
LAYER ACCESS MAP:
═══════════════════════════════════════════════════════════════════
Left thumb:
  Hold ESC  → MEDIA  (media, bluetooth, RGB)
  Hold SPC  → NAV    (vim arrows, clipboard, nav keys)
  Hold TAB  → MOUSE  (cursor, scroll, click)

Right thumb:
  Hold RET  → SYM    (symbols: {} [] () ! @ # $ % ^ & * | ~)
  Hold BKSP → NUM    (numbers: numpad layout + [ ] ; = ~ \)
  Hold DEL  → FUN    (F1-F12, PrintScr, ScrollLock, Pause)
═══════════════════════════════════════════════════════════════════

COMBO MAP (press simultaneously within ~30ms):
  W+E   = ESC       I+O = BKSP       O+P = DEL
  S+D   = TAB       K+L = ENTER
  F+J   = CAPS WORD
  X+C   = Cmd+C     C+V = Cmd+V      X+V = Cmd+X
  F+V   = =         S+X = `          J+M = -     H+N = _
  L+'   = ;
═══════════════════════════════════════════════════════════════════

HOME ROW MODS (GACS order, hold to activate):
  Left:  A=GUI(Cmd)  S=ALT  D=CTRL  F=SHIFT
  Right: J=SHIFT     K=CTRL L=ALT   '=GUI(Cmd)
  Timing: 200ms tapping-term, 150ms prior-idle, tap-preferred
═══════════════════════════════════════════════════════════════════
```

---

## Further Reading

| Resource | URL | Best for |
|---|---|---|
| Miryoku | github.com/manna-harbour/miryoku | Your layer strategy reference |
| Colemak-DH | colemakmods.github.io/mod-dh | If you consider switching |
| ZMK Docs | zmk.dev/docs | Firmware behavior reference |
| KeyBR | keybr.com | Learning new layouts |
| Monkeytype | monkeytype.com | Speed benchmarking |
| Layout Analyzer | cyanophage.github.io/tool.html | Comparing layouts |
| r/KeyboardLayouts | reddit.com/r/KeyboardLayouts | Community and alt layouts |
| r/ErgoMechKeys | reddit.com/r/ErgoMechKeys | Split/ergonomic community |
| Keyboard Layout Doc | docs.google.com/document/d/1_a5Nzbkwyk1o0bvTctZrtgsee9jSP-6I0q3A0_9Mzm0 | Layout theory deep dive |
