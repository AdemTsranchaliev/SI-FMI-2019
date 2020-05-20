#include <iostream>
#include <string>

#include "ShoppingCart.hpp";

#pragma warning (disable:4996)

//Constructor
ShoppingCart::ShoppingCart()
{
	this->productId = 0;
	this->quantity = 0;
	this->price = 0;
	this->productCategory = "";

	this->name = "";
}

ShoppingCart::ShoppingCart(string productCategory, int productId, int quantity, double price,string name)
{
	this->name = name;
	this->productCategory = productCategory;
	this->productId = productId;
	this->quantity = quantity;
	this->price = price;
}

ShoppingCart::ShoppingCart(const ShoppingCart& shoppingCart)
{
	this->name = shoppingCart.name;
	this->productCategory = shoppingCart.productCategory;
	this->setPrice(shoppingCart.getPrice());
	this->setProductId(shoppingCart.getProductId());
	this->setQuantity(shoppingCart.getQuantity());
}

//Assignment operator
ShoppingCart& ShoppingCart::operator=(const ShoppingCart& prod)
{
	if (this != &prod)
	{
		this->name = prod.name;

		this->productCategory = prod.productCategory;
		this->setPrice(prod.getPrice());
		this->setProductId(prod.getProductId());
		this->setQuantity(prod.getQuantity());
	}

	return *this;
}

//Mutators
void ShoppingCart::setProductCategory(string productCategory)
{
	this->productCategory=productCategory;

}
string ShoppingCart::getProductCategory() const
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

void ShoppingCart::setName(string name)
{
	this->name = name;

}
string ShoppingCart::getName() const
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
	cout << getProductId() << " | " << getProductCategory() << " | " << getName() << " | " << getPrice() << " | " << getQuantity() << " | " << getPrice()*getQuantity() << " leva " << endl;
}