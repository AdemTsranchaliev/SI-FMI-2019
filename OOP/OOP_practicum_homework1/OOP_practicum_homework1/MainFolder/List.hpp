#pragma once

template <class T>
class List
{
private:
	T* arr;
	int index;
	int capacity;
	void doubleArray();
	bool checkIndex(int index);
public:
	List();
	List(const T& list);
	~List();

	void add(T& num);
	void insertAt(int index, int value);
	void removeAt(int index);
	int Count();
	T& getAt(int position);
};
