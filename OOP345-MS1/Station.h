
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
using namespace std;
namespace sdds {

    class Station {
        int m_id;
        int m_nextSequence;
        int m_stockQuantity;

        static size_t m_widthField;
        static size_t id_generator;

        string m_name;
        string m_description;

    public:

        size_t getQuantity();

        void updateQuantity();

        size_t getNextSerialNumber();

        void display(ostream& os, bool full);

        Station(string& rec);

        string& getItemName();


    };
}


#endif 
