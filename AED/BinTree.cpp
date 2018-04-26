#include <iostream>
using namespace std;

template <class T>
struct CLess{
	inline bool operator()(T a, T b){return a<b;};
};
struct CGreater{
	inline bool operator()(T a, T b){return a>b;};
};


template <class T>
struct CBinNode{
	T m_data;
	CBinNode<T> *m_nodes[2];
	CBinNode(T x){
		m_nodes[0] = m_nodes[1] = 0;
		m_data = x;
	};
};

template <class T, class C>
struct CBinTree{
	CBinTree();
	~CBinTree();
	bool find(T x, CBinNode<T> **&p);
	bool insert(T x);
	bool remove(T x);

	CBinNode<T> *m_root;
	C m_cmp;
};

template <class T, class C>
CBinTree<T, C>::CBinTree(){
	a
};

template <class T, class C>
bool CBinTree<T, C>::find(T x, CBinNode<T> **&p){
	for(p=&m_root; *p && (*p)->m_data!=x; p=&((*p)->m_nodes[m_cmp(x, (*p)->m_data)]));
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
bool CBinTree<T, C>::rightest(CBinNode<T> **&q){
	for(p=&m_root; *p && (*p)->m_data!=x; p=&((*p)->m_nodes[m_cmp(x, (*p)->m_data)]));
	return !!*p;
};

template <class T, class C>
bool CBinTree<T, C>::remove(T x){
	CBinNode<T> **p;
	if(!find(x, p)) return 0;
	if((*p)->m_nodes[0]&&(*p)->m_nodes[1]){
		CBinNode<T> **q = rightest(p); // moving the pointer to most lef from the right
		(*p)->m_data = (*q)->m_data;
		p = q;
	}
	CBinNode<T> *t = *p;
	*p = (*t)->m_nodes[!!(*p)->m_nodes[0]];
	delete t;
	return 1;

};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
