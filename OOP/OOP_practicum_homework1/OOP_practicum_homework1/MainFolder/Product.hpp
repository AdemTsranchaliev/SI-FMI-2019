#pragma once
using namespace std;


class Product
{
private:
	int id;
	double price;
	string name;
public:

	Product();
	Product(int, double,string);
	Product(const Product& product);

	Product& operator=(const Product& product);

	void setId(int);
	int getId() const;
	void setPrice(double);
	double getPrice() const;
	void setName(string);
	string getName() const;



};
