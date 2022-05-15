#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

///a class with char array member including big 4 and methods
class String {
private:
	char* data;

public:
	///default constructor
	String();
	String(const char* other_string);
	///copy constructor
	String(const String& other);
	///operator = overload
	String& operator=(const String& other);
	///destructor
	~String();
	///method that returns the size of the array
	size_t getSize() const;
	///operator + overload
	String operator+(const String& other) const; 
	///method used to append the string
	void add(const String& other); 
	///prints out string
	void print() const;
	///converts to const char*
	const char* str() const;
	///reads from binary file
	void deserialize(std::ifstream& in);
	///input operator
	friend std::istream& operator >> (std::istream& in, String& string);
	///output operator
	friend std::ostream& operator << (std::ostream& out, const String& string);

private:
	void copy(const String& other);
	void clear();
};


