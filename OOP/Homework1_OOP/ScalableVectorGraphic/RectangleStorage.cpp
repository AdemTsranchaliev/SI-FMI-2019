#include <iostream>
#include "RectangleStorage.hpp"

void RectangleStorage::add(Rectangle& rectangle)
{
	this->rectangles.add(rectangle);
}
void RectangleStorage::addByGivenPoints(Point diagonalStart, Point diagonalEnd)
{
	Rectangle newRectangle(diagonalStart,diagonalEnd);
	this->rectangles.add(newRectangle);
}
int RectangleStorage::getIndexWithMaxArea()
{
	double maxArea =-1;
	int maxIndex = -1;

	for (int i = 0; i < rectangles.Count(); i++)
	{
		if (rectangles.getAt(i).getArea()>maxArea)
		{
			maxArea = rectangles.getAt(i).getArea();
			maxIndex = i;
		}
	}
	return maxIndex;
}