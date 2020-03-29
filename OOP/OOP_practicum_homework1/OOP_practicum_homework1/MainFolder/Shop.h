#pragma once

#include "Phone.hpp"
#include "Laptop.hpp"
#include "Printer.hpp"
#include "SmartWatch.hpp"
#include "ShoppingCart.hpp"
#include "List.hpp"

class Shop
{
private:
	List<Laptop> laptops;
	List<Phone> phones;
	List<Printer> printers;
	List<SmartWatch> smarthWatches;
	List<ShoppingCart> shoppingCart;

	int CheckIfProductExistInShoppingCart(int productId);
	int CheckIfProductExistInGivenCategory(int productId, int category);

public:

	Shop();

	void InsertData();
	void SortAndPrint(int);
	void ShowShoppingCart();
	void PrintCategory(int);
	void PrintCategoryName(int);
	int AddProductInShoppingCart(int productId, int category);
};

