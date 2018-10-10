// Workshop 5 - Lambda Expression
// w5.cpp
// Chris Szalwinski
// 2018-05-23

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;
using namespace std;

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr <<
			"\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	try {
		Grades grades(argv[1]);
	
		// lambda expression for converting to letter 

		auto gradeLetter = [](double grade) -> std::string {

			Letter newGrade;

			if (grade >= 90)
				newGrade = Letter::Ap;

			else if (grade >= 80)
				newGrade = Letter::A;

			else if (grade >= 75)
				newGrade = Letter::Bp;

			else if (grade >= 70)
				newGrade = Letter::B;

			else if (grade >= 65)
				newGrade = Letter::Cp;

			else if (grade >= 60)
				newGrade = Letter::C;

			else if (grade >= 55)
				newGrade = Letter::Dp;

			else if (grade >= 50)
				newGrade = Letter::D;

			else if (grade < 50)
				newGrade = Letter::F;

			return convertLetter(newGrade);

		};

		grades.displayGrades(std::cout, gradeLetter);

		// report the error message
	}
	catch (const char *err){
		std::cerr << argv[0] << ": Failed to open file "
			<< argv[1] << "\n";
		return 2;
	}
	

};