#include <iostream>

using namespace std;

int InputAndValidation();
void ConvertToHexAndPrint(int);

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
	else if (firstHexNumber >= 65 && firstHexNumber <= 70)
	{
		firstNum = (firstHexNumber - 'A')+10;
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

	if (command=='+')
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
	
	ConvertToHexAndPrint(result);
	system("PAUSE");

}

void ConvertToHexAndPrint(int result)
{
	if (result==0)
	{
		return;
	}
	ConvertToHexAndPrint(abs(result / 16));
	int res = abs(result % 16);
	if (result<=0)
	{
		cout << "-";
	}
	if (res>=0&&res<=9)
	{
		char temp = '0';
		cout << (char)(temp + res);
	}
	else if (res>=10&&res<=15)
	{
		char temp = 'A';
		cout << (char)(temp + (res-10));
	}

	

}

