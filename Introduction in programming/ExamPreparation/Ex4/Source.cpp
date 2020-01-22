#include <iostream>

using namespace std;

void Func(int n,int** arr)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i][i];
	}
	cout << sum;
}

int main()
{
	int n = 0;
	cin >> n;
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	
	Func(3, matrix);
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	system("pause");
}