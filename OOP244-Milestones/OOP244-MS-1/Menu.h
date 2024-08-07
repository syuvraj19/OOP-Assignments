/*
*****************************************************************************
                              milestone - 1
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds {

    const int MAX_MENU_ITEMS = 20;

    class Menu;

    class MenuItem { //A class that hold a text Item; (an option or title to be displayed) in a menu to be selected by the user. This is a fully private class that is only accessible by Menu 

        char* s_desc;

        MenuItem(const char* d = nullptr);
        ~MenuItem();
        MenuItem(const MenuItem& dup1) = delete;
        MenuItem& operator=(const MenuItem& dup1) = delete;
        operator bool()const;
        operator const char*()const;
        std::ostream& display(std::ostream& os)const;

        friend Menu;
    };

    class Menu { //A class that has several MenuItems to be displayed so the user can select one of them for an action to be executed in the program

        MenuItem* s_tit;
        MenuItem* listofitems[MAX_MENU_ITEMS];
        int s_alloc;

    public:
        
        Menu(const Menu& dup1) = delete;
        
        Menu& operator=(const Menu& dup1) = delete;
        
        Menu(const char* title="");
        
        virtual ~Menu();
        
        std::ostream& displayTitle(std::ostream& os = std::cout)const;
        
        std::ostream& displayAllMenu(std::ostream& os = std::cout)const;
        
        unsigned int operator~();
        
        Menu& operator<<(const char* tmp);
        
        unsigned int run();
        
        operator bool()const;
        
        operator unsigned int()const;
        
        const char* operator[](int cnt)const;
        
    };

    std::ostream& operator<<(std::ostream& os, const Menu& stor);
}

#endif
