#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#define CORES 4
using namespace std;

const int rand_min = 1, rand_max = 100;

void Print(int *Array, int Tam){
	for (int i = 0; i < Tam; i++)
		cout << *(Array+i) << " ";
	cout << endl;
};

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
int partition (int arr[], int low, int high){
	int pivot = arr[high];
	int i = (low - 1);
 
	for (int j = low; j <= high- 1; j++){
		if (arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high){
	if (low < high){
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main(void){
	srand(time(0));
	thread myThreads[4];
	
	int n = 15;
	n = ceil(float(n)/float(CORES))*CORES;
	int* v = new int[n];
	int* r1 = new int[n/2];
	int* r2 = new int[n/2];
	int* r3 = new int[n];
	

	for (int i = 0; i < n; ++i)
		v[i] = (rand() % (rand_max - rand_min+1))+rand_min;
	for (int i = 0; i < n; ++i)
		cout << v[i] << ' ';
	cout <<endl;

	int size_block = n/CORES;
	for(int i = 0; i < CORES; ++i)
		myThreads[i] = thread(quickSort, v ,size_block*i, (size_block*(i+1) -1 ));
	for(int i = 0; i < CORES; ++i)
		myThreads[i].join();
	//merge(v, v+(size_block), v+(size_block), v+(size_block*2), r1);
	//merge(v+(size_block*2), v+(size_block*3), v+(size_block*3), v+(size_block*4), r2);
	//merge(r1, r1+(size_block*2), r2, r2+(size_block*2), r3);

	thread merge1(merge<int*, int*, int*>, v, v+(size_block), v+(size_block), v+(size_block*2), r1);
	thread merge2(merge<int*, int*, int*>, v+(size_block*2), v+(size_block*3), v+(size_block*3), v+(size_block*4), r2);
	merge1.join();
	merge2.join();
	thread merge3(merge<int*, int*, int*>, r1, r1+(size_block*2), r2, r2+(size_block*2), r3);
	merge3.join();

	Print(r3,n);
	return 0;
};
