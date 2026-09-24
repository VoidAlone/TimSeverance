#include <stdio.h>

int main() {

  char name[64] = "Tim";
  char letter = name[0];
  int age = 5;
  double height = 5.5695;
  int isTeacher = 1;
  int ch;

  // printf("Name: %s, Age: %d, Height: %.2f\n",
  // 		name, age, height);

  // printf("%5d\n", 42);       // width
  // printf("%05d\n", 42);      // zero-pad
  // printf("%10.3f\n", 3.14159); // precision

  // int result = scanf("%49s %d %lf",
  // 	   name, &age, &height);
  //
  // printf("Name: %s, Age: %d, Height: %.2f\n, Teacher: %d",
  // 		name, age, height, isTeacher);
  //
  // while ((ch = getchar()) != EOF) {
  // 	putchar(ch);
  // }

  // for(int i = 0; i < 10; i++){
  // 	ch = getchar();
  // 	putchar(ch);
  // }
  // putchar(ch);
  // putchar(ch);
  //
  // int ret_code = 0;
  //    for (char c = 'a'; (ret_code != EOF) && (c != 'z'); c++)
  //        ret_code = putchar(c);


  // printf("Enter age: ");
  // scanf("%d", &age);
  //
  // printf("Enter name: ");
  // fgets(name, sizeof(name), stdin);
  // return 0;
}

// [T]x3000 <- name
// [i]x3001 <- name + 1*(sizeof(char))
// [m]x3002
// [\0]x3003
