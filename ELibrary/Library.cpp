#include <iostream>
#include <cstring>
#include "Library.h"

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
		bool correctEntry = false;
		do {
		std::cin >> rating_;
		if (rating_ >= 0 && rating_ <= 10)
		{
			correctEntry = true;
		}
		else
		{
			std::cout << "You entered incorrect rating.Try again:\n";
			correctEntry = false;
		}
		} while (correctEntry != true);
		std::cout << "Input ISBN: ";
		std::cin >> ISBN_;
		Book book(author_, title_, file_name_, resume_, rating_, ISBN_);
		Book* array_ = new Book[size+1];
		for (int i = 0; i < size; i++)
		{
			array_[i] = list[i];
		}
		array_[size] = book;
		size++;
		delete[] list;
		list = array_;
	}

void Library::removeBook(int index)
{
	--size;
	for (int i = index; i < size; i++)
	{
		list[i] = list[i + 1];
	}
}

int Library::getIndex()
{
	int index = -1;
	String title_, author_, ISBN_;
	do {
		std::cout << "Enter title:";
		std::cin>>title_;
		std::cout << "Enter author:";
		std::cin >> author_;
		std::cout << "Enter ISBN";
		std::cin >> ISBN_;
		for (int i = 0; i < size; i++)
		{
			if (strcmp(title_.str(), list[i].getTitle().str()) == 0 && strcmp(author_.str(), list[i].getAuthor().str()) == 0 && strcmp(ISBN_.str(), list[i].getISBN().str())==0)
			{
				index = i;
			}
		}
	} while (index == -1);
	return index;
}

void Library::serialize(std::ofstream& out) const
{
	out.write((const char*)&size,sizeof(size));
	for (int i = 0; i < size; i++)
	{
		list[i].bookSerialize(out);
	}
}

void Library::deserialize(std::ifstream& in)
{
	clear();
	in.read((char*)&size, sizeof(size));
	if (size > 0)
	{
	list = new Book[size];
	}
	for (int i = 0; i < size; i++)
	{
		list[i] = Book(in);
	}
}

void Library::sortAuthorAtoZ()
{
	int min_index;
	
	for (int i = 0; i < size; i++)
	{
		min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(list[j].getAuthor().str(), list[min_index].getAuthor().str()) < 0)
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			Book temp;
			temp = list[i];
			list[i] = list[min_index];
			list[min_index] = temp;
		}
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << list[i] << std::endl;
	}
}

void Library::sortAuthorZtoA()
{
	int min_index;

	for (int i = 0; i < size; i++)
	{
		min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(list[j].getAuthor().str(), list[min_index].getAuthor().str()) > 0)
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			Book temp;
			temp = list[i];
			list[i] = list[min_index];
			list[min_index] = temp;
		}
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << list[i] << std::endl;
	}
}

void Library::sortTitleAtoZ()
{
	int min_index;

	for (int i = 0; i < size; i++)
	{
		min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(list[j].getTitle().str(), list[min_index].getTitle().str()) < 0)
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			Book temp;
			temp = list[i];
			list[i] = list[min_index];
			list[min_index] = temp;
		}
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << list[i] << std::endl;
	}
}

void Library::sortTitleZtoA()
{
	int min_index;

	for (int i = 0; i < size; i++)
	{
		min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(list[j].getTitle().str(), list[min_index].getTitle().str()) > 0)
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			Book temp;
			temp = list[i];
			list[i] = list[min_index];
			list[min_index] = temp;
		}
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << list[i] << std::endl;
	}
}

void Library::sortRatingLtoH()
{
	int min_index;

	for (int i = 0; i < size; i++)
	{
		min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (list[j].getRating() < list[min_index].getRating())
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			Book temp;
			temp = list[i];
			list[i] = list[min_index];
			list[min_index] = temp;
		}
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << list[i] << std::endl;
	}
}

void Library::sortRatingHtoL()
{
	int min_index;

	for (int i = 0; i < size; i++)
	{
		min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (list[j].getRating() > list[min_index].getRating())
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			Book temp;
			temp = list[i];
			list[i] = list[min_index];
			list[min_index] = temp;
		}
	}
	for (int i = 0; i < size; i++)
	{
		print(i);
	}
}

void Library::print(int index)
{
	std::cout << list[index] << std::endl;
}

void Library::findTitleBook()
{
	std::cout << "Enter title:";
	String string;
	std::cin >> string;
	bool bookExists = false;
	for (int i = 0; i < size; i++)
	{
		if (stricmp(list[i].getTitle().str(), string.str()) == 0)
		{
			print(i);
			bookExists = true;
		}
	}
	if (bookExists == false)
	{
		std::cout << "There isn't such book.";
	}
}

void Library::findAuthorBook()
{
	std::cout << "Enter author:";
	String string;
	std::cin >> string;
	bool bookExists = false;
	for (int i = 0; i < size; i++)
	{
		if (stricmp(list[i].getAuthor().str(), string.str()) == 0)
		{
			print(i);
			bookExists = true;
		}
	}
	if (bookExists == false)
	{
		std::cout << "There isn't such book.";
	}
}

void Library::findISBNBook()
{
	std::cout << "Enter ISBN:";
	String string;
	std::cin >> string;
	bool bookExists = false;
	for (int i = 0; i < size; i++)
	{
		if (stricmp(list[i].getISBN().str(), string.str()) == 0)
		{
			print(i);
			bookExists = true;
		}
	}
	if (bookExists == false)
	{
		std::cout << "There isn't such book.";
	}
}

//void Library::findDescrBook()
//{
//	std::cout << "Enter description:";
//	String description;
//	std::cin >> description;
//	bool bookExists = false;
//	//minimize characters of getResume()
//	for (int i = 0; i < size; i++)
//	{
//		if (strstr(list[i].getResume().str(), description.str()) != '\0')
//		{
//			print(i);
//			bookExists = true;
//		}
//	}
//	if (bookExists == false)
//	{
//		std::cout << "There isn't such book.";
//	}
//}

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
