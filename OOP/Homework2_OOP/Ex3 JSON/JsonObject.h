#pragma once
#include <iostream>
#include <string.h>

using namespace std;

template <class V>
class JsonObject
{
private:
	char* key;
	V value;
public:
	JsonObject<V>();
	JsonObject<V>(const char* key, V value);
	JsonObject<V>(const JsonObject& obj);
	~JsonObject<V>();
	JsonObject<V>& operator=(const JsonObject& obj);

	void setKey(const char* key);
	char* getKey() const;

	void setValue(V value);
	V getValue() const;

	void getObjectJson() const;
};

template <class V>
JsonObject<V>::JsonObject<V>()
{
	this->key = new char[1];
	this->key[0] = '\0';

	
	
}
template <class V>
JsonObject<V>::JsonObject<V>(const char* key, V value)
{
	this->key = new char[strlen(key) + 1];
	strncpy(this->key, key, strlen(key) + 1);
	this->key[strlen(key)] = '\0';

	this->value = value;
	

}
template <class V>
JsonObject<V>::JsonObject<V>(const JsonObject& obj)
{
	this->key = new char[strlen(obj.key) + 1];
	strncpy(this->key, obj.key, strlen(obj.key) + 1);
	this->key[strlen(obj.key)] = '\0';

	this->value = obj.value;
	
	
}
template <class V>
JsonObject<V>::~JsonObject<V>()
{
	delete[] this->key;
	
}

template <class V>
JsonObject<V>& JsonObject<V>::operator=(const JsonObject& obj)
{
	if (this != &obj)
	{
		delete[] this->key;
	

		this->key = new char[strlen(obj.key) + 1];
		strncpy(this->key, obj.key, strlen(obj.key) + 1);
		this->key[strlen(obj.key)] = '\0';

		
		this->value = obj.value;
		
	
	}
	return *this;
}

template <class V>
void JsonObject<V>::setKey(const char* key)
{
	delete[] this->key;

	this->key = new char[strlen(key) + 1];
	strncpy(this->key, key, strlen(key) + 1);
	this->key[strlen(key)] = '\0';
}

template <class V>
char* JsonObject<V>::getKey() const
{
	return this->key;
}

template <class V>
void JsonObject<V>::setValue(V value)
{
	
	this->value = value;
	
}

template <class V>
V JsonObject<V>::getValue() const
{
	return this->value;
}

template <class V>
void JsonObject<V>::getObjectJson() const
{
	cout << "{" << endl;
	if (strcmp(typeid(V).name(),"char")==0)
	{
		cout << "  \"" << this->getKey() << "\": \'" << this->getValue() << "\'" << endl;
	}
	else
	{
		cout << "  \"" << this->getKey() << "\": " << this->getValue()  << endl;
	}
	cout << "}" << endl;
}


