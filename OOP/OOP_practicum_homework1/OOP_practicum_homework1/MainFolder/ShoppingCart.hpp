#pragma once

using namespace std;

class ShoppingCart
{
private:
	string productCategory;//1-Laptop, 1-Phone ...
	int productId;
	int quantity;
	string name;
	double price;
public:

	ShoppingCart();
	ShoppingCart(string productCategory,int productId,int quantity,double price, string name);
	ShoppingCart(const ShoppingCart& shoppingCart);

	ShoppingCart& operator=(const ShoppingCart& shoppingCart);

	void setProductCategory(string);
	string getProductCategory() const;
	void setProductId(int);
	int getProductId() const;
	void setQuantity(int);
	int getQuantity() const;
	void setPrice(double);
	double getPrice() const;
	void setName(string);
	string getName() const;

	void print();


};