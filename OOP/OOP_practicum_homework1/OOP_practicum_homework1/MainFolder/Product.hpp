#pragma once


class Product
{
private:
	int id;
	double price;
	char name[50];
public:

	Product();
	Product(int, double,const char*);


	void setId(int);
	int getId();
	void setPrice( double);
	double getPrice();
	void setName(const char*);
	char* getName();



};
