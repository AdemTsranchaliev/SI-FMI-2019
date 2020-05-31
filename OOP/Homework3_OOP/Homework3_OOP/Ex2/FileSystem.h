#pragma once
#include "Folder.h"
#include "File.h"
#include "Music.h"
#include "Image.h"

#include <vector>
class FileSystem
{
private:
	vector<Folder> folders;
public:
	void createNewFolder(string name);
	void addFileToFolder(string folderName, File* file);
	File& searchForFile(string searchInFolder);
};

