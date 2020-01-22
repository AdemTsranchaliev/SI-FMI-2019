#include <iostream>
using namespace std;
int GetMaxNum(int[],int);
int main()
{
	int arr[100];
	int n=0;
	cout << "Insert how much digits you will enter(max 100):" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "arr["<<i+1<<"] = ";
		cin >> arr[i];
	}
	int maxNum = GetMaxNum(arr,n);

	cout << maxNum << endl;

	system("pause");
	return 0;

}

int GetMaxNum(int arr[],int n)
{
	int maxNum = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		if (arr[i]>maxNum)
		{
			maxNum = arr[i];
		}
	}

	return maxNum;
}