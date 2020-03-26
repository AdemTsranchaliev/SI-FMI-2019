#pragma once

#include "Product.hpp"

class Laptop:public Product
{
private:
	char* processor;
	int ramMemory;
	char* videoCard;
public:

	Laptop();
	Laptop(const char* processor,int ramMemory, const char* videoCart, int id, const char* name, double price);
	~Laptop();

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

