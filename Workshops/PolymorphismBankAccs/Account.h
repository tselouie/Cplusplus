
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account :public iAccount {
		
	protected:
		double balance() const;
		double rate;
		double currentBalance;
	

	public:
		Account();
		Account(double);
	bool credit(double);
	bool debit(double);

	};


}
#endif
