#pragma once
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class File
{
private:
	string name;
	Date date;
	double megaBytes;
	string extension;
public:
	File();
	File(const File& file);
	File(string name, double megaBytes, string extension);
	File(string name, double megaBytes);

	void setName(string name);
	string getName() const;

	Date& getDate();

	void setMegaBytes(double mb);
	double getMegaBytes() const;

	void setExtension(string extension);
	string getExtension() const;
};

