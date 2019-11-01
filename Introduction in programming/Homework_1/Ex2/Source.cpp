#include <iostream>

using namespace std;

int InputAndValidation();


int main()
{
	int a = 450527;
	int counter = 0;
	for (int i = a; i >= 0; i-=365)
	{
		
		if (counter%4==0)
		{
			i -= 1;
		}
		counter++;
	}
	cout << counter;
	system("Pause");
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
