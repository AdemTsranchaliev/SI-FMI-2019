#include <iostream>

#include "SmartWatch.hpp"


using namespace std;

SmartWatch::SmartWatch() {}

SmartWatch::SmartWatch(const char* style, const char* operatingSystem, const char* typeDisplay, int id, const char* name, double price)
{
	this->setId(id);
	this->setName(name);
	this->setPrice(price);
	strcpy_s(this->style, style);
	strcpy_s(this->operatingSystem, operatingSystem);
	strcpy_s(this->typeDisplay, typeDisplay);
}


void SmartWatch::setStyle(const char* style)
{
	strcpy_s(this->style, style);
}

char* SmartWatch::getStyle()
{
	return this->style;
}
void SmartWatch::setOperatingSystem(const char* operatingSystem)
{
	strcpy_s(this->operatingSystem, operatingSystem);
}

char* SmartWatch::getOperatingSystem()
{
	return this->operatingSystem;
}
void SmartWatch::setTypeDisplay(const char* typeDispaly)
{
	strcpy_s(this->typeDisplay, typeDispaly);
}

char* SmartWatch::getTypeDisplay()
{
	return this->typeDisplay;
}


void SmartWatch::addSmartWatch(const char* style, const char* operatingSystem, const char* typeDisplay, int id, const char* name, double price)
{
	this->setId(id);
	this->setName(name);
	this->setPrice(price);
	strcpy_s(this->style, style);
	strcpy_s(this->operatingSystem, operatingSystem);
	strcpy_s(this->typeDisplay, typeDisplay);
}

void SmartWatch::print()
{
	cout << this->getId() << " | " << this->getName() << " | " << this->getStyle() << " | " << this->getOperatingSystem() << " | " << this->getTypeDisplay() << " | " << this->getPrice() << endl;
}

SmartWatch& SmartWatch::operator=(SmartWatch& smwt)
{
	if (this != &smwt)
	{
		this->setId(smwt.getId());
		this->setName(smwt.getName());
		this->setPrice(smwt.getPrice());

		strcpy_s(this->style, smwt.getStyle());
		strcpy_s(this->operatingSystem, smwt.getOperatingSystem());
		strcpy_s(this->typeDisplay, smwt.getTypeDisplay());

		return *this;
	}
}