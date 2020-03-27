//ex.22

#include <iostream>
#include "List.h"
using namespace std;

int main() {

	int n;
	cin >> n;
	List numbers=List();

	for (int i = 0; i < 5000; i++)
	{
		numbers.add(i);
			
	}
	for (int i = 0; i < 1000; i++)
	{
		numbers.removeAt(0);
	}

	for (int i = 0; i < numbers.Count(); i++)
	{
		cout << i + 1 << ". " << numbers.getAt(i) << endl;
	}
	system("pause");
	return 0;
}