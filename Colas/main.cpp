#include <iostream>
#include "nodo.h"
#include "lista.h"

using namespace std;

int main()
{
	LISTA<int> test;

	for (int i=1; i<=10; i++)
		test.Push(i);
	test.Print();
	test.Pop();
	test.Pop();
	test.Pop();
	test.Print();
	test.Clean();
	test.Print();

	
	return 0;
}