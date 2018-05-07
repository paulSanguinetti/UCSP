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
		CNode(T x){ m_Data = x; m_Next=0; };
		~CNode();
		T m_Data;
		CNode<T> *m_Next;
};
// +++++++++  CLASS LINKED LIST ++++++++++++++++++
template <class T, class C>
struct CLinkedList{
	CLinkedList();
	//~CLinkedList();
	bool find(T x, CNode<T> **&p);
	bool insert(T x);
	bool remove(T x);
	void print();

	CNode<T> *m_Head;
	C m_cmp;
};

template <class T, class C>
CLinkedList<T, C>::CLinkedList(){
	m_Head = 0;
};

template <class T, class C>
bool CLinkedList<T, C>::find(T x, CNode<T> **&p){
	for(p=&m_Head; *p && m_cmp((*p)->m_Data, x); p=&((*p)->m_Next));
	return *p && (*p)->m_Data==x ;
};

template <class T, class C>
bool CLinkedList<T, C>::insert(T x){
	CNode<T> **p;
	if(find(x, p))
		return 0;	
	CNode<T> *q = new CNode<T>(x);
	q->m_Next = *p;
	(*p) = q;
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
	CNode<T> *p;
	int i=0;
	for(p=m_Head; !!p; p=(p->m_Next), i++)
		cout << "  * "<<i+1 <<" th: " << p->m_Data << endl;
	if(!i)
		cout << "empty list." << endl;
	return;
};


int main(int argc, char const *argv[])
{
	CLinkedList<int, CLess<int>> test;
	int option, n;
	while(true){
		cout << " |+++++ Binary Tree ++++| " <<endl;
		cout << " |+Press (1) to Insert +| " <<endl;
		cout << " |+Press (2) to Remove +| " <<endl;
		cout << " |+Press (0) to Quit +++| " <<endl;
		cout << " |++++++++++++++++++++++| " <<endl;
		cin>>option;
		if(option==1){
			while(true){
			cout << "\n\n 0 para volver, ingrese un numero: " <<endl;
			cin >> n;
			if(n==0)
				break;
			test.insert(n);
			test.print();
			}
		}
		else if(option==2){
			cout << "\n\n 0 para volver, borrar el numero: " <<endl;
			cin >> n;
			test.remove(n);
			test.print();
		}
		else if(option==0)
			break;
	}

	return 0;
};