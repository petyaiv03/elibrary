#pragma once
#include <iostream>
#include <cstring>

class String {
private:
	char* string;

public:
	String();
	String(const char* other_string);
	String(const String& other);
	String& operator=(const String& other);
	~String();
	size_t getSize() const;
	String operator+(const String& other); 

	void add(const String& other);
	void print() const;

	friend std::istream& operator >> (std::istream& in, const String& other_string);
	friend std::ostream& operator << (std::ostream& out, const String& other_string);

private:
	void copy(const String& other);
	void clear();
};


