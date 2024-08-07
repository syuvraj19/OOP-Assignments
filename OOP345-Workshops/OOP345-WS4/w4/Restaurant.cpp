

#include <iostream>
#include "Restaurant.h"
using namespace std;
namespace sdds
{
    Restaurant::Restaurant(const Reservation *reservations[], size_t cnt)
    {
        m_elements = cnt;
        m_ptrArr = new Reservation *[m_elements];
        for (size_t i = 0; i < m_elements; i++)
            m_ptrArr[i] = new Reservation (*reservations[i]);
    }

    Restaurant::Restaurant(const Restaurant &obj)
    {
        m_ptrArr = nullptr;
        *this = obj;
    }
    Restaurant &Restaurant::operator=(const Restaurant &res_obj)
    {
        if (this != &res_obj)
        {
            for (size_t i = 0; i < m_elements; i++)
            {
                delete m_ptrArr[i];
            }
            delete[] m_ptrArr;
            m_elements = res_obj.m_elements;
            if (res_obj.m_ptrArr != nullptr)
            {
                m_ptrArr = new Reservation *[m_elements];
                for (size_t i = 0; i < m_elements; i++)
                {
                    m_ptrArr[i] = new Reservation(*res_obj.m_ptrArr[i]);
                }
            }
            else
            {
                m_ptrArr = nullptr;
            }
        }
        return *this;
    }
    Restaurant::Restaurant(Restaurant &&res_obj) noexcept
    {
        *this = move(res_obj);
    }
    Restaurant &Restaurant::operator=(Restaurant &&res_obj) noexcept
    {
        if (this != &res_obj)
        {
            for (size_t i = 0; i < m_elements; i++)
            {
                delete m_ptrArr[i];
            }
            delete[] m_ptrArr;
            m_ptrArr = res_obj.m_ptrArr;
            m_elements = res_obj.m_elements;
            for (size_t i = 0; i < m_elements; i++)
            {
                m_ptrArr[i] = res_obj.m_ptrArr[i];
            }
            res_obj.m_ptrArr = nullptr;
            res_obj.m_elements = 0u;
        }
        return *this;
    }
    size_t Restaurant::size() const
    {
        return m_elements;
    }
    Restaurant::~Restaurant()
    {
        for (size_t i = 0; i < m_elements; i++)
        {
            delete m_ptrArr[i];
        }
        delete[] m_ptrArr;
    }


    std::ostream &operator<<(std::ostream &os, const Restaurant &res_obj)
    {
        static size_t counter = 1;
        os.fill('-');
        os.width(26);
        os << "-";
        os.fill(' ');
        os << "\nFancy Restaurant (" << counter++ << ")\n";
        os.fill('-');
        os.width(26);
        os << "-";
        os.fill(' ');
        os << endl;
        if (res_obj.m_elements > 0)
        {
            for (size_t i = 0; i < res_obj.m_elements; i++)
                os << *res_obj.m_ptrArr[i];
        }
        else
        {
            os << "This restaurant is empty!\n";
        }
        os.fill('-');
        os.width(26);
        os << "-";
        os.fill(' ');
        os << endl;
        return os;
    }
}

