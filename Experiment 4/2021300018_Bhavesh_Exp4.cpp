#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;
#define N 25


int m[N][N],s[N][N];

void calculateDimension(int *p,int n,int uid){
    for(int i=0;i<n;i++){
        p[i] = ceil(abs(sin(uid+i))*100);
        cout << "p[" << i << "] : " << p[i] << endl;
    }
}

void display(int i,int j){
    if(i > j)
        return;
    if(i == j){
        cout << "M" << i;
        return;
    }
    if(j-i == 1){
        cout << "(M" << i << "M" << j << ")";
        return;
    }
    int k = s[i][j];
    cout << "(";
    display(i,k);
    display(k+1,j);
    cout << ")";
    return;
}

void matrix_chain_mul(int *p,int n){
    for(int i=1;i<n;i++)
        m[i][i] = 0;
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j = i + l -1;
            m[i][j] = INT_MAX;
            for(int k=i;k<j;k++){
                int cost = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if(cost < m[i][j]){
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "S Table: "<< endl;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(i > j)
                cout << "-" << "\t";
            else if(i == j)
                cout << i << "\t";
            else
                cout << s[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }

    cout << "M Table: "<< endl;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(i > j)
                cout << "-" << "\t";
            else if(i == j)
                cout << m[i][i] << "\t";
            else
                cout << m[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }
}


int main(){
    int n;
    int uid;
    cout << "Enter UID(last 6 digits): ";
    cin >> uid;
    cout << "Enter chain lenght: ";
    cin >> n;
    int p[n];
    calculateDimension(p,n,uid);
    cout << endl;
    matrix_chain_mul(p,n);
    cout <<"Optimal parenthasition is:" << endl;
    display(1,n-1);
}



