#include "node.h"
typedef decltype(nullptr) nullptr_t; //equals to NULL (C++ 11)

template <class T>
NODE<T>::NODE(T data){
	m_Data = data;
	Next = nullptr;
}
template <class T>
NODE<T>::~NODE(){
	delete Next;
}

//++++++ Functions ++++++++
//GET
template <class T>
T NODE<T>::getData(){ return m_Data; }

//SET
template <class T>
void NODE<T>::setData(T newData){
	m_Data = newData;
}


template class NODE<int>;
template class NODE<double>;