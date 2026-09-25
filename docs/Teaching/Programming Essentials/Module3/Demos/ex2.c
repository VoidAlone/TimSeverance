#include <stdio.h>

static int asdf= 0;

void counter(){
	asdf++;

	printf("Counter is: %d", asdf);
}

int main(){
	counter();
	counter();
	counter();
}
