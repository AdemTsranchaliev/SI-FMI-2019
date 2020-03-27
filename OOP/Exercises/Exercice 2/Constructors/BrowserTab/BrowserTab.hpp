#pragma once
class BrowserTab
{
private:
	char* url;
	char* html;
public:
	BrowserTab();
	BrowserTab(const BrowserTab& browseTab);
	BrowserTab(char* url,char* html);

	void setUrl(char* url);
	char* getUrl();

	void setHtml(char* html);
	char* getHtml();
};

