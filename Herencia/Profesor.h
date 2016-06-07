
#ifndef PROFESOR_H
#define PROFESOR_H

#include "Empleado.h"
#include <iostream>

class Profesor
	: public Empleado
{
private:
	std::string m_Curso;
public:
	Profesor();
	Profesor(std::string Nombre, int Codigo, int Paga, std::string Curso);
	void Ensenar();
	void Mostrar_datos();
	~Profesor();
	
};

#endif //PROFESOR_H