
#include <iostream>
#include <cstring>
#include "CommonFunctions.h"

#include "Printer.hpp"

using namespace std;


Printer::Printer() 
{
	this->printingTechnology = new char[1];
	this->printingTechnology[0] = '\0';

	this->mainPrintingFormat = new char[1];
	this->mainPrintingFormat[0] = '\0';

	oneOrManyColor = false;
}

Printer::Printer(const char* printingTechnology, const char* mainPrintingFormat, bool oneOrManyColor, int id, const char* name, double price)
{

	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	this->printingTechnology = new char[strlen(printingTechnology)+1];
	CopyCharArr(this->printingTechnology,printingTechnology, strlen(printingTechnology) + 1);

	this->mainPrintingFormat = new char[strlen(mainPrintingFormat) + 1];
	CopyCharArr(this->mainPrintingFormat, mainPrintingFormat, strlen(mainPrintingFormat) + 1);


	this->oneOrManyColor = oneOrManyColor;
}

Printer::~Printer()
{
	delete[] this->printingTechnology;
	delete[] this->mainPrintingFormat;
}


void Printer::setPrintingTechnology(const char* printingTechnology)
{
	delete[] this->printingTechnology;
	this->printingTechnology = new char[strlen(printingTechnology) + 1];
	CopyCharArr(this->printingTechnology, printingTechnology, strlen(printingTechnology) + 1);
}
char* Printer::getPrintingTechnology() const
{
	return this->printingTechnology;
}

void Printer::setMainPrintingFormat(const char* mainPrintingFormat)
{
	delete[] this->mainPrintingFormat;
	this->mainPrintingFormat = new char[strlen(mainPrintingFormat) + 1];
	CopyCharArr(this->mainPrintingFormat, mainPrintingFormat, strlen(mainPrintingFormat) + 1);
}
char* Printer::getMainPrintingFormat() const
{
	return this->mainPrintingFormat;
}

void Printer::setOneOrManyColors(bool oneOrManyColors)
{
	this->oneOrManyColor = oneOrManyColor;
}
bool Printer::getOneOrManyColors() const
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

void Printer::addPrinter(const char* printingTechnology, const char* mainPrintingFormat, bool oneOrManyColor, int id, const char* name, double price)
{
	delete[] this->printingTechnology;
	delete[] this->mainPrintingFormat;


	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	this->printingTechnology = new char[strlen(printingTechnology) + 1];
	CopyCharArr(this->printingTechnology, printingTechnology, strlen(printingTechnology) + 1);

	this->mainPrintingFormat = new char[strlen(mainPrintingFormat) + 1];
	CopyCharArr(this->mainPrintingFormat, mainPrintingFormat, strlen(mainPrintingFormat) + 1);

	this->oneOrManyColor = oneOrManyColor;
}

Printer& Printer::operator=(Printer& print)
{
	if (this != &print)
	{
		delete[] this->printingTechnology;
		delete[] this->mainPrintingFormat;
		this->setId(print.getId());
		this->setName(print.getName());
		this->setPrice(print.getPrice());

		this->printingTechnology = new char[strlen(printingTechnology) + 1];
		CopyCharArr(this->printingTechnology, printingTechnology, strlen(printingTechnology) + 1);

		this->mainPrintingFormat = new char[strlen(mainPrintingFormat) + 1];
		CopyCharArr(this->mainPrintingFormat, mainPrintingFormat, strlen(mainPrintingFormat) + 1);

		this->oneOrManyColor = print.getOneOrManyColors();

	}
	return *this;
}