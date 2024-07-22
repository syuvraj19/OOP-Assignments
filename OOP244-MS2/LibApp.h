/***********************************************************************
 CLASS : OOP244
 SECTION : ZBB
 NAME          : Yuvraj Singh
 EMAIL         : yuvraj-singh5@myseneca.ca
 STUDENT ID    : 155580210
DATE CREATED ON : 22 JULY 2022
MILESTONE 2

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds {
    class LibApp {

        void load();
        void save();
        void search();

        bool confirm(const char* message);

        void returnPub();
        void newPublication();

        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;

        void checkOutPub();

    public:

        LibApp();
        ~LibApp();
        void run();

        void removePublication();


    };

}


#endif
