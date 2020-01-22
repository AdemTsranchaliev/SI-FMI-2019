#include <iostream>

using namespace std;

int** Func(int,int**)

int main()
{

	int n = 0;
	cin >> n;
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	Func(n,matrix);

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	system("pause");
}

int** Func(int n, int** arr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int swap = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = swap;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout<<arr[i][j];
		}
		cout << endl;
	}

	return arr;
}

