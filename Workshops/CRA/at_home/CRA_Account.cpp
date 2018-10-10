#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "CRA_Account.h"


using namespace std;

namespace sict {
	void CRA_Account::set(const char* familyName, const char* givenName, int sinn) {
		int sin = sinn;
		m_familyName[0] = '\0';
		m_givenName[0] = '\0';
		m_sin = 0;
		if (sin >= min_sin && sin <= max_sin && familyName[0] != '\0' && givenName[0] != '\0') {
			int sum = 0;
			for (int i = 0; i < 5; ++i) {
				int temp = sin % 100;
				int even = temp / 10 * 2;
				sum += temp % 10 + even / 10 + even % 10;
				sin /= 100;
			}
			if (sum % 10 == 0) {
				
				strncpy(m_familyName, familyName, max_name_length + 1);
				m_familyName[max_name_length] = '\0';
				strncpy(m_givenName, givenName, max_name_length + 1);
				m_givenName[max_name_length] = '\0';
				m_sin = sinn;
				
			}
		}
		for (int i = 0; i < max_yrs; ++i)
			balanceOwed[i] = 0;
			numTaxYrs = 0;
	}

	void CRA_Account::set(int year, double balance) {
		if (numTaxYrs < max_yrs)
			taxYears[numTaxYrs] = year;
		balanceOwed[numTaxYrs] = balance;
		numTaxYrs++;
	}

	void CRA_Account::display() const{
		cout << "Family Name: " << m_familyName << endl;
		cout << "Given Name : " << m_givenName << endl;
		cout << "CRA Account: " << m_sin << endl;
		cout << fixed << setprecision(2);
		for (int i = 0; i < numTaxYrs; ++i) {
			cout << "Year (" << taxYears[i] << ") ";
			if (balanceOwed[i] > 2.00) {
				cout << "balance owing: " << balanceOwed[i] << endl;
			}
			else if (balanceOwed[i] < -2.00) {
				cout << "refund due: " << -balanceOwed[i] << endl;
			}
			else {
				cout << "No balance owing or refund due!" << endl;
			}
		}
		if (isEmpty() == 1) {
			cout << "Account object is empty!" << endl;
		}
	}
	bool CRA_Account::isEmpty() const{
		return m_sin == 0;
	}

}