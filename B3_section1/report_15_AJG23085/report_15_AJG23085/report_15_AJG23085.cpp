//AJG23085 谷口香央
//いつもa.outでコンパイルしていたけど、report_15_AJG23085にしてみました。

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]){
    srand(stoi(argv[2]));
    int len = stoi(argv[1]);
    float x, y, z, a;
    int count=0;
    for(int i=0; i<len; i++){
        x=(float)rand()/(float)RAND_MAX;
        y=(float)rand()/(float)RAND_MAX;
        z=(float)rand()/(float)RAND_MAX;
        a=x*x+y*y+z*z;
        if(a<1.0){
            count++;
        }
    }
    float pi;
    pi=(float)count/(float)len*6.0;
    printf("%lf\n", pi);

    return 0;
}