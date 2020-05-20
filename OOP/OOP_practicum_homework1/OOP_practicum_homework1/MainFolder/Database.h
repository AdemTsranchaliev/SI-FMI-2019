#pragma once

#include <iostream>
#include <fstream>
#include <string>


#include "Phone.hpp"

using namespace std;

class Database
{
public:

	Database();

	void SaveToDatabase(Phone& obj);

};

