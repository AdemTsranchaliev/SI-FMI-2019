#include <iostream>
#include "MyString.hpp"
#pragma warning (disable:4996)
using namespace std;

MyString::MyString()
{
	this->str = new char[1];
	this->str = '\0';
}
MyString::MyString(const char* str)
{
	this->str = new char[strlen(str)+1];

	strncpy(this->str,str, strlen(str) + 1);
	this->str[strlen(str)] = '\0';
}
MyString::MyString(const MyString& str)
{
	this->str = new char[strlen(str.str) + 1];
	strncpy(this->str, str.str, strlen(str.str) + 1);
	this->str[strlen(str.str)] = '\0';
}
MyString::~MyString()
{
	delete[] this->str;
}

MyString& MyString::operator=(const MyString& str)
{
	if (this!=&str)
	{
		delete[] this->str;
		this->str = new char[strlen(str.str) + 1];
		strncpy(this->str, str.str, strlen(str.str) + 1);
		this->str[strlen(str.str)] = '\0';
	}
	return *this;
}

bool MyString::operator==(MyString& str)
{
	bool isEqual = true;
	if (str.length()==this->length())
	{
		int index = 0;
		while (str.str[index] != '\0')
		{
			if (str.str[index]!=this->str[index])
			{
				isEqual = false;
				break;
			}
			index++;

		}
	}
	else
	{
		isEqual = false;
	}

	return isEqual;

}
bool MyString::operator!=(MyString& str)
{
	bool isEqual = false;
	if (str.length() == this->length())
	{
		int index = 0;
		while (str.str[index] != '\0')
		{
			if (str.str[index] != this->str[index])
			{
				isEqual = true;
				break;
			}
			index++;

		}
	}
	else
	{
		isEqual = true;
	}


	return isEqual;
}
bool MyString::operator>(MyString& str)
{
	bool isThisBigger = false;
	if (this->length()>str.length())
	{
		isThisBigger = true;
	}
	else if (this->length() < str.length())
	{
		isThisBigger = false;
	}
	else
	{
		int index = 0;
		while (str.str[index] != '\0')
		{
			if (str.str[index] != this->str[index])
			{
				if (this->str[index] > str.str[index])
				{
					isThisBigger = true;
				}
				else
				{
					isThisBigger = false;
				}
				break;
			}
			index++;

		}
	}
	return isThisBigger;
}

bool MyString::operator<(MyString& str)
{
	bool isThisBigger = false;
	if (this->length() < str.length())
	{
		isThisBigger = true;
	}
	else if (this->length() > str.length())
	{
		isThisBigger = false;
	}
	else
	{
		int index = 0;
		while (str.str[index] != '\0')
		{
			if (str.str[index] != this->str[index])
			{
				if (this->str[index] < str.str[index])
				{
					isThisBigger = true;
				}
				else
				{
					isThisBigger = false;
				}
				break;
			}
			index++;
		}
	}
	return isThisBigger;
}

void MyString::append(char character)
{
	char* temp = new char[strlen(this->str) + 1];
	strncpy(temp, this->str, strlen(this->str) + 1);
	temp[strlen(this->str)] = '\0';

	delete[] this->str;
	this->str = new char[strlen(temp) + 2];
	strncpy(this->str, temp, strlen(temp) + 2);

	this->str[strlen(temp)] = character;
	this->str[strlen(temp)+1] = '\0';

	delete[] temp;

}
void MyString::print()
{
	int index = 0;
	while (this->str[index]!='\0')
	{
		cout << str[index];
		index++;
	}
}

int MyString::length()
{
	int index = 0;
	while (this->str[index] != '\0')
	{
		index++;
	}
	return index;
}
