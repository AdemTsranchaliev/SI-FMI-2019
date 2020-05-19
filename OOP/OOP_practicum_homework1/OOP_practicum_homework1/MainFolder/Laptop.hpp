#pragma once

#include "Product.hpp"
using namespace std;

class Laptop:public Product
{
private:
	string processor;
	int ramMemory;
	string videoCard;
public:

	Laptop();
	Laptop(string processor,int ramMemory, string videoCart, int id, string  name, double price,string category);
	Laptop(const Laptop& laptop);

	Laptop& operator=(const Laptop& laptop);
	bool operator==(const Laptop& laptop);

	void setProcessor(string);
	string getProcessor() const;
	void setRamMemory(int);
	int getRamMemory() const;
	void setVideoCart(string);
	string getVideoCart() const;

	friend std::istream& operator>>(std::istream& in, Laptop& laptop);


	void print();

};

