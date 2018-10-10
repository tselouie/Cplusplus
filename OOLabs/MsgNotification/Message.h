#ifndef _MESSAGE_H_
#define _MESSAGE_H_
#pragma once
#include <iostream>

using namespace std;
namespace sict {
	class Message {
		string toUser;
		string fromUser;
		string message;
	public:
		Message(std::ifstream& in, char c); // constructor retrieves a record from the in file object, parses the record(as described above) 
											//and stores its components in the Message object.c is the character that delimits each record
		void display(std::ostream&)const; //displays the Message objects within the container
	};
}
#endif