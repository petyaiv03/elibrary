#pragma once
#include <iostream>
#include <fstream>
#include "Library.h"

/// function that opens and closes the file to write in it
void writeInFile(const Library& lib) 
{
	std::ofstream out;

	out.open("books.bin", std::ios::binary);
	if (out)
	{
		lib.serialize(out);
	}
	out.close();
}

///function that opens and closes the file to read from it
void readFromFile(Library& lib) 
{
	std::ifstream in;

	in.open("books.bin", std::ios::binary);
	if (in)
	{
		lib.deserialize(in);
	}
	in.close();
}