#pragma once
#include "Product.h"

class SmartWatch:public Product
{
private:
	char style[50];//woman man or unisex
	char operatingSystem[50];
	char typeDisplay[50];

public:

	SmartWatch();
	SmartWatch(char* style,char* operatingSystem,char* typeDisplay, int id, char* name , double price);

	void setStyle(char*);
	char* getStyle();
	void setOperatingSystem(char*);
	char* getOperatingSystem();
	void setTypeDisplay(char*);
	char* getTypeDisplay();

	SmartWatch& operator=(SmartWatch&);

	void print();
	void addSmartWatch(char* style, char* operatingSystem, char* typeDisplay, int id, char* name, double price);
};