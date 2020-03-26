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
	~Phone();

	void setModel(const char* model);
	char* getModel() const;
	void setColor(const char* color);
	char* getColor() const;
	void setYearOfProduction(int year);
	int getYearOfProduction() const;

	Phone& operator=(Phone&);

	void print();
	void addPhone(const char* model, const char* color, int yearOfProduction, int id, const char* name, double price);
};
