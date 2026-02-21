//AJG23085 谷口香央

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){
  int *a;
  int b, i;
  int mid, max, min, sum=0;
  float ave, var;
  srand((unsigned int)time(NULL));
  printf("Please input a number.\n");
  scanf("%d", &b);
  if(b<=0){
    printf("The number should be positive.\n");
    exit(-1);
  }
  a = (int *)malloc(sizeof(int) * b);
  if(a == NULL){
    printf("Cannot obtain memories.\n");
    exit(-1);
  }
  for(i=0; i<b; i++){
    a[i] = rand()%100;
    printf("%d ", a[i]);
  }
  printf("\n");

  int tmp,j;

  for(i=0; i<b; i++){
    for(j=0; j<b; j++){
      if(a[i] < a[j]){
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }

  max = a[b-1];
  printf("The maximum number is %d.\n", max );

  
  min = a[0];
  printf("The minimum number is %d.\n", min );

  for(i=0; i<b; i++){
    sum += a[i];
  }
  ave = (float)sum / (float)b;
  printf("The average of these numbers is %f.\n", ave);
  
  for(i=0; i<b; i++){
    var += ((float)a[i] - ave) * ((float)a[i] - ave);
  }
  var = var / (float)b;
  printf("The variance of these numbers is %f.\n", var);

  if(b%2 == 0){
    mid = (a[b/2] + a[b/2-1]) / 2;
  }else{
    mid = a[(b-1)/2];
  }
  printf("The median of these numbers is %d.\n", mid);

  free(a);
  return 0;
}