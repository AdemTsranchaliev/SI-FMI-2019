#pragma once
#include <iostream>

using namespace std;

void CopyCharArr( char* destination, const char* strToCopy,int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		destination[i] = strToCopy[i];		
	}
}