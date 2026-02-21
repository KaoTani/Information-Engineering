//AJG23085 谷口香央

#include <stdio.h>

int average(int a[10]);

int main(void){
  int a[10];
  int i;
  printf("Please input 10 numbers.\n");
  for(i=0; i<10; i++){
    scanf("%d", &a[i]);
  }
  printf("a[10] = { ");
  for(i=0; i<10; i++){
    printf("%d, ", a[i]);
  }
  printf("}\n");

  printf("The average of these 10 numbers is %d.\n", average(a));

  return 0;
}

int average(int x[10]){
  int i, sum = 0;
  int ave = 0;
  for(i=0; i<10; i++){
    sum += x[i];
  }
  ave = sum / 10;
  
  return ave;
}

