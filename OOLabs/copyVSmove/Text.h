#pragma once
#ifndef _TEXT_H_
#define _TEXT_H_
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace sict {

	class Text {
	private:
		string *filename;
		size_t recSize;
		
	public:
		Text();
		Text(const string );
		Text(const Text&); //Copy Constructor
		Text& operator=(const Text&); // copy assignment
		Text(Text&&); // move constructor
		Text& operator=(Text&&src); // move operator
		~Text(); //destructor
		size_t size() const; // returns number of records of text data


};
}
#endif