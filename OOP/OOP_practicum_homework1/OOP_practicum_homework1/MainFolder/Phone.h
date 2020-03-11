#pragma once
#include "Product.h"

class Phone : Product
{
private:

	char model[50];
	char color[50];
	int yearOfProduction;
public:

	Phone();
	Phone(const char* model,const char* color, int yearOfProduction,int id ,const char* name,double price);
	Phone(Phone&);
	void setModel(const char* model);
	char* getModel();
	void setColor(const char* color);
	char* getColor();
	void setYearOfProduction(int year);
	int getYearOfProduction();

	void print();
	void addPhone(const char* model, const char* color, int yearOfProduction, int id, const char* name, double price);
};
