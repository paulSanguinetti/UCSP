#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>

class Empleado{

protected:
	
	std::string m_Nombre;
	int m_Codigo;
	int m_Paga;

public:
	
	Empleado(std::string Nombre, int Codigo, int Paga);
	Empleado();
	
	virtual void Mostrar_datos() = 0;  //pure virtual

	~Empleado();

};

#endif