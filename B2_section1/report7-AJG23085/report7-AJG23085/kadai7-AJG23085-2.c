//AJG23085 谷口香央

#include <stdio.h>

#define sq(a) a*a
#define sq_2(a) (a)*(a)

int main(void){
  printf("incorrect: 7+2 * 7+2 = %d\n", sq(7+2));
  printf("correct: (7+2) * (7+2) = %d\n", sq_2(7+2));
  
  return 0;
}