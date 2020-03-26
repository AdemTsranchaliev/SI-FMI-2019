#pragma once
#include "Product.hpp"


class Printer:public Product
{
private:
	char* printingTechnology;
	char* mainPrintingFormat;
	bool  oneOrManyColor;

public:

	Printer();
	Printer(const char* printingTechnology, const char* mainPrintingFormat,bool oneOrManyColor, int id , const char* name, double price);
	~Printer();

	void setPrintingTechnology(const char*);
	char* getPrintingTechnology() const;
	void setMainPrintingFormat(const char*);
	char* getMainPrintingFormat() const;
	void setOneOrManyColors(bool);
	bool getOneOrManyColors() const;

	Printer& operator=(Printer&);

	void print();
	void addPrinter(const char* printingTechnology, const char* mainPrintingFormat, bool oneOrManyColor, int id, const char* name, double price);
};