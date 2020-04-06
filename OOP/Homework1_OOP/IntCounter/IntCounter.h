#pragma once
class IntCounter
{
private:
	int* reference;
	int* count;

public:
	IntCounter();
	IntCounter(int* number);
	IntCounter(IntCounter& intcounter);
	int get_count();
	IntCounter& operator=(IntCounter& intCounter);
	~IntCounter();

};

