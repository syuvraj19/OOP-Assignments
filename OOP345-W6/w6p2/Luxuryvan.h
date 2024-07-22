

#ifndef LUXURYVAN_H
#define LUXURYVAN_H

#include "Van.h"
namespace sdds {
	class Luxuryvan : public Van {
		std::string m_consumption;
	public:
		Luxuryvan(std::istream& in);
		void display(std::ostream& out) const;
		std::string consumption() const;
	};
}


#endif // ! LUXURYVAN_H
