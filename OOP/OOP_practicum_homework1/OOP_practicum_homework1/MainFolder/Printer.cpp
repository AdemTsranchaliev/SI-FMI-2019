#include <iostream>
#include <string>
#pragma warning (disable:4996)
#include "Printer.hpp"

//Constructors
Printer::Printer() 
{
	this->printingTechnology = "";

	this->mainPrintingFormat = "";

	oneOrManyColor = false;
}

Printer::Printer(string printingTechnology, string mainPrintingFormat, bool oneOrManyColor, int id, string name, double price) : Product(id,price,name)
{
	this->printingTechnology = printingTechnology;

	this->mainPrintingFormat = mainPrintingFormat;

	this->oneOrManyColor = oneOrManyColor;
}

Printer::Printer(const Printer& printer) : Product(printer)
{

	this->printingTechnology = printer.printingTechnology;

	this->mainPrintingFormat = printer.mainPrintingFormat;

	this->oneOrManyColor = printer.getOneOrManyColors();
}

//Assignment operator
Printer& Printer::operator=(const Printer& print)
{
	if (this != &print)
	{
		this->setId(print.getId());
		this->setName(print.getName());
		this->setPrice(print.getPrice());

		this->printingTechnology = print.printingTechnology;

		this->mainPrintingFormat = print.mainPrintingFormat;

		this->oneOrManyColor = print.getOneOrManyColors();

	}
	return *this;
}

bool Printer::operator==(const Printer& printer)
{
	return this->getId() == printer.getId();
}

//Mutators
void Printer::setPrintingTechnology(string printingTechnology)
{
	this->printingTechnology = printingTechnology;

}
string Printer::getPrintingTechnology() const
{
	return this->printingTechnology;
}

void Printer::setMainPrintingFormat(string mainPrintingFormat)
{
	this->mainPrintingFormat = mainPrintingFormat;

}
string Printer::getMainPrintingFormat() const
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
	string printingTechnology;
	string mainPrintingFormat;
	bool oneOrManyColors;
	double price;
	string name;

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Name: ";
	getline(in,name);
	cout << endl;
	printer.setName(name);

	cout << "Price: ";
	in >> price;
	cout << endl;
	printer.setPrice(price);

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Main printing format: ";
	getline(in,mainPrintingFormat);
	cout << endl;
	printer.setMainPrintingFormat(mainPrintingFormat);

	cout << "Printing technology: ";
	getline(in,printingTechnology);
	cout << endl;
	printer.setPrintingTechnology(printingTechnology);

	cout << "One or many colors(1 for one,0 for many): ";
	in >> oneOrManyColors;
	cout << endl;
	printer.setOneOrManyColors(oneOrManyColors);

	cout << "You added successfully the product, press any key to continiue" << endl;

	return in;
}


