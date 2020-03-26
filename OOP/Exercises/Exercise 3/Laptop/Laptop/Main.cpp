#include "Laptop.hpp"
#include "Proccessor.hpp"

#include <iostream>

#pragma warning (disable:4996)
int main()
{
	Proccessor intelCore(2.7, 4, 3);
	Laptop assus("Assus", "VivoBook S14", 1600.0, 14.0, 8.0, 2500, intelCore);
	Laptop lenovo("Lenovo","Thinkpad X1 Carbon", 2800.0, 12.0, 16.0, 3000, intelCore);

	assus.Print();
	lenovo.Print();

	std::cout << (assus == lenovo) << std::endl;
	std::cout << (assus != lenovo) << std::endl;
	std::cout << (assus < lenovo) << std::endl;
	std::cout << (assus > lenovo) << std::endl;
	
	return 0;
}