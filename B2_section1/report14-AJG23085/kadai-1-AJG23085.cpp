// 第12回 演習課題(1)
/*
氏名：谷口香央
学籍番号：AJG23085
*/

#include <iostream>
#include <time.h>
using namespace std;

// 時を表すクラス
class time_hms { 
// write here...
private:
  int hour;
  int min;
  int sec;

public:
  time_hms(int _hour, int _min, int _sec){
    hour = _hour;
    min = _min;
    sec = _sec;
  }

  time_hms(time_hms &time){
    hour = time.hour;
    min = time.min;
    sec = time.sec;
  }

  void tasu(time_hms &time){
    hour += time.hour;
    min += time.min;
    sec += time.sec;
    if(sec>60){
      min++;
      sec-=60;
    }
    if(min>60){
      hour++;
      min-=60;
    }
  }

  void get_hour(){
    cout << hour << ":";
  }

  void get_min() {
    cout << min << ":";
  }

  void get_sec(){
    cout << sec << endl;
  }

};

int main() {
  // write here...
  time_t t = time(nullptr);
  struct tm *local = localtime(&t);
  time_hms time1(local->tm_hour, local->tm_min, local->tm_sec);
  time_hms time2(3, 35, 40);
  cout << "time1: ";
  time1.get_hour();
  time1.get_min();
  time1.get_sec();
  cout << "time2: ";
  time2.get_hour();
  time2.get_min();
  time2.get_sec();
  time1.tasu(time2);
  cout << "time1(time2 is added): ";
  time1.get_hour();
  time1.get_min();
  time1.get_sec();

  return 0;
}
