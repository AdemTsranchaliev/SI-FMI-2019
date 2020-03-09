#pragma once

#include "Product.h"

class Laptop:Product
{
private:
	char processor[50];
	int ramMemory;
	char videoCard[60];
public:

	Laptop();

	Laptop(char*,int,char*, int, char*, double);

	void setProcessor(char*);
	char* getProcessor();
	void setRamMemory(int);
	int getRamMemory();
	void setVideoCart(char*);
	char* getVideoCart();
};

