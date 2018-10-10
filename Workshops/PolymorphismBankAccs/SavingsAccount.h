
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace sict {
	class SavingsAccount :public Account{

	public:
		SavingsAccount();
		SavingsAccount(double, double);
		void monthEnd();
		 void display(std::ostream&) const;

	};
}
#endif
