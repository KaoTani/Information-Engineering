//AJG23085 谷口香央

#include <stdio.h>

int main(void){
  int a, b=0, i;
  printf("Please input a number: ");
  scanf("%d", &a);
  for(i=0; i<a; i++){
    if(a % (i+1) == 0){
      b++;
    }
  }
  if(b == 2){
    printf("This is a prime number.\n");
  }else{
    printf("This is not a prime number.\n");
  }
  
  return 0;
}