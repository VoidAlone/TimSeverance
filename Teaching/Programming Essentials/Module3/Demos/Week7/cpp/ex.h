class DynamicArray{
	int *data;
	int capacity;
	int size;
public:
	DynamicArray() = delete;
	DynamicArray(int capacity){
		capacity = capacity;
		data = new int[capacity];
	}
};
