//AJG23085 谷口香央
//Codespacesで採点お願いします。

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int a[9];
    int b=0;
    int c=0;
    int i;
    for(i=10000; i<31623; i++){
        b = i*i;
        for(int j=8; j>=0; j--){
            a[j] = b / pow(10,j);
            b = b - a[j] * pow(10,j);
            if(a[j]==0){
                c++;
            }
        } 
        for(int j=0; j<9; j++){
            for(int k=j+1; k<9; k++){
                if(a[j]==a[k]){
                    c++;
                }
            }
        }
        if(c==0){
            cout << i << " " << i*i << endl;
        }
        c=0;
    }

    return 0;
}