#include "Library.h"
#include <cstring>
#include <iostream>

Library::Library()
{
	list = nullptr;
	size = 0;
}

Library::Library(const Library& other)
{
	copy(other);
}

Library& Library::operator=(const Library& other)
{
	if (this != &other)
	{
		clear();
		this->copy(other);
	}
	return *this;
}

Library::~Library()
{
	clear();
}

void Library::createBook()
{
	String author_;
	String title_;
	String file_name_;
	String resume_;
	double rating_;
	String ISBN_;

	//Book book;
	std::cout << "Input author: ";
	std::cin >> author_;
	std::cout << "Input title: ";
	std::cin >> title_;
	std::cout << "Input file name: ";
	std::cin >> file_name_;
	std::cout << "Input resume: ";
	std::cin >> resume_;
	std::cout << "Input rating: ";
	std::cin >> rating_;
	std::cout << "Input ISBN: ";
	std::cin >> ISBN_;
	Book book(author_, title_, file_name_, resume_, rating_, ISBN_);
	list[size] = book;
	size++;
}

void Library::copy(const Library& other)
{
	size = other.size;
	list = new Book[other.size];
	for (int i = 0; i < size; ++i)
	{
		list[i] = other.list[i];
	}
}

void Library::clear()
{
	delete[] list;
}
