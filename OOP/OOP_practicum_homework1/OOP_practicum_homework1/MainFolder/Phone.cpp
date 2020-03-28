#include <iostream>
#include "Phone.hpp"
#pragma warning (disable:4996)
using namespace std;

//Constructors
Phone::Phone()
{
	this->color = new char[1];
	this->color[0] = '\0';

	this->model = new char[1];
	this->model[0] = '\0';

	this->yearOfProduction = 0;

}

Phone::Phone(const char* color,const char* model, int yearOfProduction, int id,const char* name, double price) 
{
	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	this->color = new char[strlen(color)+1];
	strncpy(this->color, color, strlen(color) + 1);

	this->model = new char[strlen(model) + 1];
	strncpy(this->model, model, strlen(model) + 1);

	this->yearOfProduction = 0;
}

Phone::Phone(const Phone& phone)
{
	this->setId(phone.getId());
	this->setName(phone.getName());
	this->setPrice(phone.getPrice());

	this->yearOfProduction = phone.getYearOfProduction();

	this->color = new char[strlen(phone.color) + 1];
	strncpy(this->color, color, strlen(phone.color) + 1);

	this->model = new char[strlen(phone.model) + 1];
	strncpy(this->model, phone.model, strlen(phone.model) + 1);
}

//Destructor
Phone::~Phone()
{
	delete[] color;
	delete[] model;
}

//Assignment operator
Phone& Phone::operator=(const Phone& phon)
{
	if (this != &phon)
	{
		delete[] this->color;
		delete[] this->model;

		this->setId(phon.getId());
		this->setName(phon.getName());
		this->setPrice(phon.getPrice());

		this->yearOfProduction = phon.getYearOfProduction();

		this->color = new char[strlen(phon.color) + 1];
		strncpy(this->color, phon.color, strlen(phon.color) + 1);

		this->model = new char[strlen(phon.model) + 1];
		strncpy(this->model, phon.model, strlen(phon.model) + 1);


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

void Phone::setColor(const char* color)
{
	delete[] this->color;
	this->color = new char[strlen(color) + 1];
	strncpy(this->color, color, strlen(color) + 1);
}
char* Phone::getColor() const
{
	return this->color;
}

void Phone::setModel(const char* model)
{
	delete[] this->model;
	this->model = new char[strlen(model) + 1];
	strncpy(this->model, model, strlen(model) + 1);
}
char* Phone::getModel() const
{
	return this->model;
}

void Phone::print()
{
	cout << this->getId() << " | " << this->getName() << " | " << this->getModel() << " | " << this->getColor() << " | " << this->getYearOfProduction() << " | " << this->getPrice()<<" leva"<<endl;
}
