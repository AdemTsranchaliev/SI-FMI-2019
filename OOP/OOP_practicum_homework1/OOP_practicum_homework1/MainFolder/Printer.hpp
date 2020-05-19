#pragma once
#include "Product.hpp"
using namespace std;


class Printer:public Product
{
private:
	string printingTechnology;
	string mainPrintingFormat;
	bool  oneOrManyColor;

public:

	Printer();
	Printer(string printingTechnology, string mainPrintingFormat,bool oneOrManyColor, int id , string name, double price, string category);
	Printer(const Printer& printer);

	Printer& operator=(const Printer& printer);
	bool operator==(const Printer& printer);

	void setPrintingTechnology(string);
	string getPrintingTechnology() const;
	void setMainPrintingFormat(string);
	string getMainPrintingFormat() const;
	void setOneOrManyColors(bool);
	bool getOneOrManyColors() const;

	friend std::istream& operator>>(std::istream& in, Printer& o);

	void print();
};