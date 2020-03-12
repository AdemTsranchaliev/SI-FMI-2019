#pragma once

class User 
{
private:
	int id;
	char username[50];
	char password[50];
	char role[50];
public:

	void setId(int id);
	int getId();
	void setUsername(char*);
	char* getUsername();
	void setPassword(char*);
	char* getPassword();
	void setRole(char*);
	char* getRole();
};