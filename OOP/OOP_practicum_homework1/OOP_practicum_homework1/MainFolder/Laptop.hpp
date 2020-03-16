#pragma once

#include "Product.hpp"

class Laptop:public Product
{
private:
	char processor[50];
	int ramMemory;
	char videoCard[60];
public:

	Laptop();
	Laptop(const char* processor,int ramMemory, const char* videoCart, int id, const char* name, double price);

	void setProcessor(const char*);
	char* getProcessor();
	void setRamMemory(int);
	int getRamMemory();
	void setVideoCart(const char*);
	char* getVideoCart();

	Laptop& operator=(Laptop&);

	void print();
	void addLaptop(const char* processor, int ramMemory, const char* videoCart, int id, const char* name, double price);

};

