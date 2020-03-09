#include <iostream>

#include "Phone.h"

using namespace std;

Phone::Phone(){}

Phone::Phone(char* color, char* model, int yearOfProduction, int id, char* name, double price) 
{
	Product(id,price,name);
	this->yearOfProduction = yearOfProduction;
	strcpy_s(this->color,color);
	strcpy_s(this->model, model);
}

void Phone::setYearOfProduction(int year)
{
	this->yearOfProduction = year;
}
int Phone::getYearOfProduction()
{
	return this->yearOfProduction;
}

void Phone::setColor(char* color)
{
	strcpy_s(this->color,color);
}

char* Phone::getColor()
{
	return this->color;
}

void Phone::setModel(char* model)
{
	strcpy_s(this->model, model);
}

char* Phone::getModel()
{
	return this->model;
}