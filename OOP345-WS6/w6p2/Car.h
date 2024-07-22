

#pragma once
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include <string>
#include "Vehicle.h"
namespace sdds {
	class Car :public Vehicle
	{
		std::string m_maker = "";
		std::string m_condition = "";
		double m_topSpeed = 0;
	public:
		Car();
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif // !SDDS_CAR_H_
