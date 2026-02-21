//AJG23085 谷口香央

#include <iostream>
#include <string>
using namespace std;

class Account {
  protected:
    string name; // 名前
    int balance; // 円残高（単位：円）

  public:
    // コンストラクタ  
    Account(string _name, int _balance) {
      name = _name;       // 名前を初期化
      balance = _balance; // 円残高を初期化
    }
    // 名前を調べる
    string get_name() {
      return name;
    }
    // 円残高を調べる
    int get_balance() {
      return balance;
    }
    // 預ける
    void deposit(int amnt) {
      balance += amnt;
    }
    // おろす
    void withdraw(int amnt) {
      balance -= amnt;
    }
};

class AccountFx : public Account{
    int balance_cent;
    double ex_rate;

  public:
    AccountFx(string _name, int _balance, int _balance_cent, double _ex_rate):Account(_name, _balance){
    balance_cent = _balance_cent;//セント残高
    ex_rate = _ex_rate;
    }

    void ex_to_cent(int yen){
      balance -= yen;
      balance_cent += yen/ex_rate;
    }

    void ex_to_yen(int cent){
      balance_cent -= cent;
      balance += cent*ex_rate;
    }

    int get_balance_cent(){
      return balance_cent;
    }

    void update_ex_rate(double _ex_rate){
      ex_rate = _ex_rate;
    }
};

int main(){
  int a,b;
  double c;
  AccountFx x("Jiro",10000,10000,0.95);
  cout << "name：" << x.get_name() << endl;
  cout << "balance(yen)：" << x.get_balance() << endl;
  cout << "balance(cent)：" << x.get_balance_cent() << endl;

  int d,e=1;
  cout << "What do you do?" << endl;
  cout << "1.yen to cent" << endl;
  cout << "2.cent to yen" << endl;
  cout << "3.update exchange rate" << endl;
  cin >> d;

  while(e==1){
    if(d==1){
      cout << "Input yen:" << endl;
      cin >> a;
      x.ex_to_cent(a);
    }else if(d==2){
      cout << "Input cent:" << endl;
      cin >> b;
      x.ex_to_yen(b);
    }else if(d==3){
      cout << "Input exchange rate:" << endl;
      cin >> c;
      x.update_ex_rate(c);
    }else{
      cout << "Invalid command." << endl;
    }
      cout << "continue? 1.yes 2.no" << endl;
      cin >> e;
  }
    cout << "balance(yen)：" << x.get_balance() << endl;
    cout << "balance(cent)：" << x.get_balance_cent() << endl;
  
  return 0;
}