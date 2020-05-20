

#include <iostream>
#include <fstream>
#include <string>

#include "Database.h"

using namespace std;



Database::Database()
{

}



void Database::SaveToDatabase(Phone& obj)
{

	string className = ((string)(typeid(obj).name()));
	string fileName = className.substr(className.find(" ") + 1) + ".txt";

	fstream file(fileName, ios::out);

	if (!file.is_open())
	{
		ofstream newFile(fileName);
		newFile.close();
		file.open(fileName, ios::out);
	}


	file << obj.print();
	file << obj.print();

	file.close();
}