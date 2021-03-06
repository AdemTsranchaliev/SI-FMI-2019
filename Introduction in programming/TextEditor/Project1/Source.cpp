#include <iostream>

using namespace std;

//Main functions
void ConvertLettersToCapital(char*, int);
void ConvertLettersToSmall(char*, int);
int SearchForWord(char*, int, char*);
int Replace(char*);
void AddWordOrSentenceOnPosition(char*);
void Delete(char*, char*, int, int, int);

//Validation functions
int GetAndCheckCommand();
int GetAndCheckPosition(int);
void GetAndCheckIfStrIsEmpty(char*);

//char[] symbol counting
int CountSymbols(char*);

//Additional funcitons
void PrintDashes();
int SearchingExactWord(char*, int, char*);


int main()
{
	cout << "WELCOME TO TEXT EDITEOR." << endl;
	cout << "Insert your text:" << endl;

	char str[1001];
	
	GetAndCheckIfStrIsEmpty(str);

	int sybmolCount = CountSymbols(str);
	int command = 0;
	cout << "Press 0, for exit" << endl;
	cout << "Press 1, for converting all letters to capital" << endl;
	cout << "Press 2, for converting all letters to small" << endl;
	cout << "Press 3, for searching word" << endl;
	cout << "Press 4, for deleting word" << endl;
	cout << "Press 5, for replacing word with other" << endl;
	cout << "Press 6, for adding word or sentence on given position" << endl;
	cout << "Press 7, for searching exact word" << endl;


	command = GetAndCheckCommand();

	while (command != 0)
	{

		if (command == 1)
		{
			PrintDashes();
			if (sybmolCount!=0)
			{
				ConvertLettersToCapital(str, sybmolCount);
				cout << "All letters was converted to capital" << endl << endl;
				cout << "The text is: " << endl;
				cout<<str << endl;
			}
			else
			{
				cout << "There are no text!" << endl;
			}
			
			PrintDashes();
		}
		else if (command == 2)
		{
			PrintDashes();
			if (sybmolCount != 0)
			{	
				ConvertLettersToSmall(str, sybmolCount);
				cout << "All letters was converted to small" << endl << endl;
				cout << "The text is: " << endl;
				cout << str << endl;
			}
			else
			{
				cout << "There are no text!" << endl;
			}
	
			PrintDashes();
		}
		else if (command == 3)
		{
			char arr2[200];
	
			PrintDashes();
			if (sybmolCount==0)
			{
				cout << "There are no text to search!" << endl;
			}
			else
			{
				cout << "Please enter the word you want to search:" << endl;
				cin.clear();
				cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			    GetAndCheckIfStrIsEmpty(arr2);

				int startIndex = SearchForWord(str, sybmolCount, arr2);

				if (startIndex != -1)
				{
					cout << "The word '" << arr2 << "' was found. The starting index is " << startIndex << endl << endl;
				}
				else
				{
					cout << "The word '" << arr2 << "' wasn't found!" << endl << endl << endl;
				}
			}
			
			PrintDashes();

		}
		else if (command == 4)
		{
			PrintDashes();
			if (sybmolCount!=0)
			{
				char arr2[200];
				cin.clear();
				cin.ignore(numeric_limits < streamsize > ::max(), '\n');
				cout << "Please enter the word(character) you want to delete from all text:" << endl;
				GetAndCheckIfStrIsEmpty(arr2);

				int countSearchingWord = CountSymbols(arr2);
				

				int startingIndex = SearchForWord(str, sybmolCount, arr2);
				if (startingIndex == -1)
				{
					cout << "The word you wanted to delete doesn't exist!" << endl;
				}
				else
				{
					Delete(str, arr2, startingIndex, countSearchingWord, sybmolCount);
					cout << "Delete was successfully completed!" << endl;
					cout << "The text is: " << endl;
					cout << str << endl;
					sybmolCount = CountSymbols(str);
				}
			}
			else
			{
				cout << "There are no text to delete!"<<endl;
			}
	
			PrintDashes();
		}
		else if (command == 5)
		{
			PrintDashes();
			if (sybmolCount!=0)
			{
			
				int isError = Replace(str);
				if (isError == 0)
				{
					sybmolCount = CountSymbols(str);
					cout << "The text is: " << endl;
					cout << str << endl;
				}
				else if (isError == 1)
				{
					cout << "The word you wanted to be replaced wasn't found!" << endl;
					cout << "The text wasn't changed!" << endl << endl;
					cout << str << endl;
				}
				else if (isError == 2)
				{
					cout << "There is no text!" << endl;
					cout << str << endl;
				}
				else if (isError == 3)
				{
					cout << "Invalid format for replacing! The word to replace must to be separated with space from replacing word!" << endl;
					cout << str << endl;
				}
			}
			else
			{
				cout << "There are no text to replace!"<<endl;
			}
			
			PrintDashes();
		}
		else if (command == 6)
		{
			PrintDashes();
			AddWordOrSentenceOnPosition(str);
			sybmolCount = CountSymbols(str);
			cout << "The text is: " << endl;
			cout << str << endl;
			PrintDashes();
		}
		else if (command==7)
	{
	char arr2[200];
	    
			PrintDashes();
			if (sybmolCount==0)
			{
				cout << "There are no text to search!" << endl;
			}
			else
			{
				cout << "Please enter the exact word you want to search:" << endl;
				cin.clear();
				cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			    GetAndCheckIfStrIsEmpty(arr2);

				int startIndex = SearchingExactWord(str, sybmolCount, arr2);

				if (startIndex != -1)
				{
					cout << "The word '" << arr2 << "' was found. The starting index is " << startIndex << endl << endl;
				}
				else
				{
					cout << "The word '" << arr2 << "' wasn't found!" << endl << endl << endl;
				}
			}
			
			PrintDashes();
	}
		else if (command == 0)
		{
			exit;
		}

		cout << "Press 0, for exit" << endl;
		cout << "Press 1, for converting all letters to capital" << endl;
		cout << "Press 2, for converting all letters to small" << endl;
		cout << "Press 3, for searching word" << endl;
		cout << "Press 4, for deleting word" << endl;
		cout << "Press 5, for replacing word with other" << endl;
		cout << "Press 6, for adding word or sentence on given position" << endl;
		cout << "Press 7, for searching exact word" << endl;
		command = GetAndCheckCommand();
	}

}


void PrintDashes()
{
	for (int i = 0; i < 60; i++)
	{
		cout << "=";
	}
	cout << endl;
}
int GetAndCheckCommand()
{
	int command = 0;

	cin >> command;

	while (true)
	{
		if (command >= 0 && command <= 7 && !cin.fail())
		{
			break;
		}
		else
		{
			cout << "Command is invalid! Please try again" << endl;
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			cin >> command;
		}
	}
	return command;
}
int GetAndCheckPosition(int mainArrCount)
{
	int position = 0;

	cin >> position;

	while (true)
	{
		if (cin.fail())
		{
			cout << "Command is invalid! Please try again" << endl;
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			cin >> position;
		}
		else if (position>mainArrCount)
		{
			cout << "Your text is "<<mainArrCount<<" characters long, how would you expect to add your text on position "<<position<<"! Please try again" << endl;
			cin.clear();
			cin.ignore(numeric_limits < streamsize > ::max(), '\n');
			cin >> position;
		}
		else
		{
			break;
		}
	}
	return position;
}


void AddWordOrSentenceOnPosition(char* arr)
{
	char arr2[200];
	int position = 0;
	cout << "Please enter the position(index) you want to add:" << endl;
	int mainArrCount = CountSymbols(arr);
	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');
	position = GetAndCheckPosition(mainArrCount);
	cin.ignore();
	cout << "Please enter the word(sentence) you want to add:" << endl;
	GetAndCheckIfStrIsEmpty(arr2);

	int countOfArr1 = CountSymbols(arr);
	int countOfArr2 = CountSymbols(arr2);
	for (int i = countOfArr2 + countOfArr1 - 1; i >= position + countOfArr2; i--)
	{
		arr[i] = arr[i - countOfArr2];
	}
	arr[countOfArr2 + countOfArr1] = '\0';
	for (int i = 0; i < countOfArr2; i++)
	{
		arr[i + position] = arr2[i];
	}

}

int Replace(char* arr)
{
	char arr2[200];
	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');
	cout << "Please enter the words you want to replace and the word to replace separated with space:" << endl;
	cin.get(arr2, 200);

	int countRepSymbols = CountSymbols(arr2);

	int spaceIndex = 0;

	while (arr2[spaceIndex] != ' '&&arr2[spaceIndex] != '\0')
	{
		spaceIndex++;
	}
	if (arr2[spaceIndex] == '\0')
	{
		return 3;
	}
	if (arr2[spaceIndex + 1] == '\0')
	{
		return 3;
	}
	char wordSearch[200];
	char wordReplace[200];
	for (int i = 0; i < spaceIndex; i++)
	{
		wordSearch[i] = arr2[i];
	}
	wordSearch[spaceIndex] = '\0';
	for (int i = 0; i < countRepSymbols - spaceIndex; i++)
	{
		wordReplace[i] = arr2[i + spaceIndex + 1];
	}

	int arrCount = CountSymbols(arr);

	if (arrCount != 0)
	{
		int wordSearchCount = CountSymbols(wordSearch);
		int wordReplaceCount = CountSymbols(wordReplace);
		int startIndexSearchWord = SearchForWord(arr, arrCount, wordSearch);

		if (startIndexSearchWord == -1)
		{
			return 1;
		}

		if (wordReplaceCount == wordSearchCount)
		{
			for (int i = 0; i < wordSearchCount; i++)
			{
				arr[startIndexSearchWord + i] = wordReplace[i];
			}
		}
		else if (wordReplaceCount > wordSearchCount)
		{
			for (int i = arrCount + wordReplaceCount - wordSearchCount - 1; i >= startIndexSearchWord + (wordReplaceCount - wordSearchCount); i--)
			{
				arr[i] = arr[i - (wordReplaceCount - wordSearchCount)];
			}
			arr[arrCount + (wordReplaceCount - wordSearchCount)] = '\0';
			for (int i = 0; i < wordReplaceCount; i++)
			{
				arr[i + startIndexSearchWord] = wordReplace[i];
			}
		}
		else
		{
			for (int i = startIndexSearchWord + wordReplaceCount; i < arrCount - (wordSearchCount - wordReplaceCount); i++)
			{
				arr[i] = arr[i - wordReplaceCount + wordSearchCount];
			}
			arr[arrCount - (wordSearchCount - wordReplaceCount)] = '\0';
			for (int i = 0; i < wordReplaceCount; i++)
			{
				arr[i + startIndexSearchWord] = wordReplace[i];
			}
		}
	}
	else
	{
		return 2;
	}
	return 0;
}

int FindWordForDeleting(char* arr1, char* arr2, int symbolCount1, int symbolCount2)
{
	int temp = 0;
	int startingIndex = 0;
	for (int i = 0; i < symbolCount1; i++)
	{
		if (arr2[temp] == arr1[i] && temp == 0)
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

void Delete(char* arr,char* arr2,int startingIndex,int countSearchingWord,int symbolCount)
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
		startingIndex = SearchForWord(arr,symbolCount,arr2);

	}
}

int SearchForWord(char* arr1, int symbolCount, char* arr2)
{
	int temp = 0;
	int startingIndex = 0;
	for (int i = 0; i < symbolCount; i++)
	{
		if (arr2[temp] == arr1[i] && temp == 0)
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
		int symbolCount2 = CountSymbols(arr2);
		if (symbolCount2 == temp)
		{
			return startingIndex;
		}

	}

	return -1;
	
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


void GetAndCheckIfStrIsEmpty(char* str)
{
	cin.get(str, 1001);


	int sybmolCount = CountSymbols(str);

	while (sybmolCount == 0)
	{
		cout << "You have to insert at least 1 character. Please try again!" << endl;
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');
		cin.get(str, 1001);
		sybmolCount = CountSymbols(str);
	}
}


int SearchingExactWord(char* arr, int symbolCount, char* arr2)
{

	int searchingWordLetterCount = CountSymbols(arr2);
	if (searchingWordLetterCount == 0)
	{
		return -1;
	}
	int temp1 = 0;
	int startIndex = 0;
	for (int i = 0; i < symbolCount; i++)
	{
		if (arr2[temp1] == arr[i] && temp1 == 0)
		{
			if (i - 1 >= 0 || i == 0)
			{
				if (i == 0)
				{
					temp1++;
					startIndex = i;
				}
				else if (arr[i - 1] == ' ')
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

		if (temp1 == searchingWordLetterCount)
		{
			if ((i + 1) < symbolCount)
			{
				if (arr[i + 1] == ' ')
				{
					break;
				}
			}
			else if (i == symbolCount - 1)
			{
				break;
			}
			else
			{
				temp1 = 0;
			}
		}

	}

	if (temp1 == searchingWordLetterCount)
	{
		return startIndex;
	}
	else
	{
		return -1;
	}

}
