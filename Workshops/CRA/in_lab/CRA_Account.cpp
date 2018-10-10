#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {
	void CRA_Account::set(const char* familyName, const char* givenName, int sin){
	
		if (sin >= min_sin && sin <= max_sin) {
			strncpy(m_familyName, familyName, max_name_length + 1);
			strncpy(m_givenName, givenName, max_name_length + 1);
			m_sin = sin;
		}
		else {
			m_familyName[0] = '\0';
			m_givenName[0] = '\0';
			m_sin = 0;
		}

	}
	void CRA_Account::display() const{
		cout << "Family Name: " << m_familyName << endl;
		cout << "Given Name : " << m_givenName << endl;
		cout << "CRA Account: " << m_sin << endl;

		if (isEmpty() == 1) {
			cout << "Account object is empty!" << endl;
		}
	}
	bool CRA_Account::isEmpty() const{
		return m_sin == 0;
	}

}