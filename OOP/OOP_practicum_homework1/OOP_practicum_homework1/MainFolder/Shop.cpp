#include <iostream>
#include <vector>


#include "Shop.h"
#include "Database.h"

Shop::Shop()
{
	InsertData();
}

void Shop::InsertData()
{

	Database dat;

//	static Phone phone1("X", "Black", 2019, 1, "Iphone", 1100,"Phone");
//	static Phone phone2("Galaxy S4", "White", 2016, 2, "Samsung", 700, "Phone");
//	static Phone phone3("PRO 20", "Black", 2017, 3, "Huawei", 200, "Phone");
//	static Phone phone4("4", "Pink", 2011, 4, "Iphone", 450, "Phone");
	
//products.push_back(&phone1);
//products.push_back(&phone2);
//products.push_back(&phone3);

	static vector<Phone> phones = dat.GetFromDbAndConvertTextToClass<Phone>();

	for (int i = 0; i < phones.size(); i++)
	{
		products.push_back(&phones[i]);
	}

	//dat.SaveToDatabase(phone1);
	//dat.SaveToDatabase(phone2);
	//dat.SaveToDatabase(phone3);
	//dat.SaveToDatabase(phone4);

	
//	static Printer printer1("RA", "A", true, 5, "ASUS", 200, "Printer");
//	static Printer printer2("Laser", "B", true, 6, "HP", 220, "Printer");

	static vector<Printer> printers = dat.GetFromDbAndConvertTextToClass<Printer>();

	for (size_t i = 0; i < printers.size(); i++)
	{
		products.push_back(&printers[i]);
	}
	
	//dat.SaveToDatabase(printer1);
	//dat.SaveToDatabase(printer2);

   // static Laptop laptop1("Intel", 4, "NVidia", 7, "Lenovo", 799, "Laptop");
	//static Laptop laptop2("Intel Core i7", 4, "NVidia GEFORCE 940mx", 8, "Asus", 799, "Laptop");
	

	static vector<Laptop> laptops = dat.GetFromDbAndConvertTextToClass<Laptop>();
	for (int i = 0; i < laptops.size(); i++)
	{
		products.push_back(&laptops[i]);
	}

	string password = security.encryptPassword("12345");
	User user1(2, "admin", password, "ROLE_ADMIN");
	users.push_back(user1);
	User user2(3, "user", password, "ROLE_USER");
	users.push_back(user2);
	dat.SaveToDatabase(user1);
	dat.SaveToDatabase(user2);

	Order order(0,"Adem","Tsranchaliev","+359892609802","Mihail Takev 26","Peshtera","ademcran4aliev@abv.bg");

	ShoppingCart shp("Phone",2,2,120,"Iphone");
	ShoppingCart shp2("Laptop", 2, 2, 120, "Iphone");

	order.addProductToShoppingCart(shp);
	order.addProductToShoppingCart(shp2);

	
	static vector<Order> oor=dat.GetFromDbAndConvertTextToClass<Order>();

	orders.push_back(order);


}


int Shop::AddProductInShoppingCart(int productId, string category)
{

	int productIndex = CheckIfProductExistInGivenCategory(productId, category);
	int index = CheckIfProductExistInShoppingCart(productId);

	if (productIndex != -1)
	{
		if (index != -1)
		{
			shoppingCart[index].setQuantity(shoppingCart[index].getQuantity() + 1);
		}
		else
		{
			ShoppingCart cart;
			if (category == "Laptop")
			{
				Laptop* laptop= ((Laptop*)products[productIndex]);
				cart = ShoppingCart((*laptop).getCategory(), productId, 1, (*laptop).getPrice(), (*laptop).getName());
			}
			else if (category == "Phone")
			{
				Phone phone = *((Phone*)products[productIndex]);
				cart = ShoppingCart(category, productId, 1, phone.getPrice(), phone.getName());
			}
			else if (category == "Printer")
			{
				Printer printer = *((Printer*)products[productIndex]);
				cart = ShoppingCart(category, productId, 1, printer.getPrice(), printer.getName());

			}
		
			shoppingCart.push_back(cart);

		}
		cout << "The product was sucessfuly added to shopping cart!" << endl;
	}
	else
	{
		cout << "In "<< category << "s wasn't found product with given index!" << endl;
	}
	return 0;
}


void Shop::PrintCategory(string category)
{
	cout << "To go back in main page ENTER 'b'" << endl;
	cout << "To sort products by price ENTER 'sort'" << endl;
	cout << "To see you shopping cart 'ENTER 's'" << endl;
	cout << "To add product in shopping cart ENTER 'add" << endl;
	cout << "============================================================================================================" << endl;

	if (category == "Laptop")
	{
		cout << "Laptops" << endl;
		cout << "No | Name | Ram memory | Processor | Video cart | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;

		for (int i = 0; i < products.size(); i++)
		{
			if ((products[i])->getCategory()=="Laptop")
			{
				((Laptop*)(products[i]))->print();
			}
			
		}
	}
	else if (category == "Phone")
	{

		cout << "Phones" << endl;
		cout << "No | Name | Color | Model | Year of production | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;
		for (int i = 0; i < products.size(); i++)
		{
			if ((products[i])->getCategory() == "Phone")
			{
				((Phone*)(products[i]))->print();
			}
		}

	}
	else if (category == "Printer")
	{
		cout << "Printers" << endl;
		cout << "No | Name | Printing technology | Main format | Printning colors | Price" << endl;
		cout << "-----------------------------------------------------------" << endl;
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i]->getCategory() == "Printer")
			{
				((Phone*)(products[i]))->print();
			}
		}

	}
}
string Shop::GetCategoryByNum(int categorySelected)
{
	string result;
	if (categorySelected == 1)
	{
		result="Laptop";

	}
	else if (categorySelected == 2)
	{
		result = "Phone";

	}
	else if (categorySelected == 3)
	{
		result = "Printer";
	}
	return result;
}


int Shop::CheckIfProductExistInGivenCategory(int productId, string category)
{
	int index = -1;
	if (category == "Laptop")
	{
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i]->getId() == productId)
			{
				index = i;
				break;
			}
		}
	}
	else if (category == "Phone")
	{
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i]->getId() == productId)
			{
				index = i;
				break;
			}
		}
	}
	else if (category == "Printer")
	{
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i]->getId() == productId)
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

	for (int i = 0; i < shoppingCart.size(); i++)
	{
		if (shoppingCart[i].getProductId() == productId)
		{
			index = i;
			break;
		}
	}

	return index;
}

void Shop::ShowShoppingCart()
{
	if (shoppingCart.size() == 0)
	{
		cout << "There are no products in Shopping Cart" << endl;
		cout << "Press any key to continiue to categories" << endl;

		string command;	
		
		getline(cin,command);

	
		system("cls");
	}
	else
	{
		system("cls");
		double totalForCart = 0;
		cout << "Shoping cart CHECKOUT" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "No | Category | Name | Price per one | Quantity | Total" << endl;

		for (int i = 0; i < shoppingCart.size(); i++)
		{
			totalForCart += shoppingCart[i].getPrice()*shoppingCart[i].getQuantity();
			shoppingCart[i].print();

			
		}
		cout << "======================" << endl;
		cout << "Total: " << totalForCart << " leva" << endl;
		cout << "======================" << endl;

		string command;
		cout << "For finishing the order press 'O'"<<endl;
		cout << "To go back PRESS any other key" << endl;

		getline(cin,command);
		if (command[0]=='O')
		{
			this->MakeOrder();
		}

		system("cls");

	}

}

void Shop::SortAndPrint(string category)
{
	system("cls");
	//cout << "SORTED" << endl;
	//if (category == "Laptop")
	//{
	//	this->products.();
	//	PrintCategory(category);
	//
	//}
	//else if (category == "Phone")
	//{
	//	this->products.Sort();
	//	PrintCategory(category);
	//}
	//else if (category == "Pritner")
	//{
	//	this->products.Sort();
	//	PrintCategory(category);
	//}

}

void Shop::registation()
{
	system("cls");

	cout << "Registration"<<endl;
	cout << "=============================="<<endl;
	User newUser;
	cin >> newUser;
	newUser.setRole("ROLE_USER");
	newUser.setId(users[users.size()-1].getId()+1);
	newUser.setPassword(security.encryptPassword(newUser.getPassword()));
	if (checkIfUsernameIsUnique(newUser.getUsername()))
	{
		users.push_back(newUser);
		cout << "You registered successfully! Press any key to continiue. Please now login with your infomration!";
	}
	else
	{
		cout << "The username already exist, your registration failed, press any key to go back."<<endl;
	}

}

void Shop::login()
{
	system("cls");
	string username;
	string password;
	cout << "Login in your profile" << endl;
	cout << "========================================" << endl << endl;

	while (true)
	{
		cout << "Enter username:" << endl;
		getline(cin, username);
		cout << endl;

		cout << "Enter password:" << endl;
		getline(cin, password);

		bool isAuthenticated = security.Authenticate(username, password,users);

		if (isAuthenticated)
		{
			cout << "Wellcome, " << security.getAuthenticateUser().getUsername() << "!" << endl;
			cout << "Press any key to continiue!" << endl;
			break;
		}
		system("cls");

		cout << "Wrong username or password." << endl;
		cout << "Press 'G' to continiue like GUEST." << endl;
		cout << "Press any other key to try again." << endl;

		getline(cin, username);

		if (username == "G")
		{
			break;
		}

		system("cls");
	}
}



bool Shop::checkIfUsernameIsUnique(string username)
{
	bool temp = true;
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getUsername()==username)
		{
			temp = false;
		}
	}

	return temp;
}


void Shop::seeAllOrders()
{
	cout << "No  |" << "Ordered name |" << " Delivery to |" << " Status"<<endl;
	for (int i = 0; i < orders.size(); i++)
	{
		orders[i].print();
	}
}

void Shop::seeAllUsers()
{
	cout << "Id  |" << "Username |" << " Role " <<  endl;
	for (int i = 0; i < users.size(); i++)
	{
		if (security.getAuthenticateUser().getId()!= users[i].getId())
		{
			users[i].print();
		}
	}
}


Order& Shop::seeOrder(int id)
{
	for (int i = 0; i < orders.size(); i++)
	{
		if ((id-1)==orders[i].getId())
		{
			return orders[i];				
		}
	}

}

void Shop::addProduct()
{
	cout << "What category of product you want to add" << endl;
	cout << "For 'Phone' press 1" << endl;
	cout << "For 'Laptop' press 2" << endl;
	cout << "For 'Printer' press 3" << endl;
	
	string tempInput;
	getline(cin,tempInput);
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
		cout << "Adding new product 'Printer'" << endl;
		cout << "================================" << endl << endl;
		addPrinter();
	}


}

void Shop::makeUserAdminOrUser(int id)
{
	User user;

	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getId()==id)
		{
			user = users[i];
			if (users[i].getRole()== "ROLE_ADMIN")
			{
				users[i].setRole("ROLE_USER");
				
				cout << users[i].getUsername() << " role was changed from ROLE_ADMIN to ROLE_USER"<<endl;
			}
			else
			{
				users[i].setRole("ROLE_ADMIN");
		
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
	order.setId(this->orders[this->orders.size()-1].getId()+1);
	
	
	for (int i = 0; i < shoppingCart.size(); i++)
	{
		order.addProductToShoppingCart(shoppingCart[i]);
	}

	if (security.isAuthenticated())
	{
		order.setUserId(security.getAuthenticateUser().getId());
		security.getAuthenticateUser().addNewOrder(order);
	}
	orders.push_back(order);
	cout << "Your order was successfully send! Press any key to continiue!";

	ClearShoppingCart();

	string temp;
	cout << order;
	getline(cin,temp);

}

void Shop::ClearShoppingCart()
{
	while (this->shoppingCart.size()!=0)
	{
		this->shoppingCart.erase(shoppingCart.begin()+0);
	}
}

bool Shop::checkIfOrderExist(int id)
{
	id = id - 1;
	for (int i = 0; i < orders.size(); i++)
	{
		if (this->orders[i].getId()==id)
		{
			return true;
		}
	}

	return false;
}


void Shop::addLaptop()
{
	static Laptop laptop;
	cin >> laptop;

	laptop.setId(products[products.size()-1]->getId()+1);
	laptop.setCategory("Laptop");

	products.push_back(&laptop);
}
void Shop::addPhone()
{
	static Phone phone;
	cin >> phone;

	phone.setId(products[products.size() - 1]->getId() + 1);
	phone.setCategory("Phone");

	products.push_back(&phone);
	string a = "";
}
void Shop::addPrinter()
{
	static Printer printer;
	cin >> printer;

	printer.setId(products[products.size() - 1]->getId() + 1);
	printer.setCategory("Printer");

	products.push_back(&printer);
}



