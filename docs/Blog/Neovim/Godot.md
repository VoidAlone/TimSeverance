This script is for running a wezterm instance with neovim. It allows godot to open neovim in an already running wezterm instance if available, and open a file in an already running instance of neovim if available. Otherwise, it spawns a new instance of wezterm or neovim if needed.

```sh
#!/bin/sh
FILE="$1"
PROJECT_DIR=$(dirname "$(dirname "$FILE")") # adjust if your .gd files are nested differently
PIPE="/tmp/godot_$(basename "$PROJECT_DIR").pipe"

if ! nvr --serverlist | grep -q "$PIPE"; then
    wezterm start --new-tab --cwd "$PROJECT_DIR" \
        -- nvim --listen "$PIPE" "$FILE"
else
    nvr --servername "$PIPE" --remote "$FILE"
fi

```