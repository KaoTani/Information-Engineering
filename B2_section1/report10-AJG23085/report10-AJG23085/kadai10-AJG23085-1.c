//AJG23085 谷口香央

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int *a, *b;
  int i;
  srand((unsigned int)time(NULL));
  a = (int*)malloc(sizeof(int)*1000);
  for(i=0; i<1000; i++){
    a[i] = rand()%100;
  }
  b = (int*)malloc(sizeof(int)*100);
  for(i=0; i<100; i++){
    *(b+i) = 0;
  }
  for(i=0; i<1000; i++){
    *(b+a[i]) += 1;
  }
  for(i=0; i<100; i++){
    printf("No.%d: %d\n", i, *(b+i));
  }

  return 0;
}