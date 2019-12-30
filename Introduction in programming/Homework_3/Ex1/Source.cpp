#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Answer
{
	char Text[200];
	bool isItTrue;
};
struct Question
{
	char Text[400];
	Answer answers[4];
	bool isItUsed = false;
};

static Question questions[10];

void AddingQuestionsInArray();
int GenerateRandomQuestion();
void GetAndCheckAnswer(int, int);
bool ContiniueOrExit();
void PrintDashes(int);

int main()
{
	AddingQuestionsInArray();

	int counter = 1;
	while (true)
	{
		system("cls");

		int randNum = GenerateRandomQuestion();
		GetAndCheckAnswer(counter, randNum);

		if (counter == 10)
		{
			cout << "There are not more questions. Game ended";
			break;
		}
		counter++;

		bool continiueOrExit = ContiniueOrExit();

		if (continiueOrExit)
		{
			return 0;
		}
	}

	system("PAUSE");
	return 0;
}

bool ContiniueOrExit()
{
	cout << "Would you like to continiue or exit. For exit pres 'e', for continiue press 'c'!" << endl;;
	char command;
	cin >> command;

	while (true)
	{
		if (command == 'c')
		{
			return 0;
		}
		else if (command == 'e')
		{
			return 1;
		}
		else
		{
			cout << "Your command is invalid! Please try again" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> command;

		}
	}
}

void GetAndCheckAnswer(int questionNum, int questionIndex)
{
	PrintDashes(2);
	cout << "Enter the letter which you think that is the correct answer." << endl;
	PrintDashes(1);
	cout << "Would you like to use 50/50. If you want to use it press 1" << endl;
	PrintDashes(1);
	cout << "Question " << questionNum << endl;

	questions[questionIndex].isItUsed = true;

	cout << questions[questionIndex].Text << endl;
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << (char)('a' + i) << ") " << questions[questionIndex].answers[i].Text << endl;
	}
	PrintDashes(1);
	char answer;
	bool isItJokerUsed = false;
	cout << "Your answer: ";

	cin >> answer;
	while (true)
	{
		if (answer == '1' && !(isItJokerUsed))
		{
			PrintDashes(1);
			cout << "You choised 50/50.Two incorect was removed." << endl;
			bool temp = true;
			cout << questions[questionIndex].Text << endl;

			for (int i = 0; i < 4; i++)
			{
				if (questions[questionIndex].answers[i].isItTrue)
				{
					cout << (char)('a' + i) << ") " << questions[questionIndex].answers[i].Text << endl;
				}
				else
				{
					if (temp)
					{
						cout << (char)('a' + i) << ") " << questions[questionIndex].answers[i].Text << endl;
						temp = false;
					}

				}
				isItJokerUsed = true;
			}
			PrintDashes(1);
			cout << "Your answer: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> answer;
		}
		else if (answer == '1' && (isItJokerUsed))
		{
			cout << "You can't use 50/50. You have already used it!" << endl;
			cout << "Your answer: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> answer;
		}
		else if (answer >= 'a'&&answer <= 'd')
		{
			if (questions[questionIndex].answers[answer - 'a'].isItTrue)
			{
				PrintDashes(1);
				cout << "The answer is corect!" << endl;
				PrintDashes(1);
			}
			else
			{
				cout << endl;
				int corAns = 0;
				for (int i = 0; i < 4; i++)
				{
					if (questions[questionIndex].answers[i].isItTrue)
					{
						corAns = i;
						break;
					}
				}
				PrintDashes(1);

				cout << "Your answer is incorect! The corect answer is " << (char)('a' + corAns) << ") " << endl;

				PrintDashes(1);
			}
			cout << endl << endl;
			break;
		}
		else
		{
			cout << "Your input is invalid! Please try again!" << endl;
			cout << "Your answer: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> answer;
		}
	}

}

void AddingQuestionsInArray()
{
	questions[0] = { "5+6=?",{"1",false,"11",true,"15",false,"9",false} };
	questions[1] = { "5%16=?",{"1",true,"5",false,"2",false,"3",false} };
	questions[2] = { "15+16-32+5=?",{"0",false,"32",false,"31",false,"4",true} };
	questions[3] = { "14, 15, 16, 17, ?",{"21",false,"20",false,"18",true,"19",false} };
	questions[4] = { "Who is the president of Bulgaria",{"Rosen Plevneliev",false,"Rumen Radev",true,"Todor Jivkov",false,"Boiko Borisov",false} };
	questions[5] = { "Which is the capital of Bulgaria",{"Plovdiv",false,"Burgas",false,"Varna",false,"Sofia",true} };
	questions[6] = { "What is occupation of Donald Trump",{"programmer",false,"chef",false,"president",true,"driver",false} };
	questions[7] = { "Where is eiffel tower",{"Paris",true,"Vratsa",false,"Hamburg",false,"London",false} };
	questions[8] = { "When 21th century started",{"2000",false,"1999",false,"2001",true,"2002",false} };
	questions[9] = { "What 'popirotq' mean",{"sugar",false,"knife",false,"apple",false,"nothing",true} };
}

void PrintDashes(int a)
{
	for (int i = 0; i < a * 40; i++)
	{
		cout << "=";
	}
	cout << endl;
}

int GenerateRandomQuestion()
{
	srand(time(NULL));
	int randNum = rand() % 10;
	while (questions[randNum].isItUsed == true)
	{
		randNum = rand() % 10;
	}

	return randNum;
}
