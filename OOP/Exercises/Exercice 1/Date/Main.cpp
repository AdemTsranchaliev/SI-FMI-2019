#include <iostream>
#include "Date.hpp"

using namespace std;

int main()
{
	Date date;

	date.setDate(20,12,2000);
	char dateName[] = "Monday";
	date.setDayName(dateName);

	date.displayC();

	system("pause");
}