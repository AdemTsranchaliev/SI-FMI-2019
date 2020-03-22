#pragma once

class Point
{
private:
	double x;
	double y;
public:

	void setXAndY(double,double);
	void setX(double);
	double getX() const;
	void setY(double);
	double getY() const;
	double getDistance() const;
	void PrintXAndY() const;
};