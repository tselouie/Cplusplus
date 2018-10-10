
// TODO: insert header files
#include <iostream>
#include "Fraction.h"
// TODO: continue the namespace
using namespace std;
using namespace sict;
	// TODO: implement the default constructor
namespace sict {
Fraction::Fraction() {
	n = -1;			//safe empty state
	d = -1;
}
	// TODO: implement the two-argument constructor
 Fraction::Fraction( int numerator,  int denominator) {
	if (numerator >= 0 && denominator > 0) {
		n = numerator;
		d = denominator;
		reduce();
	}
	else {
		n = -1;
		d = -1;
	}
}
	// TODO: implement the max query
int Fraction::max() const {
	return (n >= d) ? n : d; //return the greater of numerator/denominator
	
}
    // TODO: implement the min query
int Fraction::min() const {
	return (n >= d) ? d : n; //return lower of numerator denominator
	
}
	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {     //finds greatest common divisor
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
	void Fraction::reduce() {   //uses common divisor and reduces to the lowest pair
	
	int common = gcd();
	n /= common;
	d /= common;

	}
    // TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else if(d == 1) {
			cout << n;

		}
		else {
			cout << n << "/" << d;
		}
		

	}
    // TODO: implement the isEmpty query

	bool Fraction::isEmpty() const {
		return (d == -1);
	}
	

    // TODO: implement the + operator
	//adding the Fractions together
	//addition operator overloaded as a friend function
	Fraction operator+(const Fraction & rhs, const Fraction & lhs) {
		Fraction addition;
		if (rhs.isEmpty() == false && lhs.isEmpty() == false) {

			addition.n = (lhs.n * rhs.d) + (rhs.n * lhs.d);
			addition.d = (lhs.d * rhs.d);
			addition.reduce();
		}
		return addition;
	}

	Fraction Fraction::operator*(const Fraction & rhs) const
	{
		Fraction multiply;
		if (isEmpty() == false && rhs.isEmpty() == false) {
			multiply.n = n * rhs.n;
			multiply.d = d * rhs.d;
			multiply.reduce();
		}
		return multiply;
	}

	bool operator==(const Fraction & rhs, const Fraction & lhs) 
	{
		bool equal = false;

		if (lhs.isEmpty() == false && rhs.isEmpty() == false &&
			lhs.n == rhs.n && lhs.d == rhs.d) {				//checks if numerator and denominator is the same
			equal = true;							//if the same change return value to true
		}
		return equal;
		
	}

	bool operator!=(const Fraction & rhs, const Fraction & lhs) 
	{
		if (lhs.n == rhs.n && lhs.d == rhs.d) {				//checks if numerator and denominator is the same
			return false;						//if the same change return value to false
		}
		return true;
	
	}

	Fraction Fraction::operator+=(const Fraction & rhs)
	{
		Fraction temp;
		
		if (isEmpty() == false && rhs.isEmpty() == false) {
			
			temp.n = (n * rhs.d) + (rhs.n * d);
			temp.d = (d * rhs.d);
			temp.reduce();

		
					
     	}else{temp.n = -1;			//safe empty state
	      temp.d = -1;
	}
		*this = temp;
		return temp;
}

}