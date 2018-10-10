#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "Sale.h"
#include "iProduct.h"


namespace w6 {


	Sale::Sale(const char * fileName)
	{
		std::ifstream file(fileName);

		if (file.is_open()) {
			while (file.good()) {
				iProduct* prod = readProduct(file);
				prodList.push_back(std::move(prod));
			}
			file.close();
		}
		else {
			throw std::string("Failed to open file '") + fileName + "'";
		}
	}

	void Sale::display(std::ostream& os) const {
		double total = 0;

		os << "Product No      Cost Taxable\n";
		for (auto product : prodList) {
			os << *product << std::endl;
		}

		for (auto product : prodList) {
			total += product->getCharge();
		}

//Count number of integers to round total to 2 decimal places

		int count = 0;
		int countedTotal = (int)total;
		while (countedTotal != 0) {
			countedTotal /= 10;
			++count;
		}
//Print the output
		os << std::setw(10) << std::right << "Total" << std::setw(10) << std::right << std::fixed <<std::setprecision(2) << total << std::endl;

	}
}