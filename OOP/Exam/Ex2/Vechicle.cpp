#include "Vechicle.h"


Vechicle::Vechicle()
{
	this->brand = "";
	this->model = "";
	this->yearOfProduction = 0;
	this->problemDescription = "";
}
Vechicle::Vechicle(string brand, string model, int yearOfProduction, string problemDescription, SeriousOfProblem problemSerios)
{
	this->brand = brand;
	this->model = model;
	this->yearOfProduction = yearOfProduction;
	this->problemDescription = problemDescription;
	this->setSeriousOfProblem(problemSerios);
}


void Vechicle::setBrand(string brand)
{
	this->brand = brand;

}
string Vechicle::getBrand() const
{
	return this->brand;
}

void Vechicle::setModel(string model)
{
	this->model = model;
}
string Vechicle::getModel() const
{
	return this->model;
}

void Vechicle::setYearOfProduction(int yearOfProduction)
{
	this->yearOfProduction = yearOfProduction;
}
int Vechicle::getYearOfProduction() const
{
	return this->yearOfProduction;
}

void Vechicle::setProblemDescription(string problemDescription)
{
	this->problemDescription = problemDescription;
}
string Vechicle::getProblemDescription() const
{
	return this->problemDescription;
}

void Vechicle::setSeriousOfProblem(SeriousOfProblem problemSeriosity)
{
	this->problemSeriosity = problemSeriosity;
}
int Vechicle::getSeriousOfProblem() const
{
	return this->problemSeriosity;
}

