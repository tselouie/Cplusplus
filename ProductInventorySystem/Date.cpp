// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"
#include <iostream>
#include<stdio.h>
#include<iomanip>
#include<string>
#include <sstream>
using namespace std;

namespace AMA {
	//set to a safe empty state
	void Date::setEmpty() {
		myear = 0;
		mmonth = 0;
		mday = 0;
		compareV = 0;
		errState = NO_ERROR;
	}
	// number of days in month mon_ and year year_
  //
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode)
	{
		errState = errorCode;
	}

	int Date::errCode() const
	{
		return this->errState;
	}

	Date::Date()
	{
		Date::setEmpty();
	}

	Date::Date(int year, int month, int day)
	{
		myear = year;
		mmonth = month;
		mday = day;
		try {
			if (myear > max_year || myear < min_year) {
				throw YEAR_ERROR;
			}
			else if (mmonth < 1 || mmonth > 12) {
				throw MON_ERROR;
			}
			else if (mday < 1 || mday > mdays(month, year)) {
				throw DAY_ERROR;
			}
			else {
				compareV = year * 372 + month * 13 + day;
				throw NO_ERROR;
			}
		}
		catch (int e) {
			errCode(e);
			if (bad() == true) {
				setEmpty();
			}
		}
	}

	bool Date::operator==(const Date & rhs) const
	{
		return this->compareV == rhs.compareV;
	}

	bool Date::operator!=(const Date & rhs) const
	{
		return this->compareV != rhs.compareV;
	}

	bool Date::operator<(const Date & rhs) const
	{
		return this->compareV < rhs.compareV;
	}

	bool Date::operator>(const Date & rhs) const
	{
		return this->compareV > rhs.compareV;
	}

	bool Date::operator<=(const Date & rhs) const
	{
		return this->compareV <= rhs.compareV;
	}

	bool Date::operator>=(const Date & rhs) const
	{
		return this->compareV >= rhs.compareV;
	}
	bool Date::bad() const
	{
		return (errState != 0);
	}
	std::istream & Date::read(std::istream & istr)

	{

		istr >> myear; 
		cin.ignore();
		istr >> mmonth; 
		cin.ignore();
		istr >> mday;
		if (istr.fail())
			errCode(CIN_FAILED);
		else
		{
			if (myear >= min_year && myear <= max_year)
			{
				if (mmonth >= 1 && mmonth <= 12)
				{
					if (mday <= mdays(mmonth, myear) && mday >= 1)
					{
						errCode(NO_ERROR);
					}
					else
						errCode(DAY_ERROR);
				}
				else
					errCode(MON_ERROR);
			}
			else errCode(YEAR_ERROR);
		}
	if (errCode() != 0) {
			myear = 0;
			mmonth = 0;
			mday = 0;
		}
		return istr;

	}

	std::ostream & Date::write(std::ostream & ostr) const
	{
		ostr.fill('0');
		ostr.width(4);
		ostr << myear << "/";
		ostr.fill('0'); 
		ostr.width(2);  
		ostr << mmonth << "/";
		ostr.fill('0');
		ostr.width(2); 
		ostr << mday;
		ostr.fill(' ');

		return ostr;
	}

	std::istream & operator>>(std::istream & istr, Date & dateObj)
	{
		dateObj.read(istr);
		return istr;
	}
	std::ostream & operator<<(std::ostream & ostr, const Date & dateObj)
	{
		dateObj.write(ostr);
		return ostr;
	}
}