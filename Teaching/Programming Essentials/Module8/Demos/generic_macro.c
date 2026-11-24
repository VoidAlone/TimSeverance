#include <stdio.h>
#define cube_root(x) _Generic((x), \
    float: cbrtf,                  \
    long double: cbrtl,            \
    default: cbrt                  \
)(x)

#define printf_int(x)   printf("%d\n", x)
#define printf_float(x) printf("%f\n", x)
#define printf_char(x)  printf("%s\n", x)

#define gprintf(x) _Generic((x), \
		int: printf_int(x), 	\
		float: printf_float(x) \
		);

int main(void){
	int x = 5;
	float y = 5.0f;
	char* z = "5";

	gprintf(y);
}
