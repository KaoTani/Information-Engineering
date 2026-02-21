//AJG23085 谷口香央

#include <stdio.h>

int main(void){
  float shincho[5] = {158.3, 189.5, 167.2, 177.4, 146.8};
  float ave = 0;
  float sum = 0;
  int i, j;
  for(i=0; i<5; i++){
    sum += shincho[i];
  }
  ave = sum / 5;
  printf("The average height of five people is %f cm.\n", ave);

  float s1 = 0, s2 = 0;
  for(j=0; j<5; j++){
    s1 += (shincho[j] - ave) * (shincho[j] - ave);
  }
  s2 = s1 / 5;
  printf("The variance of five people is %f ㎠.\n", s2);

  return 0;
}