#include "Bus.h"
#include <iostream>

Bus::Bus():Vechicle(){}
Bus::Bus(string brand, string model, int yearOfProduction, string problemDescription, SeriousOfProblem problemSerios, bool isForPeople):Vechicle(brand,model,yearOfProduction,problemDescription,problemSerios)
{
	this->isForPeople = isForPeople;
}

void Bus::setIsForPeople(bool isForPeople)
{
	this->isForPeople = isForPeople;
}
bool Bus::getIsForPeople() const
{
	return this->isForPeople;
}


