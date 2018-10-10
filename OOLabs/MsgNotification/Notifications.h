#ifndef _NOTIFICATIONS_H_
#define _NOTIFICATIONS_H_
#pragma once
#include <iostream>
#include "Message.h"

namespace sict {
	const int MAX = 10;

	class Notifications {
		Message* msgArray[MAX];
		int count = 0;

	public:
		Notifications(std::ifstream&); //constructor
		Notifications(Notifications&&); //move constructor
		Notifications&& operator=(Notifications&&); //move assignment operator
		~Notifications(); //destructor
		void display(std::ostream& os) const; //inserts the Message objects to the os output stream
	};
}
#endif