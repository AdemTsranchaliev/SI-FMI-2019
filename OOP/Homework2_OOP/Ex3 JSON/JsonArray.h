#pragma once

#include "JsonObject.h"
#include <fstream>

template <class V>
class JsonArray 
{
private:
	JsonObject<V>* arr;
	int index;
	int capacity;
	void doubleArray();
	bool checkIndex(int index);
	bool checkKey(const char* key);
	int getKeyIndex(const char* key);

public:
	JsonArray();
	JsonArray(const JsonArray<V>& list);
	~JsonArray();

	void add(const JsonObject<V>& num);
	void add(const char* key,V value);

	void insertAt(const char* key, const JsonObject<V>& value);
	void insertAt(int index, const JsonObject<V>& value);

	void removeAt(int index);
	void remove(const char* key);

	JsonObject<V>& getAt(int position) const;
	JsonObject<V>& getAt(const char* key) const;

	V getValueByKey(const char* key);

	int Count() const;

	void getJson();

	void saveToFile(const char* pathToFile);
};

template <class V>
JsonArray<V>::JsonArray()
{
	this->arr = new JsonObject<V>[2];
	this->capacity = 2;
	this->index = 0;
}

template <class V>
JsonArray<V>::JsonArray(const JsonArray<V>& arr)
{
	this->arr = new JsonObject<V>[arr.capacity];
	this->capacity = arr.capacity;
	this->index = arr.index;
}

template <class V>
JsonArray<V>::~JsonArray()
{
	delete[] this->arr;
}

template <class V>
void JsonArray<V>::add(const JsonObject<V>& obj)
{
	if (this->capacity == this->index)
	{
		doubleArray();
	}

	this->arr[this->index] = obj;
	index++;

}

template <class V>
void JsonArray<V>::add(const char* key, V value)
{
	if (this->capacity == this->index)
	{
		doubleArray();
	}

	JsonObject<V> newObj(key, value);
	this->arr[this->index] = newObj;
	index++;
}

template <class V>
void JsonArray<V>::insertAt(int index, const JsonObject<V>& obj)
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
		this->arr[index] = obj;
	}
}

template <class V>
void JsonArray<V>::insertAt(const char* key, const JsonObject<V>& obj)
{
	if (!checkKey(key))
	{
		cout << "The key wasn't found!" << endl;
	}
	else
	{
		if ((this->index + 1) == this->capacity)
		{
			doubleArray();
		}

		this->index++;
		int indexOfKey = getKeyIndex(key);
		for (int i = this->index - 1; i > indexOfKey; i--)
		{
			this->arr[i] = this->arr[i - 1];
		}
		this->arr[indexOfKey] = obj;
	}
}

template <class V>
void JsonArray<V>::removeAt(int index)
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

template <class V>
void JsonArray<V>::remove(const char* key)
{
	if (!checkKey(key))
	{
		cout << "The key wasn't found!" << endl;
	}
	else
	{
		int keyIndex = getKeyIndex(key);
		for (int i = keyIndex; i < this->index; i++)
		{
			this->arr[i] = this->arr[i + 1];
		}
		this->index--;
	}
}

template <class V>
void JsonArray<V>::doubleArray()
{
	int newCapacity = this->capacity * 2;

	JsonObject<V>* temp = new JsonObject<V>[newCapacity];

	for (int i = 0; i < this->capacity; i++)
	{
		temp[i] = this->arr[i];
	}

	delete[] this->arr;

	this->arr = new JsonObject<V>[newCapacity];

	for (int i = 0; i < this->capacity; i++)
	{
		this->arr[i] = temp[i];
	}
	delete[] temp;
	this->capacity = newCapacity;
}

template <class V>
JsonObject<V>& JsonArray<V>::getAt(const char* key) const
{
	if (!checkKey(key))
	{
		cout << "Key wasn't found!" << endl;

	}
	else
	{
		int keyIndex = getKeyIndex(key);
		return this->arr[keyIndex];
	}
}

template <class V>
int JsonArray<V>::Count() const
{
	return this->index;
}

template <class V>
JsonObject<V>& JsonArray<V>::getAt(int position) const
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

template <class V>
V JsonArray<V>::getValueByKey(const char* key) 
{
	if (!checkKey(key))
	{
		cout << "Key wasn't found!" << endl;

	}
	else
	{
		int keyIndex = this->getKeyIndex(key);
		return this->arr[keyIndex].getValue();
	}
}

template <class V>
void JsonArray<V>::getJson()
{
	cout << "[" << endl;
	for (int i = 0; i < this->index; i++)
	{
		this->arr[i].getObjectJson();
		if (i != this->index - 1)
		{
			cout << "," << endl;
		}
		else
		{
			cout << endl;
		}
	}
	cout << "]" << endl;

}

template <class V>
void JsonArray<V>::saveToFile(const char* fullPathToFile)
{
	std::ofstream file;
	file.open(fullPathToFile, ios::app);
	if (file.is_open())
	{

		file << "[" << endl;
		for (int i = 0; i < this->index; i++)
		{
			if (strcmp(typeid(V).name(), "char") == 0)
			{
				file << "  {" << endl;
				file << "	\"" << this->arr[i].getKey() << "\": \'" << this->arr[i].getValue() << "\'" << endl;
				file << "  }";
			}
			else
			{
				file << "  {" << endl;
				file << "	\"" << this->arr[i].getKey() << "\": " << this->arr[i].getValue() << endl;
				file << "  }";
			}
			if (i != this->index - 1)
			{
				file << "," << endl;
			}
			else
			{
				file << endl;
			}
		}
		file << "]" << endl;

	}

	file.close();

}

template <class V>
bool JsonArray<V>::checkIndex(int index)
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

template <class V>
bool JsonArray<V>::checkKey(const char* key)
{
	for (int i = 0; i < this->index; i++)
	{
		if (strcmp(key, this->arr[i].getKey()) == 0)
		{
			return true;
		}
	}

	return false;
}

template <class V>
int JsonArray<V>::getKeyIndex(const char* key)
{
	for (int i = 0; i < this->index; i++)
	{
		if (strcmp(key, this->arr[i].getKey()) == 0)
		{
			return i;
		}
	}

	return -1;
}