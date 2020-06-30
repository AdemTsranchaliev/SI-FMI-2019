#pragma once
#include <iostream>
#include "Car.h"
#include "Vechicle.h"
#include <vector>
class AutoService
{
private:
	int points;//max 10
	vector<Vechicle*> vechicles;

	bool isThereCapacity(int points);

public:
	void AddNewVechicle(Vechicle* vechicle);
	Vechicle* getVechicle(int position);
	int getPointBySeriousOfProblem(int problemCode);
};

