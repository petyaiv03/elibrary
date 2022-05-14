#pragma once
#include "Book.h"

class Library {
private:
	Book* list;
	int size;
public:
	Library();
	Library(const Library& other);
	Library& operator=(const Library& other);
	~Library();
	void createBook();
	void removeBook(int index);
	int getIndex();
	void sortAuthorAtoZ();
	void sortAuthorZtoA();
	void sortTitleAtoZ();
	void sortTitleZtoA();
	void sortRatingLtoH();
	void sortRatingHtoL();

private:
	void copy(const Library& other);
	void clear();
	
 };