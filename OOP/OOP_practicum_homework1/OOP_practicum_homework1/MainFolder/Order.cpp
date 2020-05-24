#include <iostream>
#include <string>
#include "Order.hpp"

#pragma warning (disable:4996)

//Constructors
Order::Order()
{
	this->id=0;

	this->name = "";

	this->surname = "";

	this->phoneNumber = "";

	this->addressToDelivery = "";

	this->populatedPlace = "";

	this->email = "";

	this->isConfirmed = false;
}

Order::Order(int id,string name, string surname, string phone, string address, string populatedPlace,string email)
{
	this->id = id;

	this->name = name;

	this->surname = surname;

	this->phoneNumber = phone;

	this->addressToDelivery = address;

	this->populatedPlace = populatedPlace;

	this->email = email;

	this->isConfirmed = false;


}

Order::Order(const Order& order)
{
	this->id = order.id;

	this->name = order.name;

	this->surname = order.surname;

	this->phoneNumber = order.phoneNumber;

	this->addressToDelivery = order.addressToDelivery;

	this->populatedPlace = order.populatedPlace;

	this->email = order.email;

	this->isConfirmed = order.isConfirmed;

}



//Assignment operator
Order& Order::operator=(const Order& order)
{
	if (this!=&order)
	{
		this->id = order.id;

		this->name = order.name;

		this->surname = order.surname;

		this->phoneNumber = order.phoneNumber;

		this->addressToDelivery = order.addressToDelivery;

		this->populatedPlace = order.populatedPlace;

		this->email = order.email;

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

void Order::setName(string name)
{
	this->name = name;
}
string Order::getName() const
{
	return this->name;
}

void Order::setSurname(string surname)
{
	this->surname =surname;
}
string Order::getSurname() const
{
	return this->surname;
}

void Order::setPhoneNumber(string phone)
{
	this->phoneNumber = phone;
}
string Order::getPhoneNumber() const
{
	return this->phoneNumber;
}

void Order::setAddressToDelivery(string address)
{
	this->addressToDelivery = address;
}
string Order::getAddressToDelivery()const
{
	return this->addressToDelivery;
}

void Order::setPopulatedPlace(string populatedPlace)
{
	this->populatedPlace = populatedPlace;
}
string Order::getPopulatedPlace() const
{
	return this->populatedPlace;
}

void Order::setEmail(string email)
{
	this->email = email;
}
string Order::getEmail() const
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
	cout << "============================================="<<endl;
	cout << "Ordered items" << endl << endl;
	for (int i = 0; i < this->products.Count(); i++)
	{
		this->products.getAt(i).print();
	}

}

std::istream& operator>>(std::istream& in, Order& order)
{
	string name;
	string surname;
	string phoneNumber;
	string addressToDelivery;
	string populatedPlace;
	string email;

	in.clear();
	in.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Name: ";
	getline(in,name);
	order.setName(name);
	cout << endl;

	cout << "Surname: ";
	getline(in,surname);
	order.setSurname(surname);
	cout << endl;

	cout << "Phone: ";
	getline(in,phoneNumber);
	order.setPhoneNumber(phoneNumber);
	cout << endl;

	cout << "Town/vilage: ";
	getline(in,populatedPlace);
	order.setPopulatedPlace(populatedPlace);
	cout << endl;

	cout << "Address: ";
	getline(in,addressToDelivery);
	order.setAddressToDelivery(addressToDelivery);
	cout << endl;

	cout << "Email: ";
	getline(in,email);
	order.setEmail(email);
	cout << endl;

	return in;
}

std::ostream& operator<<(std::ostream& out, Order& order)
{
	out << "Name: " << order.name << " " << order.surname << "|";
	out << "Phone: " << order.phoneNumber << "|";
	out << "Town/Vilage to delivery: " << order.populatedPlace << "|";
	out << "Address: " << order.addressToDelivery << "|";
	out << "Email: " << order.email << "|";
	out << "IsConfirmed: " << order.email << "\n";

	return out;
}

void Order::confirmOrder()
{
	this->isConfirmed = true;
}
bool Order::getIsConfirmed() const
{
	return this->isConfirmed;
}

void Order::addProductToShoppingCart(const ShoppingCart& product)
{
	this->products.add(product);
}

