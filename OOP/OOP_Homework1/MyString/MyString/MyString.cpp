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
	this->str[strlen(str.str) + 1] = '\0';
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

//bool MyString::operator==(MyString&);
//bool MyString::operator!=(MyString&);
//bool MyString::operator>(MyString&);
//bool MyString::operator<(MyString&);

void MyString::append(char character)
{
	char* temp = new char[strlen(this->str) + 1];
	strncpy(temp, this->str, strlen(this->str) + 1);
	temp[strlen(this->str)] = '\0';

	delete[] this->str;
	this->str = new char[strlen(temp) + 2];
	strncpy(this->str, temp, strlen(temp) + 2);

	delete[] temp;

	this->str[strlen(this->str)-1] = character;
	this->str[strlen(this->str)] = '\0';

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