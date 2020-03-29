#include <iostream>


using namespace std;

#include "Shop.h"
char command[50];

void GetCommandPressAnyKeyToContiniue();

int main()
{

	Shop shop;
	



	cout << "=============================" << endl;
	cout << "Welcome in the SMART SHOP" << endl;
	cout << "=============================" << endl << endl;
	int categorySelected = 0;
	while (true)
	{
		cout << "To see you shopping cart 'PRESS 's'" << endl;
		cout << "Bellow are our categories. To open category, choice the number in front of the category and press ENTER" << endl;
		cout << "1 Laptops" << endl;
		cout << "2 Phones" << endl;
		cout << "3 Printers" << endl;
		cout << "4 Smart Watches" << endl;

		

		cin.get(command, 50);

		system("cls");
		if (strcmp(command, "s") == 0)
		{
			shop.ShowShoppingCart();
			GetCommandPressAnyKeyToContiniue();
		
			system("cls");
			
			continue;
		}
		else if (command[0]>='1'&&command[0]<='4'&&command[1]=='\0')
		{
			categorySelected = command[0] - '0';
			shop.PrintCategory(categorySelected);
		}
		else
		{
			system("cls");
			cout << "Invalid input! Enter any key to go back in categories and try again!" << endl;
			GetCommandPressAnyKeyToContiniue();
			system("cls");

			continue;
		}

		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');
		cin.get(command, 50);

		if (strcmp(command, "b") == 0)
		{
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			continue;
		}
		else if (strcmp(command, "s") == 0)
		{
			shop.ShowShoppingCart();
			GetCommandPressAnyKeyToContiniue();

			system("cls");
		
			continue;

		}
		else if (strcmp(command, "add") == 0)
		{
			int productId = 0;

			cout << "Enter the number of product which you want to add in the shopping cart" << endl;
			cin >> productId;

			shop.AddProductInShoppingCart(productId, categorySelected);
			

			cout << "Press any key to continiue to categories" << endl;
			GetCommandPressAnyKeyToContiniue();
			system("cls");
			
		}
		else if (strcmp(command, "sort") == 0)
		{
			shop.SortAndPrint(categorySelected);

			GetCommandPressAnyKeyToContiniue();

			system("cls");
		}

	}
	system("pause");

	return 0;
}



void GetCommandPressAnyKeyToContiniue()
{
	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');
	cin.get(command, 50);
	system("cls");
	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');
}