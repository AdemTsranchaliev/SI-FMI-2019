#pragma once
#include "Order.hpp"
#include "List.hpp"

class User 
{
private:
	int id;
	char* username;
	char* password;
	char* role;
	List<Order> orders;
public:
	User();
	User(int id,const char* username, const char* password, const char* role);
	~User();
	User& operator=(const User& laptop);

	void setId(int id);
	int getId() const;
	void setUsername(char*);
	char* getUsername() const;
	void setPassword(char*);
	char* getPassword() const;
	void setRole(char*);
	char* getRole() const;
};