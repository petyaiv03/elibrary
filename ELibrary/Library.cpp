#include "Library.h"
#include <cstring>
Library::Library()
{
	list = nullptr;
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
