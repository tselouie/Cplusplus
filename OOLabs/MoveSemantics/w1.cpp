//Name: Louie Tse
//Stu#027168103
//Email:lttse@myseneca.ca
//Date:May 10,2018
//Professor: Elliot Coleshill
//SECTION: OOP345SAB

#include <iostream>
#include "process.h"

using namespace std;
using namespace w1;


int main(int argC, char * argv[]){

	extern int STORED;
	int result = 0;

	std::cout << "Command Line : ";
	for (int i = 0; i < argC; i++) {
		std::cout << " " << argv[i];
	}
	std::cout << endl;

	if (argC <= 1) {
		cout << "Insufficient  number of arguments (min 1)";
		result = 1;

	}
	else {
		cout << "Maximum number of characters stored : " << STORED << endl;
	}
	for (int x = 1; x < argC; x++) {
		int counter = x-1;
		cout << counter << ": ";
		process(argv[x]);
		

	}
	cout << endl;

		return result;
}
