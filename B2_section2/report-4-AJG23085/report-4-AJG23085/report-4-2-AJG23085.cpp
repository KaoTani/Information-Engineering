//AJG23085 谷口香央

#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
  double x=2.0, fx_1, fx_2=1.0, eps, a;
  int i=0, n=500;
  eps = 0.00010;
  a = 0.10;

  ofstream ofs;
  ofs.open("report-4-2-AJG23085.txt");
  ofs << "f(x) = cos(x)" << endl;
  while(i<500 && abs(fx_2)>=eps){
    fx_1 = cos(x);
    fx_2 = -sin(x);
    ofs << i  << setw(6) << "x=" << x << setw(10) << "f(x)=" << fx_1 << setw(10) << "grad=" << fx_2 << endl;
    x = x - a*fx_2;
    i++;
  }
  ofs.close();

  return 0;
}