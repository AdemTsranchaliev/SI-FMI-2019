#include <iostream>
#include "Timestamp.hpp"
using namespace std;

int main()
{
	Timestamp time,time2;


	time.SetTimeBySeconds(-2);
	time.Print();
	system("pause");
	return 0;
}