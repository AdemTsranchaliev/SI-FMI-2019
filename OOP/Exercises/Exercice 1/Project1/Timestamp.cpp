#include <iostream>
#include "Timestamp.hpp"

using namespace std;


Timestamp::Timestamp()
{
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}

void Timestamp::SetTimeBySeconds(int seconds)
{
	if (seconds>= 86400)
	{
		seconds -= 86400;
	}
	if (seconds >= 0)
	{
		int hoursTemp = seconds / 3600;
		int minutesTemp = seconds % 3600 / 60;
		int secondsTemp = seconds % 3600 % 60;

		this->hours = hoursTemp;
		this->minutes = minutesTemp;
		this->seconds = secondsTemp;
	}
}
void Timestamp::Print()
{
	if (this->hours >= 10 && this->hours <= 23)
	{
		cout << this->hours << ":";
	}
	else
	{
		cout<< 0 << this->hours << ":";
	}
	if (this->minutes >= 10 && this->minutes <= 59)
	{
		cout << this->minutes << ":";
	}
	else
	{
		cout << 0 << this->minutes << ":";
	}
	if (this->seconds >= 10 && this->seconds <= 59)
	{
		cout << this->seconds << ":";
	}
	else
	{
		cout << 0 << this->seconds << endl;
	}
}

int Timestamp::ConvertToSeconds()
{
	return hours * 3600 + minutes * 60 + seconds;
}
void Timestamp::SumWith(const Timestamp& time)
{
	this->seconds += time.seconds;
	if (this->seconds>=60)
	{
		this->seconds -= 60;
		this->minutes += 1;
	}
	this->minutes += time.minutes;

	if (this->minutes>=60)
	{
		this->minutes -= 60;
		this->hours += 1;
	}
	this->hours += time.hours;
	if (this->hours>=24)
	{
		this->hours -= 24;
	}

}