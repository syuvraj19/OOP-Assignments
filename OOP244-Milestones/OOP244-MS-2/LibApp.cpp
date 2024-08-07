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

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "LibApp.h"

namespace sdds
{
    bool LibApp::confirm(const char* msg)
    {
        Menu var(msg);
        var << "Yes";

        int app_return = var.run();

        if (app_return)
        {
            return true;
        }

        return false;
    }

    void LibApp::load() // prints: "Loading Data"<NEWLINE>
    {
        std::cout << "Loading Data\n";
    }
    
    void LibApp::save() // prints: "Saving Data"<NEWLINE>
    {
        std::cout << "Saving Data\n";
    }

    void LibApp::search() // prints: "Searching for publication"<NEWLINE>
    {
        std::cout << "Searching for publication\n";
    }

    void LibApp::returnPub() // Call search() method and print some lines
    {
        search();
        std::cout << "Returning publication\n";
        std::cout << "Publication returned\n";
        m_changed = true;
    }

    void LibApp::newPublication()
    {
        std::cout << "Adding new publication to library\n";

        if (confirm("Add this publication to library?"))
        {
            m_changed = true;
            std::cout << "Publication added\n";
        }
    }

    void LibApp::checkOutPub()
    {
        search();

        if (confirm("Check out publication?"))
        {
            m_changed = true;
            std::cout << "Publication checked out\n";
        }
    }

    void LibApp::removePublication()
    {
        std::cout << "Removing publication from library\n";
        search();
        if (confirm("Remove this publication from the library?"))
        {
            m_changed = true;
            std::cout << "Publication removed\n";
        }
    }

    
    LibApp::LibApp()
    {
        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

        load();
    }

    void LibApp::run()
    {
        while (1)
        {
            int selection = m_mainMenu.run();

            if (selection == 1)
            {
                newPublication();
            }
            else if (selection == 2)
            {
                removePublication();
            }
            else if (selection == 3)
            {
                checkOutPub();
            }
            else if (selection == 4)
            {
                returnPub();
            }
            else if (selection == 0)
            {
                if (m_changed)
                {

                    int sel = m_exitMenu.run();

                    if (sel == 1)
                    {
                        save();
                        break;
                    }
                    else if (sel == 2)
                    {
                        ;
                    }
                    else if (sel == 0)
                    {
                        if (confirm("This will discard all the changes are you sure?"))
                            break;
                    }
                }
                else
                    break;
            }

            std::cout << std::endl;
        }

        std::cout << std::endl;
        std::cout << "-------------------------------------------\n";
        std::cout << "Thanks for using Seneca Library Application\n";

    }

}

