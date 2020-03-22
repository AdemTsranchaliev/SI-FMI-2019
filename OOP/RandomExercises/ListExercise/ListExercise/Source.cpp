//ex.22

#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int counter = 0;

	if (n > 0 && n < 1000000) {

		while (n != 0)
		{

			counter = counter + n % 2;

			n = n / 2;

		}

	}
	cout << counter << endl;
	system("pause");
	return 0;
}