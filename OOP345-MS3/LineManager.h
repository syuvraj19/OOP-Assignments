

#ifndef SDDS_LINE_MANAGER_H
#define SDDS_LINE_MANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include "Workstation.h"

using namespace std;

namespace sdds {
    class LineManager {
        vector<Workstation*> m_active_Line;
        size_t m_cntCustomer_Order;
        Workstation* m_first_Station;

    public:
        LineManager(const string& file, const vector<Workstation*>& stations);
        void reorderStations();
        bool run(ostream& os);
        void display(ostream& os) const;
    };
};

#endif
