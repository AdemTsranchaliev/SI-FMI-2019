#include <iostream>

#include "SmartWatch.h"


using namespace std;

SmartWatch::SmartWatch() {}

SmartWatch::SmartWatch(char* style, char* operatingSystem, char* typeDisplay, int id, char* name, double price)
{
	Product(id, price, name);
	strcpy_s(this->style, style);
	strcpy_s(this->operatingSystem, operatingSystem);
	strcpy_s(this->typeDisplay, typeDisplay);
}


void SmartWatch::setStyle(char* style)
{
	strcpy_s(this->style, style);
}

char* SmartWatch::getStyle()
{
	return this->style;
}
void SmartWatch::setOperatingSystem(char* operatingSystem)
{
	strcpy_s(this->operatingSystem, operatingSystem);
}

char* SmartWatch::getOperatingSystem()
{
	return this->operatingSystem;
}
void SmartWatch::setTypeDisplay(char* typeDispaly)
{
	strcpy_s(this->typeDisplay, typeDispaly);
}

char* SmartWatch::getTypeDisplay()
{
	return this->typeDisplay;
}
