//AJG23085 谷口香央

#ifndef AJG23085_pokergame_h
#define AJG23085_pokergame_h
#include "report-3_poker.h"

class PokerGame : public Poker{
  private:
    int card[52];
    char newmark[5];
    int newnumber[5];
    char change_mark[5];
    int change_number[5];
    int money;
    int max_money;
    int bet_money;
    int ex=0;

  public:
    PokerGame(int _money, int _max_money, int _bet_money);
    void draw_cards();
    void change_cards(int i);
    void change_money();
    void continue_game();
    int get_money();
    int get_ex();
    int change_bet_money(int _bet_money);

};


#endif