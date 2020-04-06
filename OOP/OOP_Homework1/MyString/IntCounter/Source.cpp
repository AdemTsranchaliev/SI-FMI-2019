#include <iostream>
#include "IntCounter.h"
using namespace std;

int main()
{
	int* some_number = new int(5);
	IntCounter first(some_number); 
	std::cout << first.get_count() << std::endl;
	IntCounter second;
	second = first;
	std::cout << first.get_count() << std::endl;
	
	{
		IntCounter third(second);
		std::cout << first.get_count() << std::endl;
	}
	std::cout << first.get_count() << std::endl;

	system("pause");
	return 0;
}