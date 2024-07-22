/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 07 AUGUST 2022
MILESTONE 5

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_MARK_H
#define SDDS_MARK_H

#include <iostream>

namespace sdds {

    const int MAX_MENU_ITEMS = 20;

    class Menu;

    class MenuItem {

        char* sen_description;

        MenuItem(const char* desc = nullptr);
        ~MenuItem();
        MenuItem(const MenuItem& copy1) = delete;
        MenuItem& operator=(const MenuItem& copy1) = delete;
        operator bool()const;
        operator const char*()const;
        std::ostream& display(std::ostream& os)const;

        friend Menu;
    };

    class Menu {

        MenuItem* sen_title;
        MenuItem* sen_itemLists[MAX_MENU_ITEMS];
        int sen_allocated;

    public:
        Menu(const Menu& copy1) = delete;
        Menu& operator=(const Menu& copy1) = delete;
        Menu(const char* title="");
        virtual ~Menu();
        std::ostream& displayTitle(std::ostream& os = std::cout)const;
        std::ostream& displayAllMenu(std::ostream& os = std::cout)const;
        unsigned int run();
        unsigned int operator~();
        Menu& operator<<(const char* variable1);
        operator unsigned int()const;
        operator bool()const;
        const char* operator[](int index)const;
    };

    std::ostream& operator<<(std::ostream& os, const Menu& var1);
}

#endif
