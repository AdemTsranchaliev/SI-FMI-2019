#include <iostream>
#include "Order.hpp"
#include "User.hpp"
#include "ShoppingCart.hpp"
#pragma warning (disable:4996)
using namespace std;

//Constructors
Order::Order()
{
	this->id=0;

	this->name = new char[1];
	this->name[0] = '\0';

	this->surname = new char[1];
	this->surname[0] = '\0';

	this->phoneNumber = new char[1];
	this->phoneNumber[0] = '\0';

	this->addressToDelivery = new char[1];
	this->addressToDelivery[0] = '\0';

	this->populatedPlace = new char[1];
	this->populatedPlace[0] = '\0';

	this->email = new char[1];
	this->email[0] = '\0';
}

Order::Order(int id,const char* name, const char* surname, const char* phone, const char* address, const char* populatedPlace,const char* email)
{
	this->id = id;

	this->name = new char[strlen(name) + 1];
	strncpy(this->name,name,strlen(name)+1);
	this->name[strlen(name)] = '\0';

	this->surname = new char[strlen(surname) + 1];
	strncpy(this->surname, surname, strlen(surname) + 1);
	this->surname[strlen(surname)] = '\0';

	this->phoneNumber = new char[strlen(phone) + 1];
	strncpy(this->phoneNumber, phone, strlen(phone) + 1);
	this->phoneNumber[strlen(phoneNumber)] = '\0';

	this->addressToDelivery = new char[strlen(address) + 1];
	strncpy(this->addressToDelivery, address, strlen(address) + 1);
	this->addressToDelivery[strlen(addressToDelivery)] = '\0';

	this->populatedPlace = new char[strlen(populatedPlace) + 1];
	strncpy(this->populatedPlace, populatedPlace, strlen(populatedPlace) + 1);
	this->populatedPlace[strlen(populatedPlace)] = '\0';


	this->email = new char[strlen(email) + 1];
	strncpy(this->email, email, strlen(email) + 1);
	this->email[strlen(email)] = '\0';

}

Order::Order(const Order& order)
{
	this->name = new char[strlen(order.name) + 1];
	strncpy(this->name, order.name, strlen(order.name) + 1);
	this->name[strlen(order.name)] = '\0';

	this->surname = new char[strlen(order.surname) + 1];
	strncpy(this->surname, order.surname, strlen(order.surname) + 1);
	this->name[strlen(order.surname)] = '\0';

	this->phoneNumber = new char[strlen(order.phoneNumber) + 1];
	strncpy(this->phoneNumber, order.phoneNumber, strlen(order.phoneNumber) + 1);
	this->name[strlen(order.phoneNumber)] = '\0';

	this->addressToDelivery = new char[strlen(order.addressToDelivery) + 1];
	strncpy(this->addressToDelivery, addressToDelivery, strlen(order.addressToDelivery) + 1);
	this->name[strlen(order.addressToDelivery)] = '\0';

	this->populatedPlace = new char[strlen(order.populatedPlace) + 1];
	strncpy(this->populatedPlace, order.populatedPlace, strlen(order.populatedPlace) + 1);
	this->name[strlen(order.populatedPlace)] = '\0';

	this->email = new char[strlen(order.email) + 1];
	strncpy(this->email, order.email, strlen(order.email) + 1);
	this->name[strlen(order.email)] = '\0';
}


//Destructor
Order::~Order()
{
	delete[] this->name;
	delete[] this->surname;
	delete[] this->phoneNumber;
	delete[] this->addressToDelivery;
	delete[] this->populatedPlace;
	delete[] this->email;

}

//Assignment operator
Order& Order::operator=(const Order& order)
{
	if (this!=&order)
	{
		delete[] this->name;
		delete[] this->surname;
		delete[] this->phoneNumber;
		delete[] this->addressToDelivery;
		delete[] this->populatedPlace;
		delete[] this->email;

		this->name = new char[strlen(order.name) + 1];
		strncpy(this->name, order.name, strlen(order.name) + 1);
		this->name[strlen(order.name)] = '\0';

		this->surname = new char[strlen(order.surname) + 1];
		strncpy(this->surname, order.surname, strlen(order.surname) + 1);
		this->name[strlen(order.surname)] = '\0';

		this->phoneNumber = new char[strlen(order.phoneNumber) + 1];
		strncpy(this->phoneNumber, order.phoneNumber, strlen(order.phoneNumber) + 1);
		this->name[strlen(order.phoneNumber)] = '\0';

		this->addressToDelivery = new char[strlen(order.addressToDelivery) + 1];
		strncpy(this->addressToDelivery, addressToDelivery, strlen(order.addressToDelivery) + 1);
		this->name[strlen(order.addressToDelivery)] = '\0';

		this->populatedPlace = new char[strlen(order.populatedPlace) + 1];
		strncpy(this->populatedPlace, order.populatedPlace, strlen(order.populatedPlace) + 1);
		this->name[strlen(order.populatedPlace)] = '\0';

		this->email = new char[strlen(order.email) + 1];
		strncpy(this->email, order.email, strlen(order.email) + 1);
		this->name[strlen(order.email)] = '\0';
	}

	return *this;
}

//Mutators

void Order::setId(int id)
{
	this->id = id;
}
int Order::getId() const
{
	return this->id;
}

void Order::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name)+1];
	strncpy(this->name, name, strlen(name) + 1);
	this->name[strlen(name)] = '\0';
}
char* Order::getName() const
{
	return this->name;
}

void Order::setSurname(char* surname)
{
	delete[] this->surname;
	this->surname = new char[strlen(surname) + 1];
	strncpy(this->surname, surname, strlen(surname) + 1);
	this->surname[strlen(surname)] = '\0';
}
char* Order::getSurname() const
{
	return this->surname;
}

void Order::setPhoneNumber(char* phone)
{
	delete[] this->phoneNumber;
	this->phoneNumber = new char[strlen(phone) + 1];
	strncpy(this->phoneNumber, phone, strlen(phone) + 1);
	this->phoneNumber[strlen(phone)] = '\0';
}
char* Order::getPhoneNumber() const
{
	return this->phoneNumber;
}

void Order::setAddressToDelivery(char* address)
{
	delete[] this->addressToDelivery;
	this->addressToDelivery = new char[strlen(address) + 1];
	strncpy(this->addressToDelivery, address, strlen(address) + 1);
	this->addressToDelivery[strlen(addressToDelivery)] = '\0';
}
char* Order::getAddressToDelivery()const
{
	return this->addressToDelivery;
}

void Order::setPopulatedPlace(char* populatedPlace)
{
	delete[] this->populatedPlace;
	this->populatedPlace = new char[strlen(populatedPlace) + 1];
	strncpy(this->populatedPlace, populatedPlace, strlen(populatedPlace) + 1);
	this->populatedPlace[strlen(populatedPlace)] = '\0';
}
char* Order::getPopulatedPlace() const
{
	return this->populatedPlace;
}

void Order::setEmail(char* email)
{
	delete[] this->email;
	this->email = new char[strlen(email) + 1];
	strncpy(this->email, email, strlen(email) + 1);
	this->email[strlen(email)] = '\0';
}
char* Order::getEmail() const
{
	return this->email;
}

//Functions
void Order::print()
{
	cout << this->id << " | " << this->getName() << " | " << this->getPopulatedPlace() << " | ";
	if (this->isConfirmed)
	{
		cout << "CONFIRMED" << endl;
	}
	else
	{
		cout << "NOT CONFIRMED" << endl;

	}
}
void Order::printDetail()
{
	cout << "Name: " << this->name << " " << this->surname << endl;
	cout << "Phone: " << this->phoneNumber << endl;
	cout << "Town/Vilage to delivery: " << this->populatedPlace<<endl;
	cout << "Address: "<<this->addressToDelivery<<endl;
	cout << "Email: " << this->email << endl;
}
