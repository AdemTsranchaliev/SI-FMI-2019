#pragma once
#include "Vechicle.h"

class Car : public Vechicle
{
private: 
	bool isPersonalOrBuisness;//0 for personal,1 for buisness
public:
	Car();
	Car(string brand, string model, int yearOfProduction, string problemDescription, SeriousOfProblem problemSerios,bool isPersonalOrBuisness);

	void setIsPersonalOrBuisness(bool isPersonalOrBuisness);
	bool getIsPersonalOrBuisness() const;
};

