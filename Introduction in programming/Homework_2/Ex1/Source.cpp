/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Adem Tsranchaliev
* @idnumber 62409
* @task 1
* @compiler VC
*
*/


#include <iostream>
using namespace std;

const int NUMBER_MINUS = '@';
int GetNumberOfColumnByGivenStr(char*,int);
int CountLetters(char*);
void GetInputAndValidateIt(char*);
int main() 
{
	char symbols[4];

	GetInputAndValidateIt(symbols);

	int lettersCount = CountLetters(symbols);

	int result = GetNumberOfColumnByGivenStr(symbols,lettersCount);
	
	cout << result << endl;

	system("pause");
	return 0;
}
void GetInputAndValidateIt(char* symbols)
{
	cout << "Insert between 1 and 3 symbols included: ";
	cin.getline(symbols, 4);

	while (true)
	{

		int i = 0;
		bool isItValid = true;
		while (symbols[i]!='\0')
		{
			
			if (symbols[i]<'A'||symbols[i]>'Z')
			{
				cout << "The input contains invalid characters! Please try again"<<endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin.getline(symbols, 4);
				isItValid = false;
			}
			i++;
		}
		if (isItValid)
		{
			break;
		}
	}

}
int CountLetters(char* arr)
{
	int counter = 0;

	while (arr[counter]!='\0')
	{
		counter++;
	}

	return counter;
}

int GetNumberOfColumnByGivenStr(char* str,int lettersCount)
{
	int sum = 0;
	if (lettersCount==1)
	{
	     sum += str[0] - NUMBER_MINUS;
	}
	else if (lettersCount == 2)
	{
		sum += 26*(str[0] - NUMBER_MINUS) + (str[1] - NUMBER_MINUS);
	}
	else if (lettersCount == 3)
	{
		sum += 26 * 26 * (str[0] - NUMBER_MINUS) + 26 * (str[1] - NUMBER_MINUS) + (str[2] - NUMBER_MINUS);
	}

	return sum;
}

