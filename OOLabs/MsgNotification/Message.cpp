#include "Message.h"
#include <iostream>
#include<fstream>
#include <string>
#include <cstring>

using namespace std;

namespace sict {
	
	Message::Message(std::ifstream & in, char c)
	{

		string msgHolder;
		string msgHolder2;
		string temp;
		
		int endofLine;
		int space;
		int invalid = 0;
		
			getline(in, fromUser, c); 

			//check for an extra name if there is, erase up to \n
			for (size_t i = 0; i < fromUser.length(); i++)
			{
				if (fromUser.at(i) == '\n')
				{
					invalid = i;
					fromUser.erase(0, invalid + 1);
				}
			}
			

			getline(in, msgHolder, '\n');


			if (msgHolder[0] == '@') {
				msgHolder2 = msgHolder;
				msgHolder.erase(0, 1);
				space = msgHolder.find(' ');
				endofLine = msgHolder.find('\n');
				temp = msgHolder;
				temp.erase(space ,endofLine - space);
				toUser = temp;
				//temp = nullptr;
				
				msgHolder2.erase(0, space +2);
			
				message = msgHolder2;
			}
			else {
				message = msgHolder;
			}
					

		
	}

	void Message::display(std::ostream &os) const
	{
		os << "Message" << endl;
		os << "  User	: " << fromUser << endl;
		if (toUser != "") {
			os << "  Reply	: " << toUser << endl;
		}
		os << "  Tweet : " << message << endl << endl;

	}
}