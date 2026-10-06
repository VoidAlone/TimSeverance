#include "actions.h"

static Menu* active_menu = nullptr;

static void priv_next(){
	active_menu->index++;
	if(active_menu->index > active_menu->count){
		active_menu->index = 0;
	}
}

static void priv_prev(){
	active_menu->index--;
	if(active_menu->index < 0){
		active_menu->index = active_menu->count;
	}
}

void set_active_menu(Menu* menu){
	active_menu = menu;
}

void action_up(){
	if(active_menu->orientation == VERTICAL){
		priv_prev();
	}
}

void action_down(){
	if(active_menu->orientation == VERTICAL){
		priv_next();
	}
}
void action_left(){

	if(active_menu->orientation == HORIZONTAL){
		priv_prev();
	}
}
void action_right(){
	if(active_menu->orientation == HORIZONTAL){
		priv_next();
	}
}

// need to make windows before I can decide what this does
void action_back(){
	
}

// need to make windows before I can decide what this does
void action_select(){
	
}
