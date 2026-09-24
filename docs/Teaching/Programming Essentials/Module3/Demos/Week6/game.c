#include <stdio.h>

int skeleton_hp;
int skeleton_atk;

int slime_hp;
int slime_atk;

int goblin_hp;
int goblin_atk;

typedef enum{
	SLIME 	 = 1,
	GOBLIN 	 = 2,
	SKELETON = 3
} E_Enemy;

int load_enemy(E_Enemy enemy_type){

	FILE *cfg;

	switch(enemy_type){
		case SLIME:
			cfg = fopen("slime.cfg", "r");
			break;
		case GOBLIN:
			break;
		case SKELETON:
			break;
		default:
			return -1;
	}
	return 1;
}

int main(){
	return 0;
}
