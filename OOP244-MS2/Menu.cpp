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
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include"Menu.h"
#include"Utils.h"
using namespace std;
using namespace sdds;

namespace sdds {

    MenuItem::MenuItem() {
        m_contentOfMenu = nullptr;
    };


    MenuItem::MenuItem(const char* content) {

        setContent(content);
    }

    void MenuItem::setContent(const char* content) {

        if (content && content[0])
        {
            m_contentOfMenu = new char[strlen(content) + 1];
            strcpy(m_contentOfMenu, content);
        }
        else
        {
            setEmpty();
        }

    }

    void MenuItem::setEmpty() {
        m_contentOfMenu = nullptr;
    }

    MenuItem::~MenuItem() {

        delete[]m_contentOfMenu;
    };

    MenuItem::operator bool() const {
        return  (m_contentOfMenu && m_contentOfMenu[0]);
    };

    MenuItem::operator const char* () const {

        return m_contentOfMenu;
    };

    ostream& MenuItem::display(ostream& ostr) {

        if (*this)
        {
            ostr << m_contentOfMenu;
        }
        return ostr;
    };


    Menu::Menu() {
        m_noMenuPointers = 0;
    };

    Menu::Menu(const char* title) :m_menuItemTitle(title) {


    };


    Menu::~Menu() {

        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
        {
            delete m_arrOfMenuPointers[i];
        }

    };

    ostream& Menu::displayTitleMenu(ostream& ostr) {

        if (m_menuItemTitle)
        {
            m_menuItemTitle.display();
        }
        return ostr;
    };


    ostream& Menu::displayMenu(ostream& ostr) {

        if (m_menuItemTitle)
        {
            m_menuItemTitle.display();
            //ostr << ":" << endl;
            ostr << endl;
        }
        for (unsigned int i = 0; i < m_noMenuPointers; i++)
        {
            ostr.width(2);
            ostr.setf(ios::right);
            ostr.fill(' ');
            ostr << i + 1 << "- ";
            ostr.unsetf(ios::right);
            m_arrOfMenuPointers[i]->display(ostr);
            ostr << endl;
        }
        ostr << " 0- Exit" << endl;
        ostr << "> ";

        return ostr;
    }


    int Menu::run() {

        unsigned int selectedItem;

        displayMenu();

        selectedItem = getInt(0, m_noMenuPointers, "Invalid Selection, try again: ");

        return selectedItem;
    }

    int Menu::operator~() {

        int selectedItem;

        displayMenu();

        selectedItem = getInt(0, m_noMenuPointers, "Invalid Selection, try again: ");

        return selectedItem;
    };

    Menu& Menu::operator<<(const char* menuitemConent) {

        if (m_noMenuPointers < MAX_MENU_ITEMS)
        {
            MenuItem* newMenuItem = new MenuItem(menuitemConent);

            m_arrOfMenuPointers[m_noMenuPointers] = newMenuItem;

            m_noMenuPointers++;
        }

        return *this;
    };

    Menu::operator int() {

        return m_noMenuPointers;
    };

    Menu::operator unsigned int() {

        return m_noMenuPointers;
    };

    Menu::operator bool() {

        return(m_noMenuPointers);
    }

    const char* Menu:: operator[](unsigned int index) const {

        if (index > m_noMenuPointers)
        {
            return(m_arrOfMenuPointers[index %= m_noMenuPointers]->m_contentOfMenu);
        }

        return(m_arrOfMenuPointers[index]->m_contentOfMenu);

    }

    ostream& operator<<(ostream& ostr, Menu& RO) {
        return(RO.displayTitleMenu(ostr));
    };
}
