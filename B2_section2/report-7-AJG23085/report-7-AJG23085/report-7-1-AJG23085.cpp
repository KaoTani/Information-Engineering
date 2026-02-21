//AJG23085 谷口香央
//Codespacesで採点お願いします。

#include <iostream>
using namespace std;

class Complex {
    double r_p;
    double i_p;

 public:
    Complex(){
        r_p = 0;
        i_p = 0;
    }
    Complex(double _r_p, double _i_p){
         r_p = _r_p;
         i_p = _i_p;
    }
    void get_ri(double &_r_p, double &_i_p){
        _r_p = r_p;
        _i_p = i_p;
    }
    Complex operator+(Complex ob2);
    Complex operator-(Complex ob2);
    Complex operator*(Complex ob2);
    Complex operator/(Complex ob2);
    int operator==(Complex &ob2) {
        return r_p == ob2.r_p && i_p == ob2.i_p;
    }
 };

Complex Complex::operator+(Complex ob2) {
    Complex temp;
    temp.r_p = r_p + ob2.r_p;
    temp.i_p = i_p + ob2.i_p;
    return temp;
}
Complex Complex::operator-(Complex ob2) {
    Complex temp;
    temp.r_p = r_p - ob2.r_p;
    temp.i_p = i_p - ob2.i_p;
    return temp;
}
Complex Complex::operator*(Complex ob2) {
    Complex temp;
    temp.r_p = r_p * ob2.r_p - i_p * ob2.i_p;
    temp.i_p = i_p * ob2.r_p + r_p * ob2.i_p;
    return temp;
}
Complex Complex::operator/(Complex ob2) {
    Complex temp;
    temp.r_p = (r_p * ob2.r_p + i_p * ob2.i_p) / (ob2.r_p * ob2.r_p + ob2.i_p * ob2.i_p);
    temp.i_p = (i_p * ob2.r_p - r_p * ob2.i_p) / (ob2.r_p * ob2.r_p + ob2.i_p * ob2.i_p);
    return temp;
}

 int main() {
    Complex o1(3.0, 4.0),o2(1.0,2.0),o3;
    double r, i;

    o1.get_ri(r, i);
    cout << "o1 : "<< r <<"+" << i << "i" << endl;
    o2.get_ri(r, i);
    cout << "o2 : "<< r <<"+" << i << "i" << endl << endl;
    if (o1 == o2) {
        cout << "o1 is equal to o2" << endl;
    } else {
        cout << "o1 is NOT equal to o2" << endl;
    }
    cout << endl;
    o3 = o1 + o2;
    o3.get_ri(r, i);
    cout << "o1 + o2 : "<< r <<"+" << i << "i" << endl;
    o3 = o1 - o2;
    o3.get_ri(r, i);
    cout << "o1 - o2 : "<< r <<"+" << i << "i" << endl;
    o3 = o1 * o2;
    o3.get_ri(r, i);
    cout << "o1 * o2 : "<< r <<"+" << i << "i" << endl;
    o3 = o1 / o2;
    o3.get_ri(r, i);
    cout << "o1 / o2 : "<< r <<"+" << i << "i" << endl;

    return 0;
 }