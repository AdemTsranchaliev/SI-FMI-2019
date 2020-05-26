#pragma once
#include <vector>
#include "ShoppingCart.hpp"
using namespace std;

class Order
{
private:
	int id;
	string name;
	string surname;
	string phoneNumber;
	string addressToDelivery;
	string populatedPlace;
	string email;
	bool isConfirmed;
	int userId;

	vector<ShoppingCart> products;

public:

	Order();
	Order(int id,string name, string surname, string phone, string address, string populatedPlace, string email);
	Order(const Order& order);
	Order& operator=(const Order& order);


	void setId(int);
	int getId() const;
	void setName(string);
	string getName() const;
	void setSurname(string);
	string getSurname() const;
	void setPhoneNumber(string);
	string getPhoneNumber() const;
	void setAddressToDelivery(string);
	string getAddressToDelivery() const;
	void setPopulatedPlace(string);
	string getPopulatedPlace() const;
	void setEmail(string);
	string getEmail() const;
	vector<ShoppingCart> getProducts() const;
	void setUserId(int);
	int getUserId() const;
	void setCofirmation(bool conf);


	void confirmOrder();
	bool getIsConfirmed() const;

	void addProductToShoppingCart(const ShoppingCart& product);

	friend std::istream& operator>>(std::istream& in, Order& order);
	friend std::ostream& operator<<(std::ostream& out, Order& order);

	void print();
	void printDetail();
};


