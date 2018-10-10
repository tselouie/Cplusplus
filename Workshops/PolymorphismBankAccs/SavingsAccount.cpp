#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace sict {
	SavingsAccount::SavingsAccount()
	{
		rate = 0.05;
		currentBalance = 0.00;
	}
	SavingsAccount::SavingsAccount(double bal, double interest)
	{
		currentBalance = bal;
		if (interest > 0) {
			rate = interest;
		}
		else {
			rate = 0.00;
		}
	}

	void SavingsAccount::monthEnd()
	{
		double interest;
		interest = currentBalance * rate;
		currentBalance += interest;
	}

	void SavingsAccount::display(std::ostream &os) const
	{
		os << "Account type: Savings" << endl << "Balance: $" << std::fixed << std::setprecision(2) << currentBalance << endl << "Interest Rate (%): " << rate *100 << endl;
		


	}
}