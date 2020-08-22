#include <iostream>
using namespace std;

void findShortest(char[], char[]);
int checkIfSetContainsSingAndReturnIndexOfFoundSign(char,char[]);
int countSymbols(char[]);
int countUniqueSymbols(char[]);

int main()
{
	char test[] = { "gudhelasing" };
	char test2[] = { "luaula" };
	char test3[] = { "gudhelasing" };
	char test4[] = { "sal" };
	char test5[] = { "creeppyyng" };
	char test6[] = { "lus" };

	findShortest(test, test2);
	findShortest(test3, test4);
	findShortest(test5, test6);
}

int checkIfSetContainsSingAndReturnIndexOfFoundSign(char sign, char set[])
{
	int i = 0;
	while (set[i]!='\0')
	{
		if (sign==set[i])
		{
			return i;
		}
		i++;
	}

	return -1;
}


void findShortest(char mainString[], char charSet[])
{
	int i = 0;
	int countOfMainString = countSymbols(mainString);
	int countOfCharSet = countUniqueSymbols(charSet);

	char* newWord = new char[countOfMainString + 1];
	char* foundedSymbols= new char[countOfCharSet + 1];

	newWord[0] = '\0';
	foundedSymbols[0] = '\0';

	int foundedSymbolsIndex = 0;
	int newWordFreeIndex = 0;

	while (mainString[i]!='\0')
	{
		int result= checkIfSetContainsSingAndReturnIndexOfFoundSign(mainString[i],charSet);
		if (result == -1 && foundedSymbolsIndex != 0)
		{
			newWord[newWordFreeIndex] = mainString[i];
			newWordFreeIndex++;
		}
		else if(result != -1)
		{

			int isSignAlreadyFounded = checkIfSetContainsSingAndReturnIndexOfFoundSign(charSet[result], foundedSymbols);

			if (isSignAlreadyFounded==-1)
			{
				foundedSymbols[foundedSymbolsIndex] = charSet[result];
				foundedSymbolsIndex++;
			}

			newWord[newWordFreeIndex] = mainString[i];
			newWordFreeIndex++;
			newWord[newWordFreeIndex] = '\0';

		}


		if (countOfCharSet == foundedSymbolsIndex)
		{
			cout << newWord<<endl;
			break;
		}

		i++;
	}
	delete[] newWord;
	delete[] foundedSymbols;;
}

int countSymbols(char set[])
{
	int i = 0;
	while (set[i] != '\0')
	{
		
		i++;
	}
	return i;
}

int countUniqueSymbols(char str[]) {
	int count = 0;

	for (int i = 0; i < strlen(str); i++) {
		bool flag = false;
		for (int j = 0; j < i; j++) {
			if (str[j] == str[i]) {
				flag = true;
				break;
			}
		}

		if (!flag) {
			count++;
		}
	}

	return count;
}