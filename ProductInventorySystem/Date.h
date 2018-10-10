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
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

using namespace std;

namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;
	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int YEAR_ERROR = 2;
	const int MON_ERROR = 3;
	const int DAY_ERROR = 4;


  class Date {
	  int myear;
	  int mmonth;
	  int mday;
	  int compareV;
     int mdays(int, int)const;
	 int errState;
	
 
  public:
	  void errCode(int);
	  int errCode() const;
	  void setEmpty();
	  Date();
	  Date(int year, int month, int day);
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;
	  bool bad() const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;
 
  };
  std::ostream& operator << (std::ostream& ostr, const Date& );
  std::istream& operator >> (std::istream& istr, Date& );
 
  

}
#endif