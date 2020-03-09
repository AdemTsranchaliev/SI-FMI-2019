#include <iostream>

using namespace std;


#include "Product.h"



int main()
{

	Product a=Product();
	
	a.setId(1);
	a.setPrice(3.13);
	a.setName("Adem");

	Product bb = Product(12,2.3,"s");

	cout << bb.getName();
	string s = "";

	return 0;
}