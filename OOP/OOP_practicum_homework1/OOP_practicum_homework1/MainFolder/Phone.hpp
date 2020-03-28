#pragma once
#include "Product.hpp"

class Phone :public Product
{
private:

	char* model;
	char* color;
	int yearOfProduction;
public:

	Phone();
	Phone(const char* model,const char* color, int yearOfProduction,int id ,const char* name,double price);
	Phone(const Phone& phone);
	~Phone();

	Phone& operator=(const Phone& phone);
	bool operator==(const Phone& phone);

	void setModel(const char* model);
	char* getModel() const;
	void setColor(const char* color);
	char* getColor() const;
	void setYearOfProduction(int year);
	int getYearOfProduction() const;

	void print();

};
