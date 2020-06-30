#include <iostream>
#include "ProtectedArray.h"
#include "ProtectedValue.h"

using namespace std;

int main()
{

	ProtectedArray<ProtectedValue<int>> in;


	ProtectedValue<int> gsdfs(123,123);

	in.add(gsdfs);
	ProtectedValue<int> asd= in.getAt(1, 123);

	string s = "asdas";
}