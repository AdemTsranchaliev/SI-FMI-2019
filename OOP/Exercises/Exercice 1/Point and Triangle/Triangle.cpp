#include <iostream>

#include "Triangle.h"

using namespace std;

void Triangle::setSides(const Point& a, const Point& b, const Point& c)
{

	this->a = a;
	this->b = b;
	this->c = c;

	this->sideA = this->a.getDistance();
	this->sideB = this->b.getDistance();
	this->sideC = this->c.getDistance();
}
bool Triangle::isValid() const
{

		return this->sideA + this->sideB > this->sideC&&this->sideA + this->sideC > this->sideB&&this->sideC + this->sideB > this->sideA;

}
void Triangle::TypeOfTriangle() const
{
	if (this->sideA == this->sideB==this->sideC)
	{
		cout << "Equal sides";
	}
	else if (this->sideA==this->sideB|| this->sideC == this->sideB|| this->sideC == this->sideA)
	{
		cout << "Two sides are equal";
	}
	else
	{
		cout << "No equal sides";
	}
}