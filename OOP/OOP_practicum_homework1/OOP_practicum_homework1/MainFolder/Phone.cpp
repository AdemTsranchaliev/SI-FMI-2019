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
	this->color[strlen(color)] = '\0';

	this->model = new char[strlen(model) + 1];
	strncpy(this->model, model, strlen(model) + 1);
	this->model[strlen(model)] = '\0';

	this->yearOfProduction = yearOfProduction;
}

Phone::Phone(const Phone& phone)
{
	this->setId(phone.getId());
	this->setName(phone.getName());
	this->setPrice(phone.getPrice());

	this->yearOfProduction = phone.getYearOfProduction();

	this->color = new char[strlen(phone.color) + 1];
	strncpy(this->color, color, strlen(phone.color) + 1);
	this->color[strlen(phone.color)] = '\0';

	this->model = new char[strlen(phone.model) + 1];
	strncpy(this->model, phone.model, strlen(phone.model) + 1);
	this->model[strlen(phone.model)] = '\0';

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
		this->color[strlen(phon.color)] = '\0';

		this->model = new char[strlen(phon.model) + 1];
		strncpy(this->model, phon.model, strlen(phon.model) + 1);
		this->model[strlen(phon.model)] = '\0';

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
	this->color[strlen(color)] = '\0';
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
	this->model[strlen(model)] = '\0';
}
char* Phone::getModel() const
{
	return this->model;
}

void Phone::print()
{
	cout << this->getId() << " | " << this->getName() << " | " << this->getModel() << " | " << this->getColor() << " | " << this->getYearOfProduction() << " | " << this->getPrice()<<" leva"<<endl;
}

std::istream& operator>>(std::istream& in, Phone& phone)
{
	char model[100];
	char color[100];
	int yearOfProduction;
	double price;
	char name[50];

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Name: ";
	in.get(name, 50);
	cout << endl;
	phone.setName(name);

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Price: ";
	in >> price;
	cout << endl;
	phone.setPrice(price);

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Color: ";
	in.get(color, 50);
	cout << endl;
	phone.setColor(color);

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Model: ";
	in.get(model, 50);
	cout << endl;
	phone.setModel(model);

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Year of production: ";
	in >> yearOfProduction;
	cout << endl;
	phone.setYearOfProduction(yearOfProduction);

	cout << "You added successfully the product, press any key to continiue" << endl;

	return in;
}