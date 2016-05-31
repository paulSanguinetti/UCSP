#include "lista.h"

#include <iostream>
using namespace std;

template <class T>
LISTA<T>::LISTA(){
	Ultimo = Primero = NULL;
}

template <class T>
void LISTA<T>::Push(T x){
	if(!Primero){
		Primero = new NODO<T>(x);
 		Ultimo = Primero;
	}
	else{
		Ultimo->Sig = new NODO<T>(x);
		Ultimo = Ultimo->Sig;

	}
}

template <class T>
void LISTA<T>::Pop(){
	if(!Primero)
		cout << "Nada que hacer..." << endl;
	else{
		Primero = Primero->Sig;
	}
	//delete Primero;
}

template <class T>
void LISTA<T>::Clean(){
	while(Primero)
		Pop();
}

template <class T>
void LISTA<T>::Print(){ 
	NODO<T> *temp = Primero;
	while(temp!=NULL){

		cout << temp -> m_Dato << ", ";
		temp = temp->Sig;

	}

	cout << endl;
}

template class LISTA<int>;
template class LISTA<double>;