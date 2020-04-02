#pragma once
class IntCounter
{
private:
	int* reference;
	int count;

public:
	IntCounter();
	IntCounter(int* number);
	int get_count();
	IntCounter& operator=(IntCounter& intCounter);
};

