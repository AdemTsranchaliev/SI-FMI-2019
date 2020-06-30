#pragma once
#include "Vechicle.h"
class Bus : public Vechicle
{
private:
	bool isForPeople; //0 for people,1 for goods
public:
	Bus();
	Bus(string brand, string model, int yearOfProduction, string problemDescription, SeriousOfProblem problemSerios, bool isForPeople);

	void setIsForPeople(bool isForPeople);
	bool getIsForPeople() const;

};

