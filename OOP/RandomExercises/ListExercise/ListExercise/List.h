#pragma once


class List
{
private:
	int* arr;
	int index;
	int capacity;
	void doubleArray();
	bool checkIndex(int index);
public:
	List();
	List(const List& list);
	~List();

	void add(int num);
	void insertAt(int index,int value);
	void removeAt(int index);
	int Count();
	int getAt(int position);
};
