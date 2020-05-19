#pragma once

#include "Phone.hpp"
#include "Laptop.hpp"
#include "Printer.hpp"
#include "ShoppingCart.hpp"
#include "List.hpp"
#include "ShoppingCart.hpp"
#include "Order.hpp"
#include "User.hpp"
using namespace std;

class Shop
{
private:
	List<Laptop> laptops;
	List<Phone> phones;
	List<Printer> printers;
	List<ShoppingCart> shoppingCart;
	List<Order> orders;
	List<User> users;

	User authenticatedUser;


	int CheckIfProductExistInShoppingCart(int productId);
	int CheckIfProductExistInGivenCategory(int productId, int category);
	bool checkIfUsernameIsUnique(string username);
	void ClearShoppingCart();
public:

	Shop();

	void InsertData();
	void SortAndPrint(int);
	void ShowShoppingCart();
	void MakeOrder();

	void PrintCategory(int);
	void PrintCategoryName(int);
	int AddProductInShoppingCart(int productId, int category);
	bool Authenticate(string username, string password);

	string getAuthenticateUserUsername();
	string getAuthenticateUserRole();
	bool isAuthenticated();
	bool isAuthorized(const char* role);
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
	void addSmartWatch();


};

