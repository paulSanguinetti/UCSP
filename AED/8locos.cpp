#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

static int rand_max = 52, rand_min = 1;

template <class T>
struct CLess{
	inline bool operator()(T a, T b){return a<b;};
};
template <class T>
struct CGreater{
	inline bool operator()(T a, T b){return a>b;};
};
template <class T>
struct CCards{
	inline bool operator()(T n1, T p1, T n2, T p2){ 
		//if(n1 == n2 && p1 == p2)
		//	cout << "found !!!" << endl;
		return n1 == n2 && p1 == p2;
	};
};
// +++++++++  CLASS NODE ++++++++++++++++++
template <class T>
struct CCard{
		CCard(T x, T y){ m_num = x; m_palo = y; m_Next=m_Prev=this;};
		~CCard(){};
		T m_num;
		T m_palo;
		CCard<T> *m_Next;
		CCard<T> *m_Prev;
};
// +++++++++  CLASS LINKED LIST ++++++++++++++++++
template <class T, class C>
class CLinkedList{
public:
	CLinkedList();
	//~CLinkedList();
	bool find(T x, T y, CCard<T> **&p);
	bool insert(T x, T y);
	bool remove(T x, T y);
	bool is_empty();
	void print();
	void print_reversed();
	void BuildCard();
	void Barajar();
	void rand_head();
	CCard<T> *m_Head;
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
bool CLinkedList<T, C>::find(T x, T y, CCard<T> **&p){
	for(p=&m_Head; (*p)->m_Next != m_Head && !m_cmp((*p)->m_num, (*p)->m_palo, x, y); p=&(*p)->m_Next);
	if((*p)->m_Next == m_Head && !m_cmp((*p)->m_num, (*p)->m_palo, x, y))
		p=&(*p)->m_Next;
	return m_cmp((*p)->m_num, (*p)->m_palo, x, y);
};


template <class T, class C>
bool CLinkedList<T, C>::insert(T x, T y){
	if(!m_Head){
		m_Head = new CCard<T>(x, y);
		return 1;
	}
	CCard<T> **p, *q;
	if(find(x, y, p))
		return 0;
	q = new CCard<T>(x, y);
	q->m_Prev = (*p)->m_Prev;
	q->m_Next = *p;
	if(p == &m_Head)
		(*p)->m_Prev->m_Next = q;
	(*p)->m_Prev = q;
	*p = q;
	return 1;
};

template <class T, class C>
bool CLinkedList<T, C>::remove(T x, T y){
	CCard<T> **p, *q;
	if(m_Head && find(x, y, p)){
		q = *p;
		if(m_Head->m_Next == m_Head){
			m_Head = 0;
			delete q;
			return 1;
		}
		(*p)->m_Next->m_Prev = (*p)->m_Prev;
		(*p)->m_Prev->m_Next = (*p)->m_Next;
		if(p == &m_Head)
			*p = (*p)->m_Next;
		q = 0;
		delete q;
		return 1;
	}
	return 0;
};
template <class T, class C>
void CLinkedList<T, C>::print(){
	CCard<T> *p;
	if (!m_Head){
		cout << "empty list." << endl;
		return;
	}
	int i=0;
	for(p=m_Head ; p->m_Next != m_Head; p=(p->m_Next), i++)
		cout << i+1 <<" th: " << p->m_num << " :: " <<  p->m_palo << endl;
	cout << i+1 <<" th: " << p->m_num << " :: " <<  p->m_palo << endl;
	return;
};
template <class T, class C>
void CLinkedList<T, C>::rand_head(){
	srand(time(0));
	CCard<T> **p;
	int rand_n = (rand() % (rand_max - rand_min+1))+rand_min;
	p=&m_Head;
	for (int i = 0; i < rand_n; ++i)
		p=&(*p)->m_Next;
	m_Head = *p;
	return;
};

// +++++++++++    CLASS PLAYER  ++++++++
template <class T, class C>
class Player{
public:
	Player(){ puntaje = 0;};
	//~Player();
	int puntaje;
	CLinkedList<T, C> mano;
};

// +++++++++++++++++++++++++++++++++    CLASS GAME 8 LOCOS  ++++++++++++++++++++++++++++++
template <class T, class C>
class Ocho_locos{
public:
	Ocho_locos(int n_players);
	//~Ocho_locos();
	void BuildCard();
	void Barajar(CLinkedList<T, C> &Cards);
	void print();
	void Repartir();
	bool Alzar_carta(Player<T,C> &Player);
	CLinkedList<T, C> Mazo;
	CLinkedList<T, C> descarte;
	Player<T, C>* players;
	int n_players;
};
template <class T, class C>
Ocho_locos<T, C>::Ocho_locos(int n_players){
	for (int i = 0; i < 13; ++i)
		for (int j = 0; j < 4; ++j)
			Mazo.insert(i, j);
	Barajar(Mazo);
	players = new Player<T,C>[n_players];
	//repartiendo  8  cartas a los players
	for (int i = 0; i < n_players; ++i)
		for (int j = 0; j < 8; ++j)
			Alzar_carta(players[i]);
};
template <class T, class C>
void Ocho_locos<T, C>::Barajar(CLinkedList<T, C> &Cards){
	CLinkedList<T, C> temp;
	while(!Cards.is_empty()){
		Cards.rand_head();
		temp.insert(Cards.m_Head->m_num, Cards.m_Head->m_palo);
		Cards.remove(Cards.m_Head->m_num, Cards.m_Head->m_palo);
	}
	while(!temp.is_empty()){
		Cards.insert(temp.m_Head->m_num, temp.m_Head->m_palo);
		temp.remove(temp.m_Head->m_num, temp.m_Head->m_palo);
	}
	return;
};
template <class T, class C>
bool Ocho_locos<T, C>::Alzar_carta(Player<T,C> &Player){
	if(Player.mano.insert(Mazo.m_Head->m_num, Mazo.m_Head->m_palo)){
		Mazo.remove(Mazo.m_Head->m_num, Mazo.m_Head->m_palo);
		return 1;
	}
	return 0;
};
template <class T, class C>
bool Ocho_locos<T, C>::Descartar_carta(CLinkedList<T, C> &Cards, T x, T y){
	descarte.insert(x, y);
	Cards.remove(x,y);
	return 1;
};
// +++++++++++++++++++++++++++++++++    CLASS GAME 8 LOCOS  ++++++++++++++++++++++++++++++
int main(int argc, char const *argv[]){
	CLinkedList<int, CCards<int>> test;
	test.insert(1,1);
	test.insert(1,2);
	test.insert(1,3);
	test.insert(1,4);
	test.insert(1,5);
	test.insert(1,6);
	test.insert(1,7);
	test.insert(1,8);

	Ocho_locos<int, CCards<int>> game(4);

	game.Mazo.print();
	game.players[0].mano.print();
	
	test.print();

	return 0;
};