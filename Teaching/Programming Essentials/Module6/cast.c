#include <stdio.h>
int main(void){
	float y = 1.31;
	int x;

	x = *(int *)(&y);
	printf("%x", x);
	return 0;
}
