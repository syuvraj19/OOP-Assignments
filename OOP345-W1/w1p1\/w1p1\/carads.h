

#include <iostream>
#ifndef CARADS_H
#define CARADS_H
extern double g_taxrate;
extern double g_discount;

namespace sdds {
    void listArgs(int argc, char* argv[]);

    class Cars {
        static int counter;

        char Brand[10];
        char Model[15];
        int Year;
        double price;
        char status;
        char DiscStatus;
        bool flag;

    public:
        Cars();
        void read(std::istream& is);
        char getStatus();
        void display(bool reset);
        
    };
}

#endif
