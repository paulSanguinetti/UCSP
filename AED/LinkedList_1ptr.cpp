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
	bool find(T x, CNode<T> *&p);
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
bool CLinkedList<T, C>::find(T x, CNode<T> *&p){
	for(p=m_Head; p->m_Next && m_cmp(p->m_Next->m_Data, x); p=p->m_Next);
	return p && p->m_Next && p->m_Next->m_Data==x ;
};

template <class T, class C>
bool CLinkedList<T, C>::insert(T x){
	CNode<T> *p, *q;
	if(!m_Head){
		m_Head = new CNode<T>(x);
		return 1;
	}else if(m_Head->m_Data == x){
		return 0;
	}else if(m_cmp(x,m_Head->m_Data)){
		CNode<T> *t = new CNode<T>(x);
		t->m_Next = m_Head;
		m_Head = t;
		return 1;
	}
	if(find(x, p)){
		return 0;	
	}
	q = new CNode<T>(x);
	q->m_Next = p->m_Next;
	p->m_Next = q;
	return 1;
};

template <class T, class C>
bool CLinkedList<T, C>::remove(T x){
	CNode<T> *p;
	if(m_Head && m_Head->m_Data  == x){ // si el buscado es el primero y existe mas de un nodo
		m_Head = m_Head->m_Next;
		return 1;
	}else if(m_Head && !m_Head->m_Next){ //si el buscado es el primero y es el unico nodo
		m_Head = 0;
		return 1;
	}else if(!find(x, p)){
		return 0;
	}
	p->m_Next = p->m_Next->m_Next;
	return 1;
};


template <class T, class C>
void CLinkedList<T, C>::print(){
	CNode<T> *p;
	int i=0;
	for(p=m_Head; !!p; p=(p->m_Next), i++)
		cout << "  * "<<i+1 <<" th: " << p->m_Data << endl;
	cout << endl;
	if(!i)
		cout << "empty list.\n" << endl;
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
		cout << "  * option: " ;
		cin>>option;
		if(option==1){
			while(true){
			cout << "\n 0 para volver, ingrese un numero: " ;
			cin >> n;
			if(n==0)
				break;
			test.insert(n);
			test.print();
			}
		}
		else if(option==2){
			cout << "\n 0 para volver, BORRAR el numero: ";
			cin >> n;
			test.remove(n);
			test.print();
		}
		else if(option==0)
			break;
	}

	return 0;
};