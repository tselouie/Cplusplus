#ifndef _CONTACT_H
#define _CONTACT_H
using namespace std;

const int maxchars = 19 + 1;
namespace sict {

	class Contact {
		char contactName[maxchars];
		long long* phoneNumbers;
		int pnCount;

	public:
		Contact();
		Contact(const char* name, long long*, int );
		Contact(const Contact &);
		~Contact();
		bool isEmpty() const;
		void display() const;
		char* copyName(const char* rhs);
		
		Contact& operator+=(long long newPhone);
		Contact& operator=(const Contact& rhs);


	};
}

#endif