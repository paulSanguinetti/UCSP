#include <iostream>
using namespace std;

class Point{
	private:
		int x, y;

	public:
		Point(int u, int v) : x(u), y(v) {}
		int getX() { return x; }
		int getY() { return y; }
};

int main(){
	Point p(5, 3);
	cout << p.getX() << ' ' << p.getY() << "\n";
	return 0;
}