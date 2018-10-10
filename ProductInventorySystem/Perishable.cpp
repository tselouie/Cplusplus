#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>
#include <ios>
#include "Perishable.h"
#include "Product.h"
#include "Date.h"

using namespace std;

namespace AMA {

	//runs the Product constructor initializing with 'P'
	Perishable::Perishable() : Product('P') {}

	std::fstream & Perishable::store(std::fstream & file, bool newLine) const
	{

		bool flag = false;
		//runs Product's overloaded store function
		Product::store(file, flag);
		//adds a comma and expiry date to the stream object
		file << "," << expiryDate;

		if (newLine == true) {
			file << std::endl;
		}

		return file;
	}

	std::fstream & Perishable::load(std::fstream & file)
	{
		//temporary variables to load into the Date object
		int tempyr;
		int tempmonth;
		int tempday;

		//extracts data from the file object
		Product::load(file);
		file.ignore();

		//extract the remaining date from the file object to the Perishable object
		file >> tempyr;
		file.ignore();
		file >> tempmonth;
		file.ignore();
		file >> tempday;

		Date *temp;
		temp = new Date(tempyr, tempmonth, tempday);

		expiryDate = *temp;


		return file;
	}

	std::ostream & Perishable::write(std::ostream & os, bool linear) const
	{
		//prints out all the information regarding the Perishableobject
		Product::write(os, linear);

		if (prodError.isClear()) {

			if (linear) {
				os << expiryDate;
			}
			else {
				os << "\n Expiry date: " << expiryDate;
			}

		}
		else {
			return os;
		}
		return os;
	}

	std::istream & Perishable::read(std::istream & is)
	{//reads out the perishable data unless there is an error
		Product::read(is);

		if (!is.fail()) {
			cout << " Expiry date (YYYY/MM/DD): ";	
			expiryDate.read(is);
		//If the date is bad, an invalid error is asigned to ErrorState object and message is printed.
			if (expiryDate.bad()) {
				is.setstate(std::ios::failbit);
				switch (expiryDate.errCode()) {
				case CIN_FAILED:
					prodError.message("Invalid Date Entry");
					break;
				case YEAR_ERROR:
					prodError.message("Invalid Year in Date Entry");
					break;
				case MON_ERROR:
					prodError.message("Invalid Month in Date Entry");
					break;
				case DAY_ERROR:
					prodError.message("Invalid Day in Date Entry");
					break;
				}
			}
		}
		
			
		
		return is;
	}
	//returns expiry date
	const Date & Perishable::expiry()
	{
		return (expiryDate);
	}

}
		

	


	
	
