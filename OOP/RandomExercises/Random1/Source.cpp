#include <iostream>

using namespace std;

class Rational
{
private:
    int num;
    int denom;
public:
	void set_num(int num)
	{
		this->num = num;
	}
	int get_num()
	{
		return this->num;
	}

	void set_denom(int denom)
	{
		this->denom = denom;
	}
	int get_demon()
	{
		return this->denom;
	}

};


int main()
{
	Rational num;

	num.set_denom(1);
	num.set_num(2);
	int num1 = num.get_num();
	int denom = num.get_demon();
	cout << num1 <<"/" << denom;
	
	system("pause");

	return 0;

}