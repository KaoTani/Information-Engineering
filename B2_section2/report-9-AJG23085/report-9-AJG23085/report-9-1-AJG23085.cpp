//AJG23085 谷口香央
//Codespacesで採点お願いします。

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

double ave(vector<int> a){
    int sum=0;
    for(int i=0; i<a.size(); i++){
        sum += a[i];
    }
    return (double)sum/(double)a.size();
}

double var(vector<int> a){
    double s = 0;
    double b = ave(a);
    for(int i=0; i<a.size(); i++){
        s += (a[i] - b) * (a[i] - b);
    }
    return s/(double)(a.size()-1);
}

void mode(vector<int> a){
    int c[101]={0};
    int max=0;
    for(int j=0; j<a.size(); j++){
            c[a[j]]++;
    }
    for(int i=0; i<101; i++){
        if(c[i]>max){max = c[i];}
    }
    vector<int> d;
    for(int i=0; i<101; i++){
        if(c[i]==max){
            d.push_back(i);
        }
    }
    for(int i=0; i<d.size(); i++){
        cout << d[i] << " ";
    }
}

double mid(vector<int> a){
    if(a.size()%2==0){
        return (double)((a[a.size()/2]+a[a.size()/2+1])/2);
    }else{
        return a[a.size()/2+1];
    }
}

int main(){
    srand((unsigned)time(NULL));
    int n;
    cout << "Input number: ";
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<a.size(); i++) {
        a[i] = rand()%101;
    }
    cout << endl;
    sort(a.begin(), a.end());
    cout << "Average: " << ave(a) << endl;
    cout << "Variance: " << var(a) << endl;
    cout << "Max: " << a.back() << endl;
    cout << "min: " << a[0] << endl;
    cout << "Mode: ";
    mode(a);
    cout << endl;
    cout << "Middle: " << mid(a) << endl;


    return 0;
}