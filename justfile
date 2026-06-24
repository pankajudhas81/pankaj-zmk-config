# justfile — local ZMK firmware builds. Run `just` to list recipes.

# List available recipes
default:
    @just --list

# Build firmware (default: all) then regenerate corne_keymap.svg.
# e.g. `just build` or `just build left right`
# Targets: left right left_view right_view reset
build *targets:
    bash build.sh {{targets}}
    command -v keymap >/dev/null && make svg || echo "==> keymap-drawer not installed; skipping SVG (run: make install)"

# Regenerate corne_keymap.svg from config/corne.keymap (requires keymap-drawer: make install)
svg:
    make svg

# Remove the local west workspace and build cache (keeps firmware/)
clean:
    rm -rf zmk zephyr modules tools bootloader .west build
