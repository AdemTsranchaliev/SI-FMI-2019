#include <iostream>
#include <string>
using namespace std;



bool IsUnique(unsigned long long int num);
int main()
{
	unsigned long long int n=0, m=0;

	scanf("%lld",&n);
	scanf("%lld", &m);

	int counter = 0;
	for (unsigned long long int i = n; i <= m; i++)
	{
		if (IsUnique(i))
		{
			counter++;
		}
	}
	printf("%lld", m - counter);
	return 0;

}

bool IsUnique(unsigned long long int num)
{

	if (9999999999<num)
	{
		return true;
	}
	else
	{
		while (true)
		{

		}
	}
	return false;
}
