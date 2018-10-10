#pragma once
#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

// Workshop 7 - STL Containers
// iProduct.h

#include <iostream>
#include <fstream>
const double PST = 0.08;
const double HST = 0.13;

namespace w6 {

	class iProduct {
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};


	class Product : public iProduct {
		unsigned int prodNum;
		double charge;

	public:
		Product(unsigned int num, double c) : prodNum(num), charge(c) {}
		double getCharge() const;
		void display(std::ostream&) const;
	};


	class TaxableProduct : public Product {
		char taxable;
		double taxRate[2] = { PST, HST };
	public:
		TaxableProduct(unsigned int num, double c,char tx) : Product(num,c), taxable(tx) {}
		double getCharge() const;
		void display(std::ostream&) const;

	};


	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);

}
#endif
