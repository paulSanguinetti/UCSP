#include <iostream>
using namespace std;

template <class T>
struct CLess{
	inline bool operator()(T a, T b){return a<b;};
};
template <class T>
struct CGreater{
	inline bool operator()(T a, T b){return a>b;};
};
// +++++++++  CLASS NODE ++++++++++++++++++
template <class T>
struct CNode{
		CNode(T x){ m_Data = x; m_Next=m_Prev=this;};
		~CNode(){};
		T m_Data;
		CNode<T> *m_Next;
		CNode<T> *m_Prev;
};
// +++++++++  CLASS LINKED LIST ++++++++++++++++++
template <class T, class C>
struct CLinkedList{
	CLinkedList();
	//~CLinkedList();
	bool find(T x, CNode<T> *&p);
	bool insert(T x);
	bool remove(T x);
	bool is_empty();
	void print();

	CNode<T> *m_Head;
	CNode<T> *m_Tail;
	C m_cmp;
};

template <class T, class C>
CLinkedList<T, C>::CLinkedList(){
	m_Head = 0;
};
template <class T, class C>
bool CLinkedList<T, C>::is_empty(){
	return !m_Head ? 1: 0;
};

template <class T, class C>
bool CLinkedList<T, C>::find(T x, CNode<T> *&p){
	int lim=0;
	for(p=m_Head; p->m_Next!=m_Head && m_cmp(p->m_Next->m_Data, x) && lim < 7; p=p->m_Next, lim++)
	//cout << " good : " << p <<endl;
		;
	return !!p && p->m_Data==x;
};

template <class T, class C>
bool CLinkedList<T, C>::insert(T x){
	CNode<T> *p, *t;
	if(is_empty()){
		m_Head = m_Tail = new CNode<T>(x);
		return 1;
	}else if(m_cmp(x,m_Head->m_Data)){
		m_Head = new CNode<T>(x);
		m_Head->m_Next = m_Tail;
		m_Head->m_Prev = m_Tail;
		m_Tail->m_Prev = m_Head;
		m_Tail->m_Next = m_Head;
		return 1;
	}
	if(find(x, p)){
		return 0;
	}if (p == m_Tail){
		t = new CNode<T>(x);
		t->m_Next = p->m_Next;
		t->m_Prev = p;
		p->m_Next->m_Prev = t;
		p->m_Next = t;
		m_Tail = t;
	}
	t = new CNode<T>(x);
	t->m_Next = p->m_Next;
	t->m_Prev = p;
	p->m_Next = t;
	p->m_Next->m_Prev = t;
	return 1;
};

template <class T, class C>
bool CLinkedList<T, C>::remove(T x){
	CNode<T> **p;
	if(!find(x, p))
		return 0;
	*p = (*p)->m_Next;
	return 1;
};

template <class T, class C>
void CLinkedList<T, C>::print(){
	CNode<T> *p, *q;
	q=m_Head;
	int i=0;
	for(p=m_Head ; i<5; p=(p->m_Prev), i++)
		cout << i+1 <<"   th: " << p << "  dir " <<  p->m_Data << endl;
	if(!i)
		cout << "empty list." << endl;
	return;
};


int main(int argc, char const *argv[])
{
	CLinkedList<int, CLess<int>> testL;
	testL.insert(3);
	
	testL.insert(1);
	testL.insert(8);
	testL.insert(9);
	//testL.insert(10);
	//testL.insert(9);
	//testL.insert(8);
//	testL.insert(6);
	//testL.insert(5);
	//testL.insert(8);
	//testL.remove(5);
	//testL.remove(10);
	testL.print();
	return 0;
};