//AJG23085 谷口香央

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
  FILE *fp1, *fp2;
  int c;
  fp1 = fopen(argv[1], "r");
  fp2 = fopen(argv[2], "w");
  if(fp1 == NULL || fp2 == NULL){
    printf("Cannot open file.\n");
    exit(1);
  }

  while((c = fgetc(fp1)) != EOF){
    for(int i = 3; i < argc ; i++){
      if(c == *argv[i]){
      c = toupper(c);
     }
    }
    fputc(c, fp2);
  }

  return 0;
}