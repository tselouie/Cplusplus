#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Grades.h"
#include "Letter.h"

using namespace std;

Grades::Grades(string filename)
{
	std::ifstream file(filename);

		if (file.fail()) {
			throw "unable to open file error"; // throw the error

		}			
		 if (file.is_open())
		{
			string line;
			while (file.good() && getline(file, line, '\n')) {
				count++;
			}

			file.seekg(0, file.beg);
			int counter = count;
			studentNumber = new string[counter];
			gradeValue = new double[counter];

			for (int i = 0; i < counter; i++) {
				file >> studentNumber[i];
				file >> gradeValue[i];
			}
		}
		file.close();
};





