//AJG23085 谷口香央
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int a;
  srand((unsigned)time(NULL));
  a = rand()%10+1;
  if(a % 2 == 0){
    a = a - 1;
  }
  printf("%d\n", a);

  return 0;
}