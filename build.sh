#!/usr/bin/env bash
# build.sh — engine for `just build`. Builds Corne ZMK firmware in ONE Docker
# container (mirrors CI: init -> update -> zephyr-export -> west build) into ./firmware/.
# Invoked by the justfile; may also be run directly: `bash build.sh [targets...]`.
# Targets: left right left_view right_view reset   (no args or "all" = every target)
set -euo pipefail

REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
IMAGE="zmkfirmware/zmk-build-arm:stable"

ALL=(left right left_view right_view reset)
if [ "$#" -eq 0 ] || [ "${1:-}" = "all" ]; then
  TARGETS=("${ALL[@]}")
else
  TARGETS=("$@")
fi

mkdir -p "$REPO_DIR/firmware"

docker run --rm -i \
  -v "$REPO_DIR:/workspace" \
  -w /workspace \
  "$IMAGE" \
  bash -euo pipefail -s -- "${TARGETS[@]}" <<'INNER'
declare -A SHIELD=(
  [left]="corne_left"
  [right]="corne_right"
  [left_view]="corne_left nice_view_adapter nice_view"
  [right_view]="corne_right nice_view_adapter nice_view"
  [reset]="settings_reset"
)
declare -A SNIPPET=(
  [left]="studio-rpc-usb-uart"
  [left_view]="studio-rpc-usb-uart"
)
declare -A OUT=(
  [left]="corne_left"
  [right]="corne_right"
  [left_view]="corne_left_nice_view"
  [right_view]="corne_right_nice_view"
  [reset]="settings_reset"
)

if [ ! -e .west/config ]; then
  west init -l config
fi
west update --fetch-opt=--filter=tree:0
west zephyr-export

for key in "$@"; do
  shield="${SHIELD[$key]:-}"
  if [ -z "$shield" ]; then
    echo "Unknown target: $key (valid: ${!SHIELD[*]})" >&2
    exit 1
  fi
  snippet="${SNIPPET[$key]:-}"
  out="${OUT[$key]}"
  d="build/$key"
  bargs=(-p always -s zmk/app -d "$d" -b "nice_nano//zmk")
  if [ -n "$snippet" ]; then bargs+=(-S "$snippet"); fi
  echo "==> Building $out (shield: $shield)"
  west build "${bargs[@]}" -- -DZMK_CONFIG=/workspace/config -DSHIELD="$shield"
  cp "$d/zephyr/zmk.uf2" "firmware/$out.uf2"
  echo "==> Wrote firmware/$out.uf2"
done

echo "==> Done. Firmware:"
ls -l firmware/
INNER

echo "All firmware written to $REPO_DIR/firmware/"
