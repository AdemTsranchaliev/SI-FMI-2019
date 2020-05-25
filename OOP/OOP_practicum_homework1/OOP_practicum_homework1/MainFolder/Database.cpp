
#include "Database.h"


vector<string> Database::split(string text, char separator)
{
	vector<string> list;
	int  index = text.find(separator);

	while (index!=-1)
	{
		string temp = text.substr(0,index);
		(list).push_back(temp);
		text = text.substr(index + 1);
		index = text.find(separator);
	}
	if (text.length()>0)
	{
		(list).push_back(text);
	}

	return list;
}

string Database::ReadFromDb(string path)
{
	fstream file;

	file.open(path, ios::in);
	if (file.is_open())
	{
		string text = "";

		char c;

		while (file.get(c))
		{
			text += c;
		}

		return text;

	}

	return "";

}