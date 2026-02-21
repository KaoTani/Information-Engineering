//AJG23085 谷口香央

#include <stdio.h>

int main(void){
  double a=(double)1;
  int N=1, i;
  int b=1, c=1;
  printf("Probability that two people have the same birthday:\n");
  while(((double)1-a)*(double)100<50){
    N++;
    a = (double)1;
  for(i=0; i<N; i++){
    a *= ((double)365-i)/(double)365;
  }
    printf("%d students class -> %lf persent\n", N, ((double)1-a)*(double)100);
  }
  printf("%d students class -> Over 50 persent\n", N);
  
  return 0;
}