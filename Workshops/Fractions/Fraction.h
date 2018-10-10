// TODO: header file guard
#ifndef SICT_FRACTION_H_
#define SICT_FRACTION_H_



// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int n; //numerator
		int d; //denominator

		int max() const;
		int min() const;
		int gcd() const;

		// TODO: declare private member functions

	public:

		void reduce(); // reduces to the lowest common denominator/numerator
		Fraction();
		Fraction(int, int);
		// TODO: declare public member functions
		bool isEmpty() const;
		void display() const;

		// TODO: declare the operator overloads

		
		Fraction operator*(const Fraction& rhs) const;
		Fraction operator+=(const Fraction& rhs);
		friend Fraction operator+ (const Fraction& rhs, const Fraction& lhs);
		friend bool operator== (const Fraction& rhs, const Fraction& lhs);
		friend bool operator!= (const Fraction& rhs, const Fraction& lhs);
	};
	//+operator,==operator, and != operator declared in sict namespace for visibility to the compiler
	Fraction operator+ (const Fraction& rhs, const Fraction& lhs);
	bool operator== (const Fraction& rhs, const Fraction& lhs);
	bool operator!= (const Fraction& rhs, const Fraction& lhs);

}

	

#endif