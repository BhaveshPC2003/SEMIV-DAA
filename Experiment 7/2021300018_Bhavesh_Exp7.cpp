#include<iostream>

using namespace std;

void display(int *x,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x[i] == j)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
    cout << "---------------------------------------" << endl;
}

bool place(int *x,int k,int i){
    for(int j=0;j<k;j++){
        if(x[j] == i || abs(x[j]-i) == abs(k-j))
            return false;
    }
    return true;
}

void n_queens(int *x,int k,int n){
    if(k == n){
        display(x,n);
        return;
    }
    for(int i=0;i<n;i++){
        if(place(x,k,i)){
           x[k] = i;
           n_queens(x,k+1,n);
        }
    }
    return;
}

int main(){
    int n;
    cout << "Enter the board size: ";
    cin >> n;
    int *x = new int[n];
    n_queens(x,0,n);
}