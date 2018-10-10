#include "SavingsAccount.h" 
#include "ChequingAccount.h"
#include "iAccount.h"
#include "Account.h"

namespace sict {
	const double interest_rate = 0.05;
	const double transaction_fee = 0.50;
	const double monthly_fee = 2.00;

	iAccount* CreateAccount(const char* nme, double value) {

		if (nme[0] == 'S') {
		SavingsAccount *newAccount;
		newAccount = new SavingsAccount[2];
			newAccount->credit(value);
			return newAccount ;
		}
		else if (nme[0] == 'C') {
			ChequingAccount *newAccount;
			newAccount = new ChequingAccount[2];
			newAccount->credit(value);
			newAccount->monthCharge = monthly_fee;
			newAccount->transactionFee = transaction_fee;
			return newAccount;
		}
		
		else {
			return nullptr;

		}

		
	}








}
