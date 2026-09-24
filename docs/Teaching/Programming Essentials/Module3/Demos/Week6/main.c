#include <stdio.h>
#include <string.h>

const int EXAMPLE_SIZE = 8;
int main(){

	char example[EXAMPLE_SIZE];
	// char ex2[8] = 'Hello';
	// sprintf("Hello", "%s", example);
	// strcpy(example, "Hello");
	for(int i = 0; i < EXAMPLE_SIZE; i++){
		example[i] = "Hello"[i];
	}
}
