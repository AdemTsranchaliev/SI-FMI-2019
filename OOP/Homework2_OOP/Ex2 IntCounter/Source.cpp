#include <iostream>
#include "IntCounter.h"


using namespace std;
#pragma warning (disable:4996)
int main()
{
	int* some_number = new int(5);
	IntCounter<int> first(some_number);

	int* some_other_number = new int(7);
	IntCounter<int>  second(some_other_number);

	std::cout << first.get_count() << std::endl;
	std::cout << second.get_count() << std::endl;


	system("pause");
	return 0;
}