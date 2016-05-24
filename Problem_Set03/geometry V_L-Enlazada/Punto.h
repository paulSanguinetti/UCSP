#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

class Punto{
	private:
		int m_x, m_y;

	public:
		Punto(const int X=0, const int Y=0);
        ~Punto();

        void Print();

		int getX() const;
		int getY() const;
		void setX(const int X);
		void setY(const int Y);

};

#endif // PUNTO_H
