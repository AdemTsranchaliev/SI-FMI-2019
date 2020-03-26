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
	~ShoppingCart();

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

	ShoppingCart& operator=(ShoppingCart&);

	void print();


};