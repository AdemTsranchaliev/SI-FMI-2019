using namespace std;
#include "ProtectedValue.h"

template <class T>
class ProtectedArray
{
private:
	T* arr;
	int index;
	int capacity;
	void makeArrayBigger();
	bool checkIndex(int index);
public:
	ProtectedArray<T>();
	ProtectedArray<T>(const ProtectedArray<T>& rotectedArray);
	~ProtectedArray<T>();

	void add(const T& object);

	void insertAt(ProtectedValue<T> value, int code);

	int Count();

	T& getAt(int position, int code);
};

template <class T>
ProtectedArray<T>::ProtectedArray()
{
	this->arr = new T[2];
	this->capacity = 2;
	this->index = 0;
}

template <class T>
ProtectedArray<T>::ProtectedArray(const ProtectedArray& ProtectedArray)
{
	this->arr = new ProtectedValue<T>[ProtectedArray.capacity];
	this->capacity = ProtectedArray.capacity;
	this->index = ProtectedArray.index;
}

template <class T>
ProtectedArray<T>::~ProtectedArray()
{
	delete[] this->arr;
}

template <class T>
void ProtectedArray<T>::add(const T& num)
{
	if (this->capacity == this->index)
	{
		makeArrayBigger();
	}

	this->arr[this->index] = num;
	index++;

}


template <class T>
void ProtectedArray<T>::insertAt(ProtectedValue<T> value, int code)
{
	if (!checkIndex(index))
	{
		cout << "Invalid index!" << endl;
	}
	else
	{
		if ((this->index + 1) == this->capacity)
		{
			makeArrayBigger();
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
void ProtectedArray<T>::makeArrayBigger()
{
	int newCapacity = this->capacity * 2;

	T* temp = new T[newCapacity];

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
int ProtectedArray<T>::Count()
{
	return this->index;
}

template <class T>
T& ProtectedArray<T>::getAt(int position,int code)
{
	if (!checkIndex(position))
	{
		cout << "Invalid index!" << endl;

	}
	else
	{
		if (this->arr[position].getCode()==code)
		{
			return this->arr[position];
		}
		else
		{
			cout << "Invalid code!" << endl;

		}
	}
}

template <class T>
bool ProtectedArray<T>::checkIndex(int index)
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