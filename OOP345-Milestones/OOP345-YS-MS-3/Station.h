// Name: yuvraj singh
// Seneca Student ID: 155580210
// Seneca email: yuvraj-singh5@myseneca.ca
// Date of completion: 30/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef STATION_H
#define STATION_H

#include <string>

using namespace std;

namespace sdds {
    class Station {
        int station_id;
        string station_iname;
        string station_desc;
        unsigned int m_serialNumber;
        unsigned int Item_stockQuantity;

        static size_t m_widthField;
        static int id_generator;

    public:
        Station(const string& record);
        const string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(ostream& os, bool full) const;
    };
};


#endif
