
#include "Database.h"


List<string>* Database::split(string text, char separator)
{
    List<string>* list=new List<string>();
	int  index = text.find(separator);

	while (index!=-1)
	{
		string temp = text.substr(0,index);
		(*list).add(temp);
		text = text.substr(index + 1);
		index = text.find(separator);
	}
	if (text.length()>0)
	{
		(*list).add(text);
	}

	return list;
}

