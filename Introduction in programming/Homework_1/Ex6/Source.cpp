/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Adem Tsranchaliev
* @idnumber 62409
* @task 6
* @compiler VC
*
*/
#include <iostream>
#include <cmath>  

using namespace std;

int main() {

	double x = 0, y = 0;
	cout << "Insert x and y: ";
	cin >> x >> y;

	int isValid = 1;
	while ((isValid == 1))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input! Please try again." << endl;
			cout << "Insert x and y: ";
			cin >> x >> y;
		}
		else
		{
			isValid = 0;
		}

	}

	double distanceToPoint = sqrt(x*x + y + y);
	//Check if the point is on the border of circle and square
	if (distanceToPoint == 2 || distanceToPoint == 3 || (x == 1 && (y >= -1 && y <= 1)) || (x == -1 && (y >= -1 && y <= 1)) || (y == -1 && (x >= -1 && x <= 1)) || (y == 1 && (x >= -1 && x <= 1)))
	{
		cout << "Undefined" << endl;
	}
	else if ((x > -1 && x < 1) && y > -1 && y < 1) //Check if the point is the square
	{
		cout << "Black" << endl;
	}
	else if (distanceToPoint > 2 && distanceToPoint < 3)//Check if the point is in the black circle
	{
		cout << "Black" << endl;
	}
	else if (distanceToPoint < 2)//Check if the point is on the white side
	{
		cout << "White" << endl;
	}
	else
	{
		cout << "Otside" << endl;
	}

	system("pause");
	return 0;
}