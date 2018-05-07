#include <iostream>
//#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int rand_min = 1, rand_max = 100;

void Print(int *Array, int Tam)
{
	for (int i = 0; i < Tam; i++)
		cout << *(Array+i) << " ";
	cout << endl;
};

void swap_ptr1(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
int partition (int* arr, int low, int high){
	int pivot = *(arr+high);
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++){
		if (*(arr+j) <= pivot){
			i++;
			swap_ptr1((arr+i), (arr+j));
		}
	}
	swap_ptr1((arr+i + 1), (arr+high));
	return (i + 1);
}
void quickSort(int* arr, int low, int high){
	if (low < high){
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main(void){
	srand(time(0));
	int n = 15;
	int* v = new int[n];

	for (int i = 0; i < n; ++i)
		*(v+i) = (rand() % (rand_max - rand_min+1))+rand_min;
	for (int i = 0; i < n; ++i)
		cout << *(v+i) << ' ';
	cout <<endl;
	
	quickSort(v ,0,  n-1);

	Print(v,n);
	return 0;
};
