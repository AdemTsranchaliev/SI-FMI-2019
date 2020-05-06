#include <iostream>
#include "Order.hpp"

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

	this->isConfirmed = false;
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
	this->addressToDelivery[strlen(address)] = '\0';

	this->populatedPlace = new char[strlen(populatedPlace) + 1];
	strncpy(this->populatedPlace, populatedPlace, strlen(populatedPlace) + 1);
	this->populatedPlace[strlen(populatedPlace)] = '\0';


	this->email = new char[strlen(email) + 1];
	strncpy(this->email, email, strlen(email) + 1);
	this->email[strlen(email)] = '\0';

	this->isConfirmed = false;


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
	strncpy(this->addressToDelivery, order.addressToDelivery, strlen(order.addressToDelivery) + 1);
	this->name[strlen(order.addressToDelivery)] = '\0';

	this->populatedPlace = new char[strlen(order.populatedPlace) + 1];
	strncpy(this->populatedPlace, order.populatedPlace, strlen(order.populatedPlace) + 1);
	this->name[strlen(order.populatedPlace)] = '\0';

	this->email = new char[strlen(order.email) + 1];
	strncpy(this->email, order.email, strlen(order.email) + 1);
	this->name[strlen(order.email)] = '\0';

	this->isConfirmed = order.isConfirmed;

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
		this->surname[strlen(order.surname)] = '\0';

		this->phoneNumber = new char[strlen(order.phoneNumber) + 1];
		strncpy(this->phoneNumber, order.phoneNumber, strlen(order.phoneNumber) + 1);
		this->phoneNumber[strlen(order.phoneNumber)] = '\0';

		this->addressToDelivery = new char[strlen(order.addressToDelivery) + 1];
		strncpy(this->addressToDelivery, order.addressToDelivery, strlen(order.addressToDelivery) + 1);
		this->addressToDelivery[strlen(order.addressToDelivery)] = '\0';

		this->populatedPlace = new char[strlen(order.populatedPlace) + 1];
		strncpy(this->populatedPlace, order.populatedPlace, strlen(order.populatedPlace) + 1);
		this->populatedPlace[strlen(order.populatedPlace)] = '\0';

		this->email = new char[strlen(order.email) + 1];
		strncpy(this->email, order.email, strlen(order.email) + 1);
		this->email[strlen(order.email)] = '\0';

		this->isConfirmed=order.isConfirmed;
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
	this->addressToDelivery[strlen(address)] = '\0';
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
	cout << this->id+1 << " | " << this->getName() << " | " << this->getPopulatedPlace() << " | ";
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
	if (this->getIsConfirmed()==true)
	{
		cout << "Order is CONFIRMED"<<endl;
	}
	else
	{
		cout << "Order is NOT CONFIRMED" << endl;

	}
}

std::istream& operator>>(std::istream& in, Order& order)
{
	char name[40];
	char surname[40];
	char phoneNumber[40];
	char addressToDelivery[40];
	char populatedPlace[40];
	char email[40];

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Name: ";
	in.get(name,39);
	order.setName(name);
	cout << endl;

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Surname: ";
	in.get(surname, 39);
	order.setSurname(surname);
	cout << endl;

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Phone: ";
	in.get(phoneNumber, 39);
	order.setPhoneNumber(phoneNumber);
	cout << endl;

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Town/vilage: ";
	in.get(populatedPlace, 39);
	order.setPopulatedPlace(populatedPlace);
	cout << endl;

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Address: ";
	in.get(addressToDelivery, 39);
	order.setAddressToDelivery(addressToDelivery);
	cout << endl;

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Email: ";
	in.get(email, 39);
	order.setEmail(email);
	cout << endl;

	return in;
}

void Order::confirmOrder()
{
	this->isConfirmed = true;
}
bool Order::getIsConfirmed() const
{
	return this->isConfirmed;
}

