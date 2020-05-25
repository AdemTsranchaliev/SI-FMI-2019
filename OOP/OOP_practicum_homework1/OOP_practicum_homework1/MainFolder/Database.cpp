
#include "Database.h"


vector<string> Database::split(string text, char separator)
{
	vector<string> list;
	int  index = text.find(separator);

	while (index!=-1)
	{
		string temp = text.substr(0,index);
		(list).push_back(temp);
		text = text.substr(index + 1);
		index = text.find(separator);
	}
	if (text.length()>0)
	{
		(list).push_back(text);
	}

	return list;
}

string Database::ReadFromDb(string path)
{
	fstream file;

	file.open(path, ios::in);
	if (file.is_open())
	{
		string text = "";

		char c;

		while (file.get(c))
		{
			text += c;
		}

		return text;

	}

	return "";

}
void Database::fillWithDefaultInfoFiles()
{
    Phone phone1("X", "Black", 2019, 1, "Iphone", 1100,"Phone");
    Phone phone2("Galaxy S4", "White", 2016, 2, "Samsung", 700, "Phone");
    Phone phone3("PRO 20", "Black", 2017, 3, "Huawei", 200, "Phone");
    Phone phone4("4", "Pink", 2011, 4, "Iphone", 450, "Phone");

	this->SaveToDatabase(phone1);
	this->SaveToDatabase(phone2);
	this->SaveToDatabase(phone3);
	this->SaveToDatabase(phone4);

    Printer printer1("RA", "A", true, 5, "ASUS", 200, "Printer");
	Printer printer2("Laser", "B", true, 6, "HP", 220, "Printer");

	this->SaveToDatabase(printer1);
	this->SaveToDatabase(printer2);

	static Laptop laptop1("Intel", 4, "NVidia", 7, "Lenovo", 799, "Laptop");
    static Laptop laptop2("Intel Core i7", 4, "NVidia GEFORCE 940mx", 8, "Asus", 799, "Laptop"); 

	this->SaveToDatabase(laptop1);
	this->SaveToDatabase(laptop2);

	Security security;
	string password = security.encryptPassword("12345");
	User user1(2, "admin", password, "ROLE_ADMIN");
	User user2(3, "user", password, "ROLE_USER");

	this->SaveToDatabase(user1);
	this->SaveToDatabase(user2);



	Order order(0, "Adem", "Tsranchaliev", "+359892609802", "Mihail Takev 26", "Peshtera", "ademcran4aliev@abv.bg");

	ShoppingCart shp("Phone",2,2,120,"Iphone");
	ShoppingCart shp2("Laptop", 2, 2, 120, "Iphone");
	
	order.addProductToShoppingCart(shp);
	order.addProductToShoppingCart(shp2);

	this->SaveToDatabase(order);
}

bool Database::checkIfFilesExistAndCreateThem()
{

	bool isAllOpen = true;

	fstream file;

	file.open("Laptop.txt",ios::in);

	if (!file.is_open())
	{
		isAllOpen = false;
		file.open("Laptop.txt", ios::out);
		file.close();
	}

	file.open("Phone.txt", ios::in);

	if (!file.is_open())
	{
		isAllOpen = false;

		file.open("Phone.txt", ios::out);
		file.close();
	}

	file.open("Printer.txt", ios::in);

	if (!file.is_open())
	{
		isAllOpen = false;

		file.open("Printer.txt", ios::out);
		file.close();
	}

	file.open("Order.txt", ios::in);

	if (!file.is_open())
	{
		isAllOpen = false;

		file.open("Order.txt", ios::out);
		file.close();
	}

	file.open("User.txt", ios::in);

	if (!file.is_open())
	{
		isAllOpen = false;
		file.open("User.txt", ios::out);
		file.close();
	}

	return isAllOpen;
}