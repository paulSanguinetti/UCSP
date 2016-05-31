#ifndef nodo_h
#define nodo_h

#include "nodo.h"
#include <iostream>

template <class T>
class NODO{
	public:
		T m_Dato; 	//miembro dato
		NODO<T>* Sig; 		//puntero que apunta al siguiente
		NODO(T);

};

#endif // nodo_h