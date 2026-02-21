//AJG23085 谷口香央

#include <stdio.h>
#include <string.h>

int main(void){
  int i;
  char s[100], t[100];
  printf("Input string: ");
  scanf("%s", s);
  printf("Input string: ");
  scanf("%s", t);
  
  i = strcmp(s, t);
   
      if(i == 0){
        printf("The two sentences are the same.\n");
      }else{
        printf("The two sentences are different.\n");
      }
   

  return 0;
}