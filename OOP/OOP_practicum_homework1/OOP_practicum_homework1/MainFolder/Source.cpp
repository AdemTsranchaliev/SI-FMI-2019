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

	getline(cin,command, 50);

	if (command[0]=='L')
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
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');
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
			system("cls");
			continue;
		}
		else if (command == "R" && !shop.isAuthenticated())
		{
			shop.registation();
			GetCommandPressAnyKeyToContiniue();
			system("cls");
			continue;
		}
		else if (command== "q" == 0 && shop.isAuthorized("ROLE_ADMIN"))
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
				cin.clear();
				cin.ignore(numeric_limits < streamsize > ::max(), '\n');
				cout << "Press user No to change his role" << endl;
				cin >> idNum;
				shop.makeUserAdminOrUser(idNum);
				
				cout << "Press any key to continiue" << endl;
				GetCommandPressAnyKeyToContiniue();
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits < streamsize > ::max(), '\n');
				system("cls");
			}

		

			continue;
		}
		else if (strcmp(command, "t") == 0 && shop.isAuthorized("ROLE_ADMIN"))
		{
			shop.addProduct();
			GetCommandPressAnyKeyToContiniue();

			system("cls");

			continue;
		}
	

		else if (strcmp(command, "e") == 0&&shop.isAuthenticated())
		{
			shop.logOut();

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
		getline(cin,command, 50);

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

void Login(Shop& shop)
{
	system("cls");
	char username[100];
	char password[100];
	cout << "Login in your profile" << endl;
	cout << "========================================" << endl << endl;
	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	while (true)
	{
		cout << "Enter username:" << endl;
		getline(cin,username, 99);
		cout << endl;
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');
		cout << "Enter password:" << endl;
		getline(cin,password, 99);

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

		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');
		getline(cin,username, 99);

		if (username[0]=='G')
		{
			break;
		}

		system("cls");
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');
	}

}
void SeeOrders(Shop& shop)
{
	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');
	while (true)
	{
		system("cls");
		cout << "All orders" << endl;
		cout << "--------------------------------" << endl;
		cout << "To see order in details press 'D'" << endl;
		cout << "To go back in main menu press any other key" << endl << endl;

		shop.seeAllOrders();

		char tempCommand[10];
		
		getline(cin,tempCommand, 10);
		if (tempCommand[0] == 'D')
		{
		
			cout << "Which No order want to see? Press the order number."<<endl;

			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			getline(cin,tempCommand, 10);
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
				cin.clear();
				cin.ignore(numeric_limits < streamsize > ::max(), '\n');

				cin >> n;
				if (n==1)
				{
					shop.seeOrder(tempCommand[0] - '0').confirmOrder();
				}

				cin.clear();
				cin.ignore(numeric_limits < streamsize > ::max(), '\n');
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
	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');
	getline(cin,command, 50);
	system("cls");
	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');
}
