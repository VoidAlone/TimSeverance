#include <stdio.h>

int main(){

	
	int a = 10, b = 3;
	int x,y,z;
	int *e,*f;

	int sum  = a + b; // 13
	int diff = a - b; // 7
	int prod = a * b; // 30
	int quot = a / b; // 3 (integer division — truncates!)
	int rem  = a % b; // 1 (remainder; integers only)
	a += 20;
					  //
	while(++a < 20){
		//do something
	}

	for(int i = 0; i < 20; i++){

	}

	int i = 0;
	i++; //-> 1;
	++i; //->2;

	const int ARR_SIZE = 5;
	int g[ARR_SIZE];
	// 0,1,2,3,4
	
	float inc = 1.2;
	inc++;

	inc++;
	printf("%f",inc);

	return 0;


}
