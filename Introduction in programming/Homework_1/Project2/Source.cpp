#include <iostream>

using namespace std;

int InputAndValidation();


int main()
{
	char command, firstHexNumber, secondHexNumber;

	cin >> command >> firstHexNumber >> secondHexNumber;

	int firstNum = 0;
	int secondNum = 0;
	if (firstHexNumber>=48&&firstHexNumber<=59)
	{
		firstNum = firstHexNumber - '0';

	}
	else if (secondHexNumber >= 65 && secondHexNumber <= 70)
	{
		firstNum = (firstHexNumber - 'A')+10;
	}
	if (secondHexNumber >= 48 && secondHexNumber <= 59)
	{
		secondNum = firstHexNumber - '0';

	}
	else if (secondHexNumber >= 65 && secondHexNumber <= 70)
	{
		secondNum = (firstHexNumber - 'A') + 10;
	}


	if (command=='+')
	{

	}
	else if (command == '-')
	{

	}
	else if (command == '/')
	{

	}
	else if (command == '*')
	{

	}
	else if (command == '%')
	{

	}

}


int InputAndValidation()
{
	int input = 0;
	cout << "Enter number: ";
	cin >> input;

	int isValid = 1;
	while (isValid == 1)
	{
		if (cin.fail())
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
