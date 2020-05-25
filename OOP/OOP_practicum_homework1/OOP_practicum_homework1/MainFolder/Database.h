#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#include "Phone.hpp"
#include "Laptop.hpp"
#include "Printer.hpp"
#include "User.hpp"
#include "Order.hpp"
#include "ShoppingCart.hpp"

using namespace std;

class Database
{
public:

	template <typename T>
	void SaveToDatabase(T& obj);
	
	string ReadFromDb(string path);

	template <typename T>
	vector<T> GetFromDbAndConvertTextToClass();

	template <>
	vector<Laptop> GetFromDbAndConvertTextToClass();

	template <>
	vector<Phone> GetFromDbAndConvertTextToClass();

	template <>
	vector<Printer> GetFromDbAndConvertTextToClass();

	template <>
	vector<User> GetFromDbAndConvertTextToClass();

	template <>
	vector<Order> GetFromDbAndConvertTextToClass();

	vector<string> split(string text,char separator);
};


template <typename T>
vector<T>  Database::GetFromDbAndConvertTextToClass()
{
	vector<int> text;

	return text;

}

template <typename T>
void Database::SaveToDatabase(T& obj)
{
	string className = ((string)(typeid(obj).name()));
	string fileName = className.substr(className.find(" ") + 1) + ".txt";
	fstream file;
	file.open(fileName, ios::app);
	if (!file.is_open())
	{
		file.open(fileName, ios::out);

	}
	file << obj;
	
	file.close();
}



template <>
vector<Laptop> Database::GetFromDbAndConvertTextToClass()
{
	string text = ReadFromDb("Laptop.txt");

	vector<string> tempList = this->split(text, '\n');

	vector<Laptop> laptops;
	for (int i = 0; i < tempList.size(); i++)
	{
		vector<string> temp = this->split(tempList[i], '|');


		string processor = temp[3];
		int memory = stoi(temp[2]);
		string videoCart = temp[4];
		int id = stoi(temp[0]);
		string name = temp[1];
		double price = stoi(temp[5]);

		Laptop laptop(processor, memory, videoCart, id, name, price, "Laptop");
		laptops.push_back(laptop);

	}

	return laptops;

}

template <>
vector<Phone> Database::GetFromDbAndConvertTextToClass()
{
	string text = ReadFromDb("Phone.txt");

	vector<string> tempList = this->split(text, '\n');

	vector<Phone> phones;
	for (int i = 0; i < tempList.size(); i++)
	{
		vector<string> temp = this->split(tempList[i], '|');


		string model = temp[3];
		string color= temp[2];
		int yearOfProduction = stoi(temp[4]);
		int id = stoi(temp[0]);
		string name = temp[1];
		double price = stoi(temp[5]);

		Phone phone(model,color,yearOfProduction, id, name, price, "Phone");
		phones.push_back(phone);

	}

	return phones;

}
template <>
vector<Printer> Database::GetFromDbAndConvertTextToClass()
{
	string text = ReadFromDb("Printer.txt");

	vector<string> tempList = this->split(text, '\n');

	vector<Printer> printers;
	for (int i = 0; i < tempList.size(); i++)
	{
		vector<string> temp = this->split(tempList[i], '|');


		string printingTechnology = temp[2];
		string mainPrintingFormat = temp[3];
		bool oneOrManyColors = temp[4]=="1";
		int id = stoi(temp[0]);
		string name = temp[1];
		double price = stoi(temp[5]);

		Printer printer(printingTechnology,mainPrintingFormat,oneOrManyColors, id, name, price, "Printer");
		printers.push_back(printer);

	}

	return printers;

}

template <>
vector<User> Database::GetFromDbAndConvertTextToClass()
{
	string text = ReadFromDb("User.txt");

	vector<string> tempList = this->split(text, '\n');

	vector<User> users;
	for (int i = 0; i < tempList.size(); i++)
	{
		vector<string> temp = this->split(tempList[i], '|');


		int id = stoi(temp[0]);
		string username = temp[1];
		string password = temp[2];
		string role = (temp[3]);


		User user(id,username,password,role);
		users.push_back(user);

	}

	return users;

}

template <>
vector<Order> Database::GetFromDbAndConvertTextToClass()
{
	string text = ReadFromDb("Order.txt");

	vector<string> tempList = this->split(text, '\n');

	vector<Order> orders;
	for (int i = 0; i < tempList.size(); i++)
	{
		vector<string> temp = this->split(tempList[i], '!');

		int id = stoi(temp[0]);
		string name = temp[1];
		string surname = temp[2];
		string phone = temp[3];
		string populatedPlace = temp[4];
		string address = temp[5];
		string email = temp[6];
		int userId = stoi(temp[7]);
		
		Order order(id,name,surname,phone,address,populatedPlace,email);

		for (size_t i = 8; i < temp.size(); i++)
		{
			vector<string> tempCart = split(temp[i], '/');

			string name = tempCart[0];
			string category = tempCart[1];
			int quantity= stoi(tempCart[2]);
			double price= stod(tempCart[3]);
			int productId = stoi(tempCart[4]);
			ShoppingCart shop(category,productId,quantity,price,name);

			order.addProductToShoppingCart(shop);
		}
		orders.push_back(order);

	}

	return orders;

}