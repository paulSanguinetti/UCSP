#include "Nodo.h"


Nodo::Nodo(Punto &P)
{
    m_Punto = P;
    Siguiente=NULL;
    Anterior=NULL;
}

Nodo::~Nodo()
{
    //delete Siguiente;
    //delete Anterior;
    m_Punto.~Punto();
}
