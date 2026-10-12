#include <stdio.h>

#define GRAVITY 9.18f;

int main(){
	float pos_y = 0;
	float tick = 1.0;
	while(tick += .01){
		pos_y -= GRAVITY;
	}
}
