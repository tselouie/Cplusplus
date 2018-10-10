#ifndef SICT_CHEQUINGACCOUNT_H_
#define SICT_CHEQUINGACCOUNT_H_

#include "Account.h"
using namespace std;

namespace sict {
   
	class ChequingAccount :public Account {
		
		

	public:
		double transactionFee;
		double monthCharge;
		ChequingAccount();
		ChequingAccount(double, double, double);
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd();
		void display(std::ostream&) const;

	};


}
#endif
