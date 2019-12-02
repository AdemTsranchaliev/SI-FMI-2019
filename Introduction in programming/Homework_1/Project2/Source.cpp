/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Adem Tsranchaliev
* @task 3
* @compiler VC
*
*/
#include <iostream>

using namespace std;


void ConvertToHexAndPrint(int);

int main()
{
	char command, firstHexNumber, secondHexNumber;
	cout << "Enter command, first hex digit and second hex digit" << endl;


	while (true)
	{
		cin >> command >> firstHexNumber >> secondHexNumber;
		bool check1 = 1;
		bool check2 = 1;
		bool check3 = 1;
		if (!(command == '+' || command == '-' || command == '*' || command == '/' || command == '%'))
		{
			check1 = 0;
		}

		if (!(firstHexNumber >= '0'&& firstHexNumber <= '9' || (firstHexNumber >= 'A'&& firstHexNumber <= 'F')))
		{
			check2 = 0;
		}

		if (!(secondHexNumber >= '0'&& secondHexNumber <= '9' || secondHexNumber >= 'A'&& secondHexNumber <= 'F'))
		{
			check3 = 0;
		}

		if (!(check1&&check2&&check3))
		{
			cout << "Invalid input please try again:" << endl << "Enter command, first hex digit and second hex digit" << endl;

		}
		else
		{
			break;
		}


	}

	int firstNum = 0;
	int secondNum = 0;
	if (firstHexNumber >= 48 && firstHexNumber <= 59)
	{
		firstNum = firstHexNumber - '0';

	}
	else if (firstHexNumber >= 65 && firstHexNumber <= 70)
	{
		firstNum = (firstHexNumber - 'A') + 10;
	}
	if (secondHexNumber >= 48 && secondHexNumber <= 59)
	{
		secondNum = secondHexNumber - '0';

	}
	else if (secondHexNumber >= 65 && secondHexNumber <= 70)
	{
		secondNum = (secondHexNumber - 'A') + 10;
	}

	int result = 0;

	if (command == '+')
	{
		result = firstNum + secondNum;
	}
	else if (command == '-')
	{
		result = firstNum - secondNum;
	}
	else if (command == '/')
	{
		result = firstNum / secondNum;
	}
	else if (command == '*')
	{
		result = firstNum * secondNum;
	}
	else if (command == '%')
	{
		result = firstNum % secondNum;
	}
	if (result == 0)
	{
		cout << 0;
	}
	else
	{
		ConvertToHexAndPrint(result);
	}
	cout << endl;
	system("PAUSE");

}

void ConvertToHexAndPrint(int result)
{
	if (result == 0)
	{
		return;
	}
	ConvertToHexAndPrint(abs(result / 16));
	int res = abs(result % 16);
	if (result <= 0)
	{
		cout << "-";
	}
	if (res >= 0 && res <= 9)
	{
		char temp = '0';
		cout << (char)(temp + res);
	}
	else if (res >= 10 && res <= 15)
	{
		char temp = 'A';
		cout << (char)(temp + (res - 10));
	}



}

