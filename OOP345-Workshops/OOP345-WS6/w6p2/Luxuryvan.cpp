

#include "Luxuryvan.h"

namespace sdds {
	Luxuryvan::Luxuryvan(std::istream& in) :Van(in) {
		char value = '\0';
		in >> value;
		if (value == 'e') {

			m_consumption = "electric van ";
		}
		else {
			throw std::string("Invalid record!");
		}
		in.ignore(1000, '\n');
	}

	void Luxuryvan::display(std::ostream& out) const {
		Van::display(out);
		out << " " << m_consumption << " *";
	}

	std::string Luxuryvan::consumption() const {
		return m_consumption;
	}
}
