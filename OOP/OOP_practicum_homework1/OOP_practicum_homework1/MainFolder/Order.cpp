#include <iostream>

#include "Order.hpp"

using namespace std;

Order::Order(){}
Order::Order(char* name, char* surname, char* phone, char* address, char* populatedPlace, char* email)
{
	strcpy_s(this->name,name);
	strcpy_s(this->surname, surname);
	strcpy_s(this->phoneNumber, phone);
	strcpy_s(this->addressToDelivery, address);
	strcpy_s(this->populatedPlace, populatedPlace);
	strcpy_s(this->email, email);

}

void Order::setName(char* name)
{
	strcpy_s(this->name, name);

	
}
char* Order::getName()
{
	return this->name;
}
void Order::setSurname(char* surname)
{
	strcpy_s(this->surname, surname);
}
char* Order::getSurname()
{
	return this->surname;
}
void Order::setPhoneNumber(char* phone)
{
	strcpy_s(this->phoneNumber, phone);
}
char* Order::getPhoneNumber()
{
	return this->phoneNumber;
}
void Order::setAddressToDelivery(char* address)
{
	strcpy_s(this->addressToDelivery, address);
}
char* Order::getAddressToDelivery()
{
	return this->addressToDelivery;
}
void Order::setPopulatedPlace(char* populatedPlace)
{
	strcpy_s(this->populatedPlace, populatedPlace);
}
char* Order::getPopulatedPlace()
{
	return this->populatedPlace;
}
void Order::setEmail(char* email)
{
	strcpy_s(this->email, email);
}
char* Order::getEmail()
{
	return this->email;
}