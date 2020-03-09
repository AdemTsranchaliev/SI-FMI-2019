#include <iostream>

#include "Product.h"


using namespace std;

Product::Product(){}

Product::Product(int id, double price,const char* name)
{
	this->id = id;
	this->price = price;
	strcpy_s(this->name,name);
}


void Product::setId(int id)
{
	this->id = id;
}

int Product::getId()
{
	return this->id;
}

void Product::setPrice(double price)
{
	this->price = price;
}

double Product::getPrice()
{
	return this->price;
}

void Product::setName(const char* name)
{
	strcpy_s(this->name,name);
}

char* Product::getName()
{
	return this->name;
}
