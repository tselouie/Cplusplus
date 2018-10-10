//Name: Louie Tse
//Stu#027168103
//Email:lttse@myseneca.ca
//Date:May 10,2018
//Professor: Elliot Coleshill
//SECTION: OOP345SAB

#pragma once
#ifndef CSTRING_H_
#define CSTRING_H_

using namespace std;
namespace w1 {
	const int MAX = 3;
	//int STORED = MAX;
	

	class CString {
		char str[MAX + 1];
	public:
		CString(const char*);
		void display(std::ostream &os) const;

	};

	std::ostream& operator<<(std::ostream&, const CString&);


}


#endif