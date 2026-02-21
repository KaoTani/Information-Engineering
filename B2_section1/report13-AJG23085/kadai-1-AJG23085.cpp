// 第11回 演習課題(1)
/*
氏名：谷口香央
学籍番号：AJG23085
*/

// ヘッダファイルなどを記述
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// クラスの定義
class Score {
// write here...
private:
  string name;
  int sugaku;
  int rika;
  int eigo;

public:
  Score(string _name, int _sugaku, int _rika, int _eigo){
    sugaku = _sugaku;
    rika = _rika;
    eigo = _eigo;
  }

  string get_name(){
    return name;
  }

  double get_ave(){
    return (double)(sugaku + rika +eigo) / 3.0;
  }

};


int main() {
  
  // ファイルを開く
  // write here...
  ifstream fin("kadai-1_score.txt");
  if (!fin) { // ファイルが開けたかどうかの確認
  cout << "Cannot open input file." << endl;
  exit(0);
  }

  // データの読み込みとクラスへの登録
  // write here...
  string n;
  int m, s, e;
  int i;
  fin >> n >> m >> s >> e;
  Score suzuki(n, m, s, e);
  fin >> n >> m >> s >> e;
  Score takeda(n, m, s, e);
  fin >> n >> m >> s >> e;
  Score yamada(n, m, s, e);


  // 人毎に平均点の算出と表示
  // The average score of (人名): (点数） で出力する．
    /*
    想定する出力：
    The average score of Suzuki: 70
    The average score of Takeda: 80
    The average score of Yamada: 63.3333
    */
  // write here...
  cout << "The average score of " << suzuki.get_name() << ": " << suzuki.get_ave() << endl;
  cout << "The average score of " << takeda.get_name() << ": " << takeda.get_ave() << endl;
  cout << "The average score of " << yamada.get_name() << ": " << yamada.get_ave() << endl;



  
  return 0;
}
