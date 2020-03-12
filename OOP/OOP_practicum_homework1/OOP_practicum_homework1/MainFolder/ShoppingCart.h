#pragma once


class ShoppingCart
{
private:
	char* productCategory;//Laptop, Phone ...
	int productId;
	int quantity;
	char* name;
	double price;
public:

	ShoppingCart();
	ShoppingCart(char* productCategory,int productId,int quantity,double price,char* name);

	void setProductCategory(char*);
	char* getProductCategory();
	void setProductId(int);
	int getProductId();
	void setQuantity(int);
	int getQuantity();
	void setPrice(double);
	double getPrice();
	void setName(char*);
	char* getName();

	void print();

	ShoppingCart& operator=(ShoppingCart&);

};