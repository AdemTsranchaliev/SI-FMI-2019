#pragma once
#include "Product.hpp"

class SmartWatch:public Product
{
private:
	char style[50];//woman man or unisex
	char operatingSystem[50];
	char typeDisplay[50];

public:

	SmartWatch();
	SmartWatch(const char* style, const char* operatingSystem, const char* typeDisplay, int id, const char* name , double price);

	void setStyle(const char*);
	char* getStyle();
	void setOperatingSystem(const char*);
	char* getOperatingSystem();
	void setTypeDisplay(const char*);
	char* getTypeDisplay();

	SmartWatch& operator=(SmartWatch&);

	void print();
	void addSmartWatch(const char* style, const char* operatingSystem, const char* typeDisplay, int id, const char* name, double price);
};