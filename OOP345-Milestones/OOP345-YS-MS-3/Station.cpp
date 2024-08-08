// Name: yuvraj singh
// Seneca Student ID: 155580210
// Seneca email: yuvraj-singh5@myseneca.ca
// Date of completion: 30/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

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

    station_id = ++id_generator;
    station_iname = utilities.extractToken(record, next_pos, more);
    m_serialNumber = stoi(utilities.extractToken(record, next_pos, more));
    Item_stockQuantity = stoi(utilities.extractToken(record, next_pos, more));
    m_widthField = m_widthField > utilities.getFieldWidth() ? m_widthField : utilities.getFieldWidth();
    station_desc = utilities.extractToken(record, next_pos, more);
}

const string& sdds::Station::getItemName() const {
    return station_iname;
}

size_t sdds::Station::getNextSerialNumber() {
    return m_serialNumber++;
}

size_t sdds::Station::getQuantity() const {
    return Item_stockQuantity;
}

void sdds::Station::updateQuantity() {
    if (Item_stockQuantity > 0) {
        Item_stockQuantity--;
    }
}

void sdds::Station::display(ostream& os, bool full) const {
    os << std::right;
    os << setw(3) << setfill('0') << station_id << " | ";
    os << left << setfill(' ') << setw(m_widthField + 1) << station_iname << " | ";
    os << right << setw(6) << setfill('0') << m_serialNumber << " | ";

    if (full) {
        os << setfill(' ');
        os << right;
        os << setw(4) << Item_stockQuantity << " | " << station_desc;
    }

    os << endl;
}
