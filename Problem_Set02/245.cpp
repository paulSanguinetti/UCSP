#include <iostream>
using namespace std;
int sum2(int n, int* p){
	int r=0;
	while((n--)>0){
		r += *(p++);
	}
	return r;
}

int sum(const int i, const int p[]){
	if(i==0)
		return 0;
	return p[0] + sum(i-1, p + 1);
}
int main()
{
	int lista[6]={1,2,3,4,5,6};
	cout << sum2(6, lista) << endl;

	return 0;
}