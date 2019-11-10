#include <iostream>

using namespace std;

int InputAndValidation();

int main()
{
	int days=0;

	days = InputAndValidation();
	int yearCounter = 0;
	for (int i = days-1; i > 0; i-=365)
	{
		yearCounter++;
		if (yearCounter%4==0)
		{
			if (!(yearCounter % 100 == 0) || (yearCounter % 400 == 0))
			{
				i -= 1;
			}
		}
	
	}
	cout <<"The year is "<< yearCounter<<endl;
	system("Pause");
}


int InputAndValidation()
{
	int input = 0;
	cout << "Enter number: ";
	cin >> input;

	int isValid = 1;
	while ((isValid == 1)||!(input>=0&& input<=1000000))
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