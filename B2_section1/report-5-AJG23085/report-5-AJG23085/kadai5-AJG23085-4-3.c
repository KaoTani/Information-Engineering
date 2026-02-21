//AJG23085 谷口香央

#define MAX_STACK 64//スタックに入れられる最大の要素数

#include <stdio.h>
#include <stdlib.h>

//push 関数．
// s[]: スタックを表現する配列
//   l: スタックの長さ
// val: スタックに格納される整数
//戻り値はスタックにval を積んだあとのスタックの長さ
int push( int s[], int l, int v );

//pop 関数．
// s[]: スタックを表現する配列
//l[2]: l[0] がスタックの長さを表し，l[1] がpop した後のスタックの長さ 
int pop( int s[], int l[2] );

//print_stack 関数
//スタックに積んだ数値を出力する関数
// s[]: スタックを表現する配列
//   l: スタックの長さ
void print_stack( int s[], int l );

int main( void ){

  int stack[ MAX_STACK ];//スタックを表現する配列
  int len = 0;//スタックの長さ．最初はスタックに何も積まれていないので0
  char eq[] = "7 8 + 4 9 - *";//逆ポーランド式記法の数式
  printf( "%s\n", eq);
  int l[ 2 ];//pop の時に使う新旧のスタックの長さを代入する配列．l[0] スタックの長さ，l[1] pop 後のスタックの長さ
  //eq を前から読んでいって，整数の場合はpush, 演算子の場合は2回pop して計算結果をpush//

  int i, x, y, z;
  int a;
  for(i=0;i<13;i++){
    if(eq[i] == ' '){
      continue;
    }else if(eq[i] == '+'){
      l[0]=len;
      l[1]=len-1;
      x = pop( stack, l );
      len = l[0];
      y = pop( stack, l );
      len = l[0];
      z = x + y;
      len = push( stack, len, z );
      //確認
      print_stack( stack, len );
    }else if(eq[i] == '-'){
      l[0]=len;
      l[1]=len-1;
      x = pop( stack, l );
      len = l[0];
      y = pop( stack, l );
      len = l[0];
      z = y - x;
      len = push( stack, len, z );
      //確認
      print_stack( stack, len );
    }else if(eq[i] == '*'){
      l[0]=len;
      l[1]=len-1;
      x = pop( stack, l );
      len = l[0];
      y = pop( stack, l );
      len = l[0];
      z = x * y;
      len = push( stack, len, z );
      //確認
      print_stack( stack, len );
    }else if(eq[i] == '/'){
      l[0]=len;
      l[1]=len-1;
      x = pop( stack, l );
      len = l[0];
      y = pop( stack, l );
      len = l[0];
      z = y / x;
      len = push( stack, len, z );
      //確認
      print_stack( stack, len );
    }else{
      a = atoi(&eq[i]);
      len = push( stack, len, a );
      //確認
      print_stack( stack, len );
    }
  }


  /////////////////////////////////ここまで//////////////////////////////////////

  printf( "equation:%s\n", eq );
  printf( "answer: %d\n", stack[0] );
  
  return 0;
}

////////////////////4-1 で完成させた関数をコピーして下さい///////////////////////
int push( int s[], int l, int val ){
  int n_val_update = 0;//スタックにval を積んだあとのスタックの長さ
  /////////////////ここからpush 関数の中身を書いて下さい///////////////////////////
  l += 1;
  s[l-1] = val;
  n_val_update = l;

  /////////////////////////ここまで//////////////////////////////////////////////
  return n_val_update;
}

////////////////////4-2 で完成させた関数をコピーして下さい///////////////////////
int pop( int s[], int l[2] ){
  int val = 0;//popした値
  l[1]=l[0];
  //////////ここからpop 関数の中身を書いて下さい．////////////////////////////////
  l[1] = l[0] - 1;
  val = s[l[1]];
  l[0] -= 1;
  //////////////////////////ここまで///////////////////////////////////////////
  return val;
}


void print_stack( int s[], int l ){
  int i;
  if( l < 0 ){
    printf( "The length of the stack should be positive.\n" );
    exit( -1 );
  }
  else{
    printf( "[" );
    for( i=0; i<l; i++ ){
      printf( "%d", s[i] );
      if( i != ( l-1 ) ){
	printf( " " );
      }
    }
    printf( "]\n" );
  }
}
