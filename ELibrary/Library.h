#pragma once
#include "Book.h"
#include  "String.h"

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
	void serialize(std::ofstream& out) const;
	void deserialize(std::ifstream& in);

	//this shit ugly i know
	void sortAuthorAtoZ();
	void sortAuthorZtoA();
	void sortTitleAtoZ();
	void sortTitleZtoA();
	void sortRatingLtoH();
	void sortRatingHtoL();
	void print(int index);
	void findTitleBook();
	void findAuthorBook();
	void findISBNBook();
	void findDescrBook();
private:
	void copy(const Library& other);
	void clear();
	
 };