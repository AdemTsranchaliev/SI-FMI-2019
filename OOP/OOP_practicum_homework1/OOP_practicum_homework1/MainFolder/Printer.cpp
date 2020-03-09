#include <iostream>

#include "Printer.h"

using namespace std;

Printer::Printer() {}

Printer::Printer(char* printingTechnology, char* mainPrintingFormat, bool oneOrManyColor, int id, char* name, double price)
{

	Product(id, price, name);
	
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
	return this->yearOfProduction;
}
