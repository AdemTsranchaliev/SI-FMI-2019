
#include <iostream>
#include "User.hpp"
using namespace std;


User::User() {}
User::User(int id, char* username, char* password, char* role) {
	this->id = id;
	strcpy_s(this->username,username);
	strcpy_s(this->password, password);
	strcpy_s(this->role, role);
}

void User::setId(int id) {
	this->id = id;
}
int User::getId()
{
	return this->id;
}
void User::setUsername(char* username)
{
	strcpy_s(this->username, username);
}
char* User::getUsername()
{
	return this->username;
}
void User::setPassword(char* password)
{
	strcpy_s(this->password, password);
}
char* User::getPassword()
{
	return this->password;
}
void User::setRole(char* role)
{
	strcpy_s(this->role, role);
}
char* User::getRole()
{
	return this->role;
}