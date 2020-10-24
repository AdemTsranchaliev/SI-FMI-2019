#include <iostream>

using namespace std;

int main()
{
	int size;
	scanf_s("%d", &size);
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &(arr[i]));
	}
	int result = 0;
	for (int i = 0; i < size-1; i++)
	{
		if (arr[i]<arr[i+1])
		{
			result += (arr[i + 1] - arr[i]);
		}
	}
	cout << result;
	delete[] arr;

	return 0;

}