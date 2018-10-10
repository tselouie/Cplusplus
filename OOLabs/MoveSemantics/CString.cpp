//Name: Louie Tse
//Stu#027168103
//Email:lttse@myseneca.ca
//Date:May 10,2018
//Professor: Elliot Coleshill
//SECTION: OOP345SAB


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CString.h"
using namespace std;

int STORED = w1::MAX;
namespace w1 {

	
	CString::CString(const char *s)
	{
		if (s != nullptr) {
			strncpy(str, s, MAX);
			str[MAX] = '\0';
		}
		else {
	
			str[0] = '\0';
			}
			
		}
		
	void CString::display(std::ostream & os) const
	{
		os << str;
	}

	std::ostream & operator<<(std::ostream &os, const CString &string)
	{
		int counter = 0;
		cout << counter << ": ";
		string.display(os);
		counter++;

		return os;
	}
}

	

	
	


