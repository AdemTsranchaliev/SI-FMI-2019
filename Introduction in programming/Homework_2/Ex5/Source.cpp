/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Adem Tsranchaliev
* @idnumber 62409
* @task 5
* @compiler VC
*
*/


#include <iostream>

using namespace std;

bool CheckIfMatrixCanBeOrderedAndOrderIt(int**,int*);
int  GetInputForMatrixSizeAndValidateIt();
int  GetMatrixElementAndValidateIt();
int main()
{
	int n = GetInputForMatrixSizeAndValidateIt();

	int** arr = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Insert element for row " << i << " , column " << j << endl;
			arr[i][j]= GetMatrixElementAndValidateIt();
		}
	}


	bool isItOrdered = CheckIfMatrixCanBeOrderedAndOrderIt(arr,&n);

	if (isItOrdered)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

	}
	else
	{
		cout << "Matrix can't be ordered!";
	}


	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
	system("pause");
	return 0;
}
int  GetMatrixElementAndValidateIt()
{
	int element = 0;
	cin >> element;
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input! Please try again!" << endl;
			cin >> element;
		}
		else
		{
			break;
		}
	}

	return element;
}
int  GetInputForMatrixSizeAndValidateIt()
{
	int n = 0;
	cout << "Insert matrix's size, which is between 1 and 10, included: " << endl;
	cin >> n;

	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input! Please try again!" << endl;
			cout << "Insert matrix's size, which is between 1 and 10, included: " << endl;
			cin >> n;
		}
		else if (n<1||n>10)
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input! Please try again!" << endl;
			cout << "Insert matrix's size, which is between 1 and 10, included: " << endl;
			cin >> n;
		}
		else
		{
			break;
		}
	}

	return n;
}

bool CheckIfMatrixCanBeOrderedAndOrderIt(int**arr,int* n)
{
	int min2 = INT_MAX;
	for (int j = 0; j < *n; j++)
	{
		if (arr[j][0] < min2)
		{
			min2 = arr[j][0];

		}
	}
	int flag = false;
	for (int i = 0; i < *n; i++)
	{
		int min = INT_MAX;
		int minIndex = i;
		flag = false;
		for (int j = i; j < *n; j++)
		{
			if (arr[j][i] <= min && arr[j][i] >= min2)
			{
				if (arr[j][i]==min&& (i + 1 )< *n)
				{
					if (arr[j][i]> arr[j][i+1])
					{
						min = arr[j][i];
						minIndex = j;
					}
				}
				else
				{
					min = arr[j][i];
					minIndex = j;
				}
			
				flag = true;
			
			}
		}
		if (!flag)
		{
			break;
		}
		for (int j = 0; j < *n; j++)
		{
				int swap = arr[i][j];
				arr[i][j] = arr[minIndex][j];
				arr[minIndex][j] = swap;
		}
		min2 = min;
		cout << endl;



	}

	return flag;
}