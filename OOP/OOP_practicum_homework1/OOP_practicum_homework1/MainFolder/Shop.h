#pragma once

#include "Phone.hpp"
#include "Laptop.hpp"
#include "Printer.hpp"
#include "ShoppingCart.hpp"
#include "List.hpp"
#include "ShoppingCart.hpp"
#include "Order.hpp"
#include "User.hpp"
#include "Security.h"

#include <string>
using namespace std;

class Shop
{
private:
	List<Product*> products;
	List<ShoppingCart> shoppingCart;
	List<Order> orders;
	List<User> users;

	int CheckIfProductExistInShoppingCart(int productId);
	int CheckIfProductExistInGivenCategory(int productId, string category);
	bool checkIfUsernameIsUnique(string username);
	void ClearShoppingCart();

public:
	Security security;

	Shop();

	void InsertData();
	void SortAndPrint(string);
	void ShowShoppingCart();
	void MakeOrder();
	string GetCategoryByNum(int);

	void PrintCategory(string);
	int AddProductInShoppingCart(int productId, string category);

	void registation();
	void login();

	//Only for users with role ROLE_ADMIN
	void seeAllOrders();
	void makeUserAdminOrUser(int id);

	bool checkIfOrderExist(int id);
	void seeAllUsers();
	Order& seeOrder(int id);
	void addProduct();
	void addLaptop();
	void addPhone();
	void addPrinter();


};

