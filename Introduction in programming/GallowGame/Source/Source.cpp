#include <iostream>
#include <stdlib.h>    
#include <time.h>  
using namespace std;

struct Word
{
	char word[8];
	int count;
};
void PrintDashes(int,char);
void AddingWords();
void NewGame();
void GameSettings();
Word words[10];
int chances = 3;
int wordCount = 5;

int main()
{
	AddingWords();
	while (true)
	{
		int command = 0;
		cout << "Press '1' for starting new game " << endl;
		cout << "Press '2' for settings " << endl;
		cout << "Press '3' for exit " << endl;
		cin >> command;

		if (command==1)
		{

			NewGame();
			
		}
		else if (command == 2)
		{
			cout << "Settings"<<endl;
			PrintDashes(20,'-');
			int settingCommand = 0;

			cout << "Press '1' for changing the word count"<<endl;
			cout << "Press '2' for changing chances count" << endl;
			cin >> settingCommand;

			if (settingCommand==1)
			{
				cout << "The current word count is "<<wordCount<<endl;
				cout << "Enter how much you want to make the word cout(word count must be between 3 and 7)"<<endl;
				cin >> wordCount;

				cout << "The word count was changed to "<<wordCount<<endl;
			}
			else if (settingCommand == 2)
			{
				cout << "The current chances count is " << wordCount << endl;
				cout << "Enter how much you want to make chances cout(chances count must be between 3 and 7)" << endl;
				cin >> chances;

				cout << "Chances count was changed to " << wordCount << endl;
			}
		}
		else if (command == 3)
		{
			return 0;
		}


	}
}

void PrintDashes(int n,char l)
{
	for (int i = 0; i < n; i++)
	{
		cout << l;
	}
	cout << endl;
}

void NewGame()
{
	srand(time(NULL));
	int randNum = rand() % 10;
	int wordCount = words[randNum].count;
	char tempChar[8];
	int chancesForGame = chances;
	for (int i = 0; i < wordCount; i++)
	{
		tempChar[i] = '_';
	}
	tempChar[wordCount] = '\0';

	while (true)
	{
		PrintDashes(20,'=');
		cout << "The word is: ";
		cout << tempChar<<endl;
		PrintDashes(20, '=');

		char letter;
		cout << "Enter letter which you think can contain the word" << endl;
		cin >> letter;

		int findedLetters = 0;

		for (int i = 0; i < wordCount; i++)
		{
			if (words[randNum].word[i] == letter)
			{
				tempChar[i] = words[randNum].word[i];
				findedLetters++;
			}
		}
		if (findedLetters == 0)
		{
			PrintDashes(30, '-');
			cout << "The letter '" << letter << "' don't exist in the given word"<<endl;
			chancesForGame--;
			if (chancesForGame==0)
			{
				cout << "GAME OVER! You couldn't guess the word!"<<endl;
				cout << "The word is '"<< words[randNum].word<<"'"<<endl;
				PrintDashes(30, '-');
				break;
			}
			PrintDashes(30, '-');
		}
		else
		{
			PrintDashes(30, '-');
			cout << "The word contains the letter '" << letter << "' " << findedLetters << " times" << endl;
			PrintDashes(30, '-');
		}
	}
}
void AddingWords()
{
	words[0] = { "dog",3 };
	words[1] = { "flower",6 };
	words[2] = { "world",5 };

	words[3] = { "sun",3 };
	words[4] = { "family",6 };
	words[5] = { "women",5 };
	words[6] = { "varna",5 };
	words[7] = { "earth",5 };

	words[8] = { "beach",5 };
	words[9] = { "request",7 };
}