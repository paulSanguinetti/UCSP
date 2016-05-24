#include "Punto.h"

Punto::Punto(const int X, const int Y) {
	m_x = X;
	m_y = Y;
}

Punto::~Punto()
{
    /*
    m_x = NULL;
    m_y = NULL;
    */
}

void Punto::Print()
{
    std::cout << " (" << m_x << ";" << m_y << ")" << std::endl;
}

// get
int Punto::getX() const { return m_x; }
int Punto::getY() const { return m_y; }

// set
void Punto::setX(const int newX) { m_x = newX; }
void Punto::setY(const int newY) { m_y = newY; }
