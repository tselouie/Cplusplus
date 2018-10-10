#include <iostream>
#include <fstream>
#include <iomanip>
#include "iProduct.h"
using namespace std;

namespace w6 {

	double Product::getCharge() const {
		return charge;
	}

	void Product::display(std::ostream& os) const
	{
		os << std::setw(10) << std::right << prodNum << std::setw(10) << std::right << std::fixed << std::setprecision(2) << charge;
	}


	double TaxableProduct::getCharge() const {
		double total = Product::getCharge();
	
		if(taxable == 'P'){
			total = (1 + taxRate[0]) * total;
		}
		if (taxable == 'H') {
			total = (1 + taxRate[1]) * total;
		}

		return total;
	}

	void TaxableProduct::display(std::ostream& os) const
	{
		Product::display(os);
		os << ' ';
		if (taxable == 'P') {
			os << "PST";
		}
		if (taxable == 'H') {
			os << "HST";
		}
	}



	//Helper functions

	std::ostream & operator<<(std::ostream &os, const iProduct &prod)
	{
		prod.display(os);
		return os;
	}

	iProduct * readProduct(std::ifstream &is)
	{
		iProduct* temp ;
		unsigned int tempProdNum;
		double tempCharge;
		char tempTax;


		is >> tempProdNum >> tempCharge;
		if (is.get() != '\n') {
			is >> tempTax;
			temp = new TaxableProduct(tempProdNum, tempCharge, tempTax);
		}
		else {
			temp = new Product(tempProdNum, tempCharge);
		}


		return temp;
	}
	


























}