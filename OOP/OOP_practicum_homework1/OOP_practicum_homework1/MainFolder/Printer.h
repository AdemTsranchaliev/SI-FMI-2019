#pragma once
#include "Product.h"


class Printer:Product
{
private:
	char printingTechnology[50];
	char mainPrintingFormat[50];
	bool  oneOrManyColor;

public:

	Printer();
	Printer(char* printingTechnology,char* mainPrintingFormat,bool oneOrManyColor, int id , char* name, double price);

	void setPrintingTechnology(char*);
	char* getPrintingTechnology();
	void setMainPrintingFormat(char*);
	char* getMainPrintingFormat();
	void setOneOrManyColors(bool);
	bool getOneOrManyColors();

	void addPrinter(char* printingTechnology, char* mainPrintingFormat, bool oneOrManyColor, int id, char* name, double price);
};