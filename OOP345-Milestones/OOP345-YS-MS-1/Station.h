// Name: yuvraj singh
// Seneca Student ID: 155580210
// Seneca email: yuvraj-singh5@myseneca.ca
// Date of completion: 17/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
using namespace std;
namespace sdds {

    class Station {
        int station_id;
        int m_serialNumber;
        int Item_stockQuantity;

        static size_t m_widthField;//the maximum number of characters required to print to the screen the item name for any object of type Station. Initial value is 0.
        static size_t id_generator;//a variable used to generate IDs for new instances of type Station

        string station_iname;//the name of the item handled by the station (string).
        string station_desc;//the description of the station (string)

    public:

        size_t getQuantity();//returns the remaining quantity of items in the Station object.

        void updateQuantity();//subtracts 1 from the available quantity; should not drop below 0.

        size_t getNextSerialNumber();//returns the next serial number to be used on the assembly line and increments m_serialNumber.

        void display(ostream& os, bool full);//inserts information about the current object into stream os.

        Station(string& rec);

        string& getItemName();//returns the name of the current Station object.


    };
}


#endif

