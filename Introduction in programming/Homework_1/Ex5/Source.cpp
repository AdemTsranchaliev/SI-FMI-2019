/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Adem Tsranchaliev
* @idnumber 62409
* @task 5
* @compiler VC
*
*/

#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	double a = 0, b = 0, c = 0;
	cout << "Enter a, b and c: ";
	cin >> a >> b >> c;

	int isValid = 1;
	while (isValid == 1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input! Please try again." << endl;
			cout << "Enter a, b and c: ";
			cin >> a >> b >> c;
		}
		else
		{
			isValid = 0;
		}
	}
	if (a == 0 & b == 0 && c == 0)
	{
		cout << "Each X" << endl;
		system("PAUSE");
		return 0;
	}
	if (a < 0)
	{
		a = a * (-1);
		b = b * (-1);
		c = c * (-1);
	}
	int discriminant = b * b - 4 * a*c;

	if (discriminant < 0)
	{
		cout << "There are not real roots";
	}
	else if (discriminant == 0)
	{
		double t1t2 = ((-1)*b) / (2 * a);
		if (t1t2 < 0)
		{
			cout << "There are not real roots" << endl;
		}
		else if (t1t2 == 0)
		{
			cout << "x1\2=0";
		}
		else
		{
			double x = sqrt(t1t2);
			cout << "x1=-" << x << endl;
			cout << "x2=+" << x << endl;
		}
	}
	else if (discriminant > 0)
	{
		double t1 = (-b + sqrt(discriminant)) / (2 * a);
		double t2 = (-b - sqrt(discriminant)) / (2 * a);

		int i = 0;
		if (t1 > 0)
		{
			cout << "x" << ++i << "= -" << sqrt(t1) << endl;
			cout << "x" << ++i << "= +" << sqrt(t1) << endl;
		}
		if (t2 > 0)
		{
			cout << "x" << ++i << "= -" << sqrt(t2) << endl;
			cout << "x" << ++i << "= +" << sqrt(t2) << endl;
		}
		if (i == 0)
		{
			cout << "There are not real roots";
		}
	}

	system("PAUSE");
	return 0;
}



