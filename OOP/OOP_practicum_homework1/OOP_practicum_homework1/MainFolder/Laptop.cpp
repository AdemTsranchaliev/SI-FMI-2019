#include <iostream>
#include "Laptop.hpp"

#include <string>
#pragma warning (disable:4996)

//Constructors
Laptop::Laptop()
{
	this->processor = "";
	this->videoCard = "";

	this->ramMemory = 0;
}

Laptop::Laptop(string processor, int ramMemory, string videoCart, int id, string name, double price,string category): Product(id,price, name, category)
{
	this->ramMemory = ramMemory;

	this->processor = processor;

	this->videoCard = videoCart;
}

Laptop::Laptop(const Laptop& laptop) : Product(laptop)
{

	this->ramMemory = laptop.getRamMemory();

	this->processor = laptop.processor;

	this->videoCard = laptop.videoCard;

}


//Assignment operator
Laptop& Laptop::operator=(const Laptop& laptop) 
{
	if (this != &laptop)
	{

		this->setId(laptop.getId());
		this->setName(laptop.getName());
		this->setPrice(laptop.getPrice());

		this->ramMemory = laptop.getRamMemory();

		this->processor = laptop.processor;

		this->videoCard = laptop.videoCard;
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

void Laptop::setProcessor(string processor)
{
	this->processor = processor;
}
string Laptop::getProcessor() const
{
	return this->processor;
}

void Laptop::setVideoCart(string videoCart)
{
	this->videoCard = videoCart;
}
string Laptop::getVideoCart() const
{
	return this->videoCard;
}

std::istream& operator>>(std::istream& in, Laptop& laptop)
{
	string procecors;
	string videoCart;
	int ramMemory;
	double price;
	string name;

	cout << "Name: ";
	getline(in, name);
	cout << endl;
	laptop.setName("");

	
	cout << "Price: ";
	in >> price;
	cout << endl;
	laptop.setPrice(price);


	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Video card: ";
	getline(in,videoCart);
	cout << endl;
	laptop.setVideoCart(videoCart);


	cout << "Processor: ";
	getline(in,procecors);
	cout << endl;
	laptop.setProcessor(procecors);

	cout << "You added successfully the product, press any key to continiue"<<endl;

	return in;
}



//Functions
void Laptop::print()
{
	cout << this->getId() << " | " << this->getName() << " | " << this->getRamMemory() << " | " << this->getProcessor() << " | " << this->getVideoCart() << " | " << this->getPrice() << endl;
}








