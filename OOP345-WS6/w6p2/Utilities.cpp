

#include <sstream>
#include <iostream>
#include "Utilities.h"

using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* ptr = nullptr;
		string temp;
		stringstream str;
		getline(in, temp);
		temp.erase(0, temp.find_first_not_of(' '));
		str.str(temp);
		if (!temp.empty()) {
			if (temp[0] == 'c' || temp[0] == 'C')
				ptr = new Car(str);
			else if (temp[0] == 'r' || temp[0] == 'R')
				ptr = new Racecar(str);
			else if (temp[0] == 'V' || temp[0] == 'v')
				ptr = new Van(str);
			else if (temp[0] == 'L' || temp[0] == 'l')
				ptr = new Luxuryvan(str);
			else
				throw char(temp[0]);
		}
		return ptr;
	}
}
