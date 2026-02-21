//AJG23085 谷口香央

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kadai9-AJG23085-2.h"
int N;

int main(void){
  float *a, *b;
  int i;
  printf("Please input a number: ");
  scanf("%d", &N);
  printf("The dimension is %d.\n", N);
  if(N<=0){
    printf("The number should be positive.\n");
    exit(-1);
  }
  
  a = (float *)malloc(sizeof(int) * N);
  if(a == NULL){
    printf("Cannot obtain memories.\n");
    exit(-1);
  }
  b = (float *)malloc(sizeof(int) * N);
  if(b == NULL){
    printf("Cannot obtain memories.\n");
    exit(-1);
  }
  
  printf("Please input integers of the vector a (%d dimension).\n", N);
  for(i=0; i<N; i++){
    scanf("%f", &a[i]);
  }
  printf("→a = [");
  for(i=0; i<N; i++){
    if(i == N-1){
      printf("%f", a[i]);
    }else{
    printf("%f, ", a[i]);
    }
  }
  printf("]\n");
  printf("Please input integers of the vector b (%d dimension).\n", N);
  for(i=0; i<N; i++){
    scanf("%f", &b[i]);
  }
  printf("→b = [");
  for(i=0; i<N; i++){
    if(i == N-1){
      printf("%f", b[i]);
    }else{
    printf("%f, ", b[i]);
    }
  }
  printf("]\n");

  printf("The length of →a is %f.\n", length(a));
  printf("The length of →b is %f.\n", length(b));
  
  printf("The unit vector of →a is ");
  printf("[");
  for(i=0; i<N; i++){
    if(i == N-1){
      printf("%f", unit(a, i));
    }else{
    printf("%f, ", unit(a, i));
    }
  }
  printf("].\n");
  printf("The unit vector of →b is ");
  printf("[");
  for(i=0; i<N; i++){
    if(i == N-1){
      printf("%f", unit(b, i));
    }else{
    printf("%f, ", unit(b, i));
    }
  }
  printf("].\n");

  printf("The inner product of →a and →b is %f.\n", inner(a, b));

  printf("The angle between →a and →b is %f degrees.\n", kaku(a, b));
  
  free(a);
  return 0;
}