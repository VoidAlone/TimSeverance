int f(int& x){
	return x+= 1;
}

int main(){
	int y = 1;
	int* x = &y;
	int& z = y;
	z = *x;

	f(y);
}
