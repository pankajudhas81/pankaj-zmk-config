#!/usr/bin/env node
// scripts/check-viewer-sync.js
// Fails (exit 1) if keymap-viewer.html structurally drifts from config/corne.keymap.
// Label-agnostic: never false-positives on styling diffs (RET vs ENTER, CMD vs LGUI, DISP vs EP TOG).
// Requires `keymap` (keymap-drawer) on PATH and node. No other deps.
//
// Invariants enforced:
//   1. Layer count: keymap layers === viewer `layers` keys.
//   2. Per-layer key count === parsed keymap layer length.
//   3. BASE thumb hold-layer order (lowercased) === viewer base thumb type:"layer" h-values.
//   4. BASE home-row-mod positions (idx 0-29 with hold mod L*/R*) === viewer base idx with .h && type!=="layer".
const fs = require("fs");
const { execSync } = require("child_process");

const html = fs.readFileSync("keymap-viewer.html", "utf8");
const m = html.match(/const layers = \{[\s\S]*?\n\};/);
if (!m) { console.error("FAIL: could not locate `const layers` in keymap-viewer.html"); process.exit(1); }
let layers;
eval("layers = " + m[0].replace(/^const layers = /, "").replace(/;\s*$/, "") + ";");

// Parse keymap -> YAML, then count layers/keys/holds with a tolerant line scanner (no YAML lib).
const yamlText = execSync("keymap parse -z config/corne.keymap", { encoding: "utf8" });
const lines = yamlText.split("\n");
let inLayers = false, cur = null;
const counts = {}, holds = {};
for (const line of lines) {
  if (/^layers:\s*$/.test(line)) { inLayers = true; continue; }
  if (inLayers && /^\S/.test(line) && !/^layers:/.test(line)) inLayers = false;
  if (!inLayers) continue;
  let mm;
  if ((mm = line.match(/^  ([A-Z]+):\s*$/))) { cur = mm[1]; counts[cur] = 0; holds[cur] = []; continue; }
  if (cur && /^  - /.test(line)) {
    counts[cur]++;
    const hm = line.match(/h:\s*'?([A-Za-z0-9]+)'?/);
    holds[cur].push(hm ? hm[1] : null);
  }
}

const NAME_MAP = { BASE:"base", NAV:"nav", NUM:"num", MEDIA:"media", SYM:"sym", FUN:"fun", MOUSE:"mouse" };
const errs = [];

if (Object.keys(layers).length !== Object.keys(counts).length)
  errs.push(`layer count: keymap ${Object.keys(counts).length} vs viewer ${Object.keys(layers).length}`);

for (const [kn, vn] of Object.entries(NAME_MAP)) {
  if (!layers[vn]) { errs.push(`viewer missing layer "${vn}"`); continue; }
  if (layers[vn].keys.length !== counts[kn])
    errs.push(`${vn}: viewer ${layers[vn].keys.length} keys vs keymap ${counts[kn]}`);
}

const kmThumbs = (holds.BASE || []).slice(30, 36).map(h => (h || "").toLowerCase());
const vwThumbs = layers.base.keys.slice(30, 36).map(k => k.type === "layer" ? (k.h || "") : "");
if (JSON.stringify(kmThumbs) !== JSON.stringify(vwThumbs))
  errs.push(`BASE thumb layers: keymap ${JSON.stringify(kmThumbs)} vs viewer ${JSON.stringify(vwThumbs)}`);

const kmHrm = (holds.BASE || []).map((h, i) => ({ h, i })).filter(o => o.i < 30 && o.h && /^[LR]/.test(o.h)).map(o => o.i);
const vwHrm = layers.base.keys.map((k, i) => ({ k, i })).filter(o => o.i < 30 && o.k.h && o.k.type !== "layer").map(o => o.i);
if (JSON.stringify(kmHrm) !== JSON.stringify(vwHrm))
  errs.push(`BASE home-row-mod positions: keymap ${JSON.stringify(kmHrm)} vs viewer ${JSON.stringify(vwHrm)}`);

if (errs.length) {
  console.error("keymap-viewer.html is OUT OF SYNC with config/corne.keymap:");
  for (const e of errs) console.error("  - " + e);
  console.error("Update keymap-viewer.html to match the keymap (see AGENTS.md).");
  process.exit(1);
}
console.log(`keymap-viewer.html structural sync OK (${Object.keys(counts).length} layers, thumb+HRM layout matches).`);
