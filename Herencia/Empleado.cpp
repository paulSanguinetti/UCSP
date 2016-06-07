
#include "Empleado.h"
#include <iostream>

Empleado::Empleado(std::string Nombre, int Codigo, int Paga)
{	
	m_Nombre = Nombre;
	m_Codigo = Codigo;
	m_Paga = Paga;
}

Empleado::Empleado() 			// arrays...
{
	
}

Empleado::~Empleado()			// destructor
{

}

/*
void Empleado::Mostrar_datos()
{
	std::cout << " -Nombre: " << m_Nombre << std::endl;
	std::cout << " -Codigo: " << m_Codigo << std::endl;
	std::cout << " -Paga: " << m_Paga << std::endl;
}
*/