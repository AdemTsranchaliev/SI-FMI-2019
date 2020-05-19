#pragma once
#include "Order.hpp"
#include "List.hpp"
using namespace std;

class User 
{
private:
	int id;
	string username;
	string password;
	string role;

	List<Order> orders;

public:
	User();
	User(int id,string username, string password, string role);
	User& operator=(const User& laptop);

	void setId(int id);
	int getId() const;
	void setUsername(string);
	string getUsername() const;
	void setPassword(string);
	string getPassword() const;
	void setRole(string);
	string getRole() const;

	void addNewOrder(const Order& order);

	friend std::istream& operator>>(std::istream& in, User& user);

	void print();

};