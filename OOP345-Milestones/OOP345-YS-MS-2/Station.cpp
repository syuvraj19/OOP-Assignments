// Name: yuvraj singh
// Seneca Student ID: 155580210
// Seneca email: yuvraj-singh5@myseneca.ca
// Date of completion: 24/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "Station.h"
using namespace std;
namespace sdds {

    size_t Station::m_widthField = 0;//the maximum number of characters required to print to the screen the item name for any object of type Station. Initial value is 0.
    size_t Station::id_generator = 1;//a variable used to generate IDs for new instances of type Station.

    size_t Station::getQuantity()
    {
        return Item_stockQuantity;
    }

    void Station::updateQuantity()
    {
        Item_stockQuantity--;
        if (0 > Item_stockQuantity)
            Item_stockQuantity = 0;
    }

    void Station::display(ostream& os, bool f)
    {
        os << setfill('0') << setw(3) << right << station_id;
        os << " | " << setw(m_widthField) << setfill(' ') << left << station_iname;
        os << " | " << setfill('0') << setw(6) << right << m_serialNumber << " | ";

        if (f)
        {
            os << right << setw(4) << setfill(' ') << Item_stockQuantity << " | ";

            os << left << station_desc << endl;
        }
        else os << endl;
    }
    Station::Station(string& record)
    {
        Utilities ut;
        size_t ps = 0;
        bool other;
        station_id = id_generator++;

        try {

            station_iname = ut.extractToken(record, ps, other);
            m_serialNumber = stoi(ut.extractToken(record, ps, other));
            Item_stockQuantity = stoi(ut.extractToken(record, ps, other));
            m_widthField = max(ut.getFieldWidth(), m_widthField);
            station_desc = ut.extractToken(record, ps, other);

        }
        catch (string& err) {
            cout << err;
        }
    }

    string& Station::getItemName()
    {
        return station_iname;
    }

    size_t Station::getNextSerialNumber()
    {
        return m_serialNumber++;
    }
}
