#include <iostream>
#include "List.h"

using namespace std;


List::List()
{
	this->arr = new int[2];
	this->capacity = 2;
	this->index = 0;
}
List::List(const List& list)
{
	this->arr = new int[list.capacity];
	this->capacity = list.capacity;
	this->index = list.index;
}
List::~List()
{
	delete[] this->arr;
}

void List::add(int num)
{
	if (this->capacity==this->index)
	{
		doubleArray();
	}

	this->arr[this->index] = num;
	index++;

}
void List::insertAt(int index,int value)
{
	if (!checkIndex(index))
	{
		cout << "Invalid index!" << endl;
	}
	else
	{
		if ((this->index + 1) == this->capacity)
		{
			doubleArray();
		}

		this->index++;

		for (int i = this->index - 1; i > index; i--)
		{
			this->arr[i] = this->arr[i - 1];
		}
		this->arr[index] = value;
	}
}
void List::removeAt(int index)
{
	if (!checkIndex(index))
	{
		cout << "Invalid index!" << endl;
	}
	else
	{
		for (int i = index; i < this->index; i++)
		{
			this->arr[i] = this->arr[i + 1];
		}
		this->index--;
	}

}
void List::doubleArray()
{
	int newCapacity = this->capacity * 2;

	int* temp = new int[newCapacity];

	for (int i = 0; i < this->capacity; i++)
	{
		temp[i] = this->arr[i];
	}

	delete[] this->arr;

	this->arr = new int[newCapacity];

	for (int i = 0; i < this->capacity; i++)
	{
		this->arr[i] = temp[i];
	}
	delete[] temp;
	this->capacity = newCapacity;
}

int List::Count()
{
	return this->index;
}

int List::getAt(int position)
{
	if (!checkIndex(position))
	{
		cout << "Invalid index!" << endl;
	}
	else
	{
		return this->arr[position];
	}
}

bool List::checkIndex(int index)
{
	if (index>=0&&index<this->index)
	{
		return true;
	}
	else
	{
		return false;
	}
}
