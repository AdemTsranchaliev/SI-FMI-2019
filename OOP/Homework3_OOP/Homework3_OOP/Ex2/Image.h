#pragma once
#include <iostream>
#include <string>
#include "File.h"

using namespace std;

class Image : public File
{
private:
	string nameOfDeviceTookImage;
	double width;
	double height;
public:
	Image();
	Image(const Image& image);
	Image(string nameOfDeviceTookImage,double width,double height, string fileName, Date date, double megaBytes, string extension);

	void setNameOfDeviceTookImage(string deviceName);
	string getNameOfDeviceTookImage() const;

	void setWidth(double width);
	double getWidth() const;
	
	void setHeight(double hight);
	double getHeight() const;
	void setImageExtension(string extension);
};

