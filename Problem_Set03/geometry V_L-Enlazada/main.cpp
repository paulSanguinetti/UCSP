
#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
    int hacer=0;
    Lista L;

    Punto P1(1, 1);
    L.Push_Back(P1);
    

    Punto P2(2, 2);
    L.Push_Back(P2);
    
    Punto P3(3, 3);
    L.Push_Back(P3);

    Punto P4(77,77);
    L.Insertar(1, P4);
    
    
    L.Print1();

    L.Remove(3);

    L.Print1();

    cout << L.Size() << endl;



    return 0;
}
