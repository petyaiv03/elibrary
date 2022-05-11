#include <iostream>
#include <cstring>
#include "String.h"

String::String()
{
	string = new char[1];
	string[0] = '\0';
}

String::String(const char* other_string)
{
	if (other_string == nullptr)
	{
		string = new char[1];
		string[0] = '\0';
	}
	else {
		string = new char[strlen(other_string) + 1];
		strcpy(string, other_string);
		string[strlen(other_string)] = '\0';
	}
}

String::String(const String& other)
{
	copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		clear();
		this->copy(other);
	}
	return *this;
}

String::~String()
{
	clear();
}

size_t String::getSize() const
{
	return strlen(string);
}

String String::operator+(const String& other)
{
	add(other);
	return nullptr;
}

void String::add(const String& other)
{
	char* array_ = new char[strlen(string) + strlen(other.string) + 1];
	strcpy(array_, string);
	strcat(array_, other.string);
	clear();
	string = array_;
}

void String::print() const
{
	std::cout << string;
}

void String::copy(const String& other)
{
	string = new char[strlen(other.string) + 1];
	strcpy(other.string, string);
}

void String::clear()
{
	delete[] string;
}

std::istream& operator>>(std::istream& in, const String& other_string)
{
	in >> other_string.string;
	return in;
}

std::ostream& operator<<(std::ostream& out, const String& other_string)
{
	out << other_string.string;
	return out;
}