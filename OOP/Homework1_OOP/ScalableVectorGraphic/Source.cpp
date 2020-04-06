#include <iostream>
#include "List.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"
#include "RectangleStorage.hpp"

using namespace std;

int main()
{
	RectangleStorage rectangleStorage;

	Point point1(2,1);
	Point point2(5,6);

	Point point3(-4, 2);
	Point point4(2,2);

	Rectangle rectangle(point1,point2);

	rectangleStorage.add(rectangle);
	rectangleStorage.addByGivenPoints(point3,point4);

	cout<<rectangleStorage.getIndexWithMaxArea();

	cout << endl;
}