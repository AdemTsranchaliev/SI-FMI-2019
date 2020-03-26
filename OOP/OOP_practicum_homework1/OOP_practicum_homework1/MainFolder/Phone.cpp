#include <iostream>
#include "CommonFunctions.h"
#include "Phone.hpp"

using namespace std;

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
	CopyCharArr(this->color, color, strlen(color) + 1);

	this->model = new char[strlen(model) + 1];
	CopyCharArr(this->model, model, strlen(model) + 1);

	this->yearOfProduction = 0;
}


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
	CopyCharArr(this->color, color, strlen(color) + 1);
}

char* Phone::getColor() const
{
	return this->color;
}

void Phone::setModel(const char* model)
{
	delete[] this->model;
	this->model = new char[strlen(model) + 1];
	CopyCharArr(this->model, model, strlen(model) + 1);
}

char* Phone::getModel() const
{
	return this->model;
}

void Phone::addPhone(const char* color, const char* model, int yearOfProduction, int id, const char* name, double price)
{
	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	this->yearOfProduction = yearOfProduction;
	this->color = new char[strlen(color) + 1];
	CopyCharArr(this->color, color, strlen(color) + 1);

	this->model = new char[strlen(model) + 1];
	CopyCharArr(this->model, model, strlen(model) + 1);
}

void Phone::print()
{
	cout << this->getId() << " | " << this->getName() << " | " << this->getModel() << " | " << this->getColor() << " | " << this->getYearOfProduction() << " | " << this->getPrice()<<" leva"<<endl;
}

Phone& Phone::operator=(Phone& phon)
{
	if (this != &phon)
	{
		delete[] color;
		delete[] model;

		this->setId(phon.getId());
		this->setName(phon.getName());
		this->setPrice(phon.getPrice());

		this->yearOfProduction = phon.getYearOfProduction();

		this->color = new char[strlen(color) + 1];
		CopyCharArr(this->color, color, strlen(color) + 1);

		this->model = new char[strlen(model) + 1];
		CopyCharArr(this->model, model, strlen(model) + 1);

		return *this;
	}
}