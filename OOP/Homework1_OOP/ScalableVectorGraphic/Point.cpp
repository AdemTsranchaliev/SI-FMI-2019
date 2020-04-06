#include "Point.hpp"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Point::setX(double x)
{
	this->x = x;
}
double Point::getX()
{
	return this->x;
}

void Point::setY(double y)
{
	this->y = y;
}
double Point::getY()
{
	return this->y;
}

Point& Point::operator=(Point& point)
{
	if (this!=&point)
	{
		this->x = point.x;
		this->y = point.y;
			
	}
	return *this;
}