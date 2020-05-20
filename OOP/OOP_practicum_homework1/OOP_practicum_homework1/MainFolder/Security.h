#pragma once
#include "User.hpp"
#include "List.hpp"

using namespace std;
class Security
{
private:
	User authenticatedUser;

public:

	Security();

	bool Authenticate(std::string username, std::string password, List<User>& users);

	User& getAuthenticateUser();

	bool isAuthenticated();
	bool isAuthorized(std::string role);
	std::string encryptPassword(std::string password);
	void logOut();
};

