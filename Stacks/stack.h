#ifndef STACK_H
#define STACK_H

#include "node.h"

template <class T>
class STACK{
	public:
		NODE<T> *First;
		NODE<T> *Last;
	STACK();
	STACK(STACK &A);
	~STACK();
	void Push(T);
	void Pop();
	bool Empty();
	void Print();
	T Top();
	STACK<T>& operator + (const STACK &Stack1);
	
};

#endif // STACK_H