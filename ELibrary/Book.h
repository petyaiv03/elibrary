#include <cstring>
//sucker u gotta code that ^

class Book
{
private:
	char* author;
	char* title;
	char* file_name;
	char* resume;
	double rating;
	char ISBN[28];
	/*
	The ISBN is ten digits long if assigned before 2007,
	and thirteen digits long if assigned on or after 1 January 2007.

	Example:
	978-3-16-148410-0
	*/

public:
	Book();
	Book(const Book& other);
	Book& operator = (const Book& other);
	~Book();

private:

	void copy(const Book& other);
	void clear();


}; 
