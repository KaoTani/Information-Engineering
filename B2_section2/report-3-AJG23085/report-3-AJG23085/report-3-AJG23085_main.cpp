//AJG23085 谷口香央

#include <iostream>
#include "report-3-AJG23085_pokergame.h"
using namespace std;

int main(){
  int x, y, z;
  cout << "所持金を入力してください: " << endl;
  cin >> x;
  cout << "最大金額を入力してください: " << endl;
  cin >> y;
  PokerGame game(x, y, 0);

  while(game.get_ex()==0){
  int d;
  cout << "かけ金を入力してください: " << endl;
  cin >> d;
  game.change_bet_money(d);

  game.draw_cards();
  game.print_cards();

  for(int i=0; i<5; i++){
    int d;
    cout << i+1 <<  "番目のカードを交換しますか？(0:交換しない, 1:交換する)" << endl;
    cin >> d;
    if(d==1){
      game.change_cards(i);
    }
  }
  game.print_cards();
  game.change_money();
  game.continue_game();
  }

}