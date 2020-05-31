#include "Music.h"


Music::Music():File()
{
	this->singerName = "";
	this->songName = "";
	this->year = 0;
}
Music::Music(string singerName, string songName, int year, Date date, double megaBytes, string extension):File(singerName+" - "+songName,megaBytes)
{
	this->singerName = singerName;
	this->songName = songName;
	this->year = year;
	this->setMusicExtension(extension);
	

}
Music::Music(const Music& music):File(music)
{
	this->singerName = music.singerName;
	this->songName = music.songName;
	this->year = music.year;
}

void Music::setSingerName(string songName)
{
	this->singerName = singerName;
}
string Music::getSingerName() const
{
	return this->singerName;
}

void Music::setSongName(string songName)
{
	this->songName = songName;
}
string Music::getSongName() const
{
	return this->songName;
}

void Music::setYear(int year)
{
	this->year = year;

}
int Music::getYear() const
{
	return this->year;
}

void Music::setMusicExtension(string extension)
{
	if (extension == ".mp3" || extension == ".flac")
	{
		this->setExtension(extension);
	}
	else
	{
		cout << "Invalid extension. Allowed extensions are '.flac'or '.mp3'. Extention was set to '.mp3' by default! If you want you can change it.";
		this->setExtension(".mp3");

	}
}
