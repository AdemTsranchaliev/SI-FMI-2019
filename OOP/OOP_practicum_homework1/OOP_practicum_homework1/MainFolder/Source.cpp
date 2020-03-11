#include <iostream>

using namespace std;

#include "Phone.h"
#include "Laptop.h"
#include "Printer.h"
#include "SmartWatch.h"

Laptop laptops[4];
Phone phones[4];
Printer printers[4];
SmartWatch smarthWatches[2];

void InsertData();

int main()
{
	InsertData();
	int num = 0;
	cout << "=============================" << endl;
	cout << "Welcome in the SMART SHOP" << endl;
	cout << "=============================" << endl << endl;
	while (true)
	{

		cout << "Bellow are our categories. To open category, choice the number in front of the category and press ENTER" << endl;
		cout << "1 Laptops" << endl;
		cout << "2 Phones" << endl;
		cout << "3 Printers" << endl;
		cout << "4 Smart Watches" << endl;

		cin >> num;

		if (num==1)
		{

		}
		else if (num==2)
		{
			cout << "To go back in main page PRESS 'b'"<<endl;
			cout << "To see you shopping cart 'PRESS 's'" << endl;
			cout << "To add product in shopping cart PRESS 'add_?', where '?' is the code of the product you want to add" << endl;
			cout << "============================================================================================================";
			cout << "Laptos"<<endl;
			cout << "No | Name | Color | Model | Year of production | Price"<<endl;
			cout << "-----------------------------------------------------------" << endl;
			for (int i = 0; i < 4; i++)
			{
				phones[i].print();
			}

		}
		else if (num==3)
		{

		}
		else if (num==4)
		{

		}

	}
	system("pause");

	return 0;
}


void InsertData()
{
	phones[0].addPhone("X","Black",2019,1,"Iphone",1100);
	phones[1].addPhone("Galaxy S4", "White", 2016, 2, "Samsung", 700);
	phones[2].addPhone("PRO 20", "Black", 2017, 3, "Huawei", 450);
	phones[3].addPhone("4", "Pink", 2011, 4, "Iphone", 200);


}





