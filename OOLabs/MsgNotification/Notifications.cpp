#include "Notifications.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
namespace sict {
	Notifications::Notifications(std::ifstream & file)
	{
		
		while (!file.eof()) {
			msgArray[count] = new Message(file, ' ');
			count++;
		}
		
	}

	Notifications::Notifications(Notifications && obj)
	{
		*this = std::move(obj);
	}

	Notifications && Notifications::operator=(Notifications && obj)
	{
		if (this != &obj) {
			for (int i = 0; i < obj.count; i++) {
				msgArray[i] = std::move(obj.msgArray[i]);
			}
			count = obj.count;
		}
		return std::move(*this);
	}

	Notifications::~Notifications()
	{
		for (count; count < MAX; count++) {
			if (msgArray[count] != nullptr) {
				msgArray[count] = nullptr;
				
			}	
		}
	//	delete[]msgArray;
		
	}

	void Notifications::display(std::ostream & os) const
	{

		for (int i = 0; i < count; i++) {

		//	os << msgArray[i] << endl;

		msgArray[i]->Message::display(os); 
		}


	}
}
