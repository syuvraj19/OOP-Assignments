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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {

    int const MAX_MENU_ITEMS = 20;

    class Menu;

    class MenuItem {    //The class MenuItem is declared here
        
        char* m_menuProds{};
        
        MenuItem();     //this is constructor
        
        MenuItem(const char* prod);
        
        ~MenuItem();        //this is deconsrtructor
        
        operator bool() const;
        
        void display();     //this displays the output
        
        friend Menu;        //this is the friend function which is calling the private member function of the class
    };

    class Menu {        //class Menu is declared here

        char* m_menuTitle{};
        
        MenuItem* m_prods[MAX_MENU_ITEMS];
        
        int num_menu = 0;
        
    public:
        
        Menu();     //this is constructor
        
        Menu(const char* m_title);      //this is an overload function
        
        ~Menu();        //this is the deconstructor
        
        int run();
        
        char* operator[](int x) const;
        
        operator bool() const;
        
        int operator~();
        
        void display();
        
        std::ostream& write(std::ostream& os = std::cout)const;
        
        Menu& operator<<(const char* ProdsMenucont);
        
        operator unsigned int() const;
    };

    std::ostream& operator<<(std::ostream& os, const Menu& m);

}
#endif

