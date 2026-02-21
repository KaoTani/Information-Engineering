//AJG23085 谷口香央
//Codespacesで確認お願いします

#include <time.h>
#include <iostream>
using namespace std;

#include <time.h>
#include <iostream>
using namespace std;

struct sum_n {
    int n[10000];
    int num;
};

int wa_1(sum_n &a) {
    int b = 0;
    for (int i = 0; i < a.num; i++) {
       b += a.n[i];
    }
    return b;
}

int wa_2(int n[], int num) {
    int b = 0;
    for (int i = 0; i < num; i++) {
       b += n[i];
    }
    return b;
}

int main() {
    clock_t start1, end1, start2, end2;
    double diff1=0, diff2=0;
    sum_n x;
    srand((unsigned int) time(NULL));
    for (int i = 0; i < 1000; i++) {
        x.n[i] = rand()%1000;        
    }
    x.num = 1000;

    
    cout << "wa_2 ";
    start1 = clock();
    cout << wa_2(x.n, x.num) << ": ";
    end1 = clock();
    diff2 = (double)(end1-start1)/CLOCKS_PER_SEC;
    cout << diff2 << endl;

    cout << "wa_1 ";
    start2 = clock();
    cout << wa_1(x) << ": ";
    end2 = clock();
    diff1 = (double)(end2-start2)/CLOCKS_PER_SEC;
    cout << diff1 << endl;

    return 0;
}