#include <cstring>
#include "Book.h"

Book::Book()
{
	author = nullptr;
	title = nullptr;
	file_name = nullptr;
	resume = nullptr;
	rating = 0;
	ISBN = nullptr;
}

Book::Book(String _author, String _title, String _file_name, String _resume, double _rating, String _ISBN)
{
	author = _author;
	title = _title;
	file_name = _file_name;
	resume = _resume;
	rating = _rating;
	ISBN = _ISBN;
}

void Book::bookSerialize(std::ofstream& out) const
{
	int length_author = author.getSize() + 1;
	out.write((const char*)&length_author, sizeof(length_author));
	out.write(author.str(), length_author);

	int length_title = title.getSize() + 1;
	out.write((const char*)&length_title, sizeof(length_title));
	out.write(title.str(), length_title);

	int length_file_name = file_name.getSize() + 1;
	out.write((const char*)&length_file_name, sizeof(length_file_name));
	out.write(file_name.str(), length_file_name);

	int length_resume = resume.getSize() + 1;
	out.write((const char*)&length_resume, sizeof(length_resume));
	out.write(resume.str(), length_resume);

	out.write((const char*)&rating, sizeof(rating));

	int length_ISBN = ISBN.getSize() + 1;
	out.write((const char*)&length_ISBN, sizeof(length_ISBN));
	out.write(ISBN.str(), length_ISBN);
}

String Book::getAuthor() const
{
	return author;
}

String Book::getTitle() const
{
	return title;
}

String Book::getFileName() const
{
	return file_name;
}

String Book::getResume() const
{
	return resume;
}

double Book::getRating() const
{
	return rating;
}

String Book::getISBN() const
{
	return ISBN;
}



std::istream& operator>>(std::istream& in,  Book& book)
{
	in >> book.author;
	in >> book.title;
	in >> book.file_name;
	in >> book.resume; //TODO:
	char ratingChar;
	in >> ratingChar;
	//other.rating = (double) ratingChar;
	return in;

}

std::ostream& operator<<(std::ostream& out, const Book& book)
{
	out << "Author: ";
	out << book.author;
	out << " ";
	out << "Title: ";
	out << book.title;
	out << " ";
	out << "File name: ";
	out << book.file_name;
	out << " ";
	out << "Resume: ";
	out << book.resume;
	out << " ";
	out << "Rating: ";
	out << book.rating;
	out << " ";
	out << "ISBN: ";
	out << book.ISBN;
	out << " ";
	return out;
}


