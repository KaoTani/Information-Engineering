//AJG23085 谷口香央

#include <stdio.h>

int nikou(int a, int b);

int main(void){
  int a, b;
  printf("Input numbers.\n");
  printf("a:");
  scanf("%d", &a);
  printf("b:");
  scanf("%d", &b);
  if(a<=0 || b<=0){
    printf("Error: Input positive number.\n");
    return 0;
  }
  printf("%dC%d = %d\n",a, b, nikou(a, b));

  return 0;
}

int nikou(int a, int b){
  
  int C, i;
  for(i = b; i > 0; i--){
    C *= a;
    a--;
    C /= b;
    b--;
  }
  
  return C;   
}