#include<iostream>
#include<time.h>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<numeric>
#include<chrono>

using namespace std;

void genNumbers(){
	ofstream fptr("input.txt");
	for(int i=0;i<100000;i++)
		fptr << rand() << endl;
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

void merge(int *arr,int low,int high,int mid){
	int left_size = mid-low+1;
	int right_size = high-mid;
	int *left_arr = new int[left_size];
	int *right_arr = new int[right_size];
	for(int i=0;i<left_size;i++)
		left_arr[i] = arr[low+i];
	for(int i=0;i<right_size;i++)
		right_arr[i] = arr[mid+i+1];
	int i=0,j=0;
	int k=low;	
	while(i<left_size && j<right_size){
		if(left_arr[i] < right_arr[j]){
			arr[k] = left_arr[i];
			i++;
		}else{
			arr[k] = right_arr[j];
			j++;
		}
		k++;
}
	while(i<left_size){
		arr[k] = left_arr[i];
		i++;
		k++;
}
	while(j<right_size){
		arr[k] = right_arr[j];
		j++;
		k++;
}
	delete[] left_arr;
	delete[] right_arr;
	return;
}

void mergeSort(int *arr,int low,int high){
	if(low < high){
		int mid = (low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,high,mid);
}
	return;
}

int partition(int *arr,int pivot,int low,int high){
	int i = low-1;
	int j = low;
	while(j<=high){
		if(arr[j] <= arr[pivot]){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	int temp = arr[i+1];
	arr[i+1] = arr[pivot];
	arr[pivot] = temp;
	return i+1;
}

void quickSort(int *arr,int low,int high){
	if(low < high){
		int pivot = high;
		pivot = partition(arr,pivot,low,high-1);
		quickSort(arr,low,pivot-1);
		quickSort(arr,pivot+1,high);
	}
	return;
}


void print(int *arr,int size){
	ofstream fp;
	fp.open("sorted.txt");
	for(int i=0;i<size;i++)
		fp << arr[i] << endl;
	fp.close();
}

int main(){
	int *arr = new int[100000];
	ofstream fp;
	fp.open("quickSort_time.txt");
	genNumbers();
	for(int i=1;i<=1000;i++){
		int size = (i*100) - 1;
		readInput(arr,size);
		auto start = std::chrono::high_resolution_clock::now();
		quickSort(arr,0,size);
		std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - start;
    	fp << time.count() << endl;
    	cout << time.count() << endl;
	}
	print(arr,100000);


return 0;
}
