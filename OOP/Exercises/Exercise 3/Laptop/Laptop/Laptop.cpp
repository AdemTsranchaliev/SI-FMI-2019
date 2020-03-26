#pragma warning (disable:4996)
#include <iostream>
#include "Laptop.hpp"
#include <cstring>
using namespace std;

Laptop::Laptop()
{
	this->model = new char[1];
	this->model[0] = '\0';
	this->brand = new char[1];
	this->brand[0] = '\0';
	this->price = 0;
	this->screenSize = 0;
	this->ramMemory = 0;
	this->bateryCapacity = 0;
	this->proccessor = Proccessor();
}
Laptop::Laptop(const Laptop& laptop)
{
	this->model = new char[strlen(laptop.model) + 1];
	this->model[strlen(laptop.model) + 1] = '\0';
	this->brand = new char[strlen(laptop.brand) + 1];
	this->brand[strlen(laptop.brand) + 1] = '\0';
	this->price = laptop.price;
	this->screenSize = laptop.screenSize;
	this->ramMemory = laptop.ramMemory;
	this->bateryCapacity = laptop.bateryCapacity;
	this->proccessor = laptop.proccessor;
}
Laptop::Laptop(const char* brand, const char* model, double price, double screenSize, int ramMemory, double batteryCapacity, double proccessorFrequency, int coresCount, int cacheMemory)
{
	this->brand = new char[strlen(brand) + 1];
	strncpy(this->brand, brand, strlen(brand) + 1);
	this->brand[strlen(brand) + 1] = '\0';

	this->model = new char[strlen(model) + 1];
	strncpy(this->model, model, strlen(model) + 1);
	this->brand[strlen(model)] = '\0';

	this->price = price;
	this->screenSize = screenSize;
	this->ramMemory = ramMemory;
	this->bateryCapacity = batteryCapacity;
	this->proccessor = Proccessor(proccessorFrequency,coresCount,cacheMemory);
}
Laptop::Laptop(const char* brand, const char* model, double price, double screenSize, int ramMemory, double batteryCapacity, Proccessor& proccessor)
{
	
	this->brand = new char[strlen(brand)+1];
	strncpy(this->brand, brand, strlen(brand)+1);
	this->brand[strlen(brand)] = '\0';

	this->model = new char[strlen(model) + 1];
	strncpy(this->model, model, strlen(model)+1);
	this->brand[strlen(model)] = '\0';

	this->price = price;
	this->screenSize = screenSize;
	this->ramMemory = ramMemory;
	this->bateryCapacity = batteryCapacity;
	this->proccessor = proccessor;
}
Laptop& Laptop::operator=(const Laptop& laptop)
{
	if (this!=&laptop)
	{
		this->model = new char[strlen(laptop.model) + 1];
		this->model[strlen(laptop.model) + 1] = '\0';
		this->brand = new char[strlen(laptop.brand) + 1];
		this->brand[strlen(laptop.brand) + 1] = '\0';
		this->price = laptop.price;
		this->screenSize = laptop.screenSize;
		this->ramMemory = laptop.ramMemory;
		this->bateryCapacity = laptop.bateryCapacity;
		this->proccessor = laptop.proccessor;
	}
	return *this;
}
Laptop::~Laptop()
{
	delete[] model;
	delete[] brand;
}

bool Laptop::operator==(const Laptop& laptop)
{
	return this->screenSize == laptop.screenSize;
}
bool Laptop::operator!=(const Laptop& laptop)
{
	return this->screenSize != laptop.screenSize;

}
bool Laptop::operator>(const Laptop& laptop)
{
	return this->screenSize > laptop.screenSize;

}
bool Laptop::operator<(const Laptop& laptop)
{
	return this->screenSize < laptop.screenSize;

}

void Laptop::UpdateProccessor(const Proccessor& proccessor)
{
	this->proccessor = proccessor;
}
void Laptop::UpdateRam(int ram)
{
	this->ramMemory = ram;
}


void Laptop::Print()
{
	cout << this->brand << " " << this->model << endl;
	cout << "Price: "<<this->price<<endl;
	cout << "Battery: " << this->bateryCapacity << endl;
	cout << "Screen size: " << this->screenSize<< " inches" << endl;
	cout << "Ram memory: " << this->ramMemory << endl;
	cout << "Proccessor: " <<  endl;
	this->proccessor.Print();
}