#include "iAccount.h"
#include <iostream>
namespace sict {









	bool iAccount::credit(double)
	{
		return false;
	}

	bool iAccount::debit(double)
	{
		return false;
	}

	void iAccount::monthEnd()
	{
	}

	void iAccount::display(std::ostream &) const
	{
	}

	iAccount * CreateAccount(const char *, double)
	{
		return nullptr;
	}

}