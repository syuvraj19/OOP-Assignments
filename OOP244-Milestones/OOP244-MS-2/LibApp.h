/*
*****************************************************************************
                              milestone - 2
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 22/07/2022

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <iostream>
#include "Menu.h"

namespace sdds
{
    class LibApp
    {
        bool m_changed = false;
        
        Menu m_mainMenu{ "Seneca Library Application" };
        
        Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?" };
        
        bool confirm(const char* msg); //Instantiate a Menu in this function and initialize it with the message argument.
        
        void load(); // prints: "Loading Data"<NEWLINE>
        
        void save(); // prints: "Saving Data"<NEWLINE>
        
        void search(); //prints: "Searching for publication"<NEWLINE>

        void returnPub(); //Calls the search() method. prints "Returning publication"<NEWLINE> prints "Publication returned"<NEWLINE> sets m_changed to true;
        
        void newPublication();//calls the confirm method with "Add this publication to library?" if confrim returns true, it will set m_changed to true and prints "Publication added" + newline
        
        void removePublication();//calls the confirm method with "Remove this publication from the library?" if confrim returns true, it will set m_changed to true and prints "Publication removed" + newline
        
        void checkOutPub(); //calls the confirm method with Check out publication?" if confrim returns true, it will set m_changed to true and prints "Publication checked out" + newline

    public:
        LibApp();
        void run();
    };
}

#endif // !SDDS_LIBAPP_H

