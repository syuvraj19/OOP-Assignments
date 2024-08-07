/*
*****************************************************************************
                              milestone - 4
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 5/08/2022

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my project milestones.
*****************************************************************************
*/

#include "Publication.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace sdds {
    
Publication::Publication()
{
    setDefault();
}

Publication::Publication(const Publication& publication)
{
    *this = publication;
}

Publication& Publication::operator=(const Publication& publication)
{
    set(publication.m_membership);
    setRef(publication.m_libRef);
    strcpy(m_shelfId, publication.m_shelfId);
    m_date = publication.m_date;

    if (m_title)
    {
        delete[] m_title;
        m_title = nullptr;
    }

    if (publication.m_title != nullptr)
    {
        m_title = new char[strlen(publication.m_title) + 1];
        strcpy(m_title, publication.m_title);
    }
    else
    {
        m_title = nullptr;
    }

    return *this;
}

Publication::~Publication()
{
    delete[] m_title;
}

void Publication::setDefault()
{
    m_title = nullptr;
    m_shelfId[0] = '\0';
    m_membership = 0;
    m_libRef = -1;
    resetDate();
}

void Publication::set(int member_id)
{
    m_membership = member_id;
}

void Publication::setRef(int value) {
    m_libRef = value;
}

void Publication::resetDate() {
    m_date = Date();
}

char Publication::type() const {
    return 'P';
}

bool Publication::onLoan() const {
    return (m_membership != 0);
}

Date Publication::checkoutDate() const {
    return m_date;
}

bool Publication::operator==(const char* title) const {
    return strstr(m_title, title) != nullptr;
}

Publication::operator const char* () const {
    return m_title;
}

int Publication::getRef() const {
    return m_libRef;
}

bool Publication::conIO(std::ios& io) const {
    return &io == &std::cin || &io == &std::cout;
}
    

std::ostream& Publication::write(std::ostream& os) const
{
    if (conIO(os))
    {
        os << "| " << m_shelfId << " | ";
        int x = 0;
        while(x < SDDS_TITLE_WIDTH)
        {
            if(m_title[x] == '\0')
            {
                break;
            }
            
            else
            {
                os << m_title[x];
            }x++;
        }
        x = x;
        while( x < SDDS_TITLE_WIDTH)
        {
            os << ".";
            x++;
        }
        os << " | ";
        (m_membership != 0) ? os << m_membership : os << " N/A ";
        os << " | " << m_date << " |";
    }
    
    else
    {
        os << type() << "\t";
        os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
        (m_membership != 0) ? os << m_membership : os << " N/A ";
        os << "\t" << m_date;
    }
    
    return os;
}

std::istream& Publication::read(std::istream& is)
{
    char tmp_title[256]{}, tmp_shelfId[SDDS_SHELF_ID_LEN + 1]{};
    int tmp_libRef = -1, tmp_membership = 0;
    Date tmp_date;

    if (m_title)
    {
        delete[] m_title;
        m_title = nullptr;
    }
    setDefault();

    if (conIO(is))
    {
        std::cout << "Shelf No: ";
        is.getline(tmp_shelfId, SDDS_SHELF_ID_LEN + 1);

        if (strlen(tmp_shelfId) != SDDS_SHELF_ID_LEN)
        {
            is.setstate(std::ios::failbit);
        }

        std::cout << "Title: ";
        is.getline(tmp_title, 256);

        std::cout << "Date: ";
        is >> tmp_date;
    }
    
    else {
        is >> tmp_libRef;
        is.ignore();
        is.getline(tmp_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
        is.getline(tmp_title, 256, '\t');
        is >> tmp_membership;
        is.ignore();
        is >> tmp_date;
    }

    if (!tmp_date) {
        is.setstate(std::ios::failbit);
    }

    if (is) {
        m_title = new char[strlen(tmp_title) + 1];
        strcpy(m_title, tmp_title);
        strcpy(m_shelfId, tmp_shelfId);
        m_membership = tmp_membership;
        m_date = tmp_date;
        m_libRef = tmp_libRef;
    }
    return is;
}

Publication::operator bool() const
{
    bool result = false;
    if (m_title != nullptr && m_shelfId[0] != '\0') {
        result = true;
    }
    return result;
    }
}
