#include <iostream>
#include "stack.h"
typedef decltype(nullptr) nullptr_t; //equals to NULL (C++ 11)

//constructor
template <class T>
STACK<T>::STACK(){
	Last = First = nullptr;
}
//constructor copia
template <class T>
STACK<T>::STACK(STACK &A){
	Last = First = nullptr;
	NODE<T> *temp = First;
	
	while(temp != nullptr){
		Push(temp->getData());
		temp = temp->Next;
	}
	delete temp;
}

//SOBRECARGO DE OPERADOR + 
//finally works !!
template <class T>
STACK<T>& STACK<T>::operator + (const STACK& Stack1){
	NODE<T> *temp = Stack1.First;
	while(temp != nullptr){
		this->Push(temp->getData());
		temp = temp->Next;
	}
	delete temp;
	return *this;
}

// DESTRUCTOR
template <class T>
STACK<T>::~STACK(){
	while(!Empty())
		Pop();
}

//+++++++++++++ funciones ++++++++++++++
//PUSH 
template <class T>
void STACK<T>::Push(T x){
	if(!First){
		First = new NODE<T>(x);
 		Last = First;
	}
	else{
		Last->Next = new NODE<T>(x);
		Last = Last->Next;
	}
}

//POP
template <class T>
void STACK<T>::Pop(){
	if(!First)
		std::cout << "Nada que hacer..." << '\n';
	else{
		First = First->Next;
		// Falta destruir el nodo...
	}
	//delete First;
}

// empty stack?
template <class T>
bool STACK<T>::Empty(){	return First ? false : true; }

//return last element
template <class T>
T STACK<T>::Top(){	return Last->getData(); }

//PRINT STACK
template <class T>
void STACK<T>::Print(){ 
	NODE<T> *temp = First;
	while(temp != nullptr){
		std::cout << temp->getData() << ", ";
		temp = temp->Next;
	}
	std::cout << '\n';
	delete temp;
}

//templates ------- tipos
template class STACK<int>;
template class STACK<double>;