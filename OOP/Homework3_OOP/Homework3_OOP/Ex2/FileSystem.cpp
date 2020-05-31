#include "FileSystem.h"


void FileSystem::createNewFolder(string name)
{
	bool isFileExist=false;
	for (int i = 0; i < this->folders.size(); i++)
	{
		if (this->folders[i].getName()==name)
		{
			isFileExist = true;
			break;
		}
	}
	if (!isFileExist)
	{
		Folder newFolder(name);
		this->folders.push_back(newFolder);
		cout << "The folder was succesfully created."<<endl;
	}
	else
	{
		cout << "There is other folder with the same name. File creation filed" << endl;
	}
}
void FileSystem::addFileToFolder(string folderName,File* file)
{
	bool isFolderExist = false;
	for (int i = 0; i < this->folders.size(); i++)
	{
		if (this->folders[i].getName() == folderName)
		{
			isFolderExist = true;
			bool isFileExist = false;

			for (int j = 0; j < this->folders[i].getFiles().size(); j++)
			{
				if (this->folders[i].getFiles()[i]->getName()==file->getName())
				{
					isFileExist = true;
				}
			}

			if (!isFileExist)
			{
				this->folders[i].addFile(*file);
				cout << "The file was successfully added to "<<folderName<<" folder"<<endl;
			}
			else
			{
				cout << "The file wasn't added to " << folderName << " folder, because there is file with the same name" << endl;
			}
			isFileExist = true;
		}
	}
	if (!isFolderExist)
	{
		cout << "The file wasn't added to " << folderName << " folder, because there is no folder with the that name" << endl;

	}
}
File& FileSystem::searchForFile(string searchFile)
{
	for (int i = 0; i < this->folders.size(); i++)
	{
		for (int j = 0; j < this->folders[i].getFiles().size(); j++)
		{
			if (this->folders[i].getFiles()[j]->getName()==searchFile)
			{
				return *(this->folders[i].getFiles()[j]);
			}
		}
	}
}