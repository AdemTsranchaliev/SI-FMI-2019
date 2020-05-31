#include "Folder.h"


Folder::Folder()
{
	this->name = "";
	this->dateOfCreation = Date("now");
}
Folder::Folder(string name)
{
	this->name = name;
}


void Folder::setName(string name)
{
	this->name = name;
}
string Folder::getName() const
{
	return this->name;
}

Date& Folder::getDateOfCreation()
{
	return this->dateOfCreation;
}

void Folder::addFile(File& file)
{
	this->files.push_back(&file);
}

vector<File*>& Folder::getFiles()
{
	return this->files;
}