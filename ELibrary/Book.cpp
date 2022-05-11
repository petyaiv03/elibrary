#include "Book.h"
#include <cstring>

Book::Book()
{
	author = nullptr;
	title = nullptr;
	file_name = nullptr;
	resume = nullptr;
	rating = 0;
	ISBN[0] = '\0';
}

Book::Book(const Book& other)
	:Book()//prosto inicializira promenlivite ;D 
{
	copy(other);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		clear();
		this->copy(other);
	}
	return *this;
}

Book::~Book()
{
	clear();
}

void Book::copy(const Book& other)
{
	author = new char[strlen(other.author) + 1];
	strcpy(author, other.author);

	title = new char[strlen(other.title) + 1];
	strcpy(title, other.title);

	file_name = new char[strlen(other.file_name) + 1];
	strcpy(file_name, other.file_name);

	resume = new char[strlen(other.resume) + 1];
	strcpy(resume, other.resume);

	rating = other.rating;

	strcpy(ISBN, other.ISBN);
}

void Book::clear()
{
	delete[] author;
	delete[] title;
	delete[] file_name;
	delete[] resume;
}

std::istream& operator>>(std::istream& in, const Book& other)
{
	in >> other.author;
	in >> other.title;
	in >> other.file_name;
	in >> other.resume;
	char ratingChar;
	in >> ratingChar;
	//other.rating = (double) ratingChar;
	return in;

}

std::ostream& operator<<(std::ostream& out, const Book& other)
{
	out << "Author: ";
	out << other.author;
	out << " ";
	out << "Title: ";
	out << other.title;
	out << " ";
	out << "File name: ";
	out << other.file_name;
	out << " ";
	out << "Resume: ";
	out << other.resume;
	out << " ";
	out << "Rating: ";
	out << other.rating;
	out << " ";
	out << "ISBN: ";
	out << other.ISBN;
	out << " ";
}


