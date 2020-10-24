#include <iostream>

using namespace std;

int main()
{
	long size;
	scanf_s("%lld", &size);
	long long* arr = new  long long[size];
	int d = 1000000007;
 for (long i = 0; i < size; i++)
	{
		scanf_s("%lld", &(arr[i]));
	}
	for (long i = 0; i < size; i++)
	{
		unsigned long long res = 1;
		for (long j = 0; j < i; j++)
		{
			res *= arr[j];
		}
		for (long p = i + 1; p < size-1; p++)
		{
			res *= arr[p];

		}
		if (res < d)
		{
			printf("%lld ", res);
		}
		else
		{
			printf("%lld ", res % d);

		}
	}

	delete[] arr;

	return 0;

}

