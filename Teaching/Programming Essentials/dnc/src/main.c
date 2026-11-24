#include "keymap.h"
#include "tuibox.h"
#include <stdio.h>

ui_t u;

int main(){
	ui_new(0, &u);
	register_keybinds(&u);
	ui_loop(u){
		ui_update(&u);
	}
	ui_free(&u);
}
