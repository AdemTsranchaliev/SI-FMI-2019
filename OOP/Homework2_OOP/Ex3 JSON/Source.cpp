#include <iostream>
#include "JsonObject.h"
#include "JsonArray.h"

using namespace std;
#pragma warning (disable:4996)
int main()
{
	JsonObject<char> obj1("name",'t');

	JsonArray<char> arr;

	arr.add(obj1);
	arr.add("Hello", 't');

	cout << arr.getValueByKey("Hello");

	arr.saveToFile("C:/Users/Asus/Desktop/SI-FMI-2019/OOP/Homework2_OOP/Ex3 JSON/Debug/test.txt");
	return 0;
}
