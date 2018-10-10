#include "ChequingAccount.h"
#include "iAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace sict {
	ChequingAccount::ChequingAccount()
	{
		rate = 0.05;
		currentBalance = 0.00;
		transactionFee = 0.00;
		monthCharge = 0.00;
	}
	ChequingAccount::ChequingAccount(double bal, double transxn, double monthfee)
	{
		currentBalance = bal;
		if (transxn > 0) {
			transactionFee = transxn;
		}
		if (monthfee > 0){
			monthCharge = monthfee;
		}
		else {
			rate = 0.00;
		}
	}
	bool ChequingAccount::credit(double amount)
	{
		bool pos = false;
		if (amount > 0.00) {
			currentBalance += amount;
			currentBalance -= transactionFee;
			pos = true;
		}
		return pos;
	}

	bool ChequingAccount::debit(double amount)
	{
		bool pos = false;
		if (amount > 0.00) {
			currentBalance -= amount;
			currentBalance -= transactionFee;
			pos = true;
		}
		return pos;

	}

	void ChequingAccount::monthEnd()
	{
		debit(monthCharge);
	}

	void ChequingAccount::display(std::ostream &os) const
	{
		os << "Account type: Chequing" << endl << "Balance: $" << std::fixed << std::setprecision(2) << currentBalance << endl << "Per Transaction Fee: " <<transactionFee<< endl << "Monthly Fee: "<< monthCharge <<endl;



	}
}