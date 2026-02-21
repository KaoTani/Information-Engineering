//AJG23085 谷口香央

#include <stdio.h>

int main(void){
  int i, j;
  int suretsu[10] = {10, 32, 43, 8, 21, 92, 55, 42, 14, 9};
  int tmp;

  for(i=0; i<10; i++){
    for(j=0; j<10; j++){
      if(suretsu[i] < suretsu[j]){
        tmp = suretsu[i];
        suretsu[i] = suretsu[j];
        suretsu[j] = tmp;
      }
    }
  }

  for(i=0;i<10;i++){
    printf("%d ", suretsu[i]);
    if(i==9){
      printf("\n");
    }
  }

  return 0;
}