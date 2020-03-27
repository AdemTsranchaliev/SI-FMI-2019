#pragma once


class Product
{
private:
	int id;
	double price;
	char* name;
public:

	Product();
	Product(int, double,const char*);
	Product(const Product& product);
	~Product();
	Product& operator=(const Product& product);

	void setId(int);
	int getId() const;
	void setPrice(double);
	double getPrice() const;
	void setName(const char*);
	char* getName() const;



};
