//AJG23085 谷口香央

#include "report-3-AJG23085_pokergame.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

PokerGame::PokerGame(int _money, int _max_money, int _bet_money):Poker(){
  money = _money;
  max_money = _max_money;
  bet_money = _bet_money;
}

void PokerGame::draw_cards(){
  srand((unsigned int)time(NULL));
  for(int i=0; i<52; i++){
    card[i] = i;
  }
  for(int i=0; i<10; i++){
    int tmp, j;
    j = rand()%52;
    tmp = card[i];
    card[i] = card[j];
    card[j] = tmp;
  }
  for (int i = 0; i < 5; i++){
    if(card[i]/13==0){
      newmark[i] = 'S';
    }else if(card[i]/13==1){
      newmark[i] = 'H';
    }else if(card[i]/13==2){
      newmark[i] = 'D';
    }else if(card[i]/13==3){
      newmark[i] = 'C';
    }
    newnumber[i] = card[i] % 13 + 1;
    mark[i]=newmark[i];
    number[i]=newnumber[i];
  }
  for (int i = 0; i < 5; i++){
    if(card[i+5]/13==0){
      change_mark[i] = 'S';
    }else if(card[i+5]/13==1){
      change_mark[i] = 'H';
    }else if(card[i+5]/13==2){
      change_mark[i] = 'D';
    }else if(card[i+5]/13==3){
      change_mark[i] = 'C';
    }
    change_number[i] = card[i+5] % 13 + 1;
  }
}

void PokerGame::change_cards(int i){
  mark[i] = change_mark[i];
  number[i] = change_number[i];
}

void PokerGame::change_money(){
  int a;
  a = decision();
  if(a==0){
    money -= bet_money;
  }else if(a==1){
    money += bet_money;
  }else if(a==2){
    money += bet_money*1.8;
  }else if(a==3){
    money += bet_money*1.5;
  }else if(a==4){
    money += bet_money*1.6;
  }else if(a==5){
    money += bet_money*1.7;
  }else if(a==6){
    money += bet_money*1.9;
  }else{
    money += bet_money*2;
  }
}

  void PokerGame::continue_game(){
    std::cout << "所持金: " << money << std::endl;
    if(money>max_money){
      std::cout << "所持金が最大金額を超えました。ゲームを終了します。" << std::endl;
      ex = 1;
    }else if(money<=0){
      std::cout << "所持金が0円になりました。ゲームを終了します。" << std::endl;
      ex = 1;
    }
  }

    int PokerGame::get_money(){ 
        return money;
    } 

    int PokerGame::get_ex(){ 
        return ex;
    } 

    int PokerGame::change_bet_money(int _bet_money){
        bet_money = _bet_money;
        return bet_money;
    }
