#include <iostream>
#include "IntCounter.h"

using namespace std;

IntCounter::IntCounter()
{
	this->reference = nullptr;
	this->count = 0;
}

IntCounter::IntCounter(int* number)
{
	this->reference = number;
	this->count = 1;
}

int IntCounter::get_count()
{
	return this->count;
}

IntCounter& IntCounter::operator=(IntCounter& intCounter)
{
	intCounter.count++;
	this->count = intCounter.count;
	this->reference = intCounter.reference;
	return *this;
}