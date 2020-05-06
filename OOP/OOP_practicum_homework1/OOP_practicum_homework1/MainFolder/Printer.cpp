
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
#include "Printer.hpp"

using namespace std;


//Constructors
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
	strncpy(this->printingTechnology,printingTechnology, strlen(printingTechnology) + 1);
	this->printingTechnology[strlen(printingTechnology)] = '\0';

	this->mainPrintingFormat = new char[strlen(mainPrintingFormat) + 1];
	strncpy(this->mainPrintingFormat, mainPrintingFormat, strlen(mainPrintingFormat) + 1);
	this->mainPrintingFormat[strlen(mainPrintingFormat)] = '\0';


	this->oneOrManyColor = oneOrManyColor;
}

Printer::Printer(const Printer& printer)
{
	this->setId(printer.getId());
	this->setName(printer.getName());
	this->setPrice(printer.getPrice());

	this->printingTechnology = new char[strlen(printer.printingTechnology) + 1];
	strncpy(this->printingTechnology, printer.printingTechnology, strlen(printer.printingTechnology) + 1);
	this->printingTechnology[strlen(printer.printingTechnology)] = '\0';

	this->mainPrintingFormat = new char[strlen(printer.mainPrintingFormat) + 1];
	strncpy(this->mainPrintingFormat, printer.mainPrintingFormat, strlen(printer.mainPrintingFormat) + 1);
	this->mainPrintingFormat[strlen(printer.mainPrintingFormat)] = '\0';

	this->oneOrManyColor = printer.getOneOrManyColors();
}

//Destructor
Printer::~Printer()
{
	delete[] this->printingTechnology;
	delete[] this->mainPrintingFormat;
}

//Assignment operator
Printer& Printer::operator=(const Printer& print)
{
	if (this != &print)
	{
		delete[] this->printingTechnology;
		delete[] this->mainPrintingFormat;

		this->setId(print.getId());
		this->setName(print.getName());
		this->setPrice(print.getPrice());

		this->printingTechnology = new char[strlen(print.printingTechnology) + 1];
		strncpy(this->printingTechnology, print.printingTechnology, strlen(print.printingTechnology) + 1);
		this->printingTechnology[strlen(print.printingTechnology)] = '\0';

		this->mainPrintingFormat = new char[strlen(print.mainPrintingFormat) + 1];
		strncpy(this->mainPrintingFormat, print.mainPrintingFormat, strlen(print.mainPrintingFormat) + 1);
		this->mainPrintingFormat[strlen(print.mainPrintingFormat)] = '\0';

		this->oneOrManyColor = print.getOneOrManyColors();

	}
	return *this;
}

bool Printer::operator==(const Printer& printer)
{
	return this->getId() == printer.getId();
}

//Mutators
void Printer::setPrintingTechnology(const char* printingTechnology)
{
	delete[] this->printingTechnology;
	this->printingTechnology = new char[strlen(printingTechnology) + 1];
	strncpy(this->printingTechnology, printingTechnology, strlen(printingTechnology) + 1);
	this->printingTechnology[strlen(printingTechnology)] = '\0';

}
char* Printer::getPrintingTechnology() const
{
	return this->printingTechnology;
}

void Printer::setMainPrintingFormat(const char* mainPrintingFormat)
{
	delete[] this->mainPrintingFormat;
	this->mainPrintingFormat = new char[strlen(mainPrintingFormat) + 1];
	strncpy(this->mainPrintingFormat, mainPrintingFormat, strlen(mainPrintingFormat) + 1);
	this->mainPrintingFormat[strlen(mainPrintingFormat)] = '\0';

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

//Functions
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
std::istream& operator>>(std::istream& in, Printer& printer)
{
	char printingTechnology[100];
	char mainPrintingFormat[100];
	bool oneOrManyColors;
	double price;
	char name[50];

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Name: ";
	in.get(name, 50);
	cout << endl;
	printer.setName(name);

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Price: ";
	in >> price;
	cout << endl;
	printer.setPrice(price);

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Main printing format: ";
	in.get(mainPrintingFormat, 50);
	cout << endl;
	printer.setMainPrintingFormat(mainPrintingFormat);

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Printing technology: ";
	in.get(printingTechnology, 50);
	cout << endl;
	printer.setPrintingTechnology(printingTechnology);

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "One or many colors(1 for one,0 for many): ";
	in >> oneOrManyColors;
	cout << endl;
	printer.setOneOrManyColors(oneOrManyColors);

	cout << "You added successfully the product, press any key to continiue" << endl;

	return in;
}


