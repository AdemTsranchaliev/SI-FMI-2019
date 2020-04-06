#include <iostream>
#include "IntCounter.h"
using namespace std;

int main()
{
	int* some_number = nullptr;
	IntCounter first(some_number);
	cout << first.get_count() << endl;
	IntCounter second = first;
	cout << first.get_count() << endl;
	system("pause");
	return 0;
}