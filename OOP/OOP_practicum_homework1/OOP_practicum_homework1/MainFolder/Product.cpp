#include <iostream>
#include "Product.hpp"
#pragma warning (disable:4996)

using namespace std;

//Constructors
Product::Product()
{
	this->id = 0;
	this->price = 0;
	this->name = new char[1];
	this->name[0] = '\0';
}

Product::Product(int id, double price,const char* name)
{
	this->id = id;
	this->price = price;
	this->name = new char[strlen(name)+1];
	strncpy(this->name,name,strlen(name)+1);
	this->name[strlen(name)] = '\0';

}

Product::Product(const Product& product)
{
	this->id = product.id;
	this->price = product.price;
	this->name = new char[strlen(product.name) + 1];
	strncpy(this->name, product.name, strlen(product.name) + 1);
	this->name[strlen(product.name)] = '\0';

}

//Destructor
Product::~Product()
{
	delete[] name;
}

//Assignment operator
Product& Product::operator=(const Product& product)
{
	if (this!=&product)
	{
		delete[] this->name;

		this->id = product.id;
		this->price = product.price;
		this->name = new char[strlen(product.name) + 1];
		strncpy(this->name, product.name, strlen(product.name) + 1);
		this->name[strlen(product.name)] = '\0';

	}
	return *this;
}

//Mutators
void Product::setId(int id)
{
	this->id = id;
}
int Product::getId() const
{
	return this->id;
}

void Product::setPrice(double price)
{
	this->price = price;
}
double Product::getPrice() const
{
	return this->price;
}

void Product::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strncpy(this->name, name, strlen(name) + 1);
	this->name[strlen(name)] = '\0';

}
char* Product::getName() const
{
	return this->name;
}

//Functions..