#pragma once
class MyString
{
private:
	char* str;
	int length();
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	~MyString();

	MyString& operator=(const MyString&);

	bool operator==(MyString&);
	bool operator!=(MyString&);
	bool operator>(MyString&);
	bool operator<(MyString&);

	void CopyCharArr(const char*);
	void append(char character);
	void print();

};

