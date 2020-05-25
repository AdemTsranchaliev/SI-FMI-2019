#pragma once
#include <vector>

#include "User.hpp"

using namespace std;
class Security
{
private:
	User authenticatedUser;

public:

	Security();

	bool Authenticate(std::string username, std::string password, vector<User>& users);

	User& getAuthenticateUser();

	bool isAuthenticated();
	bool isAuthorized(std::string role);
	std::string encryptPassword(std::string password);
	void logOut();
};

