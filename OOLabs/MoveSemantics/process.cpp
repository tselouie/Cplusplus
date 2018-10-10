//Name: Louie Tse
//Stu#027168103
//Email:lttse@myseneca.ca
//Date:May 10,2018
//Professor: Elliot Coleshill
//SECTION: OOP345SAB

#include "process.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace w1 {

	void process(const char * str)
	{	
		char tempstr[3+1];
		strncpy(tempstr,str,3);
		tempstr[3] = '\0';
		cout << tempstr << endl;
	}

}