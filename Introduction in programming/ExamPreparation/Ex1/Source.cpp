#include <iostream>

using namespace std;

void Func(int[], int[],int,int);

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6,7,8,9 };
	int b[] = { 1, 2, 3, 4, 5, 6,7 };

	Func(a, b, 9, 7);

	system("pause");
	return 0;
}
void Func(int arr1[], int arr2[], int size1, int size2)
{
	int newArraySize = size1 + size2;

	int *newArr = new int[newArraySize];

	int arrIndex1 = 0;
	int arrIndex2 = 0;
	for (int i = 0; i < newArraySize; i++)
	{
		if (arr1[arrIndex1]>arr2[arrIndex2])
		{
			newArr[i] = arr2[arrIndex2];
			arrIndex2++;
		}
		else
		{
			newArr[i] = arr1[arrIndex1];
			arrIndex1++;
		}
	}

	
	for (int j = 0; j < newArraySize; j++)
	{
		cout << newArr[j]<<endl;
	}

}