#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include "Contact.h"
using namespace sict;
using namespace std;

namespace sict {
	Contact::Contact()
	{
		contactName[0] = '\0';
		phoneNumbers = nullptr;
		pnCount = 0;
	}

	Contact::Contact(const char * name, long long *fullNum, int count)
	{
		pnCount = count;
		if (name != nullptr && name[0] != '\0') {
			strncpy(contactName, name, maxchars);
			contactName[19] = '\0';
		}
		else {
			contactName[0] = '\0';
		}

		phoneNumbers = new long long[count];

		for (int i = 0; i < count; i++) {
			phoneNumbers[i] = fullNum[i];
		}
	}

	Contact::Contact(const Contact & obj) // copyconstructor
	{
		copyName(obj.contactName);
		if (obj.phoneNumbers != nullptr) {
			phoneNumbers = new long long[pnCount = obj.pnCount];
			for (int i = 0; i < pnCount; i++) {
				phoneNumbers[i] = obj.phoneNumbers[i];
			}
		}
		else {
			phoneNumbers = nullptr;
		}
	}

	Contact::~Contact()
	{
		delete[] phoneNumbers;
	}

	bool Contact::isEmpty() const {
		return (contactName[0] == '\0');
	}

	void Contact::display() const {
		if (isEmpty() == 1) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << contactName << endl;

			for (int i = 0; i < pnCount; i++) {
				string phoneNum; //create an object with string class
				stringstream stream; // create object to store stream of phonenumber characters
				stream << phoneNumbers[i]; //put the characters into the stringstream object
				phoneNum = stream.str();

				if (phoneNum.length() == 11) {
					cout << "(+" << phoneNum.substr(0, 1) << ") " << phoneNum.substr(1, 3) << " " << phoneNum.substr(4, 3) << "-" << phoneNum.substr(7, 4) << endl;
				}
				else if (phoneNum.length() == 12) {
					cout << "(+" << phoneNum.substr(0, 2) << ") " << phoneNum.substr(2, 3) << " " << phoneNum.substr(5, 3) << "-" << phoneNum.substr(8, 4) << endl;
				}
			}
		}
	}
	Contact &Contact::operator+=(long long newPhone)
	{
		if (newPhone < 999999999999 && newPhone > 10000000000) {
			long long *temp = new long long[pnCount + 1];
			int i;
			for (i = 0; i < pnCount; i++) {
				temp[i] = phoneNumbers[i];
			}
			pnCount += 1;
			temp[i] = newPhone;
			delete[] phoneNumbers;
			phoneNumbers = temp;
		
		}
	
		return *this;
	}
	Contact &Contact::operator=(const Contact & rhs)
	{
		
		if (this != &rhs) {
			copyName(rhs.contactName);
			pnCount = rhs.pnCount;

			delete[] phoneNumbers;
			if (rhs.phoneNumbers != nullptr) {
				phoneNumbers = new long long[pnCount];
				
				for (int i = 0; i < pnCount; i++) {
					phoneNumbers[i] = rhs.phoneNumbers[i];
					contactName[i] = rhs.contactName[i];
				}
				
			}
		}
		return *this;
	}
}
char* Contact::copyName(const char* rhs)
{
	contactName[0] = '\0';
	strncpy(contactName, rhs, strlen(rhs));
	contactName[strlen(rhs)] = '\0';

	return contactName;
}