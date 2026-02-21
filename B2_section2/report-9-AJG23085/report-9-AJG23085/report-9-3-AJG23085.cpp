//AJG23085 谷口香央
//Codespacesで採点お願いします。

#include <iostream>
#include <list>
#include <cmath>
using namespace std;

int main(){
    list<int> l, m;
    int n=-1;
    int i=1;
    int sum=0;
    int c=0;
    double ave, sa;
    while(true){
        cout << i << "番目の数字を入力して下さい: ";
        cin >> n; 
        if(n==0){
            break;
        }
        l.push_back(n);
        i++;
    }

    for(auto p = l.begin(); p != l.end(); p++) {
        sum += *p;
    }
    ave = static_cast<double>(sum)/l.size();
    cout << "入力された数字の平均は" << ave << "です" << endl;

    sa = abs(static_cast<double>(*l.begin()) - ave);
    for(auto q = l.begin(); q != l.end(); q++) {
        if(sa > abs(static_cast<double>(*q) - ave)){
            sa = abs(static_cast<double>(*q) - ave);
        }
    }
    for(auto q = l.begin(); q != l.end(); q++) {
        c++;
        if(sa == abs(static_cast<double>(*q) - ave)){
            m.push_back(c);
        }
    }
    cout << "これは，";
    for (auto q = m.begin(); q != m.end(); ++q) {
        if (next(q) == m.end()) {
            cout << *q;
        } else {
            cout << *q << ", ";
        }
    }
    cout << "番目に入力された値に最も近いです" << endl;

    return 0;
}
