
/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Adem Tsranchaliev
* @idnumber 62409
* @task 4
* @compiler VC
*
*/


#include <iostream>

using namespace std;

int StrLenght(char[]);
void FindInvalidWordsAndMakeThemSpace(char*, int);
int FindLetterCountOfSmallestWord(char*, int);
int FindSmallestWordsCountByGivenSize(char*, int,int);


int main()
{
	char arr[101];
	cout << "Your input:"<<endl;
	cin.getline(arr, 100);

	int strLen = StrLenght(arr);

	FindInvalidWordsAndMakeThemSpace(arr,strLen);
	int lettersCountOfSmallestWord=FindLetterCountOfSmallestWord(arr,strLen);
	int countOfSmallestWords = FindSmallestWordsCountByGivenSize(arr, strLen, lettersCountOfSmallestWord);

	cout << countOfSmallestWords;

	system("pause");
	return 0;

}
int FindLetterCountOfSmallestWord(char* arr, int strLenght)
{
	int min = INT_MAX;
	int counter = 0;
	for (int i = 0; i < strLenght; i++)
	{
		if (arr[i]!=' ')
		{
			counter++;
		}
		
		if(arr[i] == ' '||i==strLenght-1)
		{
			if (counter>0)
			{
				if (min>counter )
				{
					min= counter;
				}
				counter = 0;
			}
		}
	}
	if (min==INT_MAX)
	{
		min = 0;
	}

	return min;
}
int StrLenght(char arr[])
{
	int count = 0;

	while (arr[count] != '\0')
	{
		count++;
	}

	return count;
}

void FindInvalidWordsAndMakeThemSpace(char* arr, int strLenght)
{
	int smallestWordCount = INT_MAX;
	int temp = 0;
	for (int i = 0; i < strLenght; i++)
	{
		if (!(arr[i] >= 'a'&&arr[i] <= 'z') && !(arr[i] >= 'A'&&arr[i] <= 'Z')
			&& arr[i] != '\t'
			&& arr[i] != '\n'
			&& arr[i] != '\r'
			&& arr[i] != '\b'
			&& arr[i] != '\a'
			&& arr[i] != ' '
			&& arr[i] != '_'
			&& arr[i] != '-')
		{

			int temp2 = i;

			while (arr[temp2] != ' '&&temp2 >= 0)
			{

				arr[temp2] = ' ';
				temp2--;

			}
			i += 1;
			while (arr[i] != ' ' && i < strLenght)
			{

				arr[i] = ' ';
				i++;

			}
		}
		else if (arr[i] == '_' || arr[i] == '-')
		{
			if (i+1<strLenght&&i-1>=0)
			{
				if (arr[i+1]==' '&&arr[i - 1] == ' ')
				{
					arr[i] = ' ';
				}
			}
			else if (i + 1 < strLenght)
			{
				if (arr[i + 1] == ' ')
				{
					arr[i] = ' ';
				}
			}
			else if (i - 1 >= 0)
			{
				if (arr[i - 1] == ' ')
				{
					arr[i] = ' ';
				}
			}
		}
	}
}

int FindSmallestWordsCountByGivenSize(char* arr, int strLenght,int smallestWordSize)
{
	int smallestWordsCount = 0;
	int tempCounter = 0;
	for (int i = 0; i < strLenght; i++)
	{
		if (arr[i]!=' ')
		{
			tempCounter++;
		}
		
		if(arr[i]==' '||i== strLenght - 1)
		{
			if (tempCounter != 0)
			{
				if (tempCounter== smallestWordSize)
				{
					smallestWordsCount++;
				}
			}
			tempCounter = 0;
		}
	}

	return smallestWordsCount;
}
