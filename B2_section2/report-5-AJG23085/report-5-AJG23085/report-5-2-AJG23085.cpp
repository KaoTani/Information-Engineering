//AJG23085 谷口香央

#include<iostream>
using namespace std;

int main(){
    int a[1999]={0};
    int i, j;
    for(i=2; i<=300; i++){
        for(j=1; j<i; j++){
            if(i%j==0){
                a[i-2]+=j;
            }
        }
    }
   for(i=2; i<=2000; i++){
        for(j=i+1; j<=2000; j++){
            if(j==a[i-2] && i==a[j-2]){
                cout << "( " << i << " , " << j << " )" << endl;
            }
        }
    }
    return 0;
}