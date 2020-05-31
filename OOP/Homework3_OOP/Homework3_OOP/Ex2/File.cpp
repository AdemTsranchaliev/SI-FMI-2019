#include "File.h"


File::File()
{
	this->name = "";
	this->extension = "";
	this->megaBytes = 0;
	Date date1("now");
	this->date = date1;
}
File::File(const File& file)
{
	this->name = file.name;
	this->extension = file.extension;
	this->megaBytes = file.megaBytes;
	this->date = file.date;
}
File::File(string name, double megaBytes, string extension)
{
	this->name = name;
	this->extension = extension;
	this->megaBytes = megaBytes;
	Date date1("now");
	this->date = date1;
}
File::File(string name, double megaBytes)
{
	this->name = name;
	this->megaBytes = megaBytes;
	Date date1("now");
	this->date = date1;
}

void File::setName(string name)
{
	this->name = name;
}
string File::getName() const
{
	return this->name;
}

Date& File::getDate()
{
	return date;
}

void File::setMegaBytes(double mb)
{
	this->megaBytes = mb;
}
double File::getMegaBytes() const
{
	return this->megaBytes;
}

void File::setExtension(string extension)
{
	this->extension = extension;
}
string File::getExtension() const
{
	return this->extension;
}