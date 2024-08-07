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
#include <iomanip>
using namespace std;
namespace sdds {

    MenuItem::MenuItem() //Constructor
    {
        m_menuProds = nullptr;
    }

    MenuItem::MenuItem(const char* prod)
    {
        delete[] m_menuProds;
        m_menuProds = new char[strlen(prod) + 1];
        strcpy(m_menuProds, prod);
    }

    MenuItem::~MenuItem() //Destructor
    {
        delete[] m_menuProds;
    }

    MenuItem::operator bool() const
    {

        if (m_menuProds != nullptr) return true;

        return false;
    }

    void MenuItem::display()
    {
        std::cout << m_menuProds;
    }

    Menu::Menu()
    {
        int x = 0;
        while (x < MAX_MENU_ITEMS)
        {
            m_prods[x] = NULL;
            x++;
        }
        m_menuTitle = nullptr;
        num_menu = 0;
    }

    Menu::Menu(const char* m_title)
    {
        int x = 0;
        while ( x < MAX_MENU_ITEMS)
        {
            m_prods[x] = NULL;
            x++;
        }
        delete[] m_menuTitle;
        m_menuTitle = new char[strlen(m_title) + 1];
        strcpy(m_menuTitle, m_title);
    }

    Menu::~Menu()
    {
        delete[] m_menuTitle;
        int x = 0;
        while ( x < num_menu)
        {
            delete m_prods[x];
            x++;
            
        }
    }

    void Menu::display()
    {
        if (m_menuTitle != nullptr)
            cout << m_menuTitle << "\n";

        for (int x = 0; x < num_menu; x++)
            cout << " " << x + 1 << "- " << m_prods[x]->m_menuProds << endl;

        cout << " 0- Exit\n> ";
    }

    int Menu::run()
    {
        display();
        char er;
        cin >> er;
        int a = er - '0';
        while (a  < 0 || a > num_menu)
        {

            cin.clear(); //clear bad input flag
            cin.ignore(80, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> er;
            a = er - '0';
        }

        return a;

    }

    Menu::operator bool() const
    {
        if (m_menuTitle == nullptr) return false;
        return true;
    }

    int Menu::operator~()
    {
        display();
        char er;
        cin >> er;

        int a = er - '0';
        while (a  < 0 || a > num_menu)
        {
            cin.clear(); //clear bad input flag
            cin.ignore(80, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> er;
            a = er - '0';
        }
        return a;
    }

    Menu& Menu::operator<<(const char* ProdsMenucont)
    {
        m_prods[num_menu++] = new MenuItem(ProdsMenucont);
        return *this;
    }

    std::ostream& Menu::write(std::ostream& out)const
    {
        if (m_menuTitle != nullptr)
            out << m_menuTitle;
        return out;
    }

    std::ostream& operator<<(std::ostream& s, const Menu& menu)
    {
        return menu.write(s);
    }

    Menu::operator unsigned int() const
    {
        return num_menu;
    }

    char* Menu::operator[](int x) const
    {
        return m_prods[x]->m_menuProds;
    }

}

