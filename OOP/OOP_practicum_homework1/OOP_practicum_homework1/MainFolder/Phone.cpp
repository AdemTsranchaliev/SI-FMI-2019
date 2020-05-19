#include <iostream>
#include <string>
#include "Phone.hpp"

#pragma warning (disable:4996)

//Constructors
Phone::Phone()
{
	this->color = "";

	this->model = "";

	this->yearOfProduction = 0;

}

Phone::Phone(string color,string model, int yearOfProduction, int id,string name, double price) : Product(id,price,name)
{

	this->color = color;

	this->model = model;

	this->yearOfProduction = yearOfProduction;
}

Phone::Phone(const Phone& phone) : Product(phone)
{
	this->yearOfProduction = phone.getYearOfProduction();

	this->color = phone.color;

	this->model = phone.model;

}


//Assignment operator
Phone& Phone::operator=(const Phone& phone)
{
	if (this != &phone)
	{

		this->setId(phone.getId());
		this->setName(phone.getName());
		this->setPrice(phone.getPrice());

		this->yearOfProduction = phone.getYearOfProduction();

		this->color = phone.color;

		this->model = phone.model;

	}
	return *this;
}

bool Phone::operator==(const Phone& phone)
{
	return this->getId() == phone.getId();
}

//Mutators
void Phone::setYearOfProduction(int year)
{
	this->yearOfProduction = year;
}
int Phone::getYearOfProduction() const
{
	return this->yearOfProduction;
}

void Phone::setColor(string color)
{
	this->color = color;
}
string Phone::getColor() const
{
	return this->color;
}

void Phone::setModel(string model)
{
	this->model = model;
}
string Phone::getModel() const
{
	return this->model;
}

void Phone::print()
{
	cout << this->getId() << " | " << this->getName() << " | " << this->getModel() << " | " << this->getColor() << " | " << this->getYearOfProduction() << " | " << this->getPrice()<<" leva"<<endl;
}

std::istream& operator>>(std::istream& in, Phone& phone)
{
	string model;
	string color;
	int yearOfProduction;
	double price;
	string name;

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Name: ";
	getline(in,name);
	cout << endl;
	phone.setName(name);

	cout << "Price: ";
	in >> price;
	cout << endl;
	phone.setPrice(price);

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Color: ";
	getline(in,color);
	cout << endl;
	phone.setColor(color);

	cout << "Model: ";
	getline(in,model);
	cout << endl;
	phone.setModel(model);

	cout << "Year of production: ";
	in >> yearOfProduction;
	cout << endl;
	phone.setYearOfProduction(yearOfProduction);

	cout << "You added successfully the product, press any key to continiue" << endl;

	return in;
}