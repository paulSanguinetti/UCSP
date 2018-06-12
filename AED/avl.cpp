#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

template <class T>
struct CLess{
	inline bool operator()(T a, T b){return a<b;};
};
template <class T>
struct CGreater{
	inline bool operator()(T a, T b){return a>b;};
};

template <class T>
struct CBinNode{
	T m_Data;
	int m_height;
	CBinNode<T> *m_nodes[2];
	CBinNode(T x){
		m_nodes[0] = m_nodes[1] = 0;
		m_Data = x;
		m_height = 0;
	};
};

template <class T, class C>
struct CBinTree{
	CBinTree(){ m_root = 0; };
	//~CBinTree();
	bool find(T x, CBinNode<T> **&p);
	bool insert(T x);
	bool remove(T x);
	void print(CBinNode<T> *p, int indent = 0);
	void foo(T x);

	CBinNode<T> *m_root;
	C m_cmp;
};
template <class T, class C>
void CBinTree<T, C>::foo(T x){
	vector<CBinNode<T>*> v;
	
	CBinNode<T> *p;
	for(p=m_root; p && p->m_Data!=x; v.push_back(p), p=p->m_nodes[m_cmp(p->m_Data, x)])
		cout << " ay! "  << endl;
	
	(v.back())->m_Data = 999;
	v.pop_back();

	//if(node->m_nodes[0])
	//return 0;
};


template <class T, class C>
bool CBinTree<T, C>::find(T x, CBinNode<T> **&p){
	for(p=&m_root; *p && (*p)->m_Data!=x; p=&((*p)->m_nodes[m_cmp((*p)->m_Data, x)]));
	return !!*p;
};
template <class T, class C>
bool CBinTree<T, C>::insert(T x){
	CBinNode<T> **p;
	if(find(x, p))
		return 0;
	*p = new CBinNode<T>(x);
	return 1;
};

template <class T, class C>
bool CBinTree<T, C>::remove(T x){
	CBinNode<T> **p, **q;
	if(!find(x, p)){
		cout << "\n No encontrado \n";
		return 0;
	}
	if((*p)->m_nodes[0]&&(*p)->m_nodes[1]){
		CBinNode<T> **q; // el mas a la derecha del hijo izquierdo
		for(q=&(*p)->m_nodes[0]; (*q)->m_nodes[1]!=0; q=&(*q)->m_nodes[1]);
		(*p)->m_Data = (*q)->m_Data;
		p = q;
	}
	CBinNode<T> *t = *p;
	*p = t->m_nodes[!!(*p)->m_nodes[0]];
	delete t;
	return 1;

};
template <class T, class C>
void CBinTree<T, C>::print(CBinNode<T> *p, int indent){
	if(!p) return;
	print(p->m_nodes[1], indent+4);
	if(indent)
		cout << setw(indent) << ' ';
	cout << "" << p->m_Data << endl;
	print(p->m_nodes[0], indent+4);
	return;
};

int main(int argc, char const *argv[])
{
	CBinTree<int, CLess<int>> test;
	
	int option, n;
	while(true){
		cout << "\n |+++++ Binary Tree ++++| " <<endl;
		cout << " |+Press (1) to Insert +| " <<endl;
		cout << " |+Press (2) to Remove +| " <<endl;
		cout << " |+Press (0) to Quit +++| " <<endl;
		cout << " |++++++++++++++++++++++| " <<endl;
		cin>>option;
		if(option==1){
			while(true){
			cout << "\n\n 0 para volver, ingrese un numero: ";
			cin >> n;
			if(n==0)
				break;
			test.insert(n);
			test.print(test.m_root);
			}
		}
		else if(option==2){
			cout << "\n\n 0 para volver, borrar el numero: ";
			cin >> n;
			test.remove(n);
			test.print(test.m_root);
		}
		else if(option==3){
			cout << "\n\n 0 para volver, encontrar camino: ";
			cin >> n;
			test.foo(n);
			//test.print(test.m_root);
		}
		else if(option==0)
			break;
	}

	return 0;
}