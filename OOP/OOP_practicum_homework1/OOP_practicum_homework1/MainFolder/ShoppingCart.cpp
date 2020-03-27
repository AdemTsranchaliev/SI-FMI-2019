#include <iostream>

#include "ShoppingCart.hpp";

#pragma warning (disable:4996)

using namespace std;


//Constructor
ShoppingCart::ShoppingCart()
{
	this->productId = 0;
	this->quantity = 0;
	this->price = 0;

	this->productCategory = new char[1];
	this->productCategory[0] = '\0';

	this->name = new char[1];
	this->name[0] = '\0';
}

ShoppingCart::ShoppingCart(char* productCategory, int productId, int quantity, double price,char* name)
{
	this->productCategory = new char[strlen(productCategory)+1];
	strncpy(this->productCategory, productCategory, strlen(productCategory) + 1);

	this->name = new char[strlen(name) + 1];
	strncpy(this->name, name, strlen(name) + 1);

	this->productId = productId;
	this->quantity = quantity;
	this->price = price;
}

ShoppingCart::ShoppingCart(const ShoppingCart& shoppingCart)
{
	this->productCategory = new char[strlen(shoppingCart.productCategory) + 1];
	strncpy(this->productCategory, shoppingCart.productCategory, strlen(shoppingCart.productCategory) + 1);

	this->name = new char[strlen(shoppingCart.name) + 1];
	strncpy(this->name, shoppingCart.name, strlen(shoppingCart.name) + 1);

	this->setPrice(shoppingCart.getPrice());
	this->setProductId(shoppingCart.getProductId());
	this->setQuantity(shoppingCart.getQuantity());
}

//Destructor
ShoppingCart::~ShoppingCart()
{
	delete[] this->name;
	delete[] this->productCategory;
}

//Assignment operator
ShoppingCart& ShoppingCart::operator=(const ShoppingCart& prod)
{
	if (this != &prod)
	{
		delete[] this->name;
		delete[] this->productCategory;

		this->productCategory = new char[strlen(prod.productCategory) + 1];
		strncpy(this->productCategory, prod.productCategory, strlen(prod.productCategory) + 1);

		this->name = new char[strlen(prod.name) + 1];
		strncpy(this->name, prod.name, strlen(prod.name) + 1);

		this->setPrice(prod.getPrice());
		this->setProductId(prod.getProductId());
		this->setQuantity(prod.getQuantity());
	}

	return *this;
}

//Mutators
void ShoppingCart::setProductCategory(char* productCategory)
{
	delete[] this->productCategory;
	this->productCategory = new char[strlen(productCategory) + 1];
	strncpy(this->productCategory, productCategory, strlen(productCategory) + 1);
}
char* ShoppingCart::getProductCategory() const
{
	return this->productCategory;
}

void ShoppingCart::setProductId(int productId)
{
	this->productId = productId;

}
int ShoppingCart::getProductId() const
{
	return this->productId;
}

void ShoppingCart::setPrice(double price)
{
	this->price = price;

}
double ShoppingCart::getPrice() const
{
	return this->price;
}

void ShoppingCart::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strncpy(this->name, name, strlen(name) + 1);
}
char* ShoppingCart::getName() const
{
	return this->name;
}

void ShoppingCart::setQuantity(int quantity)
{
	this->quantity = quantity;

}
int ShoppingCart::getQuantity() const
{
	return this->quantity;
}


//Functions

void ShoppingCart::print()
{
	cout << "";
}