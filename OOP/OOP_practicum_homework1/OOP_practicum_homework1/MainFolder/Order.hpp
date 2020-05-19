#pragma once
#include "ShoppingCart.hpp"
#include "List.hpp"
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

	List<ShoppingCart> products;

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
	
	void confirmOrder();
	bool getIsConfirmed() const;

	void addProductToShoppingCart(const ShoppingCart& product);

	friend std::istream& operator>>(std::istream& in, Order& order);

	void print();
	void printDetail();
};


