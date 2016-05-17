#include <iostream>
using namespace std;
 
 int sum(int x=0, int y=0, int w=0, int z=0){
 	return x+y+w+z;
 }

 int main(){
 	cout << sum(1,2) << endl;
 }