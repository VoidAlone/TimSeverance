#include "keymap.h"

typedef struct{
	char* keybind;
	func callback;
} Keymap;

void register_keybinds(){
	FILE *cfg= fopen("./configs/keymap.cfg", "r");
	char *action;
	char *keybind;
	if(cfg){
		while(fscanf(cfg, "%32[^=]=%32s", action, keybind)){
			Keymap keymap = {keybind, action};	
			ui_key(keybind, action, &u);
		}
	}
}
