#pragma once
#include <iostream>
#include <cstring>
#include "Library.h"

void Commands()
{
	char entry[4];
	char adminPassword[] = "apache helicopter", password[20];
	bool correctEntry = false;
	std::cout << "Welcome to the online library!\n\nTo log in as an admin type 1, \nto continue as a normal user type 2:\n";

	do {
		std::cin >> entry;
		if (strcmp(entry, "1") == 0)
		{
			correctEntry = true;
		}
		else if (strcmp(entry, "2") == 0)
		{
			correctEntry = true;
		}
		else
		{
			correctEntry = false;
			std::cout << "Wrong entry, try again!\n";
		}
	} while (correctEntry != true);

	if (strcmp(entry, "1") == 0)
	{
		std::cout << "Please enter password to verify : \n";
		std::cin.ignore(10000, '\n');
		do {
			std::cin.getline(password, 18);
			if (strcmp(password, adminPassword) == 0)
			{
				correctEntry = true;
			}
			else
			{
				correctEntry = false;
				std::cout << "Wrong password, try again!\n";
			}
		} while (correctEntry != true);
		if (correctEntry == true)
		{
			std::cout << "Welcome Admin! Please, choose one of the options below and type its number:\n1.Sort\n2.Find a book\n3.Add a book\n4.Remove a book\n5.Show text of a book\n";
			Library lib;
			do {
				std::cin >> entry;
				if (strcmp(entry, "1") == 0)
				{
					std::cout << "Choose a way to sort the list of books:\n";
					std::cout << "1. Author\n 2. Title\n 3.Rating\n";
					lib.sortAuthorAtoZ();
					correctEntry = true;
				}
				else if (strcmp(entry, "2") == 0)
				{
					std::cout << "Find a book option will be available in the next patch, releasing in September ";
					correctEntry = true;
				}
				else if (strcmp(entry, "3") == 0)
				{
					lib.createBook();
					correctEntry = true;
				}
				else if (strcmp(entry, "4") == 0)
				{
					lib.removeBook(lib.getIndex());
					correctEntry = true;
				}
				else if (strcmp(entry, "5") == 0)
				{
					std::cout << "Show a text option will be available in the next patch, releasing in September ";
					correctEntry = true;
				}
				else
				{
					correctEntry = false;
					std::cout << "There isn't such option. Please choose from the following:\n1.Sort\n2.Add a book\n3.Add a book\n4.Remove a book\n5.Show text of a book\n";
				}
			} while (true);//TODO: napravi tup exit meow

		}
	}
	else {
		std::cout << "Welcome User! These are your options:\n(Please type the number of the option you need below)\n1.Sort\n2.Find a book\n3.Show text of a book\n";
	}
}