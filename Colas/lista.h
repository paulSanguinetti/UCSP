#ifndef lista_h
#define lista_h

#include "nodo.h"

template <class T>
class LISTA{
	public:
		NODO<T> *Primero;
		NODO<T> *Ultimo;
	LISTA();
	void Push(T);
	void Pop();
	void Print();
	void Clean();

};

#endif // lista_h