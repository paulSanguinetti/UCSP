#include "Profesor.h"

Profesor::Profesor(std::string Nombre, int Codigo, int Paga, std::string Curso)
	:Empleado(Nombre, Codigo, Paga)
{
	m_Curso = Curso;
}

Profesor::Profesor() : Empleado () // arrays
{
		
}

void Profesor::Ensenar()
{
	std::cout << "  Prof enseñando... " << std::endl;
}

void Profesor::Mostrar_datos()  // : Empleado()
{
	std::cout << " -Nombre: " << m_Nombre << std::endl;
	std::cout << " -Codigo: " << m_Codigo << std::endl;
	std::cout << " -Paga: " << m_Paga << std::endl;
}

Profesor::~Profesor(){

}