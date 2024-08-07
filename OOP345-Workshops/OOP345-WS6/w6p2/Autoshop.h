

#pragma once
#ifndef SDDS_AUTOSHOP_H_
#define SDDS_AUTOSHOP_H_
#include <list>
#include <vector>
#include "Vehicle.h"
namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out)const;
		~Autoshop();

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
				if (test(*i)) {
					vehicles.push_back(*i);
				}
			}
		}
	};
}
#endif // !SDDS_AUTOSHOP_H_
