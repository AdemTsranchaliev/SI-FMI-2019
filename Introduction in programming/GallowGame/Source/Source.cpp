#include <iostream>
#include <stdlib.h>    
#include <time.h>  
using namespace std;

struct Word
{
	char word[8];
	int count;
	bool isUsed = false;
};
char GetAndCheckLetter();
void PrintDashes(int,char);
void AddingWords();
void NewGame();
int CheckIfLetterExist(char*,char);
int GetAndCheckInput(int,int);
Word words[10];
int chances = 3;
int wordCount = 5;

int main()
{
	cout << "Wellcome in GALLOW GAME"<<endl;
	AddingWords();
	while (true)
	{
		int command = 0;

		cout << "MAIN MENU"<<endl<<endl;

		cout << "Press '1' for starting new game " << endl;
		cout << "Press '2' for settings " << endl;
		cout << "Press '3' for exit " << endl;
		command = GetAndCheckInput(1,3);

		if (command==1)
		{
			NewGame();
		}
		else if (command == 2)
		{
			cout << "Settings"<<endl;
	
			int settingCommand = 0;

			cout << "Press '1' for changing the word count"<<endl;
			cout << "Press '2' for changing chances count" << endl;
			settingCommand = GetAndCheckInput(1,2);

			if (settingCommand==1)
			{
				cout << "The current word count is "<<wordCount<<endl;
				cout << "Enter how much you want to make the word cout(word count must be between 4 and 7)"<<endl;
				wordCount = GetAndCheckInput(4,7);

				cout << "The word count was changed to "<<wordCount<<endl;
			}
			else if (settingCommand == 2)
			{
				cout << "The current chances count is " << chances << endl;
				cout << "Enter how much you want to make chances cout(chances count must be between 3 and 7)" << endl;
				wordCount = GetAndCheckInput(3,7);

				cout << "Chances count was changed to " << chances << endl;
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
	int randNum = 0;
	while (true)
	{
		 srand(time(NULL));
	     randNum = rand() % 10;
		 if (words[randNum].isUsed==false)
		 {
			 break;
		 }
	}
	words[randNum].isUsed = true;
	int wordCount = words[randNum].count;
	char tempChar[8];
	int total = 0;
	int chancesForGame = chances;
	for (int i = 0; i < wordCount; i++)
	{
		tempChar[i] = '_';
	}
	tempChar[wordCount] = '\0';

	while (true)
	{

		cout << "Your chances for mistakes are "<< chancesForGame <<endl;
	
		cout << "The word is: '";
		for (int i = 0; i < words[randNum].count; i++)
		{
			if (words[randNum].count!=i+1)
			{
				cout << tempChar[i]<<" ";
			}
			else
			{
				cout << tempChar[i];
			}
		}
		cout << "'"<<endl;

		char letter;
		cout << "Enter letter which you think can contain the word" << endl;
		letter = GetAndCheckLetter();
		int checkLetterExist = CheckIfLetterExist(tempChar, letter);

		if (checkLetterExist==1)
		{
			cout << "The letter '" << letter << "' already is entered" << endl;
			continue;
		}

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
		
			cout << "The letter '" << letter << "' don't exist in the given word"<<endl;
			chancesForGame--;
			if (chancesForGame==0)
			{
				cout << "GAME OVER!Your don't have more chances! You couldn't guess the word!"<<endl;
				cout << "The word is '"<< words[randNum].word<<"'"<<endl;
				PrintDashes(30, '*');
				break;
			}
		
		}
		else
		{
			
				cout << "The word contains the letter '" << letter << "' " << findedLetters << " times" << endl;
				total += findedLetters;
			
		}


		if (total== words[randNum].count)
		{
			cout << "You won that game! You guessed the word!"<<endl;
			cout << "The word is: "<< words[randNum].word << endl;
			break;
		}

	}
}
int CheckIfLetterExist(char* arr,char letter)
{
	int counter = 0;
	while (arr[counter]!='\0')
	{
		if (arr[counter]==letter)
		{
			return 1;
		}
		counter++;
	}

	return 0;
}

int GetAndCheckInput(int start,int end)
{
	int input = 0;

	cin >> input;

	while (true)
	{
		if (cin.fail())
		{
			cout << "Wrong input! Try again!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> input;
		}
		else if (input >= start && input <= end)
		{
			break;
		}
		else
		{
			cout << "Wrong input! Try again!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> input;
		}
	}


	return input;
}

char GetAndCheckLetter()
{
	char input ;

	cin >> input;

	while (true)
	{
		if (input>='a'&&input<='z')
		{
			break;
			
		}
		else
		{
			cout << "Wrong input! Try again!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> input;
		}

	}


	return input;
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