<!-- FilePath: CLAUDE.md -->

<!-- FilePath: AGENTS.md -->

# Project Rules

> Keep this section ABOVE the `<!-- gitnexus:start -->` / `<!-- gitnexus:end -->`
> markers below. Everything between those markers is regenerated and overwritten
> by `npx gitnexus analyze`, so rules placed inside them are lost.

## keymap-viewer.html Must Track the Keymap

`keymap-viewer.html` is a hand-maintained visual mirror of the keymap in
`config/corne.keymap` (plus hardware/feature settings in `config/corne.conf`).
It is NOT auto-generated.

- ALWAYS update `keymap-viewer.html` in the SAME change whenever you edit layers,
  key bindings, home row mods, thumb/layer assignments, or combos in
  `config/corne.keymap`. A keymap edit is not complete until the viewer matches.
- Mirror keymap changes into the JavaScript data inside `keymap-viewer.html`:
  - The `layers` object (`base`, `nav`, `num`, `media`, `sym`, `fun`, `mouse`) —
    each key's tap (`t`), hold (`h`), and `type`, kept in ZMK keymap order.
  - The `combosDef` array — combo key positions and labels, matching any
    `combos` block defined in the keymap.
  - The sidebar header counts (`N keys · N layers · N combos`) and the `info-bar`
    values (board, Bluetooth profiles, RGB LED count, home-row-mod tap time) when
    the corresponding `config/corne.conf` or keymap settings change.
- NEVER let `keymap-viewer.html` drift from `config/corne.keymap`.
- CI enforces this: the `Draw Keymap` workflow runs `scripts/check-viewer-sync.js`,
  which fails the build if `keymap-viewer.html` structurally drifts from
  `config/corne.keymap` (layer count, per-layer key count, BASE thumb-layer order,
  home-row-mod positions). Labels/glyphs are not checked, so styling is free.

<!-- gitnexus:start -->
# GitNexus — Code Intelligence

This project is indexed by GitNexus as **yuyudhan-zmk-for-keyboards** (82 symbols, 97 relationships, 4 execution flows). Use the GitNexus MCP tools to understand code, assess impact, and navigate safely.

> If any GitNexus tool warns the index is stale, run `npx gitnexus analyze` in terminal first.

## Always Do

- **MUST run impact analysis before editing any symbol.** Before modifying a function, class, or method, run `gitnexus_impact({target: "symbolName", direction: "upstream"})` and report the blast radius (direct callers, affected processes, risk level) to the user.
- **MUST run `gitnexus_detect_changes()` before committing** to verify your changes only affect expected symbols and execution flows.
- **MUST warn the user** if impact analysis returns HIGH or CRITICAL risk before proceeding with edits.
- When exploring unfamiliar code, use `gitnexus_query({query: "concept"})` to find execution flows instead of grepping. It returns process-grouped results ranked by relevance.
- When you need full context on a specific symbol — callers, callees, which execution flows it participates in — use `gitnexus_context({name: "symbolName"})`.

## Never Do

- NEVER edit a function, class, or method without first running `gitnexus_impact` on it.
- NEVER ignore HIGH or CRITICAL risk warnings from impact analysis.
- NEVER rename symbols with find-and-replace — use `gitnexus_rename` which understands the call graph.
- NEVER commit changes without running `gitnexus_detect_changes()` to check affected scope.

## Resources

| Resource | Use for |
|----------|---------|
| `gitnexus://repo/yuyudhan-zmk-for-keyboards/context` | Codebase overview, check index freshness |
| `gitnexus://repo/yuyudhan-zmk-for-keyboards/clusters` | All functional areas |
| `gitnexus://repo/yuyudhan-zmk-for-keyboards/processes` | All execution flows |
| `gitnexus://repo/yuyudhan-zmk-for-keyboards/process/{name}` | Step-by-step execution trace |

## CLI

| Task | Read this skill file |
|------|---------------------|
| Understand architecture / "How does X work?" | `.claude/skills/gitnexus/gitnexus-exploring/SKILL.md` |
| Blast radius / "What breaks if I change X?" | `.claude/skills/gitnexus/gitnexus-impact-analysis/SKILL.md` |
| Trace bugs / "Why is X failing?" | `.claude/skills/gitnexus/gitnexus-debugging/SKILL.md` |
| Rename / extract / split / refactor | `.claude/skills/gitnexus/gitnexus-refactoring/SKILL.md` |
| Tools, resources, schema reference | `.claude/skills/gitnexus/gitnexus-guide/SKILL.md` |
| Index, status, clean, wiki CLI commands | `.claude/skills/gitnexus/gitnexus-cli/SKILL.md` |

<!-- gitnexus:end -->