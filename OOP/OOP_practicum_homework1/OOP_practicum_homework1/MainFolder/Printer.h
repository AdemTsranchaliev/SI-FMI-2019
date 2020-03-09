#pragma once
#include "Product.h"


class Printer:Product
{
private:
	char* printingTechnology;
	char* mainPrintingFormat;
	bool  oneOrManyColor;

public:

	Printer();
	Printer(char* printingTechnology,char* mainPrintingFormat,bool oneOrManyColor, int, char*, double);

	void setPrintingTechnology(char*);
	char* getPrintingTechnology();
	void setPrintingTechnology(char*);
	char* getPrintingTechnology();

};