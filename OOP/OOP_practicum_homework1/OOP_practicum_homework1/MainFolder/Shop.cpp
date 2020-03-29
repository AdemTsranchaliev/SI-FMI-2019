#include <iostream>
#include "Shop.h"

using namespace std;





Shop::Shop()
{
	InsertData();
}

void Shop::InsertData()
{
	Phone phone1("X", "Black", 2019, 1, "Iphone", 1100);
	Phone phone2("Galaxy S4", "White", 2016, 2, "Samsung", 700);
	Phone phone3("PRO 20", "Black", 2017, 3, "Huawei", 200);
	Phone phone4("4", "Pink", 2011, 4, "Iphone", 450);
	phones.add(phone1);
	phones.add(phone2);
	phones.add(phone3);
	phones.add(phone4);
	phone1.setColor("");
	Printer printer1("RA", "A", true, 5, "ASUS", 200);
	Printer printer2("Laser", "B", true, 6, "HP", 220);

	printers.add(printer1);
	printers.add(printer2);

	Laptop laptop1("Intel", 4, "NVidia", 7, "Lenovo", 799);
	Laptop laptop2("Intel Core i7", 4, "NVidia GEFORCE 940mx", 8, "Asus", 799);
	laptops.add(laptop1);
	laptops.add(laptop2);

	SmartWatch smartWatch("Women", "IOS", "Liquid RETINA", 9, "IWatch", 900);
	smarthWatches.add(smartWatch);

}



int Shop::AddProductInShoppingCart(int productId, int category)
{

	int productIndex = CheckIfProductExistInGivenCategory(productId, category);
	int index = CheckIfProductExistInShoppingCart(productId);

	if (productIndex != -1)
	{
		if (index != -1)
		{
			shoppingCart.getAt(index).setQuantity(shoppingCart.getAt(index).getQuantity() + 1);
		}
		else
		{
			ShoppingCart cart;
			if (category == 1)
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
		cout << "In ";
		PrintCategoryName(category);
		cout << "s wasn't found product with given index!" << endl;
	}
	return 0;
}


void Shop::PrintCategory(int category)
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
	else if (category == 2)
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



int Shop::CheckIfProductExistInGivenCategory(int productId, int category)
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
int Shop::CheckIfProductExistInShoppingCart(int productId)
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

void Shop::ShowShoppingCart()
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

void Shop::PrintCategoryName(int category)
{
	if (category == 1)
	{
		cout << "Laptop";
	}
	else if (category == 2)
	{

		cout << "Phone";


	}
	else if (category == 3)
	{
		cout << "Printer";


	}
	else if (category == 4)
	{
		cout << "Smart Watch";

	}
}


void Shop::SortAndPrint(int category)
{
	system("cls");
	cout << "SORTED" << endl;
	if (category == 1)
	{
		this->laptops.Sort();
		PrintCategory(1);

	}
	else if (category == 2)
	{
		this->phones.Sort();
		PrintCategory(2);
	}
	else if (category == 3)
	{
		this->printers.Sort();
		PrintCategory(3);
	}
	else if (category == 4)
	{
		this->smarthWatches.Sort();
		PrintCategory(4);
	}

}




