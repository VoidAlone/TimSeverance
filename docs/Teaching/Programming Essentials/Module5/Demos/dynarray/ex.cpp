class Example{
	int x;
	public:
	Example(int x){
		this->x = x;
	}
};

int main(){

	Example* ex = new Example(5);
}
