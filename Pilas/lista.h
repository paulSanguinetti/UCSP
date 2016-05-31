#ifndef lista_h
#define lista_h

#include "nodo.h"

template <class T>
class LISTA{
	public:
		NODO<T> *Primero;
		NODO<T> *Segundo;
	LISTA();
	void Push(T);
	void Pop();

	void Print();
	void Print2();
	void Reverse();
};

#endif // lista_h