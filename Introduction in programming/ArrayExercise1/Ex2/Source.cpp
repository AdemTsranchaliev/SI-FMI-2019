#include <iostream>

using namespace std;

int main()
{
	int input = 0, number=0;
	cin >> input;
	cin >> number;

	int* arr = new int[input];

	for (int i = 0; i < input; i++)
	{
       arr[i]=number % 10;
	   number /= 10;
	}

	for (int i = 0; i < input; i++)
	{
		cout << arr[i] << endl;
	}


	delete[] arr;
	system("pause");
	return 0;
}