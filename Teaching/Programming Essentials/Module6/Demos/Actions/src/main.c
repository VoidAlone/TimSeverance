#include <stdio.h>
int main(void) {
  typedef union FloatShift {
    int x;
    float y;
  } FloatShift;

  float y = 3.14;
  int x = *(float *)&y;

  FloatShift val;
  val.y = 234891.023872;

  printf("%f\n", val.y);
  printf("%d", val.x);
}
