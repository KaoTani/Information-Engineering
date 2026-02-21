//AJG23085 谷口香央

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
  char id[100];
  char L_name[100];
  char F_name[100];
  int birth;
  char phone[11];
}x[100], y;

  int delete(FILE *b, char *a){
    b = fopen(a, "w");
    if(b == NULL){
      printf("Cannot open file.\n");
      exit(1);
    }
    int d, e;
    printf("Please input id: ");
    scanf("%s", y.id);
    printf("delete it?(1:yes, 0:no): ");
    scanf("%d", &d);
    if(d == 1){
    for(int i=0; i<100; i++){
      if((strcmp(x[i].id, y.id)) == 0){
        x[i].id[0] = '\0';
        x[i].L_name[0] = '\0';
        x[i].F_name[0] = '\0';
        x[i].birth = '\0';
        x[i].phone[0] = '\0';
        e = 0;
        for(int j=i; j<99; j++){
          x[j] = x[j+1];
          }
        printf("delete success.\n");
      }else{ 
      e++;
      }
      if(x[i].birth != 0){
      fprintf(b, "%s %s %s %d %s\n", x[i].id, x[i].L_name, x[i].F_name, x[i].birth, x[i].phone);
      }
    }
      fclose(b);
      if(e == 100){
        printf("id not found.\n");
      }
      }else{
      delete(b, a);
    }

    return 0;
  }

int search(){
  int c, f=0;
  printf("What do you want to search?\n");
  printf("1. id\n");
  printf("2. last name\n");
  printf("3. first name\n");
  printf("4. birth\n");
  printf("5. phone number\n");
  printf("User input number: ");
  scanf("%d", &c);
  if(c<1 || c>5){
    printf("Please input 1~5.\n");
    search();
  }
  if(c == 1){
    printf("Please input id: ");
    scanf("%s", y.id);
    for(int i=0; i<100; i++){
      if(strcmp(x[i].id, y.id) == 0){
        printf("%s %s %s %d %s\n", x[i].id, x[i].L_name, x[i].F_name, x[i].birth, x[i].phone);
        f++;
      }
    }
    if(f == 0){
      printf("not found.\n");
    }
  }else if(c == 2){
      printf("Please input last name: ");
      scanf("%s", y.L_name);
      for(int i=0; i<100; i++){
        if(strcmp(x[i].L_name, y.L_name) == 0){
          printf("%s %s %s %d %s\n", x[i].id, x[i].L_name, x[i].F_name, x[i].birth, x[i].phone);
          f++;
        }
      }
    if(f == 0){
      printf("not found.\n");
    }
    }else if(c == 3){
      printf("Please input first name: ");
      scanf("%s", y.F_name);
      for(int i=0; i<100; i++){
        if(strcmp(x[i].F_name, y.F_name) == 0){
          printf("%s %s %s %d %s\n", x[i].id, x[i].L_name, x[i].F_name, x[i].birth, x[i].phone);
          f++;
        }
      }
    if(f == 0){
      printf("not found.\n");
    }
    }else if(c == 4){
      printf("Please input birth: ");
      scanf("%d", &y.birth);
      for(int i=0; i<100; i++){
        if(x[i].birth == y.birth){
          printf("%s %s %s %d %s\n", x[i].id, x[i].L_name, x[i].F_name, x[i].birth, x[i].phone);
          f++;
        }
      }
    if(f == 0){
      printf("not found.\n");
    }
    }else if(c == 5){
      printf("Please input phone number: ");
      scanf("%s", y.phone);
      for(int i=0; i<100; i++){
        if(strcmp(x[i].phone, y.phone) == 0){
          printf("%s %s %s %d %s\n", x[i].id, x[i].L_name, x[i].F_name, x[i].birth, x[i].phone);
          f++;
        }
      }
    if(f == 0){
      printf("not found.\n");
    }
    }

  return 0;
}

int main(int argc, char *argv[]){
  FILE *fp1, *fp2, *fp3;
  fp1 = fopen(argv[1], "r");
  fp2 = fopen(argv[1], "a");
  if(fp1 == NULL){
    printf("Cannot open file.\n");
    exit(1);
  }
  int a=0, b, c;
  int st[100];
  
  printf("File opened.\n");
  for(int i=0; i<100; i++){
    if(fscanf(fp1, "%s %s %s %d %s", x[i].id, x[i].L_name, x[i].F_name, &x[i].birth, x[i].phone)==EOF){
    break;
    }
  }
  printf("1. register\n");
  printf("2. delete\n");
  printf("3. search\n");
  printf("User input number: ");
  scanf("%d", &a);
  if(a<1 || a>3){
    printf("Please input 1~3.\n");
    main(argc, argv);
  }
  if(a == 1){
    printf("Please input id: ");
    scanf("%s", y.id);
    printf("Please input last name: ");
    scanf("%s", y.L_name);
    printf("Please input first name: ");
    scanf("%s", y.F_name);
    printf("Please input birth(ex: 20240603): ");
    scanf("%d", &y.birth);
    printf("Please input phone number: ");
    scanf("%s", y.phone);
    fprintf(fp2, "%s %s %s %d %s\n", y.id, y.L_name, y.F_name, y.birth, y.phone);
      fclose(fp1);
      fclose(fp2);
    printf("continue?(1:yes, 0:no): ");
    scanf("%d", &b);
    if(b == 1){
      main(argc, argv);
    }else{
      printf("Thank you for using.\n");
    }
  }else if(a == 2){
    delete(fp3, argv[1]);
    printf("continue?(1:yes, 0:no): ");
    scanf("%d", &b);
    if(b == 1){
      main(argc, argv);
    }else{
      printf("Thank you for using.\n");
    }
  }else if(a == 3){
    search();
    printf("continue?(1:yes, 0:no): ");
    scanf("%d", &b);
    if(b == 1){
      main(argc, argv);
    }else{
      printf("Thank you for using.\n");
    }
  }

  return 0;
}