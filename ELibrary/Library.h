#pragma once
#include "Book.h"
class Library {
private:
	//masiv ot knigi?
	Book* list;

public:
	//b4
	Library();
	Library(const Library& other);
	Library& operator=(const Library& other);
	~Library();
 };