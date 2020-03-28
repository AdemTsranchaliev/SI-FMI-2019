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
	Laptop(const Laptop& laptop);
	~Laptop();
	Laptop& operator=(const Laptop& laptop);
	bool operator==(const Laptop& laptop);

	void setProcessor(const char*);
	char* getProcessor() const;
	void setRamMemory(int);
	int getRamMemory() const;
	void setVideoCart(const char*);
	char* getVideoCart() const;

	void print();

};

