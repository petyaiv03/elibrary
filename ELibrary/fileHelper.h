#pragma once
#include <iostream>
#include <fstream>
#include "Library.h"

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