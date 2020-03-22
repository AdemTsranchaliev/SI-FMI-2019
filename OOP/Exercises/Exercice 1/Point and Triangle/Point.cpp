#include <iostream>

#include "Point.hpp"

using namespace std;



void Point::setXAndY(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Point::setX(double x)
{
	this->x = x;
}
double Point::getX() const
{
	return this->x;
}

void Point::setY(double y)
{
	this->y = y;
}
double Point::getY() const
{
	return this->y;
}
double Point::getDistance() const
{
	if (this->x>this->y)
	{
		return this->x - this->y;
	}
	else
	{
		return  this->y - this->x;
	}
}
void Point::PrintXAndY() const
{
	cout << "("<<this->x<<", "<<this->y<<")";
}
