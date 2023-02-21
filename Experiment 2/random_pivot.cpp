#include<iostream>
#include<time.h>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<numeric>
#include<chrono>

using namespace std;

int swaps = 0;

void genNumbers(){
	ofstream fptr("input.txt");
	for(int i=0;i<100000;i++)
		fptr << rand()%100000 << endl;
	fptr.close();
}

void readInput(int *arr,int size){
	ifstream fptr("input.txt");
	int i = 0;
	while(i<=size){
		fptr >> arr[i];
		i++;
}
	fptr.close();
}

void print(int *arr,int size){
	ofstream fp;
	fp.open("sorted.txt");
	for(int i=0;i<size;i++)
		fp << arr[i] << endl;
	fp.close();
}

void swap(int *arr,int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr,int low,int high){
    int i = low-1;
    int j = low;
    int pivot = arr[high];

    for(;j<high;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr,j,i);
			swaps++;
        }
    }
    i++;
    swap(arr,i,high);
    return i;
}

int partition_r(int *arr,int low,int high){
    int r = low + rand() % (high - low);
    swap(arr,high,r);

    return partition(arr,low,high);
}


void quickSort(int *arr,int low,int high){
	if(low < high){
		int pivot = partition_r(arr,low,high);
		quickSort(arr,low,pivot-1);
		quickSort(arr,pivot+1,high);
	}
	return;
}



int main(){
	int *arr = new int[100000];
	ofstream fp,fp2;
	fp.open("quickSort_time_random_pivot.txt");
	fp2.open("quickSort_random_count.txt");
	genNumbers();
	for(int i=1;i<=1000;i++){
		swaps = 0;
		int size = (i*100) - 1;
		readInput(arr,size);
		auto start = std::chrono::high_resolution_clock::now();
		quickSort(arr,0,size);
		std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - start;
		fp2 << swaps << endl;
    	fp << time.count() << endl;
    	cout << time.count() << endl;
	}
	print(arr,100000);


return 0;
}