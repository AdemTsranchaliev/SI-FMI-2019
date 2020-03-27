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
	ShoppingCart(const ShoppingCart& shoppingCart);
	~ShoppingCart();
	ShoppingCart& operator=(const ShoppingCart& laptop);

	void setProductCategory(char*);
	char* getProductCategory() const;
	void setProductId(int);
	int getProductId() const;
	void setQuantity(int);
	int getQuantity() const;
	void setPrice(double);
	double getPrice() const;
	void setName(char*);
	char* getName() const;

	void print();


};