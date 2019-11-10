#include <iostream>
#include <cmath>  

using namespace std;

int main() {

	double x = 0, y = 0;
	cout << "Insert x and y: ";
	cin >> x >> y;

	int isValid = 1;
	while ((isValid == 1) )
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input! Please try again." << endl;
			cout << "Insert x and y: ";
			cin >> x>>y;
		}
		else
		{
			isValid = 0;
		}

	}

	double distanceToPoint = sqrt(x*x + y + y);

	if ((x >= -1 && x <= 1) && y >= -1 && y <= 1)
	{
		cout << "Black";
	}
	else if (distanceToPoint > 2 && distanceToPoint < 3)
	{
		cout << "Black";
	}
	else if (distanceToPoint < 2)
	{
		cout << "White";
	}
	else if (distanceToPoint == 2 || distanceToPoint == 3 || (x == 1 && y == 1) || (x == 1 && y == -1) || (x == -1 && y == 1) || (x == -1 && y == -1))
	{
		cout << "Undefined";
	}
	else
	{
		cout << "Otside" << endl;
	}

	system("pause");
	return 0;
}