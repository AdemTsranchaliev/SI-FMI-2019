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
void SortAndPrint(char*);
void ShowShoppingCart();
void PrintCategory(char*);

template <typename T>
void Sort(T&);




int CheckIfProductExistInShoppingCart(int productId);
int CheckIfProductExistInGivenCategory(int productId,char* category);
int AddProductInShoppingCart(int productId, int category);

int main()
{
	InsertData();
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
		

		int categorySelected=0;
		
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

			AddProductInShoppingCart(productId,categorySelected)
			

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
	Phone phone2("X", "Black", 2019, 1, "Iphone", 1100);
	Phone phone3("X", "Black", 2019, 1, "Iphone", 1100);
	Phone phone4("X", "Black", 2019, 1, "Iphone", 1100);
	phones.add(phone1);
	phones.add(phone2);
	phones.add(phone3);
	phones.add(phone4);

	Printer printer1("RA", "A", true, 5, "ASUS", 200);
	Printer printer2("Laser", "B", true, 6, "HP", 220);


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
}


void PrintCategory(char* category)
{
	cout << "To go back in main page ENTER 'b'" << endl;
	cout << "To sort products by price ENTER 'sort'" << endl;
	cout << "To see you shopping cart 'ENTER 's'" << endl;
	cout << "To add product in shopping cart ENTER 'add" << endl;
	cout << "============================================================================================================" << endl;

	if (strcmp(category, "1") == 0)
	{
		cout << "Laptops" << endl;
		cout << "No | Name | Ram memory | Processor | Video cart | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;

		for (int i = 0; i < laptops.Count(); i++)
		{
			laptops.getAt(i).print();
		}
	}
	else if (strcmp(category, "2") == 0)
	{

		cout << "Phones" << endl;
		cout << "No | Name | Color | Model | Year of production | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;
		for (int i = 0; i < phones.Count(); i++)
		{
			phones.getAt(i).print();
		}

	}
	else if (strcmp(category, "3") == 0)
	{
		cout << "Printers" << endl;
		cout << "No | Name | Printing technology | Main format | Printning colors | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;
		for (int i = 0; i < printers.Count(); i++)
		{
			printers.getAt(i).print();
		}

	}
	else if (strcmp(category, "4") == 0)
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



int CheckIfProductExistInGivenCategory(int productId,char* category)
{
	int index = -1;
	if (strcmp(category, "Laptop") == 0)
	{
		for (int i = 0; i < laptops.Count(); i++)
		{
			if (laptops.getAt(i).getId() == 0)
			{
				index = i;
				break;
			}
		}
	}
	else if (strcmp(category, "Phone") == 0)
	{
		for (int i = 0; i < phones.Count(); i++)
		{
			if (laptops.getAt(i).getId() == 0)
			{
				index = i;
				break;
			}
		}
	}
	else if (strcmp(category, "Printer") == 0)
	{
		for (int i = 0; i < printers.Count(); i++)
		{
			if (laptops.getAt(i).getId() == 0)
			{
				index = i;
				break;
			}
		}
	}
	else if (strcmp(category, "SmartWatch") == 0)
	{
		for (int i = 0; i < smarthWatches.Count(); i++)
		{
			if (laptops.getAt(i).getId() == 0)
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
		if (shoppingCart.getAt(i).getProductId() == 0)
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
void Sort(T& t)
{
	int i, j;
	for (i = 0; i < t.Count() - 1; i++) {

		for (j = 0; j < t.Count() - i - 1; j++)
		{
			if (t.getAt(j).getPrice() > t.getAt(j + 1).getPrice())
			{
				t temp = t.getAt(j);
				t.getAt(j) = t.getAt(j + 1);
				t.getAt(j + 1) = temp;
			}
		}
	}
}
void SortAndPrint(char* category)
{
	system("cls");
	cout << "SORTED"<<endl;
	if (strcmp(category, "Phone") == 0)
	{
		Sort(phones);
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
		Sort(printers);

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
		Sort(smarthWatches);

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
		Sort(laptops);

		cout << "Laptops" << endl;
		cout << "No | Name | Ram memory | Processor | Video cart | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;

		for (int i = 0; i < 4; i++)
		{
			laptops[i].print();
		}
	}
}






