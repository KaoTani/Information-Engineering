//AJG23085 谷口香央

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand((unsigned)time(NULL));
  int i;
  for(i=0; i<100; i++){
    int a;
    a = rand()%100+1;
    printf("%d\n", a);
  }
  return 0;
}