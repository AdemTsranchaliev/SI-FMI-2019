#include <iostream>

#include "Point.hpp"
using namespace std;

int main()
{
	Point p;

	p.setX(1);
	p.setY(5);

	p.PrintXAndY();

	system("pause");
}