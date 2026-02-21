//AJG23085 谷口香央
//課題へのコメント：coutやcinにはstdを付けなくてはいけないことをすっかり忘れていて、1時間くらい悩みました。もう忘れないように頑張ります。

#include <iostream>
#include <time.h>
using namespace std;

#define NUM_CARDS 52     // トランプ1組のカード枚数
#define NUM_ATTRIBUTES 2 // ゲームに関わる人数 (プレイヤとディーラ)

enum ATTRIBUTE { // プレイヤとディーラの区別用
    PLAYER, 
    DEALER
};

class Blackjack {
 protected:

// 引いたカードのマーク (S:スペード, H:ハート, D:ダイヤ, C:クラブ) と番号を格納
// 1番目の配列要素でプレイヤとディーラ，
// 2番目の配列要素で引いた各カードを区別 (カードは最大11枚まで引ける)
    char mark[NUM_ATTRIBUTES][11]; 
    int number[NUM_ATTRIBUTES][11];

// プレイヤとディーラが既に引いたカードの枚数を格納
// 配列要素でプレイヤとディーラを区別
// プレイヤがカードを2枚引き終えると num_cards_drawn[PLAYER] == 2，
// 3枚引き終えると num_cards_drawn[PLAYER] == 3 のように更新されていく
    int num_cards_drawn[NUM_ATTRIBUTES]; 

// 当該カードが既に引かれているか (0:引かれてない, 1:引かれている)
    bool drawn[NUM_CARDS];

 public:
    Blackjack(){
        int a=0, b=0;
        for(int i=0; i<NUM_CARDS; i++){
            drawn[i] = 0;
        }
        srand((unsigned int)time(NULL));
        for(int i=0; i<NUM_ATTRIBUTES; i++){
            for(int j=0; j<11; j++){
                a = rand() % 4 + 1;
                b = rand() % 13 + 1;
                if(drawn[a*b]==0){
                    if(a==1){
                        mark[i][j] = 'S';
                    }else if(a==2){
                        mark[i][j] = 'H';
                    }else if(a==3){
                        mark[i][j] = 'D';
                    }else if(a==4){
                        mark[i][j] = 'C';
                    }
                    number[i][j] = b;
                    drawn[a*b] = 1;
                }else{
                    j--;
                }
            }
            num_cards_drawn[i] = 0;
        }
    } // コンストラクタ (各データメンバの初期化が必要)

 // ディーラとプレイヤがそれぞれ最初の2枚のカードを引く (講義資料p.5の処理1)
    void init_action(){
        cout << "Dealer: " << mark[DEALER][0] << number[DEALER][0] << " ***" << endl;
        num_cards_drawn[DEALER] = 2;
        num_cards_drawn[PLAYER] = 2;
        print_cards(PLAYER);
    }

 // プレイヤがHitかStandを決める (講義資料p.5の処理2)
 //返り値として，2-bに該当する場合に0，2-a-bに該当する場合に1をそれぞれ返し，
// 値が返された後の分岐処理はmain関数で行うことを想定
    int player_action(){
        int a=2;
        char b;
        int sum = 0;
        sum = sum_cards(PLAYER);
        do{
            cout << "Hit (h) or Stand (s)?: ";
            cin >> b;
            if(b=='s'){
                a=0;
                break;
            }
            num_cards_drawn[PLAYER]++;
            sum = sum_cards(PLAYER);
            if(sum>21){
                a=1;
            }
            print_cards(PLAYER);
        }while(a==2);

        return a;
    };

 // ディーラがカードを引く (講義資料p.6の処理3)
 // 返り値として，3-bに該当する場合に0，3-a-bに該当する場合に1をそれぞれ返し，
// 値が返された後の分岐処理，および講義資料p.6の処理4はmain関数で行うことを想定
    int dealer_action(){
        int a=2;
        int sum = 0;
        sum = sum_cards(DEALER);
        do{
            if(sum>16){
                a=0;
                break;
            }
            num_cards_drawn[DEALER]++;
            sum = sum_cards(DEALER);
            if(sum>21){
                a=1;
            }
        }while(a==2);
        print_cards(DEALER);

        return a;
    };

// 以下のメンバ関数は，処理対象（プレイヤかディーラ）を引数で指定
// 例: ディーラがカードを引く処理は draw_card(DEALER) で実行

// カードを1枚自動で引く
// 引いたカードはデータメンバのmarkとnumberに2番目の配列要素値が小さい順に
// 格納していく
    //void draw_card(ATTRIBUTE attr){};

 // 引いた全カードの合計値を計算
    int sum_cards(ATTRIBUTE attr){
        int sum = 0;
        for(int i=0; i<num_cards_drawn[attr]; i++){
            if(number[attr][i]<10){
                sum += number[attr][i];
            }else{
                sum += 10;
            }
        }
        return sum;
    };

 // 引いた全てのカードを表示
    void print_cards(ATTRIBUTE attr){
        if(attr==0){
            cout << "Player: ";
        }else{
            cout << "Dealer: ";
        }
        for(int i=0; i<num_cards_drawn[attr]; i++){
            cout << mark[attr][i] << number[attr][i] << " ";
        }
        cout << endl;
    };

}; // class Blackjack

int main(){
    Blackjack black;
    int a=2, b=2;
    int p_sum = 0, d_sum = 0;
    black.init_action();
    a = black.player_action();
    b = black.dealer_action();
    p_sum = black.sum_cards(PLAYER);
    d_sum = black.sum_cards(DEALER);
    if(a==0 && b==0){
        if(p_sum>d_sum){
            cout << "Player win (Player:" << p_sum << ", Dealer:" << d_sum << ")" << endl;
        }else if(p_sum<d_sum){
            cout << "Player lose (Player:" << p_sum << ", Dealer:" << d_sum << ")" << endl;
        }else{
            cout << "Push (Player:" << p_sum << ", Dealer:" << d_sum << ")" << endl;
        }
    }else if(a==0 && b==1){
        cout << "Player win (Player:" << p_sum << ", Dealer:" << d_sum << ") (Dealer Bust)" << endl;
    }else if(a==1 && b==0){
        cout << "Player lose (Player:" << p_sum << ", Dealer:" << d_sum << ") (Player Bust)" << endl;
    }else{
        cout << "Push (Player:" << p_sum << ", Dealer:" << d_sum << ") (Player & Dealer Bust)" << endl;
    }

    return 0;
 }