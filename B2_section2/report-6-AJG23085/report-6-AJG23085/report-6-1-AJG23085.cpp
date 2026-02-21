//AJG23085 谷口香央
//Codespacesで確認お願いします

#include <iostream>
using namespace std;

void swap(int &x, int &y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

int main(){
    int a=1;
    int b=2;
    cout << "a = " << a << " , b = " << b << endl;
    swap(a, b);
    cout << "a = " << a << " , b = " << b << endl;
    
    return 0;
}