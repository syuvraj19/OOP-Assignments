

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>

using namespace std;
namespace sdds {

    class Station {
        int m_idOfSta;
        string m_nameOfSta;
        string m_descriptionOfSta;
        unsigned m_nextSequence;
        unsigned m_stockQuantity;

        static size_t m_widthField;
        static size_t id_generator;
    public:
        size_t getQuantity();
        void updateQuantity();
        size_t getNextSerialNumber();
        void display(ostream& os, bool full);
        Station(string& record);
        string& getItemName();
    };
}

#endif 
