// TODO: add file header comments here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
// TODO: add header file guard here

// TODO: declare your namespace here
namespace sict {
	const int SIZE = 32;
	// TODO: define the Passenger class here
	class Passenger {
        
		char customer[SIZE];
		char destination[SIZE];
		int departYr;
		int departMonth;
		int departDay;

	public:
		
		Passenger();
		Passenger(const char[], const char[]);
		Passenger(const char[], const char[], int, int, int);
		void setEmpty();
		bool isEmpty() const; //checks if field is empty
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger& person) const;
	};

}


#endif