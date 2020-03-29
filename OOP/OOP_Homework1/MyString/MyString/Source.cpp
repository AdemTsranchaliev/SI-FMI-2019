#include <iostream>
#include "MyString.hpp"

using namespace std;

int main()
{
	char arr[] = "sd";
	MyString str(arr);

	str.print();
	cout << endl;

	str.append('!');

	str.print();

	cout << endl;


	system("pause");
	return 0;
}



