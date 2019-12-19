#include <iostream>
#include <string>

using namespace std;

int main() {

	string fruit;
	cin >> fruit;

	string day;
	cin >> day;

	double quantity;
	cin >> quantity;

	double price = 0.0;

	cout.setf(ios::fixed);
	cout.precision(2);
	//banana / apple / orange / grapefruit / kiwi / pineapple / grapes
	//Monday / Tuesday / Wednesday / Thursday / Friday / Saturday / Sunday
	if (day == "Monday" || day == "Tuesday" || day == "Wednesday" || day == "Thursday" || day == "Friday") {

		if (fruit == "banana")
		{
			price = price * 2.5 * quantity;
			cout << price;
		}
		else if (fruit == "apple")
		{
			price = price * 1.2 * quantity;
			cout << price;
		}
		else if (fruit == "orange")
		{
			price = price * 0.85 * quantity;
			cout << price;

		}
		else if (fruit == "grapefruit")
		{
			price = price * 1.45 * quantity;
			cout << price;
		}
		else if (fruit == "kiwi")
		{
			price = price * 2.70 * quantity;
			cout << price;
		}
		else if (fruit == "pineapple")
		{
			price = price * 5.5 * quantity;
			cout << price;
		}
		else if (fruit == "grapes")
		{
			price = price * 3.85 * quantity;
			cout << price;
		}
	}
	else if (day == "Saturday" || day == "Sunday")
	{
		if (fruit == "banana")
		{
			price = price * 2.7 * quantity;
			cout << price;
		}
		else if (fruit == "apple")
		{
			price = price * 1.25 * quantity;
			cout << price;
		}
		else if (fruit == "orange")
		{
			price = price * 0.9 * quantity;
			cout << price;

		}
		else if (fruit == "grapefruit")
		{
			price = price * 1.60 * quantity;
			cout << price;
		}
		else if (fruit == "kiwi")
		{
			price = price * 3 * quantity;
			cout << price;
		}
		else if (fruit == "pineapple")
		{
			price = price * 5.60 * quantity;
			cout << price;
		}
		else if (fruit == "grapes")
		{
			price = price * 4.20 * quantity;
			cout << price;
		}

	}
	return 0;
}