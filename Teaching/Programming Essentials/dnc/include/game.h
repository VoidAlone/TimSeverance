#ifndef GAME_H
#define GAME_H

typedef enum{
	STATE_OPTIONS,
	STATE_WORLD,
	STATE_BATTLE,
	STATE_INVENTORY,
	STATE_DIALOGUE,
	STATE_INTRO
} GameState;

void set_game_state(GameState);
GameState get_game_state(void);

#endif // !GAME_H
