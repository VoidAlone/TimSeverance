#include "keymap.h"
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

typedef uint64_t ActionId;
#define WORDSIZE 8
#define CHARSIZE 8
#define WORD(a,b,c,d,e,f,g,h) (ActionId) ( \
	(uint64_t)(uint8_t)(a) << 7 * CHARSIZE | \
	(uint64_t)(uint8_t)(b) << 6 * CHARSIZE | \
	(uint64_t)(uint8_t)(c) << 5 * CHARSIZE | \
	(uint64_t)(uint8_t)(d) << 4 * CHARSIZE | \
	(uint64_t)(uint8_t)(e) << 3 * CHARSIZE | \
	(uint64_t)(uint8_t)(f) << 2 * CHARSIZE | \
	(uint64_t)(uint8_t)(g) << 1 * CHARSIZE | \
	(uint64_t)(uint8_t)(h) << 0 * CHARSIZE   \
) 

ActionId word(char* string){
	return WORD(
			string[0] == '\0' ? 0 : string[0],
			string[1] == '\0' ? 0 : string[1],
			string[2] == '\0' ? 0 : string[2],
			string[3] == '\0' ? 0 : string[3],
			string[4] == '\0' ? 0 : string[4],
			string[5] == '\0' ? 0 : string[5],
			string[6] == '\0' ? 0 : string[6],
			string[7] == '\0' ? 0 : string[7]
			);
}

typedef enum{
	MENU 	= WORD('M','E','N','U',0,0,0,0),
	SELECT 	= WORD('S','E','L','E','C','T',0,0),
	UP 		= WORD('U','P',0,0,0,0,0,0),
	DOWN 	= WORD('D','O','W','N',0,0,0,0),
	LEFT 	= WORD('L','E','F','T',0,0,0,0),
	RIGHT 	= WORD('R','I','G','H','T',0,0,0),
} Action;


void register_keybinds(ui_t *u){
	FILE *cfg= fopen("./configs/keymap.cfg", "r");
	char action[WORDSIZE + 1] = {0};
	char keybind[WORDSIZE + 1] = {0};
	if(cfg){
		while(fscanf(cfg, "%8[^=]=%8s", action, keybind)){
			switch(word(action)){
				case MENU:
					// ui_key(keybind, func, u);
					break;
				case SELECT:
					break;
				case UP:
					break;
				case DOWN:
					break;
				case LEFT:
					break;
				case RIGHT:
					break;
				default:
					break;
			}
		}
	}
}
