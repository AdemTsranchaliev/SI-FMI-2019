#pragma once

#include "Proccessor.hpp"

class Laptop
{
private:
	char* brand;
	char* model;
	double price;
	double screenSize;
	int ramMemory;
	double bateryCapacity;
	Proccessor proccessor;
public:
	Laptop();
	Laptop(const Laptop& laptop);
	Laptop(const char* brand, const char* model, double price, double screenSize, int ramMemory,double batteryCapacity, double proccessorFrequency, int coresCount, int cacheMemory );
	Laptop(const char* brand, const char* model, double price, double screenSize, int ramMemory, double batteryCapacity, Proccessor& proccessor);
	Laptop& operator=(const Laptop& laptop);
	~Laptop();

	bool operator==(const Laptop& laptop);
	bool operator!=(const Laptop& laptop);
	bool operator>(const Laptop& laptop);
	bool operator<(const Laptop& laptop);

	void UpdateProccessor(const Proccessor& proccessor);
	void UpdateRam(int ram);

	void Print();

};

