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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
    class Menu;
    const unsigned int  MAX_MENU_ITEMS = 20;


    class MenuItem
    {

        MenuItem(const char* content);

        MenuItem(const MenuItem& MI) = delete;

        void operator= (const MenuItem& MI) = delete;

        char* m_contentOfMenu{};

        MenuItem();



        ~MenuItem();

        operator bool() const;

        operator const char* () const;

        void setContent(const char* content);

        void setEmpty();

        friend class Menu;

        std::ostream& display(std::ostream& ostr = std::cout);


    };

    class Menu {

        MenuItem* m_arrOfMenuPointers[MAX_MENU_ITEMS]{ };

        MenuItem m_menuItemTitle;



        unsigned int m_noMenuPointers{};

    public:

        Menu();

        Menu(const Menu& M) = delete;

        Menu(const char* title);



        void operator= (const Menu& M) = delete;

        ~Menu();



        int run();

        int operator~();

        Menu& operator<<(const char* menuitemConent);

        std::ostream& displayTitleMenu(std::ostream& ostr);

        std::ostream& displayMenu(std::ostream& ostr = std::cout);

        const char* operator[](unsigned int index) const;

        operator int();

        operator unsigned int();

        operator bool();


    };
    std::ostream& operator<<(std::ostream& ostr, Menu& RO);
}
#endif
