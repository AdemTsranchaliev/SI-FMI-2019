

#include <iostream>
using namespace std;

int main()
{   
	int forSearch =0;
	cin >> forSearch;
	int counter = 0;
	while (true)
	{
		if (counter==5)
		{
			cout << "You could not find the number! The number is "<<forSearch << endl;
			break;
		}
		counter++;
		int lookFor = 0;
		cin >> lookFor;
		if (lookFor==forSearch)
		{
			cout << "You found the number" << endl;
			break;
		}
		if (forSearch>lookFor)
		{
			cout << "The number is warger than "<<lookFor<<endl;
		}
		if (forSearch < lookFor)
		{
			cout << "The number is smaller than " << lookFor << endl;
		}


	}

	
	return 0;
}
