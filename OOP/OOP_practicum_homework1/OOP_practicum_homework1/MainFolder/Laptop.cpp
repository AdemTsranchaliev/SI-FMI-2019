#include <iostream>
#include "Laptop.hpp"
#pragma warning (disable:4996)
using namespace std;

//Constructors
Laptop::Laptop()
{
	this->processor = new char[1];
	this->processor = '\0';
	this->videoCard = new char[1];
	this->videoCard = '\0';
	this->ramMemory = 0;
}

Laptop::Laptop(const char* processor, int ramMemory, const char* videoCart, int id, const char* name, double price)
{
	this->setId(id);
	this->setName(name);
	this->setPrice(price);

	this->ramMemory = ramMemory;

	this->processor = new char[strlen(processor)+1];
	strncpy(this->processor,processor, strlen(processor) + 1);

	this->videoCard = new char[strlen(videoCart) + 1];
	strncpy(this->videoCard, videoCart, strlen(videoCart) + 1);

}

Laptop::Laptop(const Laptop& laptop)
{

	this->setId(laptop.getId());
	this->setName(laptop.getName());
	this->setPrice(laptop.getPrice());

	this->ramMemory = laptop.getRamMemory();

	this->processor = new char[strlen(laptop.processor) + 1];
	strncpy(this->processor, laptop.processor, strlen(laptop.processor) + 1);

	this->videoCard = new char[strlen(laptop.videoCard) + 1];
	strncpy(this->videoCard, laptop.videoCard, strlen(laptop.videoCard) + 1);
}

//Destructor
Laptop::~Laptop()
{
	delete[] this->processor;
	delete[] this->videoCard;
}

//Assignment operator
Laptop& Laptop::operator=(const Laptop& lap)
{
	if (this != &lap)
	{
		delete[] this->processor;
		delete[] this->videoCard;

		this->setId(lap.getId());
		this->setName(lap.getName());
		this->setPrice(lap.getPrice());

		this->ramMemory = lap.getRamMemory();

		this->processor = new char[strlen(lap.processor) + 1];
		strncpy(this->processor, lap.processor, strlen(lap.processor) + 1);

		this->videoCard = new char[strlen(lap.videoCard) + 1];
		strncpy(this->videoCard, lap.videoCard, strlen(lap.videoCard) + 1);
	}
	return *this;
}

bool Laptop::operator==(const Laptop& laptop)
{
	return this->getId() == laptop.getId();
}

//Mutators
void Laptop::setRamMemory(int ramMemory) 
{
	this->ramMemory = ramMemory;
}
int Laptop::getRamMemory() const
{
	return this->ramMemory;
}

void Laptop::setProcessor(const char* processor)
{
	delete[] this->processor;
	this->processor = new char[strlen(processor) + 1];
	strncpy(this->processor, processor, strlen(processor) + 1);
}
char* Laptop::getProcessor() const
{
	return this->processor;
}

void Laptop::setVideoCart(const char* videoCart)
{
	delete[] this->videoCard;
	this->videoCard = new char[strlen(videoCart) + 1];
	strncpy(this->videoCard, videoCart, strlen(videoCart) + 1);
}
char* Laptop::getVideoCart() const
{
	return this->videoCard;
}


//Functions
void Laptop::print()
{
	cout << this->getId() << " | " << this->getName() << " | " << this->getRamMemory() << " | " << this->getProcessor() << " | " << this->getVideoCart() << " | " << this->getPrice() << endl;
}








