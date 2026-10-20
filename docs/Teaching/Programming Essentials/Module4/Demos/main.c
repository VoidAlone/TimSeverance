#include <stdio.h>
#include <stdlib.h>
/*
 * 
 */

int* f(){
	int *ex;
	ex = malloc(sizeof(int));
	if(ex == nullptr)
		return ex;
	*ex = 5;
	return ex;
}

typedef struct{
	int x;
} Foo;

void f1(){
	int** myarr = malloc(10 * sizeof(Foo*));
	for(size_t i = 0; i< 10; i++){
		myarr[i] = malloc(sizeof(Foo));
	}
	free(myarr);
	myarr = malloc(5 * sizeof(int));
	myarr[0] = 5;
	free(myarr);
	return;
}

// int* f1(){
// 	int x = 5;
// 	return &x;
// }
//
// int* f2(){
// 	int y = 0;
// 	int x = 3;
// 	return &x;
// }

int main(){
	int *xe = f();
	free(xe);
	// int *xe1 = f1();
	// f2();
	printf("done.");
	return 0;
}
