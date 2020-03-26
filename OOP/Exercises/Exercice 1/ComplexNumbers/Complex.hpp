#pragma once
class Complex
{
private:
	double imaginery;
	double real;
public:
	Complex();
	Complex(double real,double imaginery);

	void Add(const Complex& complex);
	void Mulptiply(const Complex& complex);
	void Print();
};

