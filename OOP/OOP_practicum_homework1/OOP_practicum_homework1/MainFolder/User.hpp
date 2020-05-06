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
	void setUsername(const char*);
	char* getUsername() const;
	void setPassword(const char*);
	char* getPassword() const;
	void setRole(const char*);
	char* getRole() const;

	void addNewOrder(const Order& order);

	friend std::istream& operator>>(std::istream& in, User& user);

	void print();

};