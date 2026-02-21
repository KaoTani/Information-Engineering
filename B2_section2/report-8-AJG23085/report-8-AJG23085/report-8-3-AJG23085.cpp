//AJG23085 谷口香央
//Codespacesで採点お願いします。

#include <iostream>
#include <string>
using namespace std;

int main(){
    int a[4] = {2, 4, 6, 8};
    string num;
    int b[4];
    int c;
    int d;
    while(c!=4){
        c=0;
        d=0;
        cout << "予想する数字を入力して下さい：";
        cin >> num;
        for(int i=0; i<4; i++){
            b[i] = (int)(num[i] - '0');
        }
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(a[i]==b[j]){
                    if(i==j){
                        c++;
                    }else{
                        d++;
                    }
                }
            }
        }
        cout << "ヒット数 = " << c << " ブロー数 = " << d << endl;
    }
    cout << "正解です" << endl;

    return 0;
}