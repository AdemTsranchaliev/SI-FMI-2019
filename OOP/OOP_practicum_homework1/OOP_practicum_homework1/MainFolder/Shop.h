#pragma once

#include "Phone.hpp"
#include "Laptop.hpp"
#include "Printer.hpp"
#include "ShoppingCart.hpp"
#include "List.hpp"
#include "ShoppingCart.hpp"
#include "Order.hpp"
#include "User.hpp"
#include <string>
using namespace std;

class Shop
{
private:
	List<Product*> products;

	List<ShoppingCart> shoppingCart;
	List<Order> orders;
	List<User> users;

	User authenticatedUser;


	int CheckIfProductExistInShoppingCart(int productId);
	int CheckIfProductExistInGivenCategory(int productId, string category);
	bool checkIfUsernameIsUnique(string username);
	void ClearShoppingCart();
public:

	Shop();

	void InsertData();
	void SortAndPrint(string);
	void ShowShoppingCart();
	void MakeOrder();
	string GetCategoryByNum(int);

	void PrintCategory(string);
	int AddProductInShoppingCart(int productId, string category);
	bool Authenticate(string username, string password);

	string getAuthenticateUserUsername();
	string getAuthenticateUserRole();
	bool isAuthenticated();
	bool isAuthorized(string role);
	void registation();
	void logOut();

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

