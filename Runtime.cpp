#include<iostream>
#include<time.h>
#include <cstdlib>
#include<fstream>
#include<iomanip>
#include<numeric>
#include<chrono>

using namespace std;

void genInput(){
ofstream fp;
srand(time(0));
fp.open("input.txt");
for(int i=0;i<100000;i++)
    fp << rand() << endl;
fp.close();

}


void readInput(int *arr,int size){
int i = 0;
ifstream fp;
fp.open("sorted.txt");
while(i<=size){
fp >> arr[i];
i++;
}
fp.close();
}

void insertionSort(int *arr,int size){
for(int i=1;i<=size;i++){
    int key = arr[i];
    int j = i-1;
    while(j>=0 && arr[j]>key){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}
}

void SelectionSort(int *arr,int size){
for(int i=0;i<size;i++){
    int min_idx = i;
    for(int j=min_idx+1;j<size;j++)
        if(arr[min_idx] > arr[j])
            min_idx = j;
    if(min_idx != i){
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }    
}
}

void print(int *arr){
ofstream fp;
fp.open("sorted.txt");
for(int i=0;i<100000;i++)
    fp << arr[i] << endl;
fp.close();

}

int main(){
int *arr = new int[100000];
genInput();
ofstream fp;
fp.open("insertion_time.txt");
for(int i=1;i<=1000;i++){
    auto start = std::chrono::high_resolution_clock::now();
    int size = (i*100) - 1;
    readInput(arr,size);
    insertionSort(arr,size);
    std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - start;
    fp << time.count() << endl;
    cout << time.count() << endl;
}
return 0;
}
