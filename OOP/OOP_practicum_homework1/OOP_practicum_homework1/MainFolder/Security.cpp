#include <iostream>
#include <string>

#include "Security.h"



Security::Security()
{
	User user;
	this->authenticatedUser = user;
}

User& Security::getAuthenticateUser()
{
	return this->authenticatedUser;
}


bool Security::Authenticate(string username, string password, vector<User>& users)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getUsername() == username)
		{
			
			if (this->encryptPassword(users[i].getPassword()) == password)
			{
				authenticatedUser = users[i];
				return true;
			}
			return false;
		}
	}
	return false;
}
bool Security::isAuthenticated()
{
	if (this->authenticatedUser.getId() == 0)
	{
		return false;

	}
	return true;
}
bool Security::isAuthorized(string role)
{
	if (this->authenticatedUser.getRole() == role)
	{
		return true;

	}
	return false;
}


void Security::logOut()
{
	User user;
	this->authenticatedUser = user;
	cout << "Successfully logout, press any key to continiue";
}





string Security::encryptPassword(string password) {
	char key = 'A'; 
	string output = password;

	for (int i = 0; i < password.size(); i++)
		output[i] = password[i] ^ key;

	return output;
}