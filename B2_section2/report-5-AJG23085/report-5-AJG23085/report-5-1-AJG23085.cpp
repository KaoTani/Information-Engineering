//AJG23085 谷口香央

#include<iostream>
#include<string>
#include"assignment5.h"
using namespace std;

class apple: public base{
    public:
        apple():base("apple", 1000){}
        double get_price(double weight){
            int price;
            price = unit_price * weight;
            return price;
        }
};

class yogurt: public base{
    public:
        yogurt():base("yogurt", 350){}
        double get_price(double weight){
            int price;
            price = unit_price * weight + 50;
            return price;
        }
};

int main(){
    base *p;
    int c=0;
    double w;
    string n;

    while(c==0){
        apple a;
        yogurt y;

        cout << "Enter 'name' (apple or yogurt)." << endl;
        cin >> n;
        if(n=="apple"){
            p = &a;
        }else if(n=="yogurt"){
            p = &y;
        }else{
            cout << "Error" << endl << endl;
            continue;
        }
        cout << "Enter 'weight' (kg)." << endl;
            cin >> w;
        if(w<0){
            cout << "Error" << endl << endl;
            continue;
        }
            cout <<  "The price of " << p->get_name() << " is " << p->get_price(w) << " yen." << endl << endl;
    }
}