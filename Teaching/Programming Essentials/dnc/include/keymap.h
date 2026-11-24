#ifndef KEYMAP_H
#define KEYMAP_H

#include "tuibox.h"

typedef struct Keymap *keymap;

void register_keybinds(ui_t *u);

#endif // !KEYMAP
