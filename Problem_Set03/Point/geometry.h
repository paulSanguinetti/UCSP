#ifndef GEOMETRY_H
#define GEOMETRY_H

class Point{
	private:
		int x, y;

	public:
		Point(const int X=0, const int Y=0);
		int getX() const;
		int getY() const;
		void setX(const int X);
		void setY(const int Y);
};

#endif  // GEOMETRY_H
