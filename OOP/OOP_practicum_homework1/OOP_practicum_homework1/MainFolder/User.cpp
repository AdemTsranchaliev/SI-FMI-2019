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

User::User(int id, const char* username, const char* password, const char* role) {
	this->id = id;
	this->username = new char[strlen(username)+1];
	strncpy(this->username,username, strlen(username) + 1);
	this->username[strlen(username)] = '\0';

	this->password = new char[strlen(password) + 1];
	strncpy(this->password, password, strlen(password) + 1);
	this->password[strlen(password)] = '\0';

	this->role = new char[strlen(role) + 1];
	strncpy(this->role, role, strlen(role) + 1);
	this->role[strlen(role)] = '\0';

}

//Destructor
User::~User() {
	delete[] this->username;
	delete[] this->password;
	delete[] this->role;
}

User& User::operator=(const User& user)
{
	if (this!=&user)
	{
		delete[] this->username;
		delete[] this->password;
		delete[] this->role;

		this->id = user.id;
		this->username = new char[strlen(user.username) + 1];
		strncpy(this->username, user.username, strlen(user.username) + 1);
		this->username[strlen(user.username)] = '\0';

		this->password = new char[strlen(user.password) + 1];
		strncpy(this->password, user.password, strlen(user.password) + 1);
		this->password[strlen(user.password)] = '\0';

		this->role = new char[strlen(user.role) + 1];
		strncpy(this->role, user.role, strlen(user.role) + 1);
		this->role[strlen(user.role)] = '\0';

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

void User::setUsername(const char* username)
{
	delete[] this->username;
	this->username = new char[strlen(username) + 1];
	strncpy(this->username, username, strlen(username) + 1);
	this->username[strlen(username)] = '\0';

}
char* User::getUsername() const
{
	return this->username;
}

void User::setPassword(const char* password)
{
	delete[] this->password;
	this->password = new char[strlen(password) + 1];
	strncpy(this->password, password, strlen(password) + 1);
	this->password[strlen(password)] = '\0';

}
char* User::getPassword() const
{
	return this->password;
}

void User::setRole(const char* role)
{
	delete[] this->role;
	this->role = new char[strlen(role) + 1];
	strncpy(this->role, role, strlen(role) + 1);
	this->role[strlen(role)] = '\0';

}
char* User::getRole() const
{
	return this->role;
}

std::istream& operator>>(std::istream& in, User& user)
{

	char username[100];
	char password[100];


	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Username: ";
	in.get(username, 50);
	cout << endl;
	user.setUsername(username);

	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	cout << "Password: ";
	cin >> password;
	cout << endl;
	user.setPassword(password);

	

	return in;
}

void User::print()
{
	cout << this->id << " | " << this->username << " | " << this->role << endl;
	
}