#include <iostream>
#include "IntCounter.h"

using namespace std;

IntCounter::IntCounter(int* number)
{
	this->reference = number;
	this->count= new int(1);
}

int IntCounter::get_count()
{
	return *this->count;
}

IntCounter::IntCounter(IntCounter& intCounter)
{
	
	*intCounter.count= *intCounter.count+1;
	this->count = intCounter.count;
	this->reference = intCounter.reference;
}

IntCounter& IntCounter::operator=(IntCounter& intCounter)
{
	if (this!= &intCounter)
	{
		*intCounter.count = *intCounter.count + 1;
		this->count = intCounter.count;
		this->reference = intCounter.reference;
	}
	
	return *this;

}

IntCounter::~IntCounter()
{
	*this->count = *this->count-1;
	if (*this->count==0)
	{
		delete this->count;
	}
	delete this->reference;
}