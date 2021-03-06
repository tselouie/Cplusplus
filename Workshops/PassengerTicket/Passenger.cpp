#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Passenger.h"

// TODO: continue your namespace here
using namespace std;

namespace sict {
	// TODO: implement the default constructor here

	Passenger::Passenger() {
		setEmpty();
	}


	void Passenger::setEmpty() {
		customer[0] = '\0';
		destination[0] = '\0';
		departYr = 0;
		departMonth = 0;
		departDay = 0;
		}

	   // TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char cname[], const char cdestination[]) {

		if (cname != NULL && cname[0] != '\0' &&
			cdestination != NULL  &&  cdestination[0] != '\0') {
		
			strncpy( customer, cname, SIZE );
			strncpy(destination, cdestination, SIZE);

		}       
		else {
			setEmpty();
		}
	}
	//constructor that takes 5 parameters
	Passenger::Passenger(const char cname[], const char cdestination[], int cyear, int cmonths, int cdays)
	{

		if (cname != NULL && cname[0] != '\0' &&
			cdestination != nullptr
			&&  cdestination[0] != '\0' && 
			2016 < cyear && cyear < 2021 && 0 < cmonths && cmonths < 13 && 0 < cdays && cdays < 32  ) {

			strncpy(customer, cname, SIZE);
			strncpy(destination, cdestination, SIZE);
			departYr = cyear;
			departMonth = cmonths;
			departDay = cdays;
		}
		else {
			setEmpty();
		}
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if (customer[0] == '\0' &&
		   destination[0] == '\0' &&
			departYr == 0 &&
			departMonth == 0 &&
			departDay == 0) {
			return true;
		}else{
			return false;
	}
}
	// TODO: implement display query here
	void Passenger::display() const {

			if (this->isEmpty()) {
				cout << "No passenger!" << endl;
			}
			else {
				cout << this->customer << " - " << this->destination << " on "<<
					this->departYr << "/" << std::setw(2) << std::setfill('0') << this->departMonth << "/" << departDay << endl;
			}
		
	}
	//displays name
	const char * Passenger::name() const
	{
		if (!isEmpty()) {
			return this->customer;
		}
		else {
			return 0;
		}
		
	}
	//checks if passenger has the same travel date and destination
	bool Passenger::canTravelWith(const Passenger & pair) const
	{
		if (strcmp(destination, pair.destination) == 0 &&
			departDay == pair.departDay &&
			departMonth == pair.departMonth &&
			departYr == pair.departYr){
		return true;
 		}else{
		return false;
		}
	}
}
