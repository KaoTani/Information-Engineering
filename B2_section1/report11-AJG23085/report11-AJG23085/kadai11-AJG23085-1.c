//AJG23085 谷口香央

#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i;
  int *a;
  a = (int*)malloc(sizeof(int)*1000);
  if( a == NULL ){
    printf( "cannot obtain memories.\n" );
    exit( -1 );
  }
  for( i=0; i<1000; i++ ){
    a[i] = i+1;
    if(a[i]%31 == 0){
      printf( "%d\n", a[i] );
    }
  }
  
  return 0;
}