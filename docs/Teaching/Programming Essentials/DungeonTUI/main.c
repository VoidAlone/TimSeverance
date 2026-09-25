#include "tuibox.h"
#include <stdio.h>

ui_t u;

void stop(){
	ui_free(&u);
   	exit(0);
}

void quit(){
	ui_box_t(ui_t);
}

typedef struct{
	char* keybind;
	func callback;
} Keybind;

void register_keybinds(){
	FILE *cfg= fopen("./configs/keymap.cfg", "r");
	char *action;
	char *keybind;
	if(cfg){
		while(fscanf(cfg, "%32[^=]=%32s", action, keybind)){
			Keybind keymap = {keybind, action};	
			ui_key(keybind, action, &u);
		}
	}
}

int main(){
	ui_new(0, &u);
	ui_key("q", quit, &u);
	ui_loop(u){
		ui_update(&u);
	}
	ui_free(&u);
}
