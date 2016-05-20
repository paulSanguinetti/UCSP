#include <iostream>
#include "geometry.h"
using namespace std;

int main(){
	
	Point p(5, 3);
	p.setX(7);
	p.setY(10);
	cout << p.getX() << " " << p.getY() << "\n";
	return 0;

}
