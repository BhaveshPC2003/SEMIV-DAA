#include<iostream>

using namespace std;

int main(){
    int A[2][2],B[2][2];
    cout << "Enter 4 elements for matrix A: ";
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cin >> A[i][j];
    cout << "Enter 4 elements for matrix B: ";
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cin >> B[i][j];
    int p[7];
    p[0] = A[0][0]*(B[0][1] - B[1][1]);
    p[1] = (A[0][0] + A[0][1])*B[1][1];
    p[2] = (A[1][0] + A[1][1])*B[0][0];
    p[3] = A[1][1]*(B[1][0] - B[0][0]);
    p[4] = (A[0][0] + A[1][1])*(B[0][0] + B[1][1]);
    p[5] = (A[0][1] - A[1][1])*(B[1][0] + B[1][1]);
    p[6] = (A[0][0] - A[1][0])*(B[0][0] + B[0][1]);

    int C[2][2]; 
    C[0][0] = p[3]+p[4]-p[1]+p[5];
    C[0][1] = p[0] + p[1];
    C[1][0] = p[2] + p[3];
    C[1][1] = p[0] + p[4] - p[2] -p[6];

    cout << "Multiplication of A and B using strassen's algorithm: " << endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
}
