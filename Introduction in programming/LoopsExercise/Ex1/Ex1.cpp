
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cout << "Insert N:";
	cin >> n;
	cout << endl;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	cout << sum;

	return 0;
}

