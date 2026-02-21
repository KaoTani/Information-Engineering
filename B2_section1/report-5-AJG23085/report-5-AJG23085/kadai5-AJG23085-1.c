//AJG23085 谷口香央

#include <stdio.h>

int main(void){
  int i,k,l;
  for(i=1;i<10;i++){
    for(k=1;k<10;k++){
      l = i * k;
      printf("%d × %d = %d\n", i, k, l);
    }
  }

  return 0;
}