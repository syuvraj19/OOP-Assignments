

#ifndef __SDDS_CARADS_H__
#define __SDDS_CARADS_H__

#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>

extern double g_taxrate;
extern double g_discount;

namespace sdds
{
    
    class Cars
    {
    public:
        Cars();
        Cars(const Cars &PresentCar);
        
        void display(bool reset);
        char getStatus();
        
        void read(std::istream &in);
        operator bool();
        
        Cars& operator=(const Cars& PresentCar);
        
        ~Cars();
    private:
        
        double Price;
        char status;
        char* Brand;
        char Model[15];
        bool DiscStatus;
        int Year;

    };
    std::istream &operator>>(std::istream &is, Cars &car);
    void operator>>(const Cars &car1, Cars &car2);
    void listArgs(int argc, char* argv[]);
}
#endif

