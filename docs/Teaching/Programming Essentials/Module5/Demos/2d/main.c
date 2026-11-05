#include <stdio.h>
int main(){
	int grid[2][2] = {
		{0,1},
		{2,3}
	};

	int (*p)[2][2] = &grid;

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			printf("grid[%p][%p]", p+i, p+i+j);
			//[][][][]
			//
			//[][]
			//[][]
		}
	}

	return 0;
}
