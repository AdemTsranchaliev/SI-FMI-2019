#pragma once

#include <vector>
#include "Order.hpp"
using namespace std;

class User 
{
private:
	int id;
	string username;
	string password;
	string role;

	vector<Order> orders;

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

	vector<Order>& getOrders();
	void addNewOrder(const Order& order);

	friend std::istream& operator>>(std::istream& in, User& user);
	friend std::ostream& operator<<(std::ostream& out, User& user);

	void print();

};