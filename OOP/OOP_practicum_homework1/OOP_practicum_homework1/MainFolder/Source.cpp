#include <iostream>
#include <string>


using namespace std;

#include "Shop.h"
string command;

void GetCommandPressAnyKeyToContiniue();
void Login(Shop& shop);
void SeeOrders(Shop& shop);

int main()
{

	Shop shop;

	cout << "=============================" << endl;
	cout << "Welcome in the SMART SHOP" << endl;
	cout << "=============================" << endl << endl;

	cout << "Would you like to login in your profile" << endl << endl;
	cout << "Press 'L' for login" << endl;
	cout << "Press 'R' for register" << endl;
	cout << "Press any other key to continiue like guest" << endl;

	getline(cin,command);

	if (command=="L")
	{
		Login(shop);
		GetCommandPressAnyKeyToContiniue();
	}
	else if (command[0] == 'R')
	{
		shop.registation();
		GetCommandPressAnyKeyToContiniue();
	}
	else
	{
		system("cls");	
	}

	int categorySelected = 0;
	while (true)
	{
		if (shop.isAuthenticated())
		{
			cout << "---------------------------------------" << endl;

			if (shop.isAuthorized("ROLE_USER"))
			{
				cout << "You are loged as " << shop.getAuthenticateUserUsername() << endl;
			
				cout << "To logout press 'e'" << endl;

			}
			else
			{
				cout << "You are loged as " << shop.getAuthenticateUserUsername() << endl;
				cout << "To see orders press 'q'" << endl;
				cout << "To see users 'u'" << endl;
				cout << "To add new product 't'" << endl;
				cout << "To logout press 'e'" << endl;
			}
			
			
			cout << "---------------------------------------"<<endl;
		}
		else
		{
			cout << "To login PRESS 'L'" << endl;
			cout << "Press 'R' for register" << endl;
		}
		cout << "To see you shopping cart PRESS 's'" << endl;
		cout << "Bellow are our categories. To open category, choice the number in front of the category and press ENTER" << endl;
		cout << "1 Laptops" << endl;
		cout << "2 Phones" << endl;
		cout << "3 Printers" << endl;
		cout << "4 Smart Watches" << endl;

		

		getline(cin,command);

		system("cls");

		if (command=="s")
		{
			shop.ShowShoppingCart();
					
			continue;
		}
		else if (command == "L" && !shop.isAuthenticated())
		{
			Login(shop);
			GetCommandPressAnyKeyToContiniue();
			continue;
		}
		else if (command == "R" && !shop.isAuthenticated())
		{
			shop.registation();
			GetCommandPressAnyKeyToContiniue();
			system("cls");
			continue;
		}
		else if (command== "q"&& shop.isAuthorized("ROLE_ADMIN"))
		{	
			SeeOrders(shop);

			GetCommandPressAnyKeyToContiniue();

			system("cls");

			continue;
		}
		else if (command == "u" && shop.isAuthorized("ROLE_ADMIN"))
		{
			cout << "All users"<<endl;
			cout << "----------------------------" << endl;

			shop.seeAllUsers();

			cout << "============================"<<endl;
			cout << "If you want to change user role press 'role'" << endl;
			cout << "If you want to go back, press any other key" << endl;

			getline(cin, command);

			if ("role"==command)
			{
				int idNum;
				
				cout << "Press user No to change his role" << endl;
				cin >> idNum;

				cin.clear();
				cin.ignore(numeric_limits < streamsize > ::max(), '\n');

				shop.makeUserAdminOrUser(idNum);
				
				cout << "Press any key to continiue" << endl;
				GetCommandPressAnyKeyToContiniue();
			}
			else
			{
				system("cls");
			}
			continue;
		}
		else if (command== "t"&& shop.isAuthorized("ROLE_ADMIN"))
		{
			shop.addProduct();
			GetCommandPressAnyKeyToContiniue();

			continue;
		}
	

		else if (command== "e"&&shop.isAuthenticated())
		{
			shop.logOut();

			GetCommandPressAnyKeyToContiniue();

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

			continue;
		}
	
		getline(cin,command);

		if (command== "b")
		{
			system("cls");

			continue;
		}
		else if (command== "s")
		{
			shop.ShowShoppingCart();

			system("cls");
		
			continue;

		}
		else if (command=="add")
		{
			int productId = 0;

			cout << "Enter the number of product which you want to add in the shopping cart" << endl;
			cin >> productId;

			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');

			shop.AddProductInShoppingCart(productId, categorySelected);
			

			cout << "Press any key to continiue to categories" << endl;
			GetCommandPressAnyKeyToContiniue();			
		}
		else if (command== "sort")
		{
			shop.SortAndPrint(categorySelected);

			GetCommandPressAnyKeyToContiniue();
		}

	}
	system("pause");

	return 0;
}

void Login(Shop& shop)
{
	system("cls");
	string username;
	string password;
	cout << "Login in your profile" << endl;
	cout << "========================================" << endl << endl;

	while (true)
	{
		cout << "Enter username:" << endl;
		getline(cin,username);
		cout << endl;

		cout << "Enter password:" << endl;
		getline(cin,password);

		bool isAuthenticated = shop.Authenticate(username, password);

		if (isAuthenticated)
		{
			cout << "Wellcome, "<<shop.getAuthenticateUserUsername()<<"!"<<endl;
			cout << "Press any key to continiue!"<<endl;
			break;
		}
		system("cls");

		cout << "Wrong username or password."<<endl;
		cout << "Press 'G' to continiue like GUEST." << endl;
		cout << "Press any other key to try again." << endl;

		getline(cin,username);

		if (username=="G")
		{
			break;
		}

		system("cls");
	}

}
void SeeOrders(Shop& shop)
{

	while (true)
	{
		system("cls");
		cout << "All orders" << endl;
		cout << "--------------------------------" << endl;
		cout << "To see order in details press 'D'" << endl;
		cout << "To go back in main menu press any other key" << endl << endl;

		shop.seeAllOrders();

		string tempCommand;
		
		getline(cin,tempCommand);
		if (tempCommand == "D")
		{
		
			cout << "Which No order want to see? Press the order number."<<endl;

			getline(cin,tempCommand);
			system("cls");

			if (!shop.checkIfOrderExist(tempCommand[0] - '0'))
			{
				cout << "Order with that number doesn't exist!"<<endl;
				cout << "Press any key to continiue back." << endl;

				GetCommandPressAnyKeyToContiniue();
				continue;

			}

			cout << "Order No: "<<tempCommand<<endl;
			cout << "====================================="<<endl<<endl;
			shop.seeOrder(tempCommand[0] - '0').printDetail();

			if (shop.seeOrder(tempCommand[0] - '0').getIsConfirmed()==false&&shop.isAuthorized("ROLE_ADMIN"))
			{
	
				cout << "==================================================================" << endl;
				cout << "That order is not confirmed, if you want to confirm it press '1'"<<endl;
				cout << "If you want to go back press any other key" << endl;

				int n;
		

				cin >> n;

				cin.clear();
				cin.ignore(numeric_limits < streamsize > ::max(), '\n');

				if (n==1)
				{
					shop.seeOrder(tempCommand[0] - '0').confirmOrder();
				}

			}
			else
			{
				GetCommandPressAnyKeyToContiniue();
			}
		}
		else
		{
			break;
		}
	}
}
void GetCommandPressAnyKeyToContiniue()
{
	
	getline(cin,command);
	system("cls");
	
}
