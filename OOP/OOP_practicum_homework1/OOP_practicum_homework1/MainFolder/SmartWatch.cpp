#include <iostream>
#include "SmartWatch.hpp"
#pragma warning (disable:4996)

using namespace std;

//Constructors
SmartWatch::SmartWatch() 
{
	this->style = new char[1];
	this->style[0] = '\0';
	this->operatingSystem = new char[1];
	this->operatingSystem[0] = '\0';
	this->typeDisplay = new char[1];
	this->typeDisplay[0] = '\0';

}

SmartWatch::SmartWatch(const char* style, const char* operatingSystem, const char* typeDisplay, int id, const char* name, double price)
{
	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	this->style = new char[strlen(style)+1];
	strncpy(this->style,style, strlen(style) + 1);
	this->style[strlen(style)] = '\0';

	this->operatingSystem = new char[strlen(operatingSystem) + 1];
	strncpy(this->operatingSystem, operatingSystem, strlen(operatingSystem) + 1);
	this->operatingSystem[strlen(operatingSystem)] = '\0';

	this->typeDisplay = new char[strlen(typeDisplay) + 1];
	strncpy(this->typeDisplay, typeDisplay, strlen(typeDisplay) + 1);
	this->typeDisplay[strlen(typeDisplay)] = '\0';

}

SmartWatch::SmartWatch(const SmartWatch& smartWatch)
{
	this->setId(smartWatch.getId());
	this->setName(smartWatch.getName());
	this->setPrice(smartWatch.getPrice());

	this->style = new char[strlen(smartWatch.style) + 1];
	strncpy(this->style, style, strlen(smartWatch.style) + 1);
	this->style[strlen(smartWatch.style)] = '\0';

	this->operatingSystem = new char[strlen(smartWatch.operatingSystem) + 1];
	strncpy(this->operatingSystem, smartWatch.operatingSystem, strlen(smartWatch.operatingSystem) + 1);
	this->operatingSystem[strlen(smartWatch.operatingSystem)] = '\0';

	this->typeDisplay = new char[strlen(smartWatch.typeDisplay) + 1];
	strncpy(this->typeDisplay, smartWatch.typeDisplay, strlen(smartWatch.typeDisplay) + 1);
	this->typeDisplay[strlen(smartWatch.typeDisplay)] = '\0';

}

//Destructor
SmartWatch::~SmartWatch()
{
	delete[] this->operatingSystem;
	delete[] this->style;
	delete[] this->typeDisplay;
}

//Assignment operator
SmartWatch& SmartWatch::operator=(const SmartWatch& smwt)
{
	if (this != &smwt)
	{
		delete[] this->operatingSystem;
		delete[] this->style;
		delete[] this->typeDisplay;

		this->setId(smwt.getId());
		this->setName(smwt.getName());
		this->setPrice(smwt.getPrice());

		this->style = new char[strlen(smwt.style) + 1];
		strncpy(this->style, smwt.style, strlen(smwt.style) + 1);
		this->style[strlen(smwt.style)] = '\0';

		this->operatingSystem = new char[strlen(smwt.operatingSystem) + 1];
		strncpy(this->operatingSystem, smwt.operatingSystem, strlen(smwt.operatingSystem) + 1);
		this->operatingSystem[strlen(smwt.operatingSystem)] = '\0';

		this->typeDisplay = new char[strlen(smwt.typeDisplay) + 1];
		strncpy(this->typeDisplay, smwt.typeDisplay, strlen(smwt.typeDisplay) + 1);
		this->typeDisplay[strlen(smwt.typeDisplay)] = '\0';

	}

	return *this;
}

bool SmartWatch::operator==(const SmartWatch& smartWatch)
{
	return this->getId() == smartWatch.getId();
}

//Mutators
void SmartWatch::setStyle(const char* style)
{
	delete[] this->style;
	this->style = new char[strlen(style) + 1];
	strncpy(this->style, style, strlen(style) + 1);
	this->style[strlen(style)] = '\0';

}
char* SmartWatch::getStyle() const
{
	return this->style;
}

void SmartWatch::setOperatingSystem(const char* operatingSystem)
{
	delete[] this->operatingSystem;
	this->operatingSystem = new char[strlen(operatingSystem) + 1];
	strncpy(this->operatingSystem, operatingSystem, strlen(operatingSystem) + 1);
	this->operatingSystem[strlen(operatingSystem)] = '\0';

}
char* SmartWatch::getOperatingSystem() const
{
	return this->operatingSystem;
}

void SmartWatch::setTypeDisplay(const char* typeDispaly)
{
	delete[] this->typeDisplay;
	this->typeDisplay = new char[strlen(typeDispaly) + 1];
	strncpy(this->typeDisplay, typeDispaly, strlen(typeDispaly) + 1);
	this->typeDisplay[strlen(typeDispaly)] = '\0';

}
char* SmartWatch::getTypeDisplay() const
{
	return this->typeDisplay;
}

//Functions
void SmartWatch::print()
{
	cout << this->getId() << " | " << this->getName() << " | " << this->getStyle() << " | " << this->getOperatingSystem() << " | " << this->getTypeDisplay() << " | " << this->getPrice() << endl;
}

std::istream& operator>>(std::istream& in, SmartWatch& smartWatch)
{
	char style[100];
	char operatingSystem[100];
	char typeDisplay[100];
	double price;
	char name[50];

	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Name: ";
	in.get(name, 50);
	cout << endl;
	smartWatch.setName(name);

	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Price: ";
	cin >> price;
	cout << endl;
	smartWatch.setPrice(price);

	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Style (man or women): ";
	in.get(style, 50);
	cout << endl;
	smartWatch.setStyle(style);

	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Operating system: ";
	in.get(operatingSystem, 50);
	cout << endl;
	smartWatch.setOperatingSystem(operatingSystem);

	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Type display: ";
	cin >> typeDisplay;
	cout << endl;
	smartWatch.setTypeDisplay(typeDisplay);

	cout << "You added successfully the product, press any key to continiue" << endl;

	return in;
}