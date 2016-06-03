#include <iostream>
#include "node.h"
#include "stack.h"
using namespace std;

int main()
{
	STACK<int> test;
	STACK<int> test2;

	for (int i=1; i<=5; i++){
		test.Push(i);
		test2.Push(i+5);
	}
	test.Print();
	test2.Print();

	test.Last->setData(777);

	STACK<int> test3;
	test3 = test+test2;
	test3.Print();

	test.~STACK();
	test2.~STACK();
		
	return 0;
}