#include <iostream>

using namespace std;

int main()
{
	int input = 0;
	cin >> input;

	int* arr = new int[input];

	for (int i = 0; i < input; i++)
	{
		cin >> arr[i];
	}

	for (int i = input - 1; i >= 0; i--)
	{
		cout << arr[i] << endl;
	}


	system("pause");
	return 0;
}