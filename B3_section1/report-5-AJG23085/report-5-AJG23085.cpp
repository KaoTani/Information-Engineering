//
//  hopfield_sample_modified1.cpp
//
//  Created by Naoki Masuyama on 2020/05/08.
//  Copyright © 2020 Naoki Masuyama. All rights reserved.
//




//////////////////////////////////////////////////////

// 学籍番号：AJG23085
// 氏名：谷口 香央

//////////////////////////////////////////////////////




#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

using namespace std;

#define N 5     // Number of Data
#define dim 64  // Dimensions of Data

// Train Data
int X[][dim+1]={
    {-1,-1, 1, 1, 1,-1,-1,-1,-1, 1, 1, 1, 1, 1,-1,-1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1, 1, 1, 1, 1, 1,-1, 1, 1, 1, 1, 1, 1, 1,-1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1,-1,-1,-1, 1, 1,-1},  // A
    { 1, 1, 1, 1, 1, 1,-1,-1,-1, 1, 1,-1,-1, 1, 1, 1,-1, 1, 1,-1,-1, 1, 1, 1,-1, 1, 1, 1, 1, 1, 1,-1,-1, 1, 1, 1, 1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1, 1,-1, 1, 1,-1,-1, 1, 1, 1, 1, 1, 1, 1, 1, 1,-1,-1},  // B
    {-1,-1, 1, 1, 1, 1,-1,-1,-1, 1, 1, 1, 1, 1, 1,-1, 1, 1, 1,-1,-1,-1, 1, 1, 1, 1,-1,-1,-1,-1,-1,-1, 1, 1,-1,-1,-1,-1,-1,-1, 1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1, 1, 1, 1, 1,-1,-1,-1, 1, 1, 1, 1,-1,-1},  // C
    { 1, 1, 1, 1, 1,-1,-1,-1,-1, 1, 1, 1, 1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1, 1, 1, 1, 1,-1, 1, 1, 1, 1, 1,-1,-1,-1},  // D
    { 1, 1, 1, 1, 1, 1, 1, 1,-1, 1, 1,-1,-1,-1,-1, 1,-1, 1, 1,-1,-1, 1,-1,-1,-1, 1, 1, 1, 1, 1,-1,-1,-1, 1, 1, 1, 1, 1,-1,-1,-1, 1, 1,-1,-1, 1,-1,-1,-1, 1, 1,-1,-1,-1,-1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  // E
};

// Test Data (These are Train Data with noise.)
int noiseX[][dim+1]={
    { 1,-1, 1, -1, 1,-1,-1,-1,-1, 1,-1, 1, 1, 1,-1,-1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1, 1,-1,-1, 1, 1,-1, 1,-1, 1,-1, 1, 1, 1,-1, 1, 1, 1, 1,-1, 1, 1,-1, 1, 1,-1,-1,-1, 1, 1,-1,-1, 1,-1,-1,-1,-1, 1,-1}, // A with noise
    { 1, 1, 1, 1, 1, 1,-1,-1,-1, 1, 1, 1,-1, 1, 1, 1,-1, 1,-1,-1,-1, 1, 1, 1,-1, 1, 1, 1,-1, 1, 1,-1,-1, 1, 1, 1, 1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1, 1, 1, 1, 1, 1, 1, 1,-1, 1, 1,-1,-1},  // B with noise
    {-1,-1, 1, 1, 1, 1,-1,-1,-1,-1, 1, 1, 1, 1, 1, 1, 1, 1, 1,-1, 1,-1, 1, 1, 1, 1,-1,-1,-1,-1,-1,-1, 1, 1,-1,-1,-1,-1,-1,-1, 1,-1, 1,-1,-1,-1, 1, 1,-1, 1,-1, 1, 1,-1, 1,-1,-1,-1, 1, 1, 1, 1,-1,-1},  // C with noise
    { 1, 1, 1, 1, 1, 1,-1,-1,-1, 1,-1, 1, 1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1, 1, 1,-1,-1,-1,-1, 1,-1,-1, 1, 1, 1,-1,-1, 1, 1, 1, 1, 1,-1,-1,-1, 1,-1,-1, 1, 1,-1, 1, 1, 1,-1, 1, 1, 1, 1, 1,-1,-1,-1},  // D with noise
    { 1, 1,-1, 1,-1,-1, 1, 1,-1, 1, 1,-1, 1,-1,-1, 1,-1,-1, 1,-1,-1, 1, 1,-1,-1, 1, 1, 1,-1, 1,-1,-1,-1,-1, 1, 1,-1, 1,-1,-1,-1, 1, 1, 1,-1, 1,-1,-1,-1, 1, 1,-1, 1,-1,-1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  // E with noise
};


// Show Results by ■ and □
void drawResult(double ary[]){
    int cnt=0;
    for(int i=0;i<dim;i++){
        if(ary[i]>=0.0){
            printf("■");
        }
        else{
            printf("□");
        }
        cnt++;
        if(cnt==8){
            cout<<endl;
            cnt=0;
        }
    }
    cout<<endl;
}




int main(int argc, const char * argv[])
{

    double W_xx[dim+1][dim+1]={{0.0}}; // Weight Matrix
    double X_in[dim+1]={0.0};        // Input Data
    double X_out[dim+1]={0.0};       // Associated Result

    size_t rows = sizeof(W_xx) / sizeof(W_xx[0]);
    size_t cols = sizeof(W_xx[0]) / sizeof(W_xx[0][0]);
    cout << "W_xx size: " << rows << "x" << cols << endl;

    // =====================================================================================================
    cout<<"=================="<<endl;
    cout<<"    Exercise 1"<<endl;
    cout<<"=================="<<endl;
    // Calculate a weight matrix W_xx using all the train data, and get an associated data using the weight matrix W_xx.
    // =====================================================================================================

    // ==========================================
    // Learning Phase
    // ==========================================
    // Write a weight matrix W_xx calculation here...
    // W_xx =

    for(int i=0; i<N; i++){
        for(int j=0; j<dim; j++){
            for(int k=0; k<dim; k++){
                W_xx[k][j] += X[i][j] * X[i][k];
            }
        }
    }
    for(int j=0; j<dim; j++){
        for(int k=0; k<dim; k++){
            W_xx[k][j] = W_xx[k][j] / (double)N;
            if(k==j){
                W_xx[k][j] = W_xx[k][j] - 1.0;
            }
        }
    }


    // ==========================================
    // Association Phase
    // ==========================================
    // Now, you have a trained weight W_xx that can associate A, B, C, D, and E.
    // From the following, "A" is considered.
    cout<<"Associate 'A':"<<endl;
    // Set input data
    for (int i=0;i<dim;i++){
        X_in[i] = (double)noiseX[0][i]; // noiseX[0][i]: A, noiseX[1][i]: B, noiseX[2][i]: C, noiseX[3][i]: D, noiseX[4][i]: E
    }
    cout<<"X_in (A with noise): "<<endl;
    drawResult(X_in);
    // You may see this result.
    // ■□■□■□□□
    // □■□■■■□□
    // ■■□□□■■□
    // ■■■□□■■□
    // ■□■□■■■□
    // ■■■■□■■□
    // ■■□□□■■□
    // □■□□□□■□

    // Write Association Process (W_xx * X_in) here...
    // internal_state = W_xx * X_in, then X_out = \phi(internal_state)

    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            X_out[i] += W_xx[i][j] * X_in[j]; 
        }
        if(X_out[i]<0){
            X_out[i] = -1.0;
        }else{
            X_out[i] = 1.0;
        }
    }






    // Show Results by ■ and □
    cout<<"Associated Result X_out (A without noise): "<<endl;
    drawResult(X_out);
    // If association is succeed, you get the following result (A).
    // □□■■■□□□
    // □■■■■■□□
    // ■■□□□■■□
    // ■■□□□■■□
    // ■■■■■■■□
    // ■■■■■■■□
    // ■■□□□■■□
    // ■■□□□■■□



    // ======================================================================================================
    cout<<"=================="<<endl;
    cout<<"    Exercise 2"<<endl;
    cout<<"=================="<<endl;
    // Associate a correct "E" from data with high noise using the weight matrix W_xx calculated in Exercise 1.
    // ======================================================================================================


    // Test Data (E with high noise)
    int High_noiseX[dim+1]={
         1, 1, 1, 1, 1, 1, 1, 1,-1,-1, 1,-1,-1,-1,-1, 1,-1, 1, 1,-1, 1, 1,-1,-1,-1, 1, 1, 1,-1,-1,-1,-1, 1, 1,-1,-1, 1, 1, 1,-1,-1,-1,-1, 1, 1,-1, 1,-1, 1,-1, 1, 1, 1,-1, 1, 1,-1,-1, 1, 1, 1,-1,-1,-1  // E with high noise
    };

    // Set input data
    for (int i=0;i<dim;i++){
        X_in[i] = (double)High_noiseX[i];
    }

    cout<<"X_in (E with high noise): "<<endl;
    drawResult(X_in);
    // You may see this result.
    // ■■■■■■■■
    // □□■□□□□■
    // □■■□■■□□
    // □■■■□□□□
    // ■■□□■■■□
    // □□□■■□■□
    // ■□■■■□■■
    // □□■■■□□□


    // Write Association Process here...
    // internal_state = W_xx * X_in, then X_out = \phi(internal_state)
    // If you conduct an association process once, you may get an incorrect "E".
    // How to associate a correct "E"?
    // Note that X_in is used as the initial internal_state. Do not use X_out of Exercise 1 directly.
    // Association processes in Exercise 2 should be written by using for-loop, efficiently.
    // Do not write as:
    // for(
    //   // 1st association process 
    // )
    // for(
    //   // 2nd association process 
    // )
    // ...
    // Write as:
    // for( // Loop for association process
    //     for(
    //      // association process
    //     )
    // )
    // Do not initialize an internal_state after an association process.
    // Recall E by updating the internal_state continually.


    double X_old_out[dim+1]={0.0};
    double X_new_out[dim+1]={0.0};
    int a=0;
    for(int i=0; i<dim; i++){
        X_old_out[i] = X_in[i];
    }
    while(a<dim){
        for(int i=0; i<dim; i++){
            for(int j=0; j<dim; j++){
                X_new_out[i] += W_xx[i][j] * X_old_out[j]; 
            }
            if(X_new_out[i]<0){
                X_new_out[i] = -1.0;
            }else{
                X_new_out[i] = 1.0;
            }
            if(X_old_out[i]==X_new_out[i]){
                a++;
            }
        }
        if(a<dim){
            a = 0;
            drawResult(X_new_out);
        }
        if(a==0){
            for(int i=0; i<dim; i++){
                X_old_out[i] = X_new_out[i];
                X_new_out[i] = 0;
           }
        }  
    }
    for(int i=0; i<dim; i++){
        X_out[i] = X_new_out[i];
    }



    // Show Results by ■ and □
    cout<<"Associated Result X_out (E without noise): "<<endl;
    drawResult(X_out);
    // If association is succeed, you get the following result (E).
    // ■■■■■■■■
    // □■■□□□□■
    // □■■□□■□□
    // □■■■■■□□
    // □■■■■■□□
    // □■■□□■□□
    // □■■□□□□■
    // ■■■■■■■■

}
