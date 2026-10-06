#include <stdarg.h>
int sum_n(int n, ...) {
	va_list a; 
	va_start(a, n);
	
	int t = 0;
	for (int i = 0; i < n; i++) 
		t += va_arg(a, int);

	va_end(a); return t;
}

int main(){
	sum_n(5, 10,11,'x',14,16);
}

