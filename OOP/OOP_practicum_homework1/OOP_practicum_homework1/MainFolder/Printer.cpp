
#include <iostream>
#include <cstring>

#include "Printer.h"

using namespace std;


Printer::Printer() {}

Printer::Printer(char* printingTechnology, char* mainPrintingFormat, bool oneOrManyColor, int id, char* name, double price)
{

	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	strcpy_s(this->printingTechnology, printingTechnology);
	strcpy_s(this->mainPrintingFormat, mainPrintingFormat);
	this->oneOrManyColor = oneOrManyColor;
}

void Printer::setPrintingTechnology(char* printingTechnology)
{
	strcpy_s(this->printingTechnology, printingTechnology);
}
char* Printer::getPrintingTechnology()
{
	return this->printingTechnology;
}

void Printer::setMainPrintingFormat(char* mainPrintingFormat)
{
	strcpy_s(this->mainPrintingFormat, mainPrintingFormat);
}
char* Printer::getMainPrintingFormat()
{
	return this->mainPrintingFormat;
}

void Printer::setOneOrManyColors(bool oneOrManyColors)
{
	this->oneOrManyColor = oneOrManyColor;
}
bool Printer::getOneOrManyColors()
{
	return this->oneOrManyColor;
}

void Printer::addPrinter(char* printingTechnology, char* mainPrintingFormat, bool oneOrManyColor, int id, char* name, double price)
{

	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	strcpy_s(this->printingTechnology, printingTechnology);
	strcpy_s(this->mainPrintingFormat, mainPrintingFormat);
	this->oneOrManyColor = oneOrManyColor;
}