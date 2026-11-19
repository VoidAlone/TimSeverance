#include <stdio.h>
#include "actions.h"

typedef enum{
	READ,
	WRITE
} file_mode;

#define NUM_MAPPINGS 2

int main(void){
	
	//FILE OPEN
	file_mode fp_mode;
	bool file_content;
	FILE *fp = fopen("./mappings.bin", "rb+");

	fp_mode = READ;
	file_content = fgetc(fp) != EOF;
	rewind(fp);

	if(!file_content){
		fclose(fp);
		fp = fopen("./mappings.bin", "wb+");
		fp_mode = WRITE;
	}
	if(fp == nullptr){
		return -1;
	}

	

	if(fp_mode == WRITE){
		InMap mappings[2] = {
			[0] = (InMap){UP, 'w'},
			[1] = (InMap){DOWN,'s'}
		};
		fwrite(mappings, sizeof(InMap) * NUM_MAPPINGS, NUM_MAPPINGS, fp);
	}	
	

	InMap mappings[2];
	fread(mappings, sizeof(InMap) * NUM_MAPPINGS, NUM_MAPPINGS, fp);
	return 0;
}
