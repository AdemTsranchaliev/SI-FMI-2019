#include <iostream>

#include "Login.hpp"

using namespace std;

Login::Login() {}

Login::Login(char* username)
{
	this->username = username;

	int lenght = 0;
	cout << "Please enter how will be the lenght of password" << endl;
	cin >> lenght;
	cin.ignore();
	this->password = new char[lenght+1];
	cout << "Please enter password"<<endl;
	cin >> this->password;
	this->sessionType = 1;
}

Login::Login(char* username, char* password)
{
	this->username = username;
	this->password = password;
	this->sessionType = 1;
}
Login::Login(char* username, char* password, int sessionType)
{
	this->username = username;
	this->password = password;
	this->sessionType = sessionType;
}

Login::Login(const Login& info)
{
	this->username = info.username;
	this->password = info.password;
	this->sessionType = info.sessionType;
}
void Login::setUsername(char* username)
{
	this->username = username;
}
char* Login::getUsername() const
{
	return this->username;
}
void  Login::setPassword(char* password)
{
	this->password = password;
}
char* Login::getPassword() const
{
	return this->password;
}
void Login::setSessionType(int sessionType)
{
	this->sessionType = sessionType;
}
int Login::getSessionType() const
{
	return this->sessionType;
}
