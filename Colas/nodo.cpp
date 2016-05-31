#include "nodo.h"
#include <iostream>

template <class T>
NODO<T>::NODO(T a){
	m_Dato=a;
	Sig = NULL;
}

template class NODO<int>;
template class NODO<double>;