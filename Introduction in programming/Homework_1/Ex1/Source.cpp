/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Adem Tsranchaliev
* @task 1
* @compiler VC
*
*/


#include <iostream>

using namespace std;

int InputAndValidation();


int main()
{
	int number = 0;
	bool flag = 1;
	number = InputAndValidation();

	int temp = number;

	while (temp)
	{
		int lastDigit = temp % 10;
		int secondTemp = number;
		int counter = 0;

		while (secondTemp)
		{
			if (secondTemp % 10 == lastDigit)
			{
				counter++;
			}
			secondTemp /= 10;
		}
		if (counter >= 2)
		{
			cout << "Yes, there are two equal digits in the number.";
			flag = 0;
			break;
		}
		temp /= 10;
	}

	if (flag)
	{
		cout << "No, there are not two equal digits in the number.";
	}

	system("PAUSE");
	return 0;
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
