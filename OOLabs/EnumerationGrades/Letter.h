#pragma once
#ifndef _LETTER_H_
#define _LETTER_H_

#include <string>
#include <cstring>
#include "Grades.h"
using namespace std;

namespace sict {
	enum class Letter { Ap, A, Bp, B, Cp, C, Dp, D, F };

	template<typename T>
	//convert into C-style string
	 std::string convertLetter(T& letter) {
		 std::string str;
		 switch (letter) {
		 case Letter::Ap:
			 str = "A+";
			 break;
		 case Letter::A:
			 str = "A";
			 break;
		 case Letter::Bp:
			 str = "B+";
			 break;
		 case Letter::B:
			 str = "B";
			 break;
		 case Letter::Cp:
			 str = "C+";
			 break;
		 case Letter::C:
			 str = "C";
			 break;
		 case Letter::Dp:
			 str = "D+";
			 break;
		 case Letter::D:
			 str = "D";
			 break;
		 case Letter::F:
			 str = "F";
			 break;
		 }
		 return str;
	}
	
			

}	
#endif