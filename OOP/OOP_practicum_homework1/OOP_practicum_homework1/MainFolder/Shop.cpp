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

	User user1(2, "admin", "12345", "ROLE_ADMIN");
	users.add(user1);
	User user2(3, "user", "12345", "ROLE_USER");
	users.add(user2);

	Order order(0,"Adem","Tsranchaliev","+359892609802","Mihail Takev 26","Peshtera","ademcran4aliev@abv.bg");
	orders.add(order);

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

		char command[3];	
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');

		cin.get(command, 3);

		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');

		system("cls");
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

		char command[3];
		cout << "For finishing the order press 'O'"<<endl;
		cout << "To go back PRESS any other key" << endl;

		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');
		cin.get(command,3);
		if (command[0]=='O')
		{
			this->MakeOrder();
		}

		system("cls");
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');

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

bool Shop::Authenticate(const char* username, const char* password)
{
	for (int i = 0; i < users.Count(); i++)
	{
		if (strcmp(users.getAt(i).getUsername(),username)==0)
		{
			if (strcmp(users.getAt(i).getPassword(), password) == 0)
			{
				authenticatedUser = users.getAt(i);
				return true;
			}
			return false;
		}
	}
	return false;
}

bool Shop::isAuthenticated()
{
	if (this->authenticatedUser.getId()==0)
	{
		return false;

	}
	return true;
}
bool Shop::isAuthorized(const char* role)
{
	if (strcmp(this->authenticatedUser.getRole(),role)==0)
	{
		return true;

	}
	return false;
}

void Shop::registation()
{
	system("cls");

	cout << "Registration"<<endl;
	cout << "=============================="<<endl;
	User newUser;
	cin >> newUser;
	newUser.setRole("ROLE_USER");
	newUser.setId(users.getAt(users.Count()-1).getId()+1);
	if (checkIfUsernameIsUnique(newUser.getUsername()))
	{
		this->authenticatedUser = newUser;
		users.add(newUser);
		cout << "You registered successfully! Press any key to continiue.";
	}
	else
	{
		cout << "The username already exist, your registration failed, press any key to go back."<<endl;
	}

}


bool Shop::checkIfUsernameIsUnique(const char* username)
{
	bool temp = true;
	for (int i = 0; i < users.Count(); i++)
	{
		if (strcmp(users.getAt(i).getUsername(),username)==0)
		{
			temp = false;
		}
	}

	return temp;
}

char* Shop::getAuthenticateUserUsername()
{
	return this->authenticatedUser.getUsername();
}
char* Shop::getAuthenticateUserRole()
{
	return this->authenticatedUser.getRole();
}

void Shop::logOut()
{
	User user;
	this->authenticatedUser = user;
	cout << "Successfully logout, press any key to continiue";
}


void Shop::seeAllOrders()
{
	cout << "No  |" << "Ordered name |" << " Delivery to |" << " Status"<<endl;
	for (int i = 0; i < orders.Count(); i++)
	{
		orders.getAt(i).print();
	}
}

void Shop::seeAllUsers()
{
	cout << "Id  |" << "Username |" << " Role " <<  endl;
	for (int i = 0; i < users.Count(); i++)
	{
		if (this->authenticatedUser.getId()!= users.getAt(i).getId())
		{
			users.getAt(i).print();
		}
	}
}


Order& Shop::seeOrder(int id)
{
	for (int i = 0; i < orders.Count(); i++)
	{
		if ((id-1)==orders.getAt(i).getId())
		{
			return orders.getAt(i);				
		}
	}

}

void Shop::addProduct()
{
	cout << "What category of product you want to add" << endl;
	cout << "For 'Phone' press 1" << endl;
	cout << "For 'Laptop' press 2" << endl;
	cout << "For 'Smart watch' press 3" << endl;
	cout << "For 'Printer' press 4" << endl;
	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');
	char tempInput[40];
	cin.get(tempInput,10);
	if (tempInput[0]=='1')
	{
		system("cls");
		cout << "Adding new product 'Phone'"<<endl;
		cout << "================================" << endl << endl;
		addPhone();
	}
	else if (tempInput[0] == '2')
	{
		system("cls");
		cout << "Adding new product 'Laptop'" << endl;
		cout << "================================" << endl << endl;
		addLaptop();
	}
	else if (tempInput[0] == '3')
	{
		system("cls");
		cout << "Adding new product 'Smart Watch'" << endl;
		cout << "================================" << endl << endl;
		addSmartWatch();
	}
	else if (tempInput[0] == '4')
	{
		system("cls");
		cout << "Adding new product 'Printer'" << endl;
		cout << "================================" << endl << endl;
		addPrinter();
	}


}

void Shop::makeUserAdminOrUser(int id)
{
	User user;

	for (int i = 0; i < users.Count(); i++)
	{
		if (users.getAt(i).getId()==id)
		{
			user = users.getAt(i);
			if (strcmp(users.getAt(i).getRole(), "ROLE_ADMIN") == 0)
			{
				users.getAt(i).setRole("ROLE_USER");
				
				cout << users.getAt(i).getUsername() << " role was changed from ROLE_ADMIN to ROLE_USER"<<endl;
			}
			else
			{
				users.getAt(i).setRole("ROLE_ADMIN");
		
				cout << user.getUsername() << " role was changed from ROLE_USER to ROLE_ADMIN"<<endl;
			}
		}
	}

	if (user.getId()==0)
	{
		cout << "User with given id wasn't found!"<<endl;
	}
	
	
}

void Shop::MakeOrder()
{
	system("cls");

	cout << "FINISHING ORDER" << endl;
	cout << "====================================" << endl;

	Order order;

	cin >> order;
	order.setId(this->orders.getAt(this->orders.Count()-1).getId()+1);
	

	for (int i = 0; i < shoppingCart.Count(); i++)
	{
		order.addProductToShoppingCart(shoppingCart.getAt(i));
	}

	if (this->isAuthenticated())
	{
		this->authenticatedUser.addNewOrder(order);
	}
	orders.add(order);
	cout << "Your order was successfully send! Press any key to continiue!";

	ClearShoppingCart();

	char temp[50];

	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	cin.get(temp,50);

}

void Shop::ClearShoppingCart()
{
	while (this->shoppingCart.Count()!=0)
	{
		this->shoppingCart.removeAt(0);
	}
}

bool Shop::checkIfOrderExist(int id)
{
	id = id - 1;
	for (int i = 0; i < orders.Count(); i++)
	{
		if (this->orders.getAt(i).getId()==id)
		{
			return true;
		}
	}

	return false;
}


void Shop::addLaptop()
{
	Laptop laptop;
	cin >> laptop;
	laptop.setId(laptops.getAt(laptops.Count()-1).getId()+1);
	laptops.add(laptop);
}
void Shop::addPhone()
{
	Phone phone;
	cin >> phone;
	phone.setId(phones.getAt(phones.Count() - 1).getId() + 1);

	phones.add(phone);
}
void Shop::addPrinter()
{
	Printer printer;
	cin >> printer;
	printer.setId(printers.getAt(printers.Count() - 1).getId() + 1);

	printers.add(printer);
}
void Shop::addSmartWatch()
{
	SmartWatch smartWatch;
	cin >> smartWatch;
	smartWatch.setId(smarthWatches.getAt(smarthWatches.Count() - 1).getId() + 1);

	smarthWatches.add(smartWatch);
}


