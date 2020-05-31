#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <ctime> 

using namespace std;

class Date
{
private:
	int seconds;
	int minutes;
	int hours;
	int days;
	int months;
	int years;
public:
	Date();
	Date(int seconds,int minutes,int hours,int days,int months,int years);
	Date(int days, int months, int years);
	Date(string time);
	Date(const Date& date);
	Date& operator=(const Date& date);


	void setSeconds(int seconds);
	int getSeconds() const;

	void setMinutes(int minutes);
	int getMinutes() const;

	void setHours(int hours);
	int getHours() const;

	void setDays(int days);
	int getDays() const;

	void setMonths(int months);
	int getMonths() const;

	void setYears(int years);
	int getYears() const;

	void print();
};

