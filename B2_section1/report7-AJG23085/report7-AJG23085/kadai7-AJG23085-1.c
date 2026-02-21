//AJG23085 谷口香央

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int counter(void);

int main(int argc, char *argv[]){
  srand((unsigned)time(NULL));
  int a=0, b=0, f=0, i, j;
  int c[a];
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  if(b>=10){
    printf("Please input 0~9 in the second argument.\n");
  }else{
  printf("%d %d\n", a, b);
  for(i=0; i<a; i++){
    c[i] = rand()%10;
    printf("%d ", c[i]);
    if(c[i]==b){
      f = counter();
    }else{    }
  }
  printf("\n");

  printf("%d times.\n", f);
  }

  return 0;
}

int counter(void){
  static int l = 0;
  l++;

  return l;
}