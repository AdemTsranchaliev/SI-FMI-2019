#include <iostream>

using namespace std;
int ConvertSecondsToHourAndMinutes(int);
int main(int)
{
	int seconds = 0;

	cin >> seconds;
	ConvertSecondsToHourAndMinutes(seconds);

	system("pause");
	return 0;
}

int ConvertSecondsToHourAndMinutes(int seconds)
{

	cout << seconds / 3600<<":"<< seconds / 60 % 60;

	return 0;
}