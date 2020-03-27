#include <iostream>
#include "List.hpp"

using namespace std;

template <class T>
List<T>::List()
{
	this->arr = new T[2];
	this->capacity = 2;
	this->index = 0;
}

template <class T>
List<T>::List(const T& list)
{
	this->arr = new int[list.capacity];
	this->capacity = list.capacity;
	this->index = list.index;
}

template <class T>
List<T>::~List()
{
	delete[] this->arr;
}

template <class T>
void List<T>::add(T& num)
{
	if (this->capacity == this->index)
	{
		doubleArray();
	}

	this->arr[this->index] = num;
	index++;

}

template <class T>
void List<T>::insertAt(int index, int value)
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

template <class T>
void List<T>::removeAt(int index)
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

template <class T>
void List<T>::doubleArray()
{
	int newCapacity = this->capacity * 2;

	int* temp = new T[newCapacity];

	for (int i = 0; i < this->capacity; i++)
	{
		temp[i] = this->arr[i];
	}

	delete[] this->arr;

	this->arr = new T[newCapacity];

	for (int i = 0; i < this->capacity; i++)
	{
		this->arr[i] = temp[i];
	}
	delete[] temp;
	this->capacity = newCapacity;
}

template <class T>
int List<T>::Count()
{
	return this->index;
}

template <class T>
T& List<T>::getAt(int position)
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

template <class T>
bool List<T>::checkIndex(int index)
{
	if (index >= 0 && index < this->index)
	{
		return true;
	}
	else
	{
		return false;
	}
}
