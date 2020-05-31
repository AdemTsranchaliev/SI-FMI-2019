#include "Date.h"
#pragma warning(disable : 4996)

Date::Date()
{
	this->seconds = 0;
	this->minutes = 0;
	this->hours = 0;
	this->days = 0;
	this->months = 0;
	this->years=0;
}
Date::Date(int seconds, int minutes, int hours, int days, int months, int years)
{
	this->seconds = seconds;
	this->minutes = minutes;
	this->hours = hours;
	this->days = days;
	this->months = months;
	this->years= years;
}

Date::Date(int days, int months, int years)
{
	this->seconds = 0;
	this->minutes = 0;
	this->hours = 0;
	this->days = days;
	this->months = months;
	this->years = years;
}
Date::Date(string time)
{
	if (time=="now")
	{
		typedef std::chrono::system_clock Clock;

		auto now = Clock::now();
		std::time_t now_c = Clock::to_time_t(now);
		struct tm* parts = std::localtime(&now_c);

		this->years = 1900 + parts->tm_year;
		this->months = 1 + parts->tm_mon;
		this->days = parts->tm_mday;
		this->hours = parts->tm_hour;
		this->minutes = parts->tm_min;
		this->seconds = parts->tm_sec;
	}
}

Date::Date(const Date& date)
{
	this->seconds = date.seconds;
	this->minutes = date.minutes;
	this->hours = date.hours;
	this->days = date.days;
	this->months = date.months;
	this->years = date.years;
}
Date& Date::operator=(const Date& date)
{
	if (&date!=this)
	{
		this->seconds = date.seconds;
		this->minutes = date.minutes;
		this->hours = date.hours;
		this->days = date.days;
		this->months = date.months;
		this->years = date.years;
	}

	return *this;
}


void Date::setSeconds(int seconds)
{
	this->seconds = seconds;
}
int Date::getSeconds() const
{
	return this->seconds;
}

void Date::setMinutes(int minutes)
{
	this->minutes = minutes;
}
int Date::getMinutes() const
{
	return this->minutes;
}

void Date::setHours(int hours)
{
	this->hours = hours;
}
int Date::getHours() const
{
	return this->hours;
}

void Date::setDays(int days)
{
	this->days = days;
}
int Date::getDays() const
{
	return this->days;
}

void Date::setMonths(int months)
{
	this->months = months;
}
int Date::getMonths() const
{
	return this->months;
}

void Date::setYears(int years)
{
	this->years = years;
}
int Date::getYears() const
{
	return this->years;
}

void Date::print()
{
	cout << this->days << "/" << this->months << "/" << this->years << "  " << this->hours << ":" << this->minutes << ":" <<this->seconds << endl;
}
