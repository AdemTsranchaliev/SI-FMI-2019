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

	this->operatingSystem = new char[strlen(operatingSystem) + 1];
	strncpy(this->operatingSystem, operatingSystem, strlen(operatingSystem) + 1);

	this->typeDisplay = new char[strlen(typeDisplay) + 1];
	strncpy(this->typeDisplay, typeDisplay, strlen(typeDisplay) + 1);
}

SmartWatch::SmartWatch(const SmartWatch& smartWatch)
{
	this->setId(smartWatch.getId());
	this->setName(smartWatch.getName());
	this->setPrice(smartWatch.getPrice());

	this->style = new char[strlen(smartWatch.style) + 1];
	strncpy(this->style, style, strlen(smartWatch.style) + 1);

	this->operatingSystem = new char[strlen(smartWatch.operatingSystem) + 1];
	strncpy(this->operatingSystem, smartWatch.operatingSystem, strlen(smartWatch.operatingSystem) + 1);

	this->typeDisplay = new char[strlen(smartWatch.typeDisplay) + 1];
	strncpy(this->typeDisplay, smartWatch.typeDisplay, strlen(smartWatch.typeDisplay) + 1);
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

		this->operatingSystem = new char[strlen(smwt.operatingSystem) + 1];
		strncpy(this->operatingSystem, smwt.operatingSystem, strlen(smwt.operatingSystem) + 1);

		this->typeDisplay = new char[strlen(smwt.typeDisplay) + 1];
		strncpy(this->typeDisplay, smwt.typeDisplay, strlen(smwt.typeDisplay) + 1);
	}

	return *this;
}

//Mutators
void SmartWatch::setStyle(const char* style)
{
	delete[] this->style;
	this->style = new char[strlen(style) + 1];
	strncpy(this->style, style, strlen(style) + 1);
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

