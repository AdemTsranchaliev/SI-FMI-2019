#pragma once
#include "Product.hpp"

class SmartWatch:public Product
{
private:
	char* style;//woman man or unisex
	char* operatingSystem;
	char* typeDisplay;

public:

	SmartWatch();
	SmartWatch(const char* style, const char* operatingSystem, const char* typeDisplay, int id, const char* name , double price);
	SmartWatch(const SmartWatch& smartWatch);
	~SmartWatch();

	SmartWatch& operator=(const SmartWatch&);
	bool operator==(const SmartWatch&);

	void setStyle(const char*);
	char* getStyle() const;
	void setOperatingSystem(const char*);
	char* getOperatingSystem() const;
	void setTypeDisplay(const char*);
	char* getTypeDisplay() const;

	friend std::istream& operator>>(std::istream& in, SmartWatch& o);


	void print();
};