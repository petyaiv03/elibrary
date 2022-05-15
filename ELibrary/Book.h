#pragma once
#include <cstring>
#include <iostream>
#include <fstream>
#include "String.h"

/// class used to create object Book with the included members - author, title, file name, resume, rating and ISBN, all of them string except rating|includes the big 4|includes methods
class Book
{
private:
	String author;
	String title;
	String file_name;
	String resume;
	double rating;
	String ISBN;

public:
	/// default constructor
	Book();
	/// constructor used to set the object members
	Book(String _author, String _title, String _file_name, String _resume, double _rating, String _ISBN);
	/// constructor used to read from binary file
	Book(std::ifstream& in);
	/// method that is used to write in binary file
	void bookSerialize(std::ofstream& out) const;
	/// method that returns the value of class member: author
	String getAuthor() const; 
	/// method that returns the value of class member: title
	String getTitle() const; 
	/// method that returns the value of class member: file name
	String getFileName() const; 
	/// method that returns the value of class member: resume
	String getResume() const; 
	/// method that returns the value of class member: rating
	double getRating() const; 
	/// method that returns the value of class member: ISBN
	String getISBN() const; 
	/// friend(can access all private and protected members of the class) function overload for operator >>
	friend std::istream& operator >> (std::istream& in, Book& book);
	/// friend(can access all private and protected members of the class) function overload for operator <<
	friend std::ostream& operator << (std::ostream& out, const Book& book);

}; 
