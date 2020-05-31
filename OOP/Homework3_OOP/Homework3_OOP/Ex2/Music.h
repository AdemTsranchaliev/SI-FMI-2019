#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "File.h"


using namespace std;

class Music : public File
{
private:
	string singerName;
	string songName;
	int year;
public:
	Music();
	Music(string singerName,string songName,int year, Date date, double megaBytes, string extension);
	Music(const Music& music);

	void setSingerName(string songName);
	string getSingerName() const;

	void setSongName(string songName);
	string getSongName() const;

	void setYear(int year);
	int getYear() const;

	void setMusicExtension(string extension);
};