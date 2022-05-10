#pragma once
class User {
private:
	char* username;
public:
	User();
	User(const User& other);
	User& operator = (const User& other);
	~User();
private:
	void copy(const User& other);
	void clear();
 };