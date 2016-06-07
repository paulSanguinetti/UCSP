#include <iostream>
#include "Empleado.h"
#include "Profesor.h"
using namespace std;
int main()
{

	Profesor x("x", 1, 1, "mate");
	
	x.Mostrar_datos();

	x.Ensenar();

	int A[10]={1,2,3,4,5,6,7,8,9};

	// necesita tipo
	//A.ordenar.metodo1();

	cout << endl << endl;
	Profesor profs[10];

	profs[0]=x;
	profs[0].Mostrar_datos();
	
	return 0;
}