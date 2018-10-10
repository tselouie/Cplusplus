#pragma once
#ifndef SALE_H
#define SALE_H

#include <iostream>
#include <vector>
#include "iProduct.h"

namespace w6 {
	class Sale {
		std::vector <iProduct*>prodList;
	public:
		Sale(const char* fileName);
		void display(std::ostream& os) const;

	};

}
#endif