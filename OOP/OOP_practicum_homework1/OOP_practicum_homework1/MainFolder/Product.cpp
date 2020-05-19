#include <iostream>
#include "Product.hpp"
#pragma warning (disable:4996)


//Constructors
Product::Product()
{
	this->id = 0;
	this->price = 0;
	this->name = "";
}

Product::Product(int id, double price, string name,string cateogry)
{
	this->id = id;
	this->price = price;
	this->name = name;
	this->category = category;
}

Product::Product(const Product& product)
{
	this->id = product.id;
	this->price = product.price;
	this->name = product.name;
	this->category = product.category;

}


//Assignment operator
Product& Product::operator=(const Product& product)
{
	if (this!=&product)
	{
		this->id = product.id;
		this->price = product.price;
		this->name = product.name;
		this->category = product.category;

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

void Product::setName(string name)
{
	this->name = name;

}
string Product::getName() const
{
	return this->name;
}

void Product::setCategory(string category)
{
	this->category = category;
}
string Product::getCategory() const
{
	return this->category;
}

//Functions..