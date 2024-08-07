


#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

size_t sdds::Station::m_widthField = 0;
int sdds::Station::id_generator = 0;

sdds::Station::Station(const string& record) {
    Utilities utilities;
    size_t next_pos = 0;
    bool more = true;

    id = ++id_generator;
    name = utilities.extractToken(record, next_pos, more);
    nextSerialNo = stoi(utilities.extractToken(record, next_pos, more));
    noItems = stoi(utilities.extractToken(record, next_pos, more));
    m_widthField = m_widthField > utilities.getFieldWidth() ? m_widthField : utilities.getFieldWidth();
    desc = utilities.extractToken(record, next_pos, more);
}

const string& sdds::Station::getItemName() const {
    return name;
}

size_t sdds::Station::getNextSerialNumber() {
    return nextSerialNo++;
}

size_t sdds::Station::getQuantity() const {
    return noItems;
}

void sdds::Station::updateQuantity() {
    if (noItems > 0) {
        noItems--;
    }
}

void sdds::Station::display(ostream& os, bool full) const {
    os << std::right;
    os << setw(3) << setfill('0') << id << " | ";
    os << left << setfill(' ') << setw(m_widthField + 1) << name << " | ";
    os << right << setw(6) << setfill('0') << nextSerialNo << " | ";

    if (full) {
        os << setfill(' ');
        os << right;
        os << setw(4) << noItems << " | " << desc;
    }

    os << endl;
}
