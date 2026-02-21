//AJG23085 谷口香央
//Makefileを使って実行してます。

#include <iostream>
#include <cmath>
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
    ex2image mag( img );
    double x,y;

	//画像をsobelにかける
	int w = mag.img_width();
	int h = mag.img_height();
	for( int j=1; j<h-1; j++ ){
	  for( int i=1; i<w-1; i++ ){
        x=(-1)*img(i-1,j-1,0)+(-2)*img(i-1,j,0)+(-1)*img(i-1,j+1,0)+img(i+1,j-1,0)+2*img(i+1,j,0)+img(i+1,j+1,0);
	    y=img(i-1,j-1,0)+(-1)*img(i-1,j+1,0)+2*img(i,j-1,0)+(-2)*img(i,j+1,0)+img(i+1,j-1,0)+(-1)*img(i+1,j+1,0);
        if(x<0){
            x=0;
        }else if(x>255){
            x=255;
        }
        if(y<0){
            y=0;
        }else if(y>255){
            y=255;
        }
        mag(i,j,0)=sqrt(x*x+y*y);
      }
	}
	if( !mag.write( "mag-AJG23085.pgm" ) ){
	  std::cerr << "cannot write the file!: mag-AJG23085.pgm" << std::endl;
	  exit( -1 );
	}
	
    return 0;
}