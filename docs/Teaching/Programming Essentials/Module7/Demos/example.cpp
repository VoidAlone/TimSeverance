#include <string>

using std::string;

class Example{
	private:
		string s;
		//
};

//cpp style
void example(const int& x){} //direct read, no write to x
							 //
							 //

//mutator							 
void examplea(int& x){
	x = 6;
} //direct read and write to x


void exampleb(int* x){} //direct read and write to x, but you care about memory

//calculations
void examplec(int x){} //just copies


//c style
void example1(int x){

}

void example2(const int *x){

}

int main(){
	int y = 5;
	examplea(y);

	exampleb(&y);
}
