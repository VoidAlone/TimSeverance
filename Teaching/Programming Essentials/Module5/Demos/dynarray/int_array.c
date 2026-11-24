#include "int_array.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct IntArray{
	int* data;
	int size;
	int capacity;
} IntArray;

IntArray* int_array_create(int cap){
	IntArray* new = malloc(sizeof(IntArray));
	if(new == nullptr) return nullptr;

	new->capacity = cap;
	new->size = 0;
	new->data = malloc(sizeof(int) * new->capacity);
	if(new->data == nullptr){
		free(new);
		return nullptr;
	}
	return new;
}

void int_array_destroy(IntArray* self){
	free(self->data);
	free(self);
}

//getters
size_t int_array_size(const IntArray* arr){
	return arr->size;
}
size_t int_array_capacity(const IntArray* arr){
	return arr->capacity;
}

void int_array_push(IntArray* self, int value){
	if() 
}
bool int_array_get_at(const IntArray* self, size_t index, int* out_var);
bool int_array_set_at(IntArray* self, size_t index, int value);

//bubble sort
void int_array_sort(IntArray* arr){
	bool swapped = false;
	size_t size = arr->size;

	for(size_t i = 0; i < size - 1; i++){
		for(size_t j = 0; j < size - i - 1; j++){
			if(arr->data[j] > arr->data[j+1]){
				int temp = arr->data[j];
				arr->data[j] = arr->data[j+1];
				arr->data[j+1] = temp;
				swapped = true;
				// size -= 1;
			}
		}
		if(!swapped){
			break;
		}
	}
}

bool int_array_find(const IntArray* array, int target, size_t *out_index){
	return false;
}

static int linear_search_index(IntArray* self, int target){
	for(int i = 0; i < self->size; i++){
		if (self->data[i] == target) {
			return i;
		}
	}
	return -1;
}

static size_t binary_search(IntArray* self, int target, int low, int high){
	if(low >= high){
		return -1;
	}
	int middle = (low + (high - low))/2;
	if(self->data[middle] == target){
		return middle;
	}

	if(self->data[middle] < target){
		//go right 
		return binary_search(self, target, middle+1, high);
	}
	else{
		//go left
		return binary_search(self, target, low, middle-1);
	}
}


int main(void){
	srand(4);
	IntArray* a = int_array_create(10);

	a->size = 10;

	for(int i = 0; i < 10; i++){
		a->data[i] = rand() % a->size;
	}

	for(int i = 0; i < 10; i++){
		printf("%d,", a->data[i]);
	}
	printf("\n");

	int_array_sort(a);
	//a.array_sort(self);

	for(int i = 0; i < 10; i++){
		printf("%d,", a->data[i]);
	}

	printf("found value %d:",binary_search(a, 3, 0, 9));


	// int index = int_array_get(a, 5);
	// printf("Index: %d", index);
	return 0;
}
