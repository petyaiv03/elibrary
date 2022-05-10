#include "User.h"
#include <cstring>

User::User()
{
	username = nullptr;
}

User::User(const User& other)
	:User()
{
	copy(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		clear();
		this->copy(other);
	}
	return *this;
}

User::~User()
{
	clear();
}

void User::copy(const User& other)
{
	username = new char[strlen(other.username) + 1];
	strcpy(other.username, username);
}

void User::clear()
{
	delete[] username;
}

