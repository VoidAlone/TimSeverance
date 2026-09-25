#include <stdio.h>

int main() {
  int age;
  char ch;

  int result;

  while (1) {
    printf("Enter age (1-120): ");
    result = scanf("%d", &age);

	if(age > 0){

	}
	else{
		print("");
	}


    if (result != 1 || age < 0 || age > 120) {
      printf("Please enter a valid number.\n");
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
	  continue;
    }
	break;
  }
}
