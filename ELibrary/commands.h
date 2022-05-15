#pragma once
#include <iostream>
#include <cstring>
#include "Library.h"
#include "fileHelper.h"

void Commands()
{
	char entry[4];
	char adminPassword[] = "apache helicopter", password[20];
	bool correctEntry = false;
	bool exit = false;

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
			Library lib;
			readFromFile(lib);
			do {
				std::cout << "\nPlease, choose one of the options below and type its number:\n1.Sort\n2.Find a book\n3.Add a book\n4.Remove a book\n5.Show text of a book\n6.Exit\n";
				std::cin >> entry;
				if (strcmp(entry, "1") == 0)
				{
					std::cout << "Choose a way to sort the list of books:\n";
					int sortEntry;
					bool sortEntryCorrect = false;
					do {
					std::cout << "1.Author A->Z\n2.Author Z->A\n3.Title A->Z\n4.Title Z->A\n5.Rating Highest to Lowest\n6.Rating Lowest to Highest\n";
					std::cin >> sortEntry;
						switch (sortEntry)
						{
						case 1: lib.sortAuthorAtoZ();
							sortEntryCorrect = true;
							break;
						case 2: lib.sortAuthorZtoA();
							sortEntryCorrect = true;
							break;
						case 3: lib.sortTitleAtoZ();
							sortEntryCorrect = true;
							break;
						case 4:lib.sortTitleZtoA();
							sortEntryCorrect = true;
							break;
						case 5:lib.sortRatingHtoL();
							sortEntryCorrect = true;
							break;
						case 6:lib.sortRatingLtoH();
							sortEntryCorrect = true;
							break;
						default: std::cout << "Your entry was incorrect!";
							sortEntryCorrect = false;
						}
					} while (sortEntryCorrect = false);
					
					correctEntry = true;
				}
				else if (strcmp(entry, "2") == 0)
				{
					std::cout << "Choose a way to find the book you are looking for:\n";
					int entryFind;
					int entryFindCorrect = false;
					std::cout << "1.Title\n2.Author\n3.ISBN\n4.Description";
					do {
						std::cin >> entryFind;
						switch (entryFind)
						{
						case 1: lib.findTitleBook();
							entryFindCorrect = true; break;
						case 2: lib.findAuthorBook();
							entryFindCorrect = true; break;
						case 3: lib.findISBNBook();
							entryFindCorrect = true; break;
						case 4:// lib.findDescrBook();
							entryFindCorrect = true; break;
						default:std::cout << "Your entry was incorrect!";
							entryFindCorrect = false;
						}
					} while (entryFindCorrect == false);
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
				else if (strcmp(entry, "6") == 0)
				{
					exit = true;
				}
				else
				{
					correctEntry = false;
					std::cout << "There isn't such option. Please choose one of the ones on the top";
				}
			} while (exit == false);
			writeInFile(lib);
		}
	}
	else {
	Library lib;
	readFromFile(lib);
	do {
		std::cout << "\nPlease, choose one of the options below and type its number:\n1.Sort\n2.Find a book\n3.Show text of a book\n4.Exit\n";
		std::cin >> entry;
		if (strcmp(entry, "1") == 0)
		{
			std::cout << "Choose a way to sort the list of books:\n";
			int sortEntry;
			bool sortEntryCorrect = false;
			do {
				std::cout << "1.Author A->Z\n2.Author Z->A\n3.Title A->Z\n4.Title Z->A\n5.Rating Highest to Lowest\n6.Rating Lowest to Highest\n";
				std::cin >> sortEntry;
				switch (sortEntry)
				{
				case 1: lib.sortAuthorAtoZ();
					sortEntryCorrect = true;
					break;
				case 2: lib.sortAuthorZtoA();
					sortEntryCorrect = true;
					break;
				case 3: lib.sortTitleAtoZ();
					sortEntryCorrect = true;
					break;
				case 4:lib.sortTitleZtoA();
					sortEntryCorrect = true;
					break;
				case 5:lib.sortRatingHtoL();
					sortEntryCorrect = true;
					break;
				case 6:lib.sortRatingLtoH();
					sortEntryCorrect = true;
					break;
				default: std::cout << "Your entry was incorrect!";
					sortEntryCorrect = false;
				}
			} while (sortEntryCorrect = false);

			correctEntry = true;
		}
		else if (strcmp(entry, "2") == 0)
		{
			std::cout << "Choose a way to find the book you are looking for:\n";
			int entryFind;
			int entryFindCorrect = false;
			std::cout << "1.Title\n2.Author\n3.ISBN\n4.Description";
			do {
				std::cin >> entryFind;
				switch (entryFind)
				{
				case 1: lib.findTitleBook();
					entryFindCorrect = true; break;
				case 2: lib.findAuthorBook();
					entryFindCorrect = true; break;
				case 3: lib.findISBNBook();
					entryFindCorrect = true; break;
				case 4:// lib.findDescrBook();
					entryFindCorrect = true; break;
				default:std::cout << "Your entry was incorrect!";
					entryFindCorrect = false;
				}
			} while (entryFindCorrect == false);
		}
		else if (strcmp(entry, "3") == 0)
		{
			std::cout << "Show a text option will be available in the next patch, releasing in September ";
			correctEntry = true;
		}
		else if (strcmp(entry, "4") == 0)
		{
			exit = true;
		}
		else
		{
			correctEntry = false;
			std::cout << "There isn't such option. Please choose one of the ones on the top";
		}
	} while (exit == false);
	writeInFile(lib);
	}
}