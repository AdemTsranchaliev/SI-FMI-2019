#include "Car.h"


Car::Car() : Vechicle()
{

}

Car::Car(string brand, string model, int yearOfProduction, string problemDescription, SeriousOfProblem problemSerios, bool isPersonalOrBuisness) : Vechicle(brand, model, yearOfProduction, problemDescription, problemSerios)
{
	this->isPersonalOrBuisness = isPersonalOrBuisness;
}

void Car::setIsPersonalOrBuisness(bool isPersonalOrBuisness)
{
	this->isPersonalOrBuisness = isPersonalOrBuisness;
}
bool Car::getIsPersonalOrBuisness() const
{
	return this->isPersonalOrBuisness;
}