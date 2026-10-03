int f(int x){
	if(x <= 0){
		return x;
	}
	x -= 1;   //Law 2: advance
	x = f(x); //Law 3: recurse
	return x;
	// return f(x - 1);
}

int main(){
	f(2);
}
