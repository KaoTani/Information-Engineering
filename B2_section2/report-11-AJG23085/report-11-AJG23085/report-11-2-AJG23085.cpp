//AJG23085 谷口香央
//Makefileを使って実行してます。

#include <iostream>
#include "ex2image.h"

int main(int argc, const char * argv[])
{
    ex2image img;
    std::string s_file = "block.pgm";
    if( !img.load( s_file.c_str() ) ){
	  std::cerr << "cannot open the file!:" <<  s_file << std::endl;
	  exit( -1 );
	}

	//保存用の画像のバッファ
    ex2image average1( img );
    ex2image average2( img );
    ex2image average3( img );

	//画像を平均化させる
	int w1 = average1.img_width();
	int h1 = average1.img_height();
	for( int j=1; j<h1-1; j++ ){
	  for( int i=1; i<w1-1; i++ ){
		average1(i,j,0)=(img(i,j,0)+img(i-1,j-1,0)+img(i-1,j,0)+img(i-1,j+1,0)+img(i,j-1,0)+img(i,j+1,0)+img(i+1,j-1,0)+img(i+1,j,0)+img(i+1,j+1,0))/9;
	  }
	}

    int w2 = average2.img_width();
	int h2 = average2.img_height();
	for( int j=2; j<h2-2; j++ ){
	  for( int i=2; i<w2-2; i++ ){
		average2(i,j,0)=(img(i-2,j-2,0)+img(i-2,j-1,0)+img(i-2,j,0)+img(i-2,j+1,0)+img(i-2,j+2,0)+img(i-1,j-2,0)+img(i-1,j-1,0)+img(i-1,j,0)+img(i-1,j+1,0)+img(i-1,j+2,0)+img(i,j-2,0)+img(i,j-1,0)+img(i,j,0)+img(i,j+1,0)+img(i,j+2,0)+img(i+1,j-2,0)+img(i+1,j-1,0)+img(i+1,j,0)+img(i+1,j+1,0)+img(i+1,j+2,0)+img(i+2,j-2,0)+img(i+2,j-1,0)+img(i+2,j,0)+img(i+2,j+1,0)+img(i+2,j+2,0))/25;
	  }
	}

    int w3 = average3.img_width();
	int h3 = average3.img_height();
	for( int j=3; j<h3-3; j++ ){
	  for( int i=3; i<w3-3; i++ ){
		average3(i,j,0)=(img(i-3,j-3,0)+img(i-3,j-2,0)+img(i-3,j-1,0)+img(i-3,j,0)+img(i-3,j+1,0)+img(i-3,j+2,0)+img(i-3,j+3,0)+img(i-2,j-3,0)+img(i-2,j-2,0)+img(i-2,j-1,0)+img(i-2,j,0)+img(i-2,j+1,0)+img(i-2,j+2,0)+img(i-2,j+3,0)+img(i-1,j-3,0)+img(i-1,j-2,0)+img(i-1,j-1,0)+img(i-1,j,0)+img(i-1,j+1,0)+img(i-1,j+2,0)+img(i-1,j+3,0)+img(i,j-3,0)+img(i,j-2,0)+img(i,j-1,0)+img(i,j,0)+img(i,j+1,0)+img(i,j+2,0)+img(i,j+3,0)+img(i+1,j-3,0)+img(i+1,j-2,0)+img(i+1,j-1,0)+img(i+1,j,0)+img(i+1,j+1,0)+img(i+1,j+2,0)+img(i+1,j+3,0)+img(i+2,j-3,0)+img(i+2,j-2,0)+img(i+2,j-1,0)+img(i+2,j,0)+img(i+2,j+1,0)+img(i+2,j+2,0)+img(i+2,j+3,0)+img(i+3,j-3,0)+img(i+3,j-2,0)+img(i+3,j-1,0)+img(i+3,j,0)+img(i+3,j+1,0)+img(i+3,j+2,0)+img(i+3,j+3,0))/49;
	  }
	}

	if( !average1.write( "average-AJG23085-3.pgm" ) ){
	  std::cerr << "cannot write the file!: average-AJG23085-3.pgm" << std::endl;
	  exit( -1 );
	}
	if( !average2.write( "average-AJG23085-5.pgm" ) ){
	  std::cerr << "cannot write the file!: average-AJG23085-5.pgm" << std::endl;
	  exit( -1 );
	}
	if( !average3.write( "average-AJG23085-7.pgm" ) ){
	  std::cerr << "cannot write the file!: average-AJG23085-7.pgm" << std::endl;
	  exit( -1 );
	}
    
    return 0;
}