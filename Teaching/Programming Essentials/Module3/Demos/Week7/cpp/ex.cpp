//pass by reference
void function(int &var){
	var = 6;	
}

//pass by pointer
void function2(int* var){
	*var = 6;
}

void fn3(int var){
	var = 6;
}

int *z = 5;

int a = 5;
int *x = &a;
int *y = nullptr;

*y = 5;

int &y =a;
