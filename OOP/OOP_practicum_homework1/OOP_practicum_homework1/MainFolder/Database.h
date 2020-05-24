#pragma once
#include <iostream>
#include "List.hpp"
#include <fstream>
#include <string>

#include "Phone.hpp"
#include "Laptop.hpp"
#include "Printer.hpp"

using namespace std;

class Database
{
public:

	template <typename T>
	void SaveToDatabase(T& obj);
	template <typename T>
	void ReadFromDb(T& obj);

	List<string>* split(string text,char separator);


};


template <typename T>
void Database::SaveToDatabase(T& obj)
{
	string className = ((string)(typeid(obj).name()));
	string fileName = className.substr(className.find(" ") + 1) + ".txt";
	fstream file;
	file.open(fileName, ios::app);
	if (!file.is_open())
	{
		file.open(fileName, ios::out);

	}
	file << obj;
	
	file.close();
}


template <typename T>
void Database::ReadFromDb(T& obj)
{
	string className = ((string)(typeid(obj).name()));
	string fileName = className.substr(className.find(" ") + 1) + ".txt";

	fstream file;
	string text="";

	file.open(fileName, ios::in);

	char c;

	while (file.get(c))
	{
		text += c;
	}

	List<string>* tempList = this->split(text,'\n');

	if (className=="class Laptop")
	{
	     List<Laptop> laptops;
		for (int i = 0; i < tempList->Count(); i++)
		{
			List<string> *temp = this->split(tempList->getAt(i),'|');
			for (int i = 0; i < temp->Count(); i++)
			{
				cout << temp->getAt(i)<<endl;
			}
			string& processor = temp->getAt(3);
			int memory = stoi(temp->getAt(2));
			string videoCart = temp->getAt(4);
			int id = stoi(temp->getAt(0));
			string name = temp->getAt(1);
			double price = stoi(temp->getAt(5));
			Laptop laptop(processor, memory, videoCart, id, name, price,"Laptop");
			laptops.add(laptop);
		}
	}

}


