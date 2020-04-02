#include <iostream>
#include "MyString.hpp"

using namespace std;

int main()
{
	MyString str1("Hello World!");
	MyString str2("Hello World");

	cout<< (str1>str2) << endl;
	cout<<(str1<str2)<<endl;
	system("pause");
	return 0;
}



