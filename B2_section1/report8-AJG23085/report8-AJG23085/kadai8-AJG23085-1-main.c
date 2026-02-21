//AJG23085 谷口香央

#include <stdio.h>
#include "kadai8-AJG23085-1.h"

int main(void){
  double a, b;
  printf("Please input two integers.\n");
  printf("a = ");
  scanf("%lf", &a);
  printf("b = ");
  scanf("%lf", &b);

  printf("%lf + %lf = %lf\n", a, b, wa(a, b));
  printf("%lf - %lf = %lf\n", a, b, sa(a, b));
  printf("%lf × %lf = %lf\n", a, b, seki(a, b));
  printf("%lf ÷ %lf = %lf\n", a, b, syou(a, b));

  return 0;
}