
/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Adem Tsranchaliev
* @idnumber 62409
* @task 2
* @compiler VC
*
*/


#include <iostream>
using namespace std;

void StrEncryption(char[],int,int,int);
int CountSymbols(char[]);
bool CheckIfStrIsValid(char*);
int InsertAndValidateMOrM(int,char);

int main()
{
	int M = 0, L = 0;

	char str[101];

	cout << "Insert input:"<<endl;
    cin.getline(str,100);
	
	M = InsertAndValidateMOrM(20,'M');

	int symbolCount = CountSymbols(str);
	L= InsertAndValidateMOrM(20, 'L');

	bool isItValid = CheckIfStrIsValid(str);

	if (isItValid)
	{
		StrEncryption(str, L, M, symbolCount);
	}
	else
	{
		cout << "The input contains invalid symbols"<<endl;
		cout << str<<endl;
	}

	system("pause");
	return 0;
}


int InsertAndValidateMOrM(int maxRange,char mOrL)
{
	int number;
	cout << "Insert "<<mOrL<<", it must be between 1 and " << maxRange << " included:" << endl;
	cin >> number;

	while (true)
	{
		if (cin.fail() || !(number >= 1 && number <= maxRange))
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input! Please try again!" << endl;
			cin >> number;
		}
		else
		{
			break;
		}
	}

	return number;
}

bool CheckIfStrIsValid(char* arr)
{
	int i = 0;
	bool isItValid = true;
	while (arr[i]!='\0')
	{
		if (!(arr[i]>=32&&arr[i]<=126))
		{
			isItValid = false;
			break;
		}
		i++;
	}
	return isItValid;
}
void StrEncryption(char str[],int L,int M,int symbolCount)
{
	 char a[101];
	 a[symbolCount] = '\0';
	 for (int i = 0; i < symbolCount; i++)
	{

		int placeToPosition = i + L;
		if (placeToPosition>=symbolCount)
		{
			placeToPosition = placeToPosition - symbolCount;
		}
		a[placeToPosition] = str[i] + M;

	}
	cout << a;
}
int CountSymbols(char str[])
{
	int counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

