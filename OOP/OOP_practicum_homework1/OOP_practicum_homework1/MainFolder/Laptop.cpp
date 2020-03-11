#include <iostream>

#include "Laptop.h"

using namespace std;

Laptop::Laptop() {}

Laptop::Laptop(char* processor, int ramMemory, char* videoCart, int id, char* name, double price)
{
	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	this->ramMemory = ramMemory;
	strcpy_s(this->processor,processor);
	strcpy_s(this->videoCard, videoCard);
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

void Laptop::setProcessor(char* processor)
{
	strcpy_s(this->processor, processor);
}

char* Laptop::getProcessor()
{
	return this->processor;
}

void Laptop::setVideoCart(char* videoCart)
{
	strcpy_s(this->videoCard, videoCart);
}

char* Laptop::getVideoCart()
{
	return this->videoCard;
}

void Laptop::addLaptop(char* processor, int ramMemory, char* videoCart, int id, char* name, double price)
{
	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	this->ramMemory = ramMemory;
	strcpy_s(this->processor, processor);
	strcpy_s(this->videoCard, videoCard);
	this->ramMemory = ramMemory;
}




