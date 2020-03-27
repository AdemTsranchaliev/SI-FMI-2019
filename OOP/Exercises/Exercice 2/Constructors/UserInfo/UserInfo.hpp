#pragma once
class UserInfo
{
private:

	char* username;
	char* password;

public:

	UserInfo();
	UserInfo(const UserInfo& user);
	UserInfo(char* username);
	UserInfo(char* username,char* password);
	~UserInfo()=default;

	void setUsername(char* username);
	char* getUsername() const;

	void setPassword(char* password);
	char* getPassword() const;


};

