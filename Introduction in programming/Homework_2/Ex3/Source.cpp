
/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Adem Tsranchaliev
* @idnumber 62409
* @task 3
* @compiler VC
*
*/


#include <iostream>
using namespace std;

int CountSymbols(char[]);
void GetAndValidateInput(char*,char*);
void ReplaceBiggerStrWithSmaller(char*, char*,int,int);

int main()
{
	char str1[1000];
    char str2[1000];
    
	
	GetAndValidateInput(str1,str2);

	int numberOfSymbolsStr1 = CountSymbols(str1);
	int numberOfSymbolsStr2 = CountSymbols(str2);

	ReplaceBiggerStrWithSmaller(str1,str2, numberOfSymbolsStr1, numberOfSymbolsStr2);

	if (numberOfSymbolsStr1> numberOfSymbolsStr2)
	{
		cout << str1;
	}
	else
	{
		cout << str2;
	}

	system("pause");
	return 0;
}

void ReplaceBiggerStrWithSmaller(char* str1, char* str2,int numberOfSymbolsStr1,int numberOfSymbolsStr2)
{



	if (numberOfSymbolsStr1 > numberOfSymbolsStr2)
	{
		for (int i = 0; i < numberOfSymbolsStr1; i += numberOfSymbolsStr2)
		{
			for (int j = 0; j < numberOfSymbolsStr2; j++)
			{
				str1[j + i] = str2[j];

			}
		}
		str1[numberOfSymbolsStr1] = '\0';
		
	}
	else
	{
		for (int i = 0; i < numberOfSymbolsStr2; i += numberOfSymbolsStr1)
		{
			for (int j = 0; j < numberOfSymbolsStr1; j++)
			{
				str2[j + i] = str1[j];

			}
		}
		str2[numberOfSymbolsStr2] = '\0';
		
	}
}

void GetAndValidateInput(char* str1, char* str2)
{
	cout << "First input:" << endl;
	cin.getline(str1, 1000);
	cout << "Second input:" << endl;
	cin.getline(str2, 1000);

	

	while (true)
	{
		int numberOfSymbolsStr1 = CountSymbols(str1);
		int numberOfSymbolsStr2 = CountSymbols(str2);

		if (numberOfSymbolsStr1 == numberOfSymbolsStr2)
		{
			cout << "Two inputs must be with different lenght! Please try again!:" << endl << endl;
			cout << "First input:" << endl;
			cin.getline(str1, 1000);
			cout << "Second input:" << endl;
			cin.getline(str2, 1000);
		}
		else
		{
			break;
		}
	}
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
