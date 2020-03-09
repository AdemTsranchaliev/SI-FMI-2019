#pragma once
#include "Product.h"

class SmartWatch:Product
{
private:
	char style[50];//woman man or unisex
	char operatingSystem[50];
	char typeDisplay[50];

public:

	SmartWatch();
	SmartWatch(char*,char*,char*, int, char*, double);

	void setStyle(char*);
	char* getStyle();
	void setOperatingSystem(char*);
	char* getOperatingSystem();
	void setTypeDisplay(char*);
	char* getTypeDisplay();
};