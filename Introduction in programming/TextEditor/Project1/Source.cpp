#include <iostream>

using namespace std;

void ConvertLettersToCapital(char*, int);
void ConvertLettersToSmall(char*, int);
int SearchForWord(char*,int,char*);
int FindWordForDeleting(char*, char*, int, int);
void FindWordIfExcistDeleteIt(char*);
void Replace(char*);
void AddWordOrSentenceOnPosition(char*);
int main();
int CountSymbols(char*);

int main()
{
	cout << "WELCOME TO TEXT EDITEOR." << endl;
	cout << "Insert your text:" << endl;

	char str[1001];
	cin.getline(str, 1001);


	int sybmolCount = CountSymbols(str);

	int command = 0;

	cout << "Press 1, for converting all letters to capital" << endl;
	cout << "Press 2, for converting all letters to small" << endl;
	cout << "Press 3, for searching word" << endl;
	cout << "Press 4, for deleting word" << endl;
	cout << "Press 5, for replacing word with other" << endl;
	cout << "Press 6, for adding word or sentence on given position" << endl;

	cin >> command;

	while (command != 0)
	{

		if (command == 1)
		{
			ConvertLettersToCapital(str, sybmolCount);
			cout << str << endl;
		}
		else if (command == 2)
		{
			ConvertLettersToSmall(str, sybmolCount);
			cout << str << endl;
		}
		else if (command == 3)
		{
			char arr2[200];
			cin.ignore();
			cout << "Please enter the word you want to search:" << endl;
			cin.getline(arr2, 200);

			int startIndex=SearchForWord(str, sybmolCount,arr2);

			if (startIndex!=-1)
			{
				cout << "The word '" << arr2 << "' was found. The starting index is " << startIndex << endl << endl;
			}
			else
			{
				cout << "The word '" << arr2 << "' wasn't found!" << endl << endl << endl;
			}
		
		}
		else if (command == 4)
		{
			FindWordIfExcistDeleteIt(str);
			sybmolCount = CountSymbols(str);
		}
		else if (command == 5)
		{
			Replace(str);
			sybmolCount = CountSymbols(str);
		}
		else if (command == 6)
		{
			AddWordOrSentenceOnPosition();
		}
		else if (command == 0)
		{

		}

		cout << "Press 1, for converting all letters to capital" << endl;
		cout << "Press 2, for converting all letters to small" << endl;
		cout << "Press 3, for searching word" << endl;
		cout << "Press 4, for deleting word" << endl;
		cout << "Press 5, for replacing word with other" << endl;
		cout << "Press 6, for adding word or sentence on given position" << endl;
		cin >> command;
	}

}

void AddWordOrSentenceOnPosition(char* arr)
{
	char arr2[200];
	int position = 0;
	cout << "Please enter the position(index) you want to add:" << endl;
	cin >> position;
	cin.ignore();
	cout << "Please enter the word(sentence) you want to add:" << endl;
	cin.getline(arr2, 200);

}

void Replace(char* arr)
{
	char arr2[200];
	cin.ignore();
	cout << "Please enter the words you want to replace and the word to replace separated with space:" << endl;
	cin.getline(arr2, 200);

	int countRepSymbols = CountSymbols(arr2);

	int spaceIndex = 0;

	while (arr2[spaceIndex]!=' ')
	{
		spaceIndex++;
	}
	char wordSearch[200];
	char wordReplace[200];
	for (int i = 0; i < spaceIndex; i++)
	{
		wordSearch[i] = arr2[i];
	}
	wordSearch[spaceIndex] = '\0';
	for (int i = 0; i < countRepSymbols-spaceIndex; i++)
	{
		wordReplace[i] = arr2[i+spaceIndex+1];
	}
	
	int arrCount = CountSymbols(arr);
	int wordSearchCount= CountSymbols(wordSearch);
	int wordReplaceCount = CountSymbols(wordReplace);
	int startIndexSearchWord = SearchForWord(arr, arrCount,wordSearch);
	if (wordReplaceCount==wordSearchCount)
	{
		for (int i = 0; i < wordSearchCount; i++)
		{
			arr[startIndexSearchWord + i] = wordReplace[i];
		}
	}
	else if (wordReplaceCount>wordSearchCount)
	{
		for (int i = arrCount+wordReplaceCount-wordSearchCount-1; i >= startIndexSearchWord+ (wordReplaceCount - wordSearchCount); i--)
		{
			arr[i] = arr[i - (wordReplaceCount - wordSearchCount)];
		}
		arr[arrCount + (wordReplaceCount - wordSearchCount) ]='\0';
		for (int i = 0; i < wordReplaceCount; i++)
		{
			arr[i+startIndexSearchWord] = wordReplace[i];
		}
	}
	else
	{
		for (int i = startIndexSearchWord+wordReplaceCount; i < arrCount-(wordSearchCount-wordReplaceCount); i++)
		{
			arr[i] = arr[i - wordReplaceCount + wordSearchCount];
		}
		arr[arrCount - (wordSearchCount - wordReplaceCount)] = '\0';
		for (int i = 0; i < wordReplaceCount; i++)
		{
			arr[i+startIndexSearchWord] = wordReplace[i];
		}
	}

}

int FindWordForDeleting(char* arr1,char* arr2, int symbolCount1,int symbolCount2)
{
	int temp = 0;
	int startingIndex = 0;
	for (int i = 0; i < symbolCount1; i++)
	{
		if (arr2[temp]==arr1[i]&&temp==0)
		{
			temp++;
			startingIndex = i;
		}
		else if (arr2[temp] == arr1[i])
		{
			temp++;
		}
		else
		{
			temp = 0;
		}

		if (symbolCount2 == temp)
		{
			return startingIndex;
		}
	
	}

	return -1;

}
void FindWordIfExcistDeleteIt(char* arr)
{
	char arr2[200];
	cin.ignore();
	cout << "Please enter the words you want to delete:" << endl;
	cin.getline(arr2, 200);

	int countSearchingWord = CountSymbols(arr2);
	int symbolCount = CountSymbols(arr);
	int startingIndex = FindWordForDeleting(arr,arr2,symbolCount,countSearchingWord);
	if (startingIndex==-1)
	{
		cout << "The word you wanted to delete doesn't exist!"<<endl;
	}
	else
	{
		while (startingIndex != -1)
		{

			if (arr[startingIndex + countSearchingWord] != ' ')
			{
				for (int i = startingIndex; i < symbolCount - countSearchingWord; i++)
				{
					arr[i] = arr[i + countSearchingWord];
				}
				arr[symbolCount - countSearchingWord] = '\0';
			}
			else
			{
				for (int i = startingIndex; i < symbolCount - countSearchingWord - 1; i++)
				{
					arr[i] = arr[i + countSearchingWord + 1];
				}
				arr[symbolCount - countSearchingWord - 1] = '\0';
			}


			symbolCount = CountSymbols(arr);
			startingIndex = FindWordForDeleting(arr, arr2, symbolCount, countSearchingWord);

		}
	}
}

int CountSymbols(char* arr)
{
	int counter = 0;

	while (arr[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

void ConvertLettersToCapital(char* arr, int symbolCount)
{
	for (int i = 0; i < symbolCount; i++)
	{
		if (arr[i] >= 'a'&&arr[i] <= 'z')
		{
			arr[i] = arr[i] - ('a' - 'A');
		}
	}
}
void ConvertLettersToSmall(char* arr, int symbolCount)
{
	for (int i = 0; i < symbolCount; i++)
	{
		if (arr[i] >= 'A'&&arr[i] <= 'Z')
		{
			arr[i] = arr[i] + ('a' - 'A');
		}
	}
}

int SearchForWord(char* arr, int symbolCount,char* arr2)
{


	int searchingWordLetterCount = CountSymbols(arr2);
	int temp1 = 0;
	int startIndex = 0;
	for (int i = 0; i < symbolCount; i++)
	{
		if (arr2[temp1]==arr[i]&&temp1==0)
		{
			if (i-1>=0||i==0)
			{
				if (i==0)
				{
					temp1++;
					startIndex = i;
				}
				else if (arr[i-1]==' ')
				{
					temp1++;
					startIndex = i;

				}
			}
		}
		else if (arr2[temp1] == arr[i])
		{
			temp1++;
		}
		else
		{
			temp1 = 0;
		}

		if (temp1== searchingWordLetterCount)
		{
			if ((i+1)<symbolCount)
			{
				if (arr[i+1]==' ')
				{
					break;
				}
			}
			else if (i==symbolCount-1)
			{
				break;
			}
			else
			{
				temp1 = 0;
			}
		}

	}

	if (temp1== searchingWordLetterCount)
	{
		return startIndex;
	}
	else
	{
		return -1;
	}

}