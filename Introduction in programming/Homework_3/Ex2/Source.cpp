#include <iostream>

using namespace std;

struct BigInt
{
	int num[1000];
	bool isItNegative = false;
};

void GetAndCheckIfStrIsValid(char*);
void ConvertAndPutNumbersInArr(char*, BigInt*, BigInt*);
int CheckWhichNumberIsBigger(BigInt*, BigInt*);
void CollectNums(BigInt*, BigInt*, BigInt*, int);
void SubtractionNums(BigInt*, BigInt*, BigInt*, int);

void MakeOperation(char, BigInt*, BigInt*, BigInt*);
int CountTheDigitsOfNum(BigInt*);
bool CheckIfTwoNumbersAreValid(char*);
int CountElementsOfStr(char* str);

int main()
{
	char str[210];

	BigInt num1;
	BigInt num2;
	BigInt result;

	GetAndCheckIfStrIsValid(str);
	ConvertAndPutNumbersInArr(str, &num1, &num2);
	MakeOperation(str[2], &num1, &num2, &result);

	if (result.isItNegative)
	{
		cout << "-";
	}

	for (int i = 0; i < 1000; i++)
	{
		if (result.num[i] >= 0)
		{
			cout << result.num[i];
		}
	}

	system("PAUSE");
	return 0;
}
void SubtractionNums(BigInt* arr1, BigInt* arr2, BigInt* result, int arr1Count)
{
	int remainder = 0;
	int indexer = 999;
	for (int i = 999; i >= 999 - arr1Count; i--)
	{
		if (arr2->num[i] != -1)
		{
			if (arr1->num[i] >= arr2->num[i])
			{
				result->num[indexer] = arr1->num[i] - arr2->num[i];
			}
			else
			{
				int takePosition = i - 1;
				while (arr1->num[takePosition] == 0)
				{
					takePosition--;
				}
				arr1->num[takePosition] -= 1;
				if (takePosition != (i - 1))
				{
					takePosition++;
					while (takePosition != i)
					{
						arr1->num[takePosition] = 9;
						takePosition++;
					}
					result->num[indexer] = arr1->num[i] + 10 - arr2->num[i];
					indexer--;
				}
				else
				{

					result->num[indexer] = arr1->num[i] + 10 - arr2->num[i];
					indexer--;
				}


			}
		}
		else
		{
			result->num[indexer] = arr1->num[i];
		}
		indexer--;
	}
	while (true)
	{
		if (result->num[indexer] == 0)
		{
			result->num[indexer] = -1;
			indexer--;
		}
		else
		{
			break;
		}
	}

}

void CollectNums(BigInt* arr1, BigInt* arr2, BigInt* result, int arr1Count)
{
	int remainder = 0;
	int indexer = 999;
	for (int i = 999; i >= 999 - arr1Count; i--)
	{
		if (arr2->num[i] != -1)
		{
			int num = arr1->num[i] + arr2->num[i] + remainder;

			remainder = num / 10;

			result->num[indexer] = num % 10;
			indexer--;
		}
		else
		{
			if (i == (999 - arr1Count) && remainder != 0)
			{
				result->num[i] = remainder;
			}
			else if (i != (999 - arr1Count))
			{
				int num = arr1->num[i] + remainder;
				remainder = num / 10;
				result->num[indexer] = num % 10;
				indexer--;
			}

		}
	}
}

int CheckWhichNumberIsBigger(BigInt* num1, BigInt* num2)
{
	int num1Count = CountTheDigitsOfNum(num1);
	int num2Count = CountTheDigitsOfNum(num2);
	if (num1Count > num2Count)
	{
		return 1;
	}
	else if (num1Count < num2Count)
	{
		return 2;
	}
	else
	{
		for (int i = 999 - num1Count; i < 1000; i++)
		{
			if (num1->num[i] > num2->num[i])
			{
				return 1;
			}
			else if (num1->num[i] < num2->num[i])
			{
				return 2;
			}
		}
		return 3;
	}
}
void MakeOperation(char operatorCom, BigInt* arr1, BigInt* arr2, BigInt* result)
{
	int arr1Count = CountTheDigitsOfNum(arr1);
	int arr2Count = CountTheDigitsOfNum(arr2);

	for (int i = 1000- arr1Count; i <= 999; i++)
	{
		if (arr1->num[i]==0)
		{
			arr1->num[i] = -1;
		}
		else
		{
			break;
		}

	}
	for (int i = 1000 - arr2Count; i <= 999; i++)
	{
		if (arr2->num[i] == 0)
		{
			arr2->num[i] = -1;
		}
		else
		{
			break;
		}

	}

	arr1Count = CountTheDigitsOfNum(arr1);
	arr2Count = CountTheDigitsOfNum(arr2);

	int biggerNum = CheckWhichNumberIsBigger(arr1, arr2);
	if (operatorCom == '+')
	{
		if ((arr1->isItNegative == true && arr2->isItNegative == true) ||
			(arr1->isItNegative == false && arr2->isItNegative == false))
		{
			if (biggerNum == 1)
			{
				CollectNums(arr1, arr2, result, arr1Count);
			}
			else
			{
				CollectNums(arr2, arr1, result, arr2Count);
			}
			if (arr1->isItNegative == true)
			{
				result->isItNegative = true;
			}
		}
		else if ((arr1->isItNegative == true && arr2->isItNegative == false))
		{
			if (biggerNum == 1)
			{
				SubtractionNums(arr1, arr2, result, arr1Count);
			}
			else if (biggerNum == 2)
			{
				SubtractionNums(arr2, arr1, result, arr2Count);
				result->isItNegative = true;
			}
			else
			{
				result->num[999] = 0;
			}
		}
		else if ((arr1->isItNegative == false && arr2->isItNegative == true))
		{
			if (biggerNum == 1)
			{
				SubtractionNums(arr1, arr2, result, arr1Count);
				
			}
			else if (biggerNum == 2)
			{
				SubtractionNums(arr2, arr1, result, arr2Count);
				result->isItNegative = true;
			}
			else
			{
				result->num[999] = 0;
			}
		}

	}
	else if (operatorCom == '-')
	{
		if ((arr1->isItNegative == false && arr2->isItNegative == false))
		{
			if (biggerNum == 1)
			{
				SubtractionNums(arr1, arr2, result, arr1Count);
				result->isItNegative = true;
			}
			else if (biggerNum == 2)
			{
				SubtractionNums(arr2, arr1, result, arr2Count);
			}
			else
			{
				result->num[999] = 0;
			}

		}
		else if ((arr1->isItNegative == true && arr2->isItNegative == true))
		{
			if (biggerNum == 1)
			{
				SubtractionNums(arr1, arr2, result, arr1Count);

			}
			else if (biggerNum == 2)
			{
				SubtractionNums(arr2, arr1, result, arr2Count);
				result->isItNegative = true;
			}
			else
			{
				result->num[999] = 0;
			}
		}
		else if ((arr1->isItNegative == true && arr2->isItNegative == false))
		{
			if (biggerNum == 1)
			{
				CollectNums(arr1, arr2, result, arr1Count);

			}
			else if (biggerNum == 2)
			{
				CollectNums(arr2, arr1, result, arr2Count);
			}

		}
		else if ((arr1->isItNegative == false && arr2->isItNegative == true))
		{
			if (biggerNum == 1)
			{
				CollectNums(arr1, arr2, result, arr1Count);
				result->isItNegative = true;

			}
			else if (biggerNum == 2)
			{
				CollectNums(arr2, arr1, result, arr2Count);
				result->isItNegative = true;
			}
		}

	}
	else
	{
		for (int i = 999; i > 999 - arr1Count; i--)
		{
			BigInt temp;
			int tempNum = 0;
			if (i==999)
			{	
				for (int i = 0; i < 1000; i++)
				{
					result->num[i] = -1;

				}
				for (int j = 999; j > 999 - arr2Count; j--)
				{
					int num = arr1->num[i] * arr2->num[j] + tempNum;
					tempNum = num / 10;
					result->num[j] = num % 10;
				}
		
				if (tempNum!=0)
				{
					result->num[999 - arr2Count] = tempNum;
				
				}
			}
			else
			{
				BigInt temp2;
				for (int j = 0; j < 1000; j++)
				{
					temp.num[j] = -1;
					temp2.num[j] = -1;
				}
				for (int j = 999; j > i; j--)
				{
					temp.num[j] = 0;
				}
				for (int j = 999; j > 999 - arr2Count; j--)
				{
					int num = arr1->num[i] * arr2->num[j] + tempNum;
					tempNum = num / 10;
					temp.num[j - (999 - i)] = num % 10;
				}
				int arr1Count2 = CountTheDigitsOfNum(&temp);
				if (tempNum != 0)
				{
					temp.num[999 - arr1Count2] = tempNum;
					arr1Count2++;
				}
				
			
				int arr2Count3 = CountTheDigitsOfNum(result);
				int biggerNum = CheckWhichNumberIsBigger(&temp, result);
				for (int j = 999; j > 999- arr2Count3; j--)
				{
					temp2.num[j] = result->num[j];

				}
				if (biggerNum==1)
				{
					CollectNums(&temp, &temp2,result,arr1Count2);
				}
				else
				{
					CollectNums(&temp2,&temp, result, arr2Count3);
				}
			}
		}
		if ((arr1->isItNegative == true && arr2->isItNegative == true) ||
			(arr1->isItNegative == false && arr2->isItNegative == false))
		{
			result->isItNegative = false;
		}
		else
		{
			result->isItNegative = true;
		}
	}
}

void ConvertAndPutNumbersInArr(char* arr, BigInt* num1, BigInt*num2)
{
	int count = CountElementsOfStr(arr);
	int i = count - 3;
	int indexer = 999;
	while (arr[i] != ' '&&arr[i] != '+'&& arr[i] != '-')
	{
		num2->num[indexer] = arr[i] - '0';
		i--;
		indexer--;
	}
	if (arr[i] != ' ')
	{
		if (arr[i] == '-')
		{
			num2->isItNegative = true;
		}
		i--;
	}
	while (indexer != -1)
	{
		num2->num[indexer] = -1;
		indexer--;
	}
	i--;
	indexer = 999;
	while (arr[i] != ' ' && arr[i] != '+' && arr[i] != '-')
	{
		num1->num[indexer] = arr[i] - '0';
		i--;
		indexer--;
	}
	if (arr[i] != ' ')
	{
		if (arr[i] == '-')
		{
			num1->isItNegative = true;
		}
	}
	while (indexer != -1)
	{
		num1->num[indexer] = -1;
		indexer--;
	}
}
int CountTheDigitsOfNum(BigInt* arr)
{
	int counter = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (arr->num[i] != -1)
		{
			counter++;

		}
	}
	return counter;
}
void GetAndCheckIfStrIsValid(char* str)
{
	cout << "Your input (the format is '<<op X1 X2 >>'):"<<endl;
	cin.get(str, 210);

	while (true)
	{
		int countOfEnteredSymbols = CountElementsOfStr(str);

		if (countOfEnteredSymbols < 9 ||
			(str[0] != '<' || str[1] != '<' || str[countOfEnteredSymbols - 2] != '>' || str[countOfEnteredSymbols - 1] != '>') ||
			(str[2] != '+'&&str[2] != '-' && str[2] != '*') ||
			(str[3] != ' '))
		{
			cout << "Invalid input format! Please try again. The format is '<< op X1 X2 >>', where the op is the operator, X1 and X2 are the numbers" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.get(str, 210);
		}
		else
		{
			bool isNumberFomratIsValid = CheckIfTwoNumbersAreValid(str);
			if (isNumberFomratIsValid)
			{
				break;
			}
			else
			{
				cout << "Invalid input format! Please try again. The format is '<< op X1 X2 >>', where the op is the operator, X1 and X2 are the numbers" << endl;

				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin.get(str, 210);
			}
		}
	}
}
bool CheckIfTwoNumbersAreValid(char* arr)
{
	int i = 4;
	int spaceCounter = 0;
	int counter1 = 0;
	int counter2 = 0;
	while (arr[i] != '>')
	{
		if (arr[i] == ' ')
		{
			spaceCounter++;
		}
		i++;
	}
	if (spaceCounter != 1)
	{
		return 0;
	}
	int firstNumInvalidCharactersCount = 0;
	i = 4;
	while (arr[i] != ' ')
	{
		counter1++;
		if ((arr[i] == '-' || arr[i] == '+') && i == 4)
		{
			i++;
			continue;
		}
		else if (arr[i] < '0' || arr[i]>'9')
		{
			firstNumInvalidCharactersCount++;
		}
		i++;
	}
	if (firstNumInvalidCharactersCount != 0)
	{
		return 0;
	}

	int secondNumInvalidCharactersCount = 0;
	i++;
	int temp = i;
	while (arr[i] != '>')
	{
		counter2++;
		if ((arr[i] == '-' || arr[i] == '+') && i == temp)
		{
			i++;
			continue;
		}
		else if (arr[i] < '0' || arr[i]>'9')
		{
			secondNumInvalidCharactersCount++;
		}
		i++;
	}
	if (secondNumInvalidCharactersCount != 0)
	{
		return 0;
	}
	if (--counter1>100||--counter2>100)
	{
		return 0;
	}
	return 1;
}
int CountElementsOfStr(char* str)
{
	int counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}

	return counter;
}