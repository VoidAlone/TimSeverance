#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum{
	SLIME,
	GOBLIN,
	SKELETON,
} E_Enemy;

typedef enum{
	REST = 1,
	MOVE = 2,
	QUIT = 3
} E_Action;

typedef enum {
	ALIVE,
	DEAD 
} E_PState;

char e_type[32];
int e_health;
int e_attack;
int e_accuracy;

int p_health;
int p_attack;
int p_accuracy;
int max_health;
E_PState p_state;

bool load_enemy(E_Enemy type){
	FILE *cfg;
	switch(type){
		case SLIME:
			cfg = fopen("slime.cfg", "r");
			fscanf(cfg, "hp=%d attack=%d accuracy=%d", &e_health, &e_attack, &e_accuracy);			
			strcpy(e_type, "Slime");
			break;
		case GOBLIN:
			cfg = fopen("goblin.cfg", "r");
			fscanf(cfg, "hp=%d attack=%d accuracy=%d", &e_health, &e_attack, &e_accuracy);			
			strcpy(e_type, "Goblin");
			break;
		case SKELETON:
			cfg = fopen("skeleton.cfg", "r");
			fscanf(cfg, "hp=%d attack=%d accuracy=%d", &e_health, &e_attack, &e_accuracy);			
			strcpy(e_type, "Skeleton");
			break;
		default:
			break;
	}
	fclose(cfg);
	return cfg;
}

int load_player(void){
	FILE *cfg = fopen("player.cfg", "r");
	if(cfg == nullptr){
		return -1;
	}
	fscanf(cfg, "hp=%d attack=%d accuracy=%d", &p_health, &p_attack, &p_accuracy);
	max_health = p_health;
	return 1;
}

E_Action player_turn(void){
	E_Action result;
	printf("\n---\nMake your move:\n1) Rest\n2) Move\n3) Quit\nInput: ");
	scanf("%d", &result);
	return result;
}

int roll_dice(void){
	return rand() % 6 + 1;
}

void select_enemy(){
	E_Enemy result = rand() % 3;
	load_enemy(result);
}

void battle(){
	int dice;
	do {
		dice = roll_dice();
		if(dice >= p_accuracy){
			e_health -= p_attack;
		}
		dice = roll_dice();
		if(dice >= e_accuracy){
			p_health -= e_attack;
		}
		if(e_health<=0){
			printf("You vanquished %s\n", e_type);
			break;
		}
		if(p_health <= 0){
			printf("You have perished...\n");
			p_state = DEAD;
			return;
		}
	} while(p_health > 0);
}

int main(){
	int dice1;
	int dice2;
	int hp_recover;
	E_Action player_choice;
	bool game_is_active = true;
	p_state = ALIVE;

	srand(time(0));

	load_player();

	while(game_is_active && p_state == ALIVE){
		printf("HP: %d", p_health);
		player_choice = player_turn();

		switch(player_choice){
			case REST:
				hp_recover = rand() % (max_health - p_health) + 1;
				p_health += hp_recover;
				printf("You recovered %d HP\n", hp_recover);
				break;
			case MOVE:
				select_enemy();
				battle();
				break;
			case QUIT:
				printf("Retreat is not always cowardice\n");
				game_is_active = false;
				break;
			default:
				break;
		}
	}
	if(p_state == ALIVE){
		printf("May you journey again!\n");
	}
	else{
		printf("May you be remembered\n");
	}
	return 0;
}
