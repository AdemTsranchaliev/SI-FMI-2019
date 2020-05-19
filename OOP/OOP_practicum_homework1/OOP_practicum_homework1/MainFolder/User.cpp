#include <iostream>
#include <string>
#include "User.hpp"

#pragma warning (disable:4996)


//Constructors
User::User()
{
	this->id = 0;
	this->username = "";
	this->role = "";
	this->password = "";

}

User::User(int id, string username, string password, string role) {
	this->id = id;
	this->username = username;

	this->password = password;

	this->role = role;

}

User& User::operator=(const User& user)
{
	if (this!=&user)
	{
		this->id = user.id;
		this->username = user.username;

		this->password = user.password;

		this->role = user.role;

	}
	return *this;
}

//Mutators
void User::setId(int id) {
	this->id = id;
}
int User::getId() const
{
	return this->id;
}

void User::setUsername(string username)
{
	this->username = username;

}
string User::getUsername() const
{
	return this->username;
}

void User::setPassword(string password)
{
	this->password = password;
}
string User::getPassword() const
{
	return this->password;
}

void User::setRole(string role)
{
	this->role = role;

}
string User::getRole() const
{
	return this->role;
}

std::istream& operator>>(std::istream& in, User& user)
{

	string username;
	string password;


	cout << "Username: ";
	getline(cin,username);
	cout << endl;
	user.setUsername(username);

	cout << "Password: ";
	getline(cin, password);
	cout << endl;
	user.setPassword(password);

	

	return in;
}

void User::addNewOrder(const Order& order)
{
	this->orders.add(order);
}

void User::print()
{
	cout << this->id << " | " << this->username << " | " << this->role << endl;
	
}