#pragma once
#include <string>
#include "EnumProblem.h"
using namespace std;
class Vechicle
{
private:
	string brand;
	string model;
	int yearOfProduction;
	string problemDescription;
	SeriousOfProblem problemSeriosity;
public:
	

	Vechicle();
	Vechicle(string brand,string model,int yearOfProduction,string problemDescription,SeriousOfProblem problemSerios );


	void setBrand(string brand);
	string getBrand() const;

	void setModel(string model);
	string getModel() const;

	void setYearOfProduction(int yearOfProduction);
	int getYearOfProduction() const;

	void setProblemDescription(string problemDescription);
	string getProblemDescription() const;

	void setSeriousOfProblem(SeriousOfProblem brand);
	int getSeriousOfProblem() const;

};

