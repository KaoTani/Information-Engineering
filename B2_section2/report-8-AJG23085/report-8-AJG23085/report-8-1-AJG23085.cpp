//AJG23085 谷口香央
//Codespacesで採点お願いします。

#include <iostream>
#include <cstdlib>
using namespace std;

class frac{
    int x,y;

    public:
        frac() { x = 0, y = 0; }
        frac(int i, int j) {
            if(j<0){
                x = -i, y = -j;
            }else{
                x = i, y = j;
            }
        }
        frac operator*(frac ob2);
        friend frac operator*(frac ob1, int i);
        friend frac operator*(int i, frac ob2);
        frac operator+(frac ob2);
        friend frac operator+(frac ob1, int i);
        friend frac operator+(int i, frac ob2);
        int operator==(frac &ob2){
            return x == ob2.x && y == ob2.y;
        }
        friend std::ostream &operator<<(std::ostream& os, const frac& ob);
};

frac frac::operator*(frac ob2) {
    frac temp;
    temp.x = x * ob2.x;
    temp.y = y * ob2.y;
    return temp;
}

frac operator*(frac ob1, int i){
    frac temp;
    temp.x = ob1.x * i;
    temp.y = ob1.y;
    return temp;
}

frac operator*(int i, frac ob2){
    frac temp;
    temp.x = i * ob2.x;
    temp.y = ob2.y;
    return temp;
}

frac frac::operator+(frac ob2) {
    frac temp;
    temp.x = x * ob2.y + ob2.x * y;
    temp.y = y * ob2.y;
    return temp;
}

frac operator+(frac ob1, int i){
    frac temp;
    temp.x = ob1.x + i * ob1.y;
    temp.y = ob1.y;
    return temp;
}

frac operator+(int i, frac ob2){
    frac temp;
    temp.x = i * ob2.y + ob2.x;
    temp.y = ob2.y;
    return temp;
}

std::ostream &operator<<(std::ostream& os, const frac& ob){
    if(ob.x == 0){
        os << "0";
    }else if(ob.y == 1){
        os << ob.x;
    }else if((ob.x<0 && ob.y>0)||(ob.x>0 && ob.y<0) ){
        os << "-" << abs(ob.x) << "/" << abs(ob.y) << "";
    }else{
        os << abs(ob.x) << "/" << abs(ob.y);
    }
    return os;
}

int main(){
    frac o1(1,3), o2(3,-5), o3;
    if (o1 == o2) {
        cout << o1 << " is equal to " << o2 << endl;
    } else {
        cout << o1 << " is NOT equal to " << o2 << endl;
    }
    cout << endl;
    o3 = o1 + 2;
    std::cout << o1 << " + 2 = " << o3 << std::endl;
    o3 = 2 + o2;
    std::cout << "2 + (" << o2 << ") = " << o3 << std::endl;
    o3 = o1 + o2;
    std::cout << o1 << " + (" << o2 << ") = " << o3 << std::endl;
    o3 = o1 * 10;
    std::cout << o1 << " * 10 = " << o3 << std::endl;
    o3 = 10 * o2;
    std::cout << "10 * (" << o2 << ") = " << o3 << std::endl;
    o3 = o1 * o2;
    std::cout << o1 << " * (" << o2 << ") = " << o3 << std::endl;

    return 0;
}