#pragma once

#include "Product.h"

class Laptop:public Product
{
private:
	char processor[50];
	int ramMemory;
	char videoCard[60];
public:

	Laptop();

	Laptop(char* processor,int ramMemory,char* videoCart, int id, char* name, double price);

	void setProcessor(char*);
	char* getProcessor();
	void setRamMemory(int);
	int getRamMemory();
	void setVideoCart(char*);
	char* getVideoCart();

	void print();
	void addLaptop(char* processor, int ramMemory, char* videoCart, int id, char* name, double price);

};

