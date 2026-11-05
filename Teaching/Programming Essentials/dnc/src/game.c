#include "game.h"

static GameState state;

void set_game_state(GameState new_state){
	state = new_state;
}

GameState get_game_state(){
	return state;
}
