#pragma once
#include "Point.hpp"
class Rectangle
{
private:
	Point diagonalFirstPoint;
	Point diagonalSecondPoint;
public:
	Rectangle();
	Rectangle(Point& diagonalStart,Point& diagonalEnd);

	void setDiagonalStartPoint(Point point);
	Point& getDiagonalStartPoint();

	void setDiagonalEndPoint(Point point);
	Point& getDiagonalEndPoint();

	Rectangle& operator=(Rectangle& rectangle);
	double getArea();
	
};

