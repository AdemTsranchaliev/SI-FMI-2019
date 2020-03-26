#include <iostream>
#include "Dispencer.hpp"

using namespace std;



Dispencer::Dispencer(double capacity, double quantity)
{
	this->capacity = capacity;
	this->quantity = quantity;
}

double Dispencer::getCapacity() const
{
	return this->capacity;
}
double Dispencer::getQuantity() const
{
	return this->quantity;
}

void Dispencer::FillWithWater(double waterToFill)
{
	if (this->quantity+waterToFill>capacity)
	{
		this->quantity = this->capacity;
		cout << "There are not enough space for all the water you want to fill. "<<waterToFill-this->capacity<<" LITERS left!";
	}
	else
	{
		this->quantity += waterToFill;
	}
}


void Dispencer::DrainWater(double waterToDrain)
{
	if (this->quantity-waterToDrain<0)
	{
		cout << "There are not enough water to drain";
	}
	else
	{
		this->quantity -= waterToDrain;
	}
}
