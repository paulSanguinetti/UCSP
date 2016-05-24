#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista
{
    public:
        Lista();
        void Push_Back(Punto &P);
        void Insertar(int Pos, Punto &P);
        int Size();
        void Remove(const int pos);
        void Print1();
        void Print2();
        virtual ~Lista();
        Nodo *Primero;
        Nodo *Ultimo;

    protected:
    private:
};

#endif // LISTA_H
