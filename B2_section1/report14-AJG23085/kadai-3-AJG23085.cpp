// 第12回 演習課題(3)
/*
氏名：谷口香央
学籍番号：AJG23085
*/

#include <iostream>
#include <stdlib.h> // rand関数のため
#include <time.h>
using namespace std;

class random_number {
// write here...
  public:
    double a;
    double b;

    random_number(){
      a = (random())/((double)RAND_MAX);
      b = (random())/((double)RAND_MAX);
    }

    ~random_number(){
      a = 0;
      b = 0;
    }
};

// 2x2の正方形と直径2の円を考える。円の中心は原点とする。
int main() {
  // write here...
  srand(time(nullptr));
  int inside = 0;
  int trial;
  cout << "Input the number of trials: ";
  cin >> trial;
  double x, y;
  for(int i=0; i<trial; i++){
    random_number obj;
    x = obj.a;
    y = obj.b;
    if(x*x + y*y <= 1){
      inside++;
    }
    }

  double pi = 4.0 * (double)inside / (double)trial;
  cout << "inside = " << inside << endl;
  cout << "A estimate of pi is " << pi << endl;


  return 0;
}
