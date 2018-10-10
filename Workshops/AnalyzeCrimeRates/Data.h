#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;
	
	
	// min returns the largest item in data
	template <class T>
	T min(const T* data, int n){
		T temp = LARGEST_NUMBER;
		for(int i =0;i< n;i++){
			if (temp > data[i]) {
				temp = data[i];
		}
		}
		return temp;
	}
	// max returns the smallest item in data
	//
	template <class T>
	T max(const T* data, int n) {
		T temp = SMALLEST_NUMBER;
		for (int i = 0; i< n; i++) {
			if (temp < data[i]) {
				temp = data[i];
			}
		}
		return temp;
	}        
	// sum returns the sum of n items in data
	template <class T>
	T sum(const T* data, int n) {
		T temp = 0;
		for (int i = 0; i< n; i++) {
			temp += data[i];
		}
		return temp;

	}
	// average returns the average of n items in data
	template <class T>
	double average(const T* data, int n) {
		double temp;
		temp = sum(data, n) / n;
		return temp;
	}
	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	template <class T>
	bool read(std::istream& input, T*data, int n) {
		bool temp = true;
		char holder;
		for (int i = 0; i < n; i++) {
			input >> holder >> data[i];
			if (input.fail()) {
			temp = false;
		}		
		}
		return temp;
	}

	// display inserts n items of data into std::cout
	template <class T>
	void display(const char* name, const T* data, int n){

		std::cout << std::setw(20) << right << name << setw(15);
		for (int i = 0; i < n; i++) {
			std::cout << data[i]<< setw(15);

			if (i == n-1) {
				std::cout << std::endl;
			}
		}
		

	}

template <class T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}
	
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

