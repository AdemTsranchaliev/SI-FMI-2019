#include <iostream>

#include "Phone.hpp"

using namespace std;

Phone::Phone(){}

Phone::Phone(const char* color,const char* model, int yearOfProduction, int id,const char* name, double price) 
{
	this->setId(id);
	this->setName(name);
	this->setPrice(price);

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

void Phone::setColor(const char* color)
{
	strcpy_s(this->color,color);
}

char* Phone::getColor()
{
	return this->color;
}

void Phone::setModel(const char* model)
{
	strcpy_s(this->model, model);
}

char* Phone::getModel()
{
	return this->model;
}

void Phone::addPhone(const char* color, const char* model, int yearOfProduction, int id, const char* name, double price)
{
	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	this->yearOfProduction = yearOfProduction;
	strcpy_s(this->color, color);
	strcpy_s(this->model, model);
}

void Phone::print()
{
	cout << this->getId() << " | " << this->getName() << " | " << this->getModel() << " | " << this->getColor() << " | " << this->getYearOfProduction() << " | " << this->getPrice()<<" leva"<<endl;
}

Phone& Phone::operator=(Phone& phon)
{
	if (this != &phon)
	{
		this->setId(phon.getId());
		this->setName(phon.getName());
		this->setPrice(phon.getPrice());

		this->yearOfProduction = phon.getYearOfProduction();
		strcpy_s(this->color, phon.getColor());
		strcpy_s(this->model, phon.getModel());

		return *this;
	}
}