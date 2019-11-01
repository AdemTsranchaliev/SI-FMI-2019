#include <iostream>
using namespace std;

int main()
{

	int n = 0;
	cin >> n;
	int first = 1, second = 1;
	cout << first << " ";
	cout << second << " ";
	for (int i = 2; i < n-1; i++)
	{
		int third = first; 
		first = second;
		second = first + third;
		cout << second<<" ";

	}
    cout << "";
}
