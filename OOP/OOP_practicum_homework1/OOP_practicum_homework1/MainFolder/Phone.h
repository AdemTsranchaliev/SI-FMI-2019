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
	Phone(char*, char*, int,int,char*,double);

	void setModel(char* model);
	char* getModel();
	void setColor(char* color);
	char* getColor();
	void setYearOfProduction(int year);
	int getYearOfProduction();
};
