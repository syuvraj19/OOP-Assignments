

#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "Station.h"
using namespace std;
namespace sdds {

    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 1;

    size_t Station::getQuantity()
    {
        return m_stockQuantity;
    }

    void Station::updateQuantity()
    {
        m_stockQuantity--;
        if (0 > m_stockQuantity)
            m_stockQuantity = 0;
    }

    void Station::display(ostream& os, bool f)
    {
        os << setfill('0') << setw(3) << right << m_id;

        os << " | " << setw(m_widthField) << setfill(' ') << left << m_name;

        os << " | " << setfill('0') << setw(6) << right << m_nextSequence << " | ";


        if (f)
        {
            os << right << setw(4) << setfill(' ') << m_stockQuantity << " | ";

            os << left << m_description << endl;
        }
        else os << endl;
    }
    Station::Station(string& record)
    {


        Utilities ut;

        size_t ps = 0;

        bool other;

        m_id = id_generator++;



        try {

            m_name = ut.extractToken(record, ps, other);

            m_nextSequence = stoi(ut.extractToken(record, ps, other));

            m_stockQuantity = stoi(ut.extractToken(record, ps, other));


            m_widthField = max(ut.getFieldWidth(), m_widthField);

            m_description = ut.extractToken(record, ps, other);

        }
        catch (string& e) {
            cout << e;
        }
    }

    string& Station::getItemName()
    {
        return m_name;
    }

    size_t Station::getNextSerialNumber()
    {
        return m_nextSequence++;
    }


}
