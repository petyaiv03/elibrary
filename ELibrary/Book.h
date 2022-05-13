#include <cstring>
#include <iostream>
#include <fstream>
#include "string.h"

class Book
{
private:
	String author;
	String title;
	String file_name;
	String resume;
	double rating;
	String ISBN;
	/*
	The ISBN is ten digits long if assigned before 2007,
	and thirteen digits long if assigned on or after 1 January 2007.

	Example:
	978-3-16-148410-0
	*/

public:
	Book();
	Book(String _author, String _title, String _file_name, String _resume, double _rating, String _ISBN);
	void bookSerialize(std::ofstream& out) const;

	friend std::istream& operator >> (std::istream& in, const Book& other);
	friend std::ostream& operator << (std::ostream& out, const Book& other);

}; 
