//AJG23085 谷口香央

#include <stdio.h>
#include <string.h>

int main(void){
  char str[][256] = { "love", "lovely", 
  "like", "link", "list"};
  int i, j, k;
  for(i=0; i<5; i++){
    printf("%s ", str[i]);
  }
  printf("\n");
  for(j=0; j<4; j++){
    for(k=0; k<4-j; k++){
      if(strcmp(str[k], str[k+1]) > 0){
        char tmp[256];
        strcpy(tmp, str[k]);
        strcpy(str[k], str[k+1]);
        strcpy(str[k+1], tmp);
      }
    }
  }
  for(i=0; i<5; i++){
    printf("%s ", str[i]);
  }
  printf("\n");

  return 0;
}