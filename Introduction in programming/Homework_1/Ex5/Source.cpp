#include <iostream>
#include <math.h>
using namespace std;

int InputAndValidation();


int main()
{
	int a = 0, b = 0, c = 0;

	cin >> a >> b >> c;

	int discriminant = b * b - 4 * a*b;

	if (discriminant<0)
	{
		cout << "There are not real roots";
	}
	else if (discriminant==0)
	{
		double t1t2 = ((-1)*b) / 2 * a;
		if (t1t2<0)
		{
			cout << "There are not real roots";
		}
		else if (t1t2==0)
		{
			cout << "x=0";
		}
		else
		{
			double x = sqrt(t1t2);
			cout << "x=" << x;
		}
	}
	else if(discriminant>0)
	{
		double t1 = (-b + sqrt(discriminant)) / 2*a;
		double t2 = (-b - sqrt(discriminant)) / 2*a;
		if (t1>0)
		{
			cout << sqrt(t1);
		}
		if (t2>0)
		{
			cout << sqrt(t2);
		}



		/*
		*/

	 /*
	

	   |================
	   |               |
	   |               |
	   |               0
	   |              /|\
	   |               |
	   |              /'\
	   |
	   |
	 
|	 */


	}
	
	system("Pause");
}


int InputAndValidation()
{
	int input = 0;
	cout << "Enter number: ";
	cin >> input;

	int isValid = 1;
	while ((isValid == 1) || !(input >= 0 && input <= 1000000))
	{
		if (cin.fail() || !(input >= 0 && input <= 1000000))
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input! Please try again." << endl;
			cout << "Enter number: ";
			cin >> input;
		}
		else
		{
			isValid = 0;
		}

	}

	return input;
}
