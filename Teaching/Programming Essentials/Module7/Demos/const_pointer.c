#include <stdio.h>

typedef struct{
	int x;
} example;

//not a mutator, just getting values for calculation
int calculator(const example *x, const example *y){
	return x->x + y->x;
}


int calculator2(example *x, example *y, example *out){
	return 0;
}

int calc(int x, int y, bool b, char c, float f1, float f2){
	return 0;
}

int calculator1(int x, int y){
	return 0;
}

void increment(int *y){
	(*y)++; //external x -> 6
	y++; //internal x -> 0xFFA2394
	(*y)++; //undefined now because we changed what y points to
}

void nothing(int arr[], int size){
	printf("%d", (int)sizeof(*arr));
}

int main(void){
	//&x -> 0xFFA2390;
	int arr[5] = {0};
	printf("%d\n", (int)sizeof(arr));
	nothing(arr, 5);
	int x = 5;

	int y = arr[5];
	int z = 5[arr];

	char *p = "hello";
	char a[] = "hello";
	char p1[] = {'h', 'e'};
	char p2[2][5] = {
		{"hello"},
		{"world"},
	};

}
