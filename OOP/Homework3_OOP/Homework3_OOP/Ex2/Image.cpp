#include "Image.h"


Image::Image() :File()
{
	this->nameOfDeviceTookImage = "";
	this->width=0;
	this->height=0;
}
Image::Image(const Image& image) : File(image)
{
	this->nameOfDeviceTookImage = image.nameOfDeviceTookImage;
	this->width = image.width;
	this->height = image.height;
}
Image::Image(string nameOfDeviceTookImage, double width, double height, string fileName, Date date, double megaBytes, string extension) : File(fileName, megaBytes)
{
	this->nameOfDeviceTookImage = nameOfDeviceTookImage;
	this->width = width;
	this->height = height;
	this->setImageExtension(extension);

}

void Image::setNameOfDeviceTookImage(string deviceName)
{
	this->nameOfDeviceTookImage = deviceName;
}
string Image::getNameOfDeviceTookImage() const
{
	return this->nameOfDeviceTookImage;
}

void Image::setWidth(double width)
{
	this->width = width;
}
double Image::getWidth() const
{
	return this->width;
}

void Image::setHeight(double hight)
{
	this->height = height;
}
double Image::getHeight() const
{
	return this->height;
}

void Image::setImageExtension(string extension)
{
	if (extension == ".jpg" || extension == ".png")
	{
		this->setExtension(extension);
	}
	else
	{
		cout << "Invalid extension. Allowed extensions are '.jpg'or '.png'. Extention was set to '.jpg' by default! If you want you can change it.";
		this->setExtension(".jpg");

	}
}
