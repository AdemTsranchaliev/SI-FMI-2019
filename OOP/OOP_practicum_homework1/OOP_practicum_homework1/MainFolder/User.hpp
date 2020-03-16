#pragma once

class User 
{
private:
	int id;
	char username[50];
	char password[50];
	char role[50];
public:
	User();
	User(int id,char* username,char* password,char* role);

	void setId(int id);
	int getId();
	void setUsername(char*);
	char* getUsername();
	void setPassword(char*);
	char* getPassword();
	void setRole(char*);
	char* getRole();
};