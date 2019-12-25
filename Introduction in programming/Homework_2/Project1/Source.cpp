#include <iostream>

using namespace std;

bool CheckIfMatrixCanBeOrderedAndOrderIt(int**, int*);
int  GetInputForMatrixSizeAndValidateIt();
int  GetMatrixElementAndValidateIt();
int main()
{
	int n = GetInputForMatrixSizeAndValidateIt();

	int** arr = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = new int[n];
	}

	int* arr2 = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr2[i] = i;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Insert element for row " << i << " , column " << j << endl;
			arr[i][j] = GetMatrixElementAndValidateIt();
		}
	}


	bool isItOrdered = CheckIfMatrixCanBeOrderedAndOrderIt(arr, &n);

	if (isItOrdered)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

	}
	else
	{
		cout << "Matrix can't be ordered!";
	}


	delete arr[];
	system("pause");
	return 0;
}
int  GetMatrixElementAndValidateIt()
{
	int element = 0;
	cin >> element;
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input! Please try again!" << endl;
			cin >> element;
		}
		else
		{
			break;
		}
	}

	return element;
}
int  GetInputForMatrixSizeAndValidateIt()
{
	int n = 0;
	cout << "Insert matrix's size, which is between 1 and 10, included: " << endl;
	cin >> n;

	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input! Please try again!" << endl;
			cout << "Insert matrix's size, which is between 1 and 10, included: " << endl;
			cin >> n;
		}
		else if (n < 1 || n>10)
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input! Please try again!" << endl;
			cout << "Insert matrix's size, which is between 1 and 10, included: " << endl;
			cin >> n;
		}
		else
		{
			break;
		}
	}

	return n;
}

bool CheckIfMatrixCanBeOrderedAndOrderIt(int** arr, int* n, int* arr2)
{
	

	if (true)
	{

	}



	return true;
}