# justfile — local ZMK firmware builds. Run `just` to list recipes.

# List available recipes
default:
    @just --list

# Build firmware (default: all) then regenerate corne_keymap.svg.
# e.g. `just build` or `just build left right`
# Targets: left right left_view right_view reset
build *targets:
    bash build.sh {{targets}}
    if command -v keymap >/dev/null 2>&1; then make svg || echo "==> SVG generation failed (see above); firmware is fine"; else echo "==> keymap-drawer not installed; run: pipx install --python python3.12 keymap-drawer==0.23.0"; fi

# Regenerate corne_keymap.svg from config/corne.keymap (requires keymap-drawer: make install)
svg:
    make svg

# Remove the local west workspace and build cache (keeps firmware/)
clean:
    rm -rf zmk zephyr modules tools bootloader .west build
