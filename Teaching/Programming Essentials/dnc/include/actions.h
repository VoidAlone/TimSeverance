#ifndef ACTIONS_H
#define ACTIONS_H

#include "menu.h"
#include "game.h"

void set_active_menu(Menu* menu);

void action_left();
void action_right();
void action_up();
void action_down();
void action_back();
void action_select();

#endif // !ACTIONS_H
