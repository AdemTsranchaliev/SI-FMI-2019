#include <iostream>
#include "Date.hpp"
using namespace std;


void Date::setDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;

}
void Date::setDayName(char* name)
{
	this->dayName = name;
}
void Date::displayA() const //dd/mm/yyyy
{
	cout << this->day<<"/" << this->month << "/" << this->year;
}
void Date::displayB() const
{
	cout << this->day << ".";

	switch (this->month)
	{
	case 1: cout << "January."; break;
	case 2: cout << "February."; break;
	case 3: cout << "March."; break;
	case 4: cout << "April."; break;
	case 5: cout << "May."; break;
	case 6: cout << "June."; break;
	case 7: cout << "July."; break;
	case 8: cout << "August."; break;
	case 9: cout << "September."; break;
	case 10: cout << "October."; break;
	case 11: cout << "November."; break;
	case 12: cout << "December."; break;
	default:
		break;
	}
	cout << this->year;
}
void Date::displayC() const
{
	int i = 0;

	while (this->dayName[i]!='\0')
	{
		cout << dayName[i];
		i++;
	}

	cout <<" "<< this->day << " ";

	switch (this->month)
	{
	case 1: cout << "January"; break;
	case 2: cout << "February"; break;
	case 3: cout << "March"; break;
	case 4: cout << "April"; break;
	case 5: cout << "May"; break;
	case 6: cout << "June"; break;
	case 7: cout << "July"; break;
	case 8: cout << "August"; break;
	case 9: cout << "September"; break;
	case 10: cout << "October"; break;
	case 11: cout << "November"; break;
	case 12: cout << "December"; break;
	default:
		break;
	}
}