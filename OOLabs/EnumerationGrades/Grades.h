#pragma once
#ifndef GRADES_H
#define GRADES_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

	class Grades {
	public:
		//data members
		std::string *studentNumber;
		double *gradeValue;
		int count = 0;
		Grades(string filename); //constructor

		//prohibit move/copy and assigning of a grades object
		Grades(Grades&&) = delete;
		Grades&& operator=(Grades&&) = delete;
		Grades(Grades&) = delete;
		Grades& operator=(Grades&) = delete;

		template<typename lambda>
		void displayGrades(std::ostream& os, lambda F) const {
			for (int i = 0; i < count; i++) {
				os << studentNumber[i] << " " << gradeValue[i] << " " << F(gradeValue[i]) << std::endl;
			}
		}
	};


#endif