#include <iostream>
using namespace std;

void swap(int **x , int **y){
	int *tmp = *x;
	cout <<"\n**x\t" << **x<< endl;
	cout <<"&**x\t" << &**x<< endl;
	cout <<"*x\t" << *x<< endl;
	cout <<"&*x\t" << &*x<< endl;
	cout <<"x\t" << x<< endl;
	cout <<"&x\t" << &x<< endl;
	cout << "\n"<< *tmp<< endl;
	cout << tmp<< endl;
	cout << &tmp<< endl;
	cout << &*tmp<< endl;
	*x = *y;
	*y = &*tmp;

}

int main(){
	int x = 0, y = 1;
	int *ptr1 = &x, *ptr2 = &y;
	
	cout << "&x\t" << &x << ' ' << "x\t" << x << endl; 	//print dir1 ^ dir2
	cout << "&*ptr1\t" << &*ptr1 << ' ' << "&*ptr2\t" << &*ptr2 << endl; 	//print dir1 ^ dir2
	cout << "*ptr1\t" << *ptr1 << ' ' << "*ptr2\t" << *ptr2 << endl; 	//print dir1 ^ dir2
	cout << "&ptr1\t" << &ptr1 << ' ' << "&ptr2\t" << &ptr2 << endl; 	//print dir1 ^ dir2
	
	swap(&ptr1 , &ptr2);
	/*
	cout << "\ndespués de llamar a swap: \n" << endl;
	
	cout << &*ptr1 << ' ' << &*ptr2 << endl; 	//print dir2 ^ dir 1
	*/
	cout << *ptr1 << ' ' << *ptr2 << endl; 	//print 1 0
	cout << x << ' ' << y << endl;			//print 0 1
	
}