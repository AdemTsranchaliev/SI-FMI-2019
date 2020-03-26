#include <iostream>
#include "BrowserTab.hpp"

using namespace std;

BrowserTab::BrowserTab()
{
	this->url = new char[1];
	this->url[0] = '\0';

	this->html = new char[1];
	this->html[0] = '\0';
}
BrowserTab::BrowserTab(const BrowserTab& browseTab)
{
	this->url = browseTab.url;
	this->html = browseTab.html;

}
BrowserTab::BrowserTab(char* url, char* html)
{
	this->url = url;
	this->html = html;

}

void BrowserTab::setUrl(char* url)
{
	delete[] this->url;

	this->url = url;
}
char* BrowserTab::getUrl()
{
	return this->url;
}

void BrowserTab::setHtml(char* html)
{
	delete[] this->html;
	this->html = html;
}
char* BrowserTab::getHtml()
{
	return this->html;
}