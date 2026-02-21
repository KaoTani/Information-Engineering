// 第12回 演習課題(2)の解
/*
氏名：谷口香央
学籍番号：AJG23085
*/

#include <iostream>	// coutのため
#include <iomanip>	// setwのため
using namespace std;


class kuku_array {
// write here...
  public:
    int **array;
    int size[2];
  
    kuku_array(){
      size[0] = 0;
      size[1] = 0;
    }

    kuku_array(int _size1, int _size2){
      size[0] = _size1;
      size[1] = _size2;
      array = new int*[size[0]];
      for(int i=0; i<size[0]; i++){
        array[i] = new int[size[1]];
      }
    }

    void kuku_array_make(){
      for(int i=0; i<size[0]; i++){
        for(int j=0; j<size[1]; j++){
          array[i][j] = (i+1) * (j+1);
        }
      }
    }

    void kuku_array_print(){
      // 1〜9の表示(横軸の表示)
      // write here...
      cout << "   |";
      for(int i=1; i<=9; i++){
        cout << setw(3) << i;
      }
      cout << endl;

      // 横線の表示
      // write here...
      cout << "-------------------------------" << endl;

      // 九九本体の表示
      // write here...
      for(int i=0; i<9; i++){
        cout << setw(3) << i+1 << "|";
        for(int j=0; j<9; j++){
          cout << setw(3) << array[i][j];
        }
        cout << endl;
      }
    }

    kuku_array(kuku_array &obj){
      size[0] = obj.size[0];
      size[1] = obj.size[1];
      array = new int*[size[0]];
      for(int i=0; i<size[0]; i++){
        array[i] = new int[size[1]];
      }
      for(int i=0; i<size[0]; i++){
        for(int j=0; j<size[1]; j++){
          array[i][j] = obj.array[i][j];
        }
      }
    }

    ~kuku_array() {
      if (size[0]!=0 || size[1]!=0) {
        delete [] array;
        size[0] = 0;
        size[1] = 0;
      }
    }
};

int main() {

  // 九九オブジェクトobj1の生成
  // write here...
  kuku_array obj1(9, 9);


  // 九九を計算して、obj1の配列に入れる
  // write here...
  obj1.kuku_array_make();


  // 九九オブジェクトobj2にobj1の中身をコピーする
  // write here...
  kuku_array obj2 = obj1;



  // obj2に保持されている九九を表示する
  // write here...
  obj2.kuku_array_print();


  return 0;
}
