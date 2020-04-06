#pragma once
class Point
{
private:

	double x;
	double y;

public:

	Point();
	Point(double x,double y);

	void setX(double x);
	double getX();

	void setY(double y);
	double getY();

	Point& operator=(Point& point);

};

