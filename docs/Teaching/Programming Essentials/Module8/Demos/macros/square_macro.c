#define SQUARE(x) (x * x)

float square(float x){
	return x*x;
}

int main(){
	int result = SQUARE(5 + 3);
	float result1 = square(5+3);
}
