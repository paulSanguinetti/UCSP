#include <iostream>
using namespace std;

class Point{
	private:
		int x, y;
	public:
		Point(int u, int v) : x(u), y(v) {}
		int getX() { return x; }
		void setX( int newX ){ x = newX; };
};

//void setX(int newX){ x = newX ; }

int main(){
	Point p(5, 3);
	p.setX(0);
	cout << p.getX() << " " << "\n";
	return 0;
}