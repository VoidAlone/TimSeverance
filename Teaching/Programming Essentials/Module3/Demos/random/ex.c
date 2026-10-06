#include <stdio.h>


int main(){
FILE *cfg;
char strstm[16];
char stat[16];
int stat_val;
	cfg = fopen("ex.cfg", "r");
	while(fgets(strstm, 16, cfg)){
		sscanf(strstm, "%15[^=]=%d", stat, &stat_val);
	}
	fclose(cfg);
}
