#ifndef NODO_H
#define NODO_H

#include <iostream>
#include "Punto.h"

class Nodo
{
    public:
        Punto m_Punto;
        Nodo *Siguiente;
        Nodo *Anterior;
        Nodo(Punto &P);
        virtual ~Nodo();
    protected:
    private:
};

#endif // NODO_H
