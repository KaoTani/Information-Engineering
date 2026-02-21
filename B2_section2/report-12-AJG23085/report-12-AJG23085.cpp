/*
学籍番号: AJG23085
氏名: 谷口香央
*/

//Add if necessary
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <cmath>


using namespace std;



int main () {
    
    
    /* input data for QR decomposition */
    double input_mat[][5] = {
        {2.3, -2.1, 8.0, 5.0, -4.1},
        {2.8, 1.3, 1.0, -9.2, -1.0},
        {1.1, 2.9, 3.1, -2.1, 5.1},
        {-2.1, -6.0, -2.1, 2.0, 3.0},
        {7.0, 0.5, -2.1, 2.0, -5.0},
    };


    
    
    /* print the input_mat before calling gramSchmidt_QRdecomposition */
    std::cout << "input_mat = " << std::endl;
    // write here...
    cout << showpoint;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << setprecision(4) << setw(6) << input_mat[i][j] << " ";
        }
        cout << endl;
    }

    std::cout << std::endl;



    // Gram-Schmidt & QR decomposition
    // write here...
    double Q[5][5], R[5][5], QR[5][5], ans[5][5];
    double a_e;
    double Q_size=0;
    for(int j=0; j<5; j++){
        Q_size=0;
        for(int i=0; i<5; i++){
            Q[i][j] = input_mat[i][j];
        }
        for(int k=0; k<j; k++){
            a_e=0;
            for(int i=0; i<5; i++){
                a_e += input_mat[i][j] * Q[i][k];
            }
            for(int i=0; i<5; i++){
                Q[i][j] -= a_e * Q[i][k];
            }
        }
        for(int i=0; i<5; i++){
                Q_size += Q[i][j] * Q[i][j];
        }
        Q_size = sqrt(Q_size);
        for(int i=0; i<5; i++){
            Q[i][j] = Q[i][j] / Q_size;
        }
    }

    for(int j=0; j<5; j++){
        for(int i=0; i<5; i++){
            R[i][j]=0;
        }
        for(int k=0; k<=j; k++){
            for(int i=0; i<5; i++){
                R[k][j] += input_mat[i][j] * Q[i][k];
            }
        }
    }

    for(int j=0; j<5; j++){
        for(int i=0; i<5; i++){
            QR[i][j]=0;
        }
        for(int i=0; i<5; i++){
            for(int k=0; k<5; k++){
                QR[i][j] += Q[i][k] * R[k][j];     
            }
        }
    }
        
    for(int j=0; j<5; j++){
        for(int i=0; i<5; i++){
            ans[i][j] = input_mat[i][j] - QR[i][j];
            if(ans[i][j]<0.0005){
                ans[i][j] = 0;
            }
        }
    }


    
    
    /* print the matrix Q resulting from gramSchmidt_QRdecomposition */
    std::cout << "Q = " << std::endl;
    // write here...
    cout << showpoint;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << fixed << setprecision(3) << setw(6) << Q[i][j] << " ";
        }
        cout << endl;
    }

    std::cout << std::endl;





    /* print the matrix R resulting from gramSchmidt_QRdecomposition */
    std::cout << "R = " << std::endl;
    // write here...
    cout << showpoint;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << fixed << setprecision(3) << setw(6) << R[i][j] << " ";
        }
        cout << endl;
    }

    std::cout << std::endl;



    
    /* print the matrix Q * R */
    std::cout << "Q * R = ?" << std::endl;
    // write here...
    cout << showpoint;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << fixed << setprecision(3) << setw(6) << QR[i][j] << " ";
        }
        cout << endl;
    }

    std::cout << std::endl;




    
    /* print Input_mat - (Q * R) */
    std::cout << "Input_mat - (Q * R) = ?" << std::endl;
    // write here...
    cout << showpoint;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << fixed << setprecision(3) << setw(6) << ans[i][j] << " ";
        }
        cout << endl;
    }

    std::cout << std::endl;    

    


    return 0;
}