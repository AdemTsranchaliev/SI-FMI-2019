#pragma once


class ShoppingCart
{
private:
	int productCategory;//1-Laptop, 1-Phone ...
	int productId;
	int quantity;
	char* name;
	double price;
public:

	ShoppingCart();
	ShoppingCart(int productCategory,int productId,int quantity,double price,char* name);
	ShoppingCart(const ShoppingCart& shoppingCart);
	~ShoppingCart();
	ShoppingCart& operator=(const ShoppingCart& shoppingCart);
	bool operator==(const ShoppingCart& laptop);

	void setProductCategory(int);
	int getProductCategory() const;
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