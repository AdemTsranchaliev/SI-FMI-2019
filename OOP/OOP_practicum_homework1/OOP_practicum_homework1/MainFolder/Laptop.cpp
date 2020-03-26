#include <iostream>
#include "CommonFunctions.h"
#include "Laptop.hpp"

using namespace std;

Laptop::Laptop() {}

Laptop::Laptop(const char* processor, int ramMemory, const char* videoCart, int id, const char* name, double price)
{
	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	this->ramMemory = ramMemory;
	strncpy(this->processor,processor);
	strncpy(this->videoCard, videoCard);
	this->ramMemory = ramMemory;
}

void Laptop::setRamMemory(int ramMemory)
{
	this->ramMemory = ramMemory;
}

int Laptop::getRamMemory()
{
	return this->ramMemory;
}

void Laptop::setProcessor(const char* processor)
{
	strncpy(this->processor, processor);
}

char* Laptop::getProcessor()
{
	return this->processor;
}

void Laptop::setVideoCart(const char* videoCart)
{
	strncpy(this->videoCard, videoCart);
}

char* Laptop::getVideoCart()
{
	return this->videoCard;
}

void Laptop::addLaptop(const char* processor, int ramMemory, const char* videoCart, int id, const char* name, double price)
{
	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	this->ramMemory = ramMemory;
	strncpy(this->processor, processor);
	strncpy(this->videoCard, videoCard);
}

void Laptop::print()
{
	cout << this->getId() << " | " << this->getName() << " | " << this->getRamMemory() << " | " << this->getProcessor() << " | " << this->getVideoCart() << " | " << this->getPrice() << endl;
}

Laptop& Laptop::operator=(Laptop& lap)
{
	if (this != &lap)
	{
		this->setId(lap.getId());
		this->setName(lap.getName());
		this->setPrice(lap.getPrice());

		this->ramMemory = lap.getRamMemory();
		strncpy(this->processor, lap.getProcessor());
		strncpy(this->videoCard, lap.getVideoCart());

		return *this;
	}
}







