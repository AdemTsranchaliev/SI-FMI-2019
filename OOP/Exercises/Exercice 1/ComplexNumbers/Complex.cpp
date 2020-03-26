#include <iostream>
#include "Complex.hpp"

using namespace std;


Complex::Complex() 
{
	this->imaginery = 0;
	this->real = 0;
}
Complex::Complex(double real, double imaginery)
{
	this->real = real;
	this->imaginery = imaginery;
}

void Complex::Add(const Complex& complex)
{
	this->real += complex.real;
	this->imaginery += complex.imaginery;
}
void Complex::Mulptiply(const Complex& complex)
{
	double tempReal = (this->real*complex.real) + (this->imaginery*complex.imaginery)*(-1);
	double tempImaginery = (this->real*complex.imaginery) + (this->imaginery*complex.real);
	this->real = tempReal;
	this->imaginery = tempImaginery;
}
void Complex::Print()
{
	if (this->imaginery>0)
	{
		cout << this->real << " + " << this->imaginery << "i";
	}
	else if (this->imaginery<0)
	{
		cout << this->real << " - " << this->imaginery*-1 << "i";
	}
	else
	{
		cout << this->real;
	}
}