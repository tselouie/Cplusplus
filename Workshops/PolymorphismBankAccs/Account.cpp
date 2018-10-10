#include "iAccount.h"
#include "Account.h"
#include <iostream>

using namespace std;

namespace sict {



	double Account::balance() const
	{
		return currentBalance;
	}

	Account::Account() {

	}

	Account::Account(double initialValue)
	{
		if (initialValue > 0) {
			currentBalance = initialValue;
		}
		else {
			currentBalance = 0.00;
		}
	}

	bool Account::credit(double amount)
	{
		bool pos = false;
		if (amount > 0.00) {
			currentBalance += amount;
			pos = true;
		}
		return pos;
	}

	bool Account::debit(double amount)
	{
		bool pos = false;
		if (amount > 0.00) {
			currentBalance -= amount;
			pos = true;
		}
		return pos;
		
	}

}
