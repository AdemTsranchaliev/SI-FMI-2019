#pragma once
#include "List.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"


class RectangleStorage
{
private:

	List<Rectangle> rectangles;

public:

	void add(Rectangle& rectangle);
	void addByGivenPoints(Point diagonalStart,Point diagonalEnd);
	int getIndexWithMaxArea();
};

