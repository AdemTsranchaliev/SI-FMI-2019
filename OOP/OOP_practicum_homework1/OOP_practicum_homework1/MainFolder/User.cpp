#include <iostream>
#include "User.hpp"
#pragma warning (disable:4996)
using namespace std;


//Constructors
User::User()
{
	this->id = 0;
	this->username = new char[1];
	this->username[0] = '\0';
	this->role = new char[1];
	this->role[0] = '\0';
	this->password = new char[1];
	this->password[0] = '\0';
}

User::User(int id, char* username, char* password, char* role) {
	this->id = id;
	this->username = new char[strlen(username)+1];
	strncpy(this->username,username, strlen(username) + 1);

	this->password = new char[strlen(password) + 1];
	strncpy(this->password, password, strlen(password) + 1);

	this->role = new char[strlen(role) + 1];
	strncpy(this->role, role, strlen(role) + 1);
}

//Destructor
User::~User() {
	delete[] this->username;
	delete[] this->password;
	delete[] this->role;
}

//Mutators
void User::setId(int id) {
	this->id = id;
}
int User::getId() const
{
	return this->id;
}

void User::setUsername(char* username)
{
	delete[] this->username;
	this->username = new char[strlen(username) + 1];
	strncpy(this->username, username, strlen(username) + 1);
}
char* User::getUsername() const
{
	return this->username;
}

void User::setPassword(char* password)
{
	delete[] this->password;
	this->password = new char[strlen(password) + 1];
	strncpy(this->password, password, strlen(password) + 1);
}
char* User::getPassword() const
{
	return this->password;
}

void User::setRole(char* role)
{
	delete[] this->role;
	this->role = new char[strlen(role) + 1];
	strncpy(this->role, role, strlen(role) + 1);
}
char* User::getRole() const
{
	return this->role;
}