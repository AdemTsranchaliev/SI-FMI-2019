#include <iostream>
#include "Complex.hpp"
using namespace std;

int main()
{
	Complex comp1 = Complex(2, 5);
	Complex comp2 = Complex(4,-3);
	comp1.Mulptiply(comp2);
	comp1.Print();
	cout << endl;
	comp2.Print();
	
	system("pause");
	return 0;
}