#pragma once
#include "Book.h"
#include  "String.h"

/// class that includes array of books and size of the array|the big 4|methods
class Library {
private:
	Book* list;
	int size;
public:
	Library();
	Library(const Library& other);
	Library& operator=(const Library& other);
	~Library();
	/// creates and adds a book to the array
	void createBook();
	/// removes a book from the array
	void removeBook(int index);
	///gets the array index of a particular book
	int getIndex();
	///writes in the binary file
	void serialize(std::ofstream& out) const;
	///reads from the binary file
	void deserialize(std::ifstream& in);
	///sorts the books using the author from A to Z
	void sortAuthorAtoZ();
	///sorts the books using the author from Z to A
	void sortAuthorZtoA();
	///sorts the books using the title from A to Z
	void sortTitleAtoZ();
	///sorts the books using the title from Z to A
	void sortTitleZtoA();
	///sorts the books using the rating from low to high
	void sortRatingLtoH();
	///sorts the books using the rating from high to low
	void sortRatingHtoL();
	///prints out the book with the particular index
	void print(int index);
	///searches for a book using the title and prints it
	void findTitleBook();
	///searches for a book using the author and prints it
	void findAuthorBook();
	///searches for a book using the ISBN and prints it
	void findISBNBook();
	///TODO: is supposed to search for the book, checking if the given description matches the resume
	void findDescrBook();
private:
	///method used in the copy constructor and operator= in the big 4
	void copy(const Library& other);
	///method used in the destructor and operator=
	void clear();
	
 };