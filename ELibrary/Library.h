#pragma once
#include "Book.h"

class Library {
private:
	//masiv ot knigi?
	Book* list;
	int size;
public:
	//b4
	Library();
	Library(const Library& other);
	Library& operator=(const Library& other);
	~Library();
	void createBook();

private:
	void copy(const Library& other);
	void clear();
	
 };