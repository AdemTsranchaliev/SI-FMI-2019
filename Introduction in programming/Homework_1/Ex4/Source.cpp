#include <iostream>

using namespace std;

int InputAndValidation();

int main()
{

	int input=0;

	input = InputAndValidation();

	for (int i = input; i >= 0; i--)
	{
		for (long j = 1; j < 2000000000; j++);
		
		system("cls");
		cout << i;
	}

	return 0;
}



int InputAndValidation()
{
	int input = 0;
	cout << "Enter number: ";
	cin >> input;

	int isValid = 1;
	while ((isValid == 1) || (input <= 0))
	{
		if (cin.fail() || (input <= 0))
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
