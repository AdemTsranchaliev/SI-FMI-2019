#pragma once
#include "Product.hpp"


class Printer:public Product
{
private:
	char printingTechnology[50];
	char mainPrintingFormat[50];
	bool  oneOrManyColor;

public:

	Printer();
	Printer(const char* printingTechnology, const char* mainPrintingFormat,bool oneOrManyColor, int id , const char* name, double price);

	void setPrintingTechnology(const char*);
	char* getPrintingTechnology();
	void setMainPrintingFormat(const char*);
	char* getMainPrintingFormat();
	void setOneOrManyColors(bool);
	bool getOneOrManyColors();

	Printer& operator=(Printer&);

	void print();
	void addPrinter(const char* printingTechnology, const char* mainPrintingFormat, bool oneOrManyColor, int id, const char* name, double price);
};