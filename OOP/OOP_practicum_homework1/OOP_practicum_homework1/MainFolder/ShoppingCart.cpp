#include <iostream>

#include "ShoppingCart.hpp";
using namespace std;

ShoppingCart::ShoppingCart(){}

ShoppingCart::ShoppingCart(char* productCategory, int productId, int quantity, double price,char* name)
{
	this->productCategory = productCategory;
	this->productId = productId;
	this->quantity = quantity;
	this->price = price;
	this->name = name;
}

void ShoppingCart::setProductCategory(char* productCategory)
{
	this->productCategory = productCategory;

}
char* ShoppingCart::getProductCategory()
{
	return this->productCategory;

}
void ShoppingCart::setProductId(int productId)
{
	this->productId = productId;

}
int ShoppingCart::getProductId()
{
	return this->productId;
}

void ShoppingCart::setPrice(double price)
{
	this->price = price;

}
double ShoppingCart::getPrice()
{
	return this->price;
}

void ShoppingCart::setName(char* name)
{
	this->name = name;

}
char* ShoppingCart::getName()
{
	return this->name;
}
void ShoppingCart::setQuantity(int quantity)
{
	this->quantity = quantity;

}
int ShoppingCart::getQuantity()
{
	return this->quantity;
}

ShoppingCart& ShoppingCart::operator=(ShoppingCart& prod)
{
	if (this!=&prod)
	{
		this->setName(prod.getName());
		this->setPrice(prod.getPrice());
		this->setProductCategory(prod.getProductCategory());
		this->setProductId(prod.getProductId());
		this->setQuantity(prod.getQuantity());

		return *this;
	}
}
