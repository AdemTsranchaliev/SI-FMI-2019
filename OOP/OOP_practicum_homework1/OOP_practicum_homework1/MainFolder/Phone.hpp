#pragma once
#include "Product.hpp"
using namespace std;

class Phone :public Product
{
private:

	string model;
	string color;
	int yearOfProduction;
public:

	Phone();
	Phone(string model,string color, int yearOfProduction,int id ,string name,double price,string category);
	Phone(const Phone& phone);

	Phone& operator=(const Phone& phone);
	bool operator==(const Phone& phone);

	void setModel(string model);
	string getModel() const;
	void setColor(string color);
	string getColor() const;
	void setYearOfProduction(int year);
	int getYearOfProduction() const;

	friend std::istream& operator>>(std::istream& in, Phone& o);
	friend std::ostream& operator<<(std::ostream& in, Phone& o);

	string print();

};
