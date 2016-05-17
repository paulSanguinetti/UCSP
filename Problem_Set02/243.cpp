#include <iostream>
using namespace std;
int sum(int a, int b, int c){
	return a+b+c;
}
int sum2(int a, int b, int c, int d){
	return a+b+c+d;
}
int main(){
	cout << sum(1,2,3) << endl;
}