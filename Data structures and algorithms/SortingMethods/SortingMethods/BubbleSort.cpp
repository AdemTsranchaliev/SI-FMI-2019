#include <iostream>

using namespace std;


void BubleSort(int arr[],int n);

int main()
{
	int arr[7] = { 8,2,10,20,-1,4,4 };


	



}

void BubleSort(int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i;-1 j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void SelectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = 0;
		for (int j = i+1; j < n ; j++)
		{
			if (arr[i]>arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
