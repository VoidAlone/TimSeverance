#include <stdio.h>

#define GRAVITY 9.8i

typedef enum{
	MOVE,
	ATTACK,
	DEFEND
} Action;

int main(){
	Action choice;
	
	printf("Make your choice: \n");

	printf("0: Move\n");
	printf("1: Attack\n");
	printf("2: Defend\n");
	scanf("%i", &choice);

	switch(choice){
		case ATTACK:
			printf("Swing sword");
			break;
		case DEFEND:
			printf("Raise shield");
			break;
		case MOVE:
			printf("Dodge");
			break;
	}

}

/*
	x > 0 ? x++ : x--; 

	if(x > 0){
		x++;
	} 
	else if(x < 0){
		x--;
	}
	else {
		//do nothing
	}
	int x = 5;
	int y = 1;
	// if(x && y){
	// 	printf("True");
	// }
	// else{
	// 	printf("False");
	// }
	//
	int z = x & y;
	printf("%d", z);
*/
