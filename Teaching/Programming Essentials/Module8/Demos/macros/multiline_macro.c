#include <stdio.h>

// #define PRINT_BOTH(a,b) printf("%d\n", a);printf("%d\n", b)

#define PRINT_BOTH(a,b) \
    printf("%d\n", a);  \
    printf("%d\n", b);	

// #define PRINT_BOTH(a, b) \
// 	{ 				 	\
//     printf("%d\n", a);  \
//     printf("%d\n", b);	\
// 	} 					\

int main(void){
	int result = 0;
	if(result)
		PRINT_BOTH(1, 2);
}
