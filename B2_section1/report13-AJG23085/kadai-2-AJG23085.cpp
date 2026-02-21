// 第11回 演習課題(2)
/*
氏名：谷口香央
学籍番号：AJG23085
*/

// ヘッダファイルなどを記述
#include <string>
#include <iostream>
using namespace std;

// クラスの定義
class Coordinate { // 座標を扱うクラス
// write here...
private:
  int x;
  int y;

public:
  Coordinate(int _x, int _y){
    x = _x;
    y = _y;
  }

  void show(){
    cout << "The current position is (" << x << ", " << y << ")" << endl;
  }

  void up(){
    y++;
  }

  void down(){
    y--;
  }

  void left(){
    x--;
  }

  void right(){
    x++;
  }
};

int main() {
  // write here...
  Coordinate z(0, 0);
  string n;
  while(1){
    cout << "Enter a command (up, down, left, right, show or quit): ";
    cin >> n;
    if(n == "up"){
      z.up();
    }else if (n == "down"){
      z.down();
    }else if (n == "left"){
      z.left();
    }else if (n == "right"){
      z.right();
    }else if (n == "quit"){
      cout << "Quit program." << endl;
      exit(1);
    }else if(n == "show"){
      z.show();
    }else{
      cout << "Invalid command." << endl; 
    }
  }

  
  return 0;
}
