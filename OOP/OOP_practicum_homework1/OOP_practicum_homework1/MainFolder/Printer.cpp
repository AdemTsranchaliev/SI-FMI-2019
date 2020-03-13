
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

void Printer::print()
{
	if (this->getOneOrManyColors()==true)
	{
		cout << this->getId() << " | " << this->getName() << " | " << this->getPrintingTechnology() << " | white and black | " << this->getPrice() << endl;
	}
	else
	{
		cout << this->getId() << " | " << this->getName() << " | " << this->getPrintingTechnology() << " | " << this->getMainPrintingFormat() << " | many colors | " << this->getPrice() << endl;

	}
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

Printer& Printer::operator=(Printer& print)
{
	if (this != &print)
	{
		this->setId(print.getId());
		this->setName(print.getName());
		this->setPrice(print.getPrice());

		strcpy_s(this->printingTechnology, print.getPrintingTechnology());
		strcpy_s(this->mainPrintingFormat, print.getMainPrintingFormat());
		this->oneOrManyColor = print.getOneOrManyColors();

		return *this;
	}
}