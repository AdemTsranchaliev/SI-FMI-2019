#include <iostream>


using namespace std;

#include "Phone.hpp"
#include "Laptop.hpp"
#include "Printer.hpp"
#include "SmartWatch.hpp"
#include "ShoppingCart.hpp"


Laptop laptops[4];
Phone phones[4];
Printer printers[4];
SmartWatch smarthWatches[2];
ShoppingCart shoppingCart[30];

void InsertData();
void SortAndPrint(char*);
void ShowShoppingCart();
void InitialiseShoppingCart();
int FindFirstEmptyIndex();

int main()
{
	InsertData();
	InitialiseShoppingCart();
	cout << "=============================" << endl;
	cout << "Welcome in the SMART SHOP" << endl;
	cout << "=============================" << endl << endl;
	while (true)
	{
		cout << "To see you shopping cart 'PRESS 's'" << endl;
		cout << "Bellow are our categories. To open category, choice the number in front of the category and press ENTER" << endl;
		cout << "1 Laptops" << endl;
		cout << "2 Phones" << endl;
		cout << "3 Printers" << endl;
		cout << "4 Smart Watches" << endl;
		char command[50];

		cin.get(command, 50);

		system("cls");
		if (strcmp(command, "s") == 0)
		{
			ShowShoppingCart();
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			cin.get(command, 50);
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			continue;
		}
		cout << "To go back in main page ENTER 'b'" << endl;
		cout << "To sort products by price ENTER 'sort'" << endl;
		cout << "To see you shopping cart 'ENTER 's'" << endl;
		cout << "To add product in shopping cart ENTER 'add" << endl;
		cout << "============================================================================================================" << endl;
		char categorySelected[50];
		if (strcmp(command, "1") == 0)
		{
			cout << "Laptops" << endl;
			cout << "No | Name | Ram memory | Processor | Video cart | Price" << endl;
			cout << "-----------------------------------------------------------" << endl;
			
			for (int i = 0; i < 4; i++)
			{
				laptops[i].print();
			}
			strcpy_s(categorySelected, "Laptop");
		}
		else if (strcmp(command, "2") == 0)
		{

			cout << "Phones" << endl;
			cout << "No | Name | Color | Model | Year of production | Price" << endl;
			cout << "-----------------------------------------------------------" << endl;
			for (int i = 0; i < 4; i++)
			{
				phones[i].print();
			}
			strcpy_s(categorySelected, "Phone");

		}
		else if (strcmp(command, "3") == 0)
		{
			cout << "Printers" << endl;
			cout << "No | Name | Printing technology | Main format | Printning colors | Price" << endl;
			cout << "-----------------------------------------------------------" << endl;
			for (int i = 0; i < 2; i++)
			{
				printers[i].print();
			}
			strcpy_s(categorySelected, "Printer");

		}
		else if (strcmp(command, "4") == 0)
		{
			cout << "Smart Watches" << endl;
			cout << "No | Name | Style | Operating system | Display type | Price" << endl;
			cout << "-----------------------------------------------------------" << endl;
			for (int i = 0; i < 2; i++)
			{
				smarthWatches[i].print();
			}
			strcpy_s(categorySelected, "SmartWatch");

		}
		else
		{
			system("cls");
			cout << "Invalid input! Enter any key to go back in categories and try again!" << endl;
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			cin.get(command, 50);
			system("cls");

			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
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
			ShowShoppingCart();
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			cin.get(command, 50);
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			continue;

		}
		else if (strcmp(command, "add") == 0)
		{
			int productId = 0;

			cout << "Enter the number of product which you want to add in the shopping cart" << endl;
			cin >> productId;
			int firstFreeIndex = FindFirstEmptyIndex();
			if (firstFreeIndex == -1)
			{
				firstFreeIndex = 20;
			}

			if (strcmp(categorySelected, "Laptop") == 0)
			{
				bool isFound = true;
				for (int i = 0; i < firstFreeIndex; i++)
				{
					if (shoppingCart[i].getProductId() == productId)
					{
						isFound = false;
						shoppingCart[i].setQuantity(shoppingCart[i].getQuantity() + 1);
						cout << "The product was sucessfuly added to shopping cart!" << endl;

						break;
					}
				}
				if (isFound)
				{
					bool isProductIdExist = false;
					int productIndex = 0;
					for (int i = 0; i < 4; i++)
					{
						if (laptops[i].getId() == productId)
						{
							isProductIdExist = true;
							productIndex = i;
						}
					}
					if (isProductIdExist)
					{
						ShoppingCart cart = ShoppingCart(categorySelected, productId, 1, laptops[productIndex].getPrice(), laptops[productIndex].getName());
						shoppingCart[firstFreeIndex] = cart;
						cout << "The product was sucessfuly added to shopping cart!" << endl;
					}
					else
					{
						cout << "In " << categorySelected << "s wasn't found product with given index!" << endl;
					}
				}
			}
			else if (strcmp(categorySelected, "Phone") == 0)
			{
				bool isFound = true;
				for (int i = 0; i < firstFreeIndex; i++)
				{
					if (shoppingCart[i].getProductId() == productId)
					{
						isFound = false;
						shoppingCart[i].setQuantity(shoppingCart[i].getQuantity() + 1);
						cout << "The product was sucessfuly added to shopping cart!" << endl;

						break;
					}
				}
				if (isFound)
				{
					bool isProductIdExist = false;
					int productIndex = 0;
					for (int i = 0; i < 4; i++)
					{
						if (phones[i].getId() == productId)
						{
							isProductIdExist = true;
							productIndex = i;
						}
					}
					if (isProductIdExist)
					{
						ShoppingCart cart = ShoppingCart(categorySelected, productId, 1, phones[productIndex].getPrice(), phones[productIndex].getName());
						shoppingCart[firstFreeIndex] = cart;
						cout << "The product was sucessfuly added to shopping cart!" << endl;

					}
					else
					{
						cout << "In " << categorySelected << "s wasn't found product with given index." << endl;
					}
				}
			}
			else if (strcmp(categorySelected, "Printer") == 0)
			{
				bool isFound = true;
				for (int i = 0; i < firstFreeIndex; i++)
				{
					if (shoppingCart[i].getProductId() == productId)
					{
						isFound = false;
						shoppingCart[i].setQuantity(shoppingCart[i].getQuantity() + 1);
						cout << "The product was sucessfuly added to shopping cart!" << endl;

						break;
					}
				}
				if (isFound)
				{
					bool isProductIdExist = false;
					int productIndex = 0;
					for (int i = 0; i < 2; i++)
					{
						if (printers[i].getId() == productId)
						{
							isProductIdExist = true;
							productIndex = i;
						}
					}
					if (isProductIdExist)
					{
						ShoppingCart cart = ShoppingCart(categorySelected, productId, 1, printers[productIndex].getPrice(), printers[productIndex].getName());
						shoppingCart[firstFreeIndex] = cart;
						cout << "The product was sucessfuly added to shopping cart!" << endl;
					}
					else
					{
						cout << "In " << categorySelected << "s wasn't found product with given index." << endl;
					}
				}
			}
			else if (strcmp(categorySelected, "SmartWatch") == 0)
			{
			bool isFound = true;
			for (int i = 0; i < firstFreeIndex; i++)
			{
				if (shoppingCart[i].getProductId() == productId)
				{
					isFound = false;
					shoppingCart[i].setQuantity(shoppingCart[i].getQuantity() + 1);
					cout << "The product was sucessfuly added to shopping cart!" << endl;

					break;
				}
			}
			if (isFound)
			{
				bool isProductIdExist = false;
				int productIndex = 0;
				for (int i = 0; i < 4; i++)
				{
					if (smarthWatches[i].getId() == productId)
					{
						isProductIdExist = true;
						productIndex = i;
					}
				}
				if (isProductIdExist)
				{
					ShoppingCart cart = ShoppingCart(categorySelected, productId, 1, smarthWatches[productIndex].getPrice(), smarthWatches[productIndex].getName());
					shoppingCart[firstFreeIndex] = cart;
					cout << "The product was sucessfuly added to shopping cart!" << endl;
				}
				else
				{
					cout << "In " << categorySelected << "s wasn't found product with given index." << endl;
				}
			}
			}

			cout << "Press any key to continiue to categories" << endl;
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			cin.get(command, 50);
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
		}
		else if (strcmp(command, "sort") == 0)
		{
			SortAndPrint(categorySelected);
			cout << "Press any key to continiue to categories" << endl;
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			cin.get(command, 50);
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
		}


	}
	system("pause");

	return 0;
}



static void InsertData()
{
	phones[0].addPhone("X", "Black", 2019, 1, "Iphone", 1100);
	phones[1].addPhone("Galaxy S4", "White", 2016, 2, "Samsung", 700);
	phones[2].addPhone("PRO 20", "Black", 2017, 3, "Huawei", 200);
	phones[3].addPhone("4", "Pink", 2011, 4, "Iphone", 450);

	printers[0].addPrinter("RA", "A", true, 5, "ASUS", 200);
	printers[1].addPrinter("Laser", "B", true, 6, "HP", 220);



}

 void InitialiseShoppingCart()
{
	for (int i = 0; i < 40; i++)
	{
		shoppingCart[i].setProductId(-1);
	}
}
int FindFirstEmptyIndex()
{
	int index = -1;
	for (int i = 0; i < 20; i++)
	{
		if (shoppingCart[i].getProductId() == -1)
		{
			index = i;
			break;
		}
	}

	return index;
}
void ShowShoppingCart()
{
	char command[50];
	int lastProductIndex = FindFirstEmptyIndex();
	if (lastProductIndex == 0)
	{
		cout << "There are no products in Shopping Cart" << endl;
		cout << "Press any key to continiue to categories" << endl;

	}
	else
	{
		if (lastProductIndex == -1)
		{
			lastProductIndex = 20;
		}
		system("cls");
		double totalForCart = 0;
		cout << "Shoping cart CHECKOUT" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "No | Category | Name | Price per one | Quantity | Total" << endl;

		for (int i = 0; i < lastProductIndex; i++)
		{
			totalForCart += shoppingCart[i].getPrice()*shoppingCart[i].getQuantity();
			cout << shoppingCart[i].getProductId() << " | " << shoppingCart[i].getProductCategory() << " | " << shoppingCart[i].getName() << " | " << shoppingCart[i].getPrice() << " | " << shoppingCart[i].getQuantity() << " | " << shoppingCart[i].getPrice()*shoppingCart[i].getQuantity() << " leva " << endl;
		}
		cout << "======================" << endl;
		cout << "Total: " << totalForCart << " leva" << endl;
		cout << "======================" << endl;


	}

}
void SortAndPrint(char* category)
{
	system("cls");
	cout << "SORTED"<<endl;
	if (strcmp(category, "Phone") == 0)
	{
		int i, j;
		for (i = 0; i < 4 - 1; i++) {

			for (j = 0; j < 4 - i - 1; j++)
			{
				if (phones[j].getPrice() > phones[j + 1].getPrice())
				{
					Phone temp = phones[j];
					phones[j] = phones[j + 1];
					phones[j + 1] = temp;
				}
			}
		}
		cout << "Phones" << endl;
		cout << "No | Name | Color | Model | Year of production | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;
		for (int i = 0; i < 4; i++)
		{
			phones[i].print();
		}

	}
	else if (strcmp(category, "Printer") == 0)
	{
		int i, j;
		for (i = 0; i < 2 - 1; i++) {

			for (j = 0; j < 2- i - 1; j++)
			{
				if (printers[j].getPrice() > printers[j + 1].getPrice())
				{
					Printer temp = printers[j];
					printers[j] = printers[j + 1];
					printers[j + 1] = temp;
				}
			}
		}
		cout << "Printers" << endl;
		cout << "No | Name | Printing technology | Main format | Printning colors | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;
		for (int i = 0; i < 2; i++)
		{
			printers[i].print();
		}
	}
	else if (strcmp(category, "SmartWatch") == 0)
	{
		int i, j;
		for (i = 0; i < 2 - 1; i++) {

			for (j = 0; j < 2 - i - 1; j++)
			{
				if (smarthWatches[j].getPrice() > smarthWatches[j + 1].getPrice())
				{
					SmartWatch temp = smarthWatches[j];
					smarthWatches[j] = smarthWatches[j + 1];
					smarthWatches[j + 1] = temp;
				}
			}
		}
		cout << "Smart Watches" << endl;
		cout << "No | Name | Style | Operating system | Display type | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;
		for (int i = 0; i < 2; i++)
		{
			smarthWatches[i].print();
		}
	}
	else if (strcmp(category, "Laptop") == 0)
	{
		int i, j;
		for (i = 0; i < 4 - 1; i++) {

			for (j = 0; j < 4 - i - 1; j++)
			{
				if (laptops[j].getPrice() > laptops[j + 1].getPrice())
				{
					Laptop temp = laptops[j];
					laptops[j] = laptops[j + 1];
					laptops[j + 1] = temp;
				}
			}
		}
		cout << "Laptops" << endl;
		cout << "No | Name | Ram memory | Processor | Video cart | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;

		for (int i = 0; i < 4; i++)
		{
			laptops[i].print();
		}
	}
}






