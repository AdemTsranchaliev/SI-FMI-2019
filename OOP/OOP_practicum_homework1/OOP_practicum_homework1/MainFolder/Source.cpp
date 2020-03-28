#include <iostream>


using namespace std;

#include "Phone.hpp"
#include "Laptop.hpp"
#include "Printer.hpp"
#include "SmartWatch.hpp"
#include "ShoppingCart.hpp"
#include "List.hpp"




 List<Laptop> laptops;
 List<Phone> phones;
 List<Printer> printers;
 List<SmartWatch> smarthWatches;
 List<ShoppingCart> shoppingCart;


void InsertData();
void SortAndPrint(int);
void ShowShoppingCart();
void PrintCategory(int);

template <typename T>
void Sort(List<T>&);



void PrintCategory(int category);
int CheckIfProductExistInShoppingCart(int productId);
int CheckIfProductExistInGivenCategory(int productId,int category);
int AddProductInShoppingCart(int productId, int category);

int main()
{


	InsertData();
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
		else if (command[0]>='1'&&command[0]<='4'&&command[1]=='\0')
		{
			categorySelected = command[0] - '0';
			PrintCategory(categorySelected);
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

			AddProductInShoppingCart(productId, categorySelected);
			

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
	Phone phone1("X", "Black", 2019, 1, "Iphone", 1100);
	Phone phone2("Galaxy S4", "White", 2016, 2, "Samsung", 700);
	Phone phone3("PRO 20", "Black", 2017, 3, "Huawei", 200);
	Phone phone4("4", "Pink", 2011, 4, "Iphone", 450);
	phones.add(phone1);
	phones.add(phone2);
	phones.add(phone3);
	phones.add(phone4);

	Printer printer1("RA", "A", true, 5, "ASUS", 200);
	Printer printer2("Laser", "B", true, 6, "HP", 220);

	printers.add(printer1);
	printers.add(printer2);
}



int AddProductInShoppingCart(int productId, int category)
{

	int productIndex = CheckIfProductExistInGivenCategory(productId, category);
	int index = CheckIfProductExistInShoppingCart(productId);

	if (productIndex != -1)
	{
		if (index!=-1)
		{
			shoppingCart.getAt(index).setQuantity(shoppingCart.getAt(index).getQuantity() + 1);		
		}
		else
		{
			ShoppingCart cart;
			if (category== 1)
			{

				cart = ShoppingCart(category, productId, 1, laptops.getAt(productIndex).getPrice(), laptops.getAt(productIndex).getName());
				
			}
			else if (category == 2)
			{	
			    cart = ShoppingCart(category, productId, 1, phones.getAt(productIndex).getPrice(), phones.getAt(productIndex).getName());
			}
			else if (category == 3)
			{
			 cart = ShoppingCart(category, productId, 1, printers.getAt(productIndex).getPrice(), printers.getAt(productIndex).getName());
		
			}
			else if (category == 4)
			{
				 cart = ShoppingCart(category, productId, 1, smarthWatches.getAt(productIndex).getPrice(), smarthWatches.getAt(productIndex).getName());
			}
			shoppingCart.add(cart);
		
		}
		cout << "The product was sucessfuly added to shopping cart!" << endl;
	}
	else
	{
		cout << "In " << category << "s wasn't found product with given index!" << endl;
	}
	return 0;
}


void PrintCategory(int category)
{
	cout << "To go back in main page ENTER 'b'" << endl;
	cout << "To sort products by price ENTER 'sort'" << endl;
	cout << "To see you shopping cart 'ENTER 's'" << endl;
	cout << "To add product in shopping cart ENTER 'add" << endl;
	cout << "============================================================================================================" << endl;

	if (category == 1)
	{
		cout << "Laptops" << endl;
		cout << "No | Name | Ram memory | Processor | Video cart | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;

		for (int i = 0; i < laptops.Count(); i++)
		{
			laptops.getAt(i).print();
		}
	}
	else if (category ==2)
	{

		cout << "Phones" << endl;
		cout << "No | Name | Color | Model | Year of production | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;
		for (int i = 0; i < phones.Count(); i++)
		{
			phones.getAt(i).print();
		}

	}
	else if (category == 3)
	{
		cout << "Printers" << endl;
		cout << "No | Name | Printing technology | Main format | Printning colors | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;
		for (int i = 0; i < printers.Count(); i++)
		{
			printers.getAt(i).print();
		}

	}
	else if (category == 4)
	{
		cout << "Smart Watches" << endl;
		cout << "No | Name | Style | Operating system | Display type | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;
		for (int i = 0; i < smarthWatches.Count(); i++)
		{
			smarthWatches.getAt(i).print();
		}
	}
}



int CheckIfProductExistInGivenCategory(int productId,int category)
{
	int index = -1;
	if (category == 1)
	{
		for (int i = 0; i < laptops.Count(); i++)
		{
			if (laptops.getAt(i).getId() == productId)
			{
				index = i;
				break;
			}
		}
	}
	else if (category == 2)
	{
		for (int i = 0; i < phones.Count(); i++)
		{
			if (phones.getAt(i).getId() == productId)
			{
				index = i;
				break;
			}
		}
	}
	else if (category == 3)
	{
		for (int i = 0; i < printers.Count(); i++)
		{
			if (printers.getAt(i).getId() == productId)
			{
				index = i;
				break;
			}
		}
	}
	else if (category == 4)
	{
		for (int i = 0; i < smarthWatches.Count(); i++)
		{
			if (smarthWatches.getAt(i).getId() == productId)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}
int CheckIfProductExistInShoppingCart(int productId)
{
	int index = -1;

	for (int i = 0; i < shoppingCart.Count(); i++)
	{
		if (shoppingCart.getAt(i).getProductId() == productId)
		{
			index = i;
			break;
		}
	}
	
	return index;
}
void ShowShoppingCart()
{


	if (shoppingCart.Count() == 0)
	{
		cout << "There are no products in Shopping Cart" << endl;
		cout << "Press any key to continiue to categories" << endl;
	}
	else
	{
		system("cls");
		double totalForCart = 0;
		cout << "Shoping cart CHECKOUT" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "No | Category | Name | Price per one | Quantity | Total" << endl;

		for (int i = 0; i < shoppingCart.Count(); i++)
		{
			totalForCart += shoppingCart.getAt(i).getPrice()*shoppingCart.getAt(i).getQuantity();
			shoppingCart.getAt(i).print();
		}
		cout << "======================" << endl;
		cout << "Total: " << totalForCart << " leva" << endl;
		cout << "======================" << endl;

	}

}

template <typename T>
void Sort(List<T> &t)
{
	int i, j;
	for (i = 0; i < t.Count() - 1; i++) {

		for (j = 0; j < t.Count() - i - 1; j++)
		{
			if (t.getAt(j).getPrice() > t.getAt(j + 1).getPrice())
			{
				T temp;
				temp=(t.getAt(j));
				t.getAt(j) = t.getAt(j + 1);
				t.getAt(j + 1) = temp;
			}
		}
	}
}

void SortAndPrint(int category)
{
	system("cls");
	cout << "SORTED"<<endl;
	if (category == 1)
	{
		Sort(laptops);
		PrintCategory(1);

	}
	else if (category == 2)
	{
		Sort(phones);
		PrintCategory(2);
	}
	else if (category == 3)
	{
		Sort(printers);
		PrintCategory(3);
	}
	else if (category == 4)
	{
		Sort(smarthWatches);
		PrintCategory(4);
	}
	
}






