#include "geometry.h"
#include <cmath>

// Point
Point::Point(const int X, const int Y) {
	x = X;
	y = Y;
}

//get
int Point::getX() const { return x; }
int Point::getY() const { return y; }

//set
void Point::setX(const int newX) { x = newX; }
void Point::setY(const int newY) { y = newY; }
