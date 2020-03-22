#pragma once
#include "Point.hpp"

class Triangle
{
private:
	double sideA;
	double sideB;
	double sideC;

	Point a;
	Point b;
	Point c;
public:
	void setSides(const Point&, const Point&, const Point&);
	bool isValid() const;
	void TypeOfTriangle() const;
	
};

