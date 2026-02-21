//AJG23085 谷口香央

#include <stdio.h>
enum WEEK {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRYDAY, SATURDAY};

int main(void){
  enum WEEK today;
  int t;
  printf( "Please input today's day: ");
  scanf("%d", &t);
  today = (t+5)%7;
  printf("June %d, 2024\n", t);
  switch(today){
    case SUNDAY:
      printf("Sunday off.\n");
      break;
    case MONDAY:
      printf("Monday.\n");
      printf("5th: Theory of signal processing\n");
      break;
    case TUESDAY:
      printf("Tuesday.\n");
      printf("1st: Electrical network introduction\n");
      printf("3rd: Ordinary differental equation\n");
      break;
    case WEDNESDAY:
      printf("Wednesday.\n");
      printf("1st: Basic thermodynamics\n");
      printf("2nd: Programming languages introduction\n");
      printf("4&5th: Applied physics experiment\n");
      break;
    case THURSDAY:
      printf("Thursday.\n");
      printf("1st: Information theory A\n");
      printf("2nd: Information mathmatics\n");
      printf("4th: Information engineering seminar\n");
      break;
    case FRYDAY:
      printf("Friday.\n");
      printf("2nd: University English 3B\n");
      break;
    case SATURDAY:
      printf("Saturday off.\n");
      break;
    default:
      printf("Invalid input.\n");
      break;
  }
  
  return 0;
}