#include <iostream>
#include "MyString.hpp"


using namespace std;
#pragma warning (disable:4996)
int main()
{


	MyString temp("Hello world");
	cout << temp;
	temp.append('!');
	cout << temp;


	MyString str("test");
	cout << str;
	cin >> str;
	cout << str;


	system("pause");
	return 0;
}
