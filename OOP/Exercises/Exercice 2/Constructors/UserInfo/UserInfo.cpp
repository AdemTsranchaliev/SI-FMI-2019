#include <iostream>
#include "UserInfo.hpp"

using namespace std;


UserInfo::UserInfo()
{
	char* tempName = new char[1];
	tempName[0] = '\0';
	char* tempPassword = new char[1];
	tempPassword[0] = '\0';
}
UserInfo::UserInfo(const UserInfo& user)
{
	char* tempName = user.username;

	char* tempPassword = user.password;
}
UserInfo::UserInfo(char* username)
{
	char* tempName =username;

	char* tempPassword = new char[1];
	tempPassword[0] = '\0';
}
UserInfo::UserInfo(char* username, char* password)
{
	char* tempName = username;
	char* tempPassword = password;
}


void UserInfo::setUsername(char* username)
{
	delete[] this->username;
	this->username = username;
}
char* UserInfo::getUsername() const
{
	return this->username;
}

void UserInfo::setPassword(char* password)
{
	delete[] this->password;
	this->password = password;
}
char* UserInfo::getPassword() const
{
	return this->password;
}