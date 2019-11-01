
#include <iostream>
using namespace std;

int main()
{

	
	int counter = 0;
	int input = 0;
	cin >> input;
	int min = input;
	int max = input;
	int sum = 0;

	while (input!=-1)
	{
		if (input>max)
		{
			 max=input;
		}
		if (input<min)
		{
			 min=input;
		}
		sum += input;
		counter++;
		cin >> input;
	}
	cout << "Min: " << min<<endl;
	cout << "Max: " << max << endl;
	cout << "Avg: " << (double)((double)sum / (double)counter) << endl;
	return 0;
}

