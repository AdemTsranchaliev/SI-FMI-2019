#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "File.h"

using namespace std;

class Folder
{
private:
	string name;
	Date dateOfCreation;
	vector<File*> files;
public:
	Folder();
	Folder(string name);


	void setName(string name);
	string getName() const;

	Date& getDateOfCreation();

	void addFile(File& file);
	vector<File*>& getFiles();
};

