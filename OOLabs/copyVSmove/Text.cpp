// Workshop 2 Move Semantics
// Text.cpp
// 2018-05-31
// Author Louie Tse
// Student ID 027168103
// Professor Elliot Coleshill

#include "Text.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;
namespace sict {

	Text::Text()
	{
		filename = '\0';
		recSize = 0;
	}

	// 1parameter constructor to use fstream
	Text::Text(const string file) 
	{
		ifstream is(file);

		if (is.is_open()) {

			size_t count = 0;
			string line;

			while (is.good()) {
				getline(is, line, '\n');
				count++;
			}
			filename = new string[count];

			for (int i = 0; is.good(); i++) {
				getline(is, filename[i], '\n');
			}
			recSize = count;
			is.close();
		}
		else {
			exit(EXIT_FAILURE);
		}


	}
	//Copy Constructor
	Text::Text(const Text& src)
	{
		if (this != &src) {
			recSize = src.recSize;
			filename = new string[recSize];
			for (size_t i = 0; i < recSize; i++) {
				filename[i] = src.filename[i];
			}
		}
	}
	// Move Constructor
	Text::Text(Text && src) 
	{
		filename = nullptr;
		recSize = 0;
		if (this != &src) {
			*this = std::move(src);
	
		}
		
	}

	//Destructor
	Text::~Text()
	{
		delete[]filename;
	}
	//returns number of records
	size_t Text::size() const
	{
		return recSize;
	}
	// copy assignment operator
	Text & Text::operator=(const Text & src)
	{
		if (this != &src) {
			recSize = src.recSize;
			filename = new string[recSize];
			for (size_t i = 0; i < recSize; i++) {
				filename[i] = src.filename[i];
			}
			
		}
		return *this;
	}
	// move operator
	Text & Text::operator=(Text && src)
	{
		
		if (this != &src) {
			recSize = src.recSize;
			delete[]filename;
			filename = src.filename;
			src.filename = nullptr;
		}
		return *this;
	}

	
	

}
