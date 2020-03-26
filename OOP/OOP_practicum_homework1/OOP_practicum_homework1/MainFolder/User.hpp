#pragma once

class User 
{
private:
	int id;
	char* username;
	char* password;
	char* role;
public:
	User();
	User(int id,char* username,char* password,char* role);
	~User();

	void setId(int id);
	int getId() const;
	void setUsername(char*);
	char* getUsername() const;
	void setPassword(char*);
	char* getPassword() const;
	void setRole(char*);
	char* getRole() const;
};