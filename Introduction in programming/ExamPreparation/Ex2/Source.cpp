#include <iostream>

using namespace std;


void Func(int, int, char);


int main()
{
	int n = 0;
	int m = 0;
	char symbol;
	cin >> n;

	cin >> m;
	
	cin >> symbol;

	Func(n, m, symbol);


	system("pause");
}

void Func(int n , int m, char symbol)
{
	int add1 = 0;
	int add2 = 0;
	if ((80 - m) % 2 == 1)
	{
		add2++;
	}
	if ((25 - n) % 2 == 1)
	{
		add1++;
	}

	for (int i = 0; i < (25 - n) / 2; i++)
	{
		for (int i = 0; i < 80; i++)
		{
			cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (80 - m) / 2; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < m; j++)
		{
			cout << symbol;
		}
		for (int j = 0; j < ((80 - m) / 2) + add2; j++)
		{
			cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < ((25 - n) / 2) + add1; i++)
	{
		for (int i = 0; i < 80; i++)
		{
			cout << " ";
		}
		cout << endl;
	}
}