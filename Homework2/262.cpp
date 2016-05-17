#include <iostream>
#include <string>
using namespace std;

void reverse(int len, int A[]){
	int temp = 0, last =0;

	for(int i=0; i < len/2; i++){
		temp = A[i];
		last = len-i-1;
		A[i] = A[last];
		A[last] = temp;
	}

}


int main(int argc, char const *argv[])
{
	int A[10];
	int len = 10;
	for(int i = 0; i < len; i++)
		A[i]=i+1;

	reverse(len, A);

	for(int i = 0; i < len; i++)
		cout << A[i] << ", ";
	cout << endl;


	return 0;
}