#include "Rectangle.hpp"


Rectangle::Rectangle()
{
	Point p1();
	Point p2();

	

}
Rectangle::Rectangle(Point& diagonalStart, Point& diagonalEnd)
{
	this->diagonalFirstPoint = diagonalStart;
	this->diagonalSecondPoint = diagonalEnd;
}

void Rectangle::setDiagonalStartPoint(Point point)
{
	this->diagonalFirstPoint = point;
}
Point& Rectangle::getDiagonalStartPoint()
{
	return this->diagonalFirstPoint;
}

void Rectangle::setDiagonalEndPoint(Point point)
{
	this->diagonalSecondPoint = point;
}
Point& Rectangle::getDiagonalEndPoint()
{
	return this->diagonalSecondPoint;
}

double Rectangle::getArea()
{
	double sideA = this->diagonalSecondPoint.getX() - this->diagonalFirstPoint.getX();
	if (sideA<0)
	{
		sideA *= -1;
	}
	double sideB = this->diagonalSecondPoint.getY() - this->diagonalFirstPoint.getY();
	if (sideB < 0)
	{
		sideB *= -1;
	}

	return sideA * sideB;
}

Rectangle& Rectangle::operator=(Rectangle& rectangle)
{
	if (this!=&rectangle)
	{
		this->diagonalFirstPoint = rectangle.diagonalFirstPoint;
		this->diagonalSecondPoint = rectangle.diagonalSecondPoint;
	}
	return *this;
}
