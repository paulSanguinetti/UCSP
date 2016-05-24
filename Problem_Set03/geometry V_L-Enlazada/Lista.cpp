#include "Lista.h"

using namespace std;

Lista::Lista()
{
    Primero = Ultimo = NULL;
}

void Lista::Push_Back(Punto &P)
{
    if (!Primero)
    {
        Primero = new Nodo(P);
        Ultimo = Primero;
    }

    else
    {
        Ultimo->Siguiente = new Nodo(P);
        Ultimo->Siguiente->Anterior = Ultimo;
        Ultimo = Ultimo->Siguiente;
    }
}

void Lista::Insertar(int Pos, Punto &P)
{
    if (Pos == 1)
    {
        if (Primero == NULL)
        {
            Push_Back(P);
            return;
        }
        Primero->Anterior=new Nodo(P);
        Primero->Anterior->Siguiente = Primero;
        Primero = Primero->Anterior;
    }

    else if (Pos == Size()+1)
    {
        Ultimo->Siguiente = new Nodo(P);
        Ultimo->Siguiente->Anterior = Ultimo;
        Ultimo = Ultimo->Siguiente;
    }

    else
    {
        Nodo *tem1 = Primero;
        for (int i=0; i<Pos-1; i++)
            tem1=tem1->Siguiente;

        tem1->Anterior->Siguiente = new Nodo(P);
        tem1->Anterior->Siguiente->Siguiente = tem1;
        tem1->Anterior->Siguiente->Anterior = tem1->Anterior;
        tem1->Anterior = tem1->Anterior->Siguiente;
    }
}

int Lista::Size()
{
    Nodo *tem = Primero;
    int Size=0;
    while (tem != NULL)
    {
        Size++;
        tem=tem->Siguiente;
    }
    return Size;
}

void Lista::Remove(const int pos)
{
    Nodo *tem = Primero;
    for (int i=1; i<pos; i++)
        tem = tem->Siguiente;
    tem->Anterior->Siguiente = tem->Siguiente;
    tem->Siguiente->Anterior = tem->Anterior;
    tem->m_Punto.Print();
}

void Lista::Print1()
{
    Nodo *x = Primero;
    if(!Primero)
    {
        cout << " Esta vacia" << endl;
    }

    else
    {
        while(x != Ultimo->Siguiente)
        {
            cout << "   ->";
            x->m_Punto.Print();
            x=x->Siguiente;
        }
    }
}

void Lista::Print2()
{
    Nodo *x = Ultimo;
    if(!Ultimo)
    {
        cout << " Esta vacia" << endl;
    }

    else
    {
        while(x != Primero->Anterior)
        {
            cout << "   ->";
            x->m_Punto.Print();
            x=x->Anterior;
        }
    }
}

Lista::~Lista()
{
    //
}




