#include <iostream>

using namespace std;

void getNumberDigits(int[],int,int);

int main()
{
	int number = 0;
	cin >> number;

	int temp = number;
	int countNumber = 0;
	while (temp!=0)
	{
		temp /= 10;
		countNumber++;
	}

	int* arr = new int[countNumber];

	getNumberDigits(arr, countNumber, number);

	delete[] arr;
	system("pause");
	return 0;
}

void getNumberDigits(int arr[],int countNumber,int number)
{
	for (int i = 0; i < countNumber; i++)
	{
		arr[i] = number % 10;
		number /= 10;
	}

	for (int i = 0; i < countNumber; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = countNumber - 1; i >= 0; i--)
	{
		cout << arr[i] << " ";
	}

}