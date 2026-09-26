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


int main(){
	ui_new(0, &u);
	ui_key("q", quit, &u);
	ui_loop(u){
		ui_update(&u);
	}
	ui_free(&u);
}
