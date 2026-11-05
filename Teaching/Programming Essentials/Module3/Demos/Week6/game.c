#include <stdio.h>

char e_type[16];
int e_hp;
int e_atk;

int p_hp;
int p_atk;

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
			fscanf(cfg, "hp=%d atk=%d", &e_hp, &e_atk);
			break;
		case GOBLIN:
			cfg = fopen("goblin.cfg", "r");
			fscanf(cfg, "hp=%d atk=%d", &e_hp, &e_atk);
			break;
		case SKELETON:
			cfg = fopen("skeleton.cfg", "r");
			fscanf(cfg, "hp=%d atk=%d", &e_hp, &e_atk);
			break;
		default:
			return -1;
	}
	fclose(cfg);
	return 1;
}

int main(){
	E_Enemy enemy = GOBLIN;
	load_enemy(enemy);
}
