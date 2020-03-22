#pragma once
class Login
{
private:
	char* username;
	char* password;
	int sessionType;
public:
	Login();
	Login(char* username);
	Login(char* username,char* password);
	Login(char* username, char* password,int sessionType);
	Login(const Login& info);

	void setUsername(char* username);
	char* getUsername() const;

	void setPassword(char* password);
	char* getPassword() const;

	void setSessionType(int sessionType);
	int getSessionType() const;
};

