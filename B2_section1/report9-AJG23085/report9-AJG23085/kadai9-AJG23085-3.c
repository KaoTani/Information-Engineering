//AJG23085 谷口香央

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
  FILE *fp1, *fp2;
  fp1 = fopen(argv[1], "r");
  fp2 = fopen(argv[2], "r");
  if(fp1 == NULL){
    printf("Cannot open file.\n");
    exit(1);
  }
  if(fp2 == NULL){
    printf("Cannot open file.\n");
    exit(1);
  }

  int x[5][5], y[5][5];
  int i, j;
  for(i=0; i<5; i++){
    if(fscanf(fp1, "%d %d %d %d %d", &x[i][0], &x[i][1], &x[i][2], &x[i][3], &x[i][4])==EOF){
    break;
    }
  }

  for(i=0; i<5; i++){
    if(fscanf(fp2, "%d %d %d %d %d", &y[i][0], &y[i][1], &y[i][2], &y[i][3], &y[i][4])==EOF){
    break;
    }
  }
  
  int a[5]={-1, -1, -1, -1, -1};
  int b[5]={0, 0, 0, 0, 0};
  int stu, kibo, juni;
  for(kibo=0; kibo<5; kibo++){
    for(stu=0; stu<5; stu++){
      if(b[stu]==0){
        if(a[y[stu][kibo]]==-1){
          a[y[stu][kibo]]=stu;
        }else{
          for(juni=0; juni<5; juni++){
            if(x[kibo][juni]==a[y[stu][kibo]]){
            }else if(x[kibo][juni]==stu){
              b[a[y[stu][kibo]]]=0;
              a[y[stu][kibo]]=stu;
            }
          }
        }
      }
      if(a[y[stu][kibo]]==-1){
        continue;  
      }else{
        b[stu]=1;
      }
      }
    }
  

  for(i=0; i<5; i++){
    printf("No.%d lab → No.%d student\n", i, a[i]);
  }

  fclose(fp1);
  fclose(fp2);
  return 0;
}