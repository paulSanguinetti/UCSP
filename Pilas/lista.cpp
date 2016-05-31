#include "lista.h"
#include <iostream>
using namespace std;

template <class T>
LISTA<T>::LISTA(){
	Primero = Segundo = NULL;
}

template <class T>
void LISTA<T>::Push(T x){
	
	LISTA();
	Segundo = Primero;
	Primero = new NODO<T>(x);
	Primero->Sig = Segundo;
}

template <class T>
void LISTA<T>::Pop(){
	if(!Primero){
		std::cout << "nada que hacer..."<< "\n";
	}	
	else{
		Primero = Primero->Sig;
	}
}

template <class T>
void LISTA<T>::Print(){
	NODO<T> *temp = Primero;
	while(temp!=NULL){

		cout << temp->m_Dato << ", ";
		temp = temp->Sig;

	}

	cout << endl;
}

template class LISTA<int>;
template class LISTA<double>;