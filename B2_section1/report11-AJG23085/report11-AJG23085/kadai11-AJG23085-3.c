//AJG23085 谷口香央

#include <stdio.h>

int main(void){
  int a, b, g;
  int c, d, e, f;
  a = 1000;
  printf("Calculate your change.\n");
  printf("Please input the price: ");
  scanf("%d", &b);
  printf("You paid 1000 yen.\n");
  g = a - b;
  if(g < 0){
    printf("You need to pay %d yen.\n", b-a);
  }else if(b <= 0){
    printf("Error.\n");
  }else{
    printf("Your change is %d yen.\n", a-b);
    c = g / 500;
    g = g - 500*c;
    d = g / 100;
    g = g - 100*d;
    e = g / 50;
    g = g - 50*e;
    f = g / 10;
    g = g - 10*f;

    printf("500 yen: %d\n", c);
    printf("100 yen: %d\n", d);
    printf("50 yen: %d\n", e);
    printf("10 yen: %d\n", f);
  }
  
  return 0;
}