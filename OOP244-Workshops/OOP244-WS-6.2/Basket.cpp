/*
*****************************************************************************
                          Workshop - #6 (P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 11/07/2022

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Basket.h"

namespace sdds
{
    Basket::Basket() = default;

    Basket::Basket(Fruit *fruits, int sizeofArr, double b_price)
    {
        if (fruits && sizeofArr > 0)
        {
            m_cnt = sizeofArr;
            m_price = b_price;
            m_fruits = new Fruit[m_cnt];
            int x = 0;
            while ( x < m_cnt)
            {
                m_fruits[x] = fruits[x];
                x++;
            }
        }
    }
    Basket::Basket(const Basket &CopResrc)
    {
        *this = CopResrc;
    }
    Basket &Basket::operator=(const Basket &CopResrc)
    {
        if (this != &CopResrc)
        {

            delete[] m_fruits;
            m_fruits = nullptr;
            m_cnt = 0;
            m_price = 0;
            if (CopResrc.m_fruits && CopResrc.m_cnt > 0)
            {
                m_cnt = CopResrc.m_cnt;
                m_price = CopResrc.m_price;
                m_fruits = new Fruit[m_cnt];
                int x = 0;
                while ( x < m_cnt)
                {
                    m_fruits[x] = CopResrc.m_fruits[x];
                    x++;
                    
                }
            }
        }
        return *this;
    }
    Basket::~Basket()//the destructor
    {
        delete[] m_fruits;
    }
    void Basket::setPrice(double s_price)//updates the m_price attribute to the value received as parameter
    {
        m_price = s_price > 0 ? s_price : m_price;
    }
    Basket::operator bool() const
    {
        return m_cnt > 0;
    }
    Basket &Basket::operator+=(const Fruit Frutz)
    {
        Fruit *StorTmpArr = new Fruit[m_cnt + 1];
        int x = 0;
        while( x < m_cnt )
        {
            StorTmpArr[x] = m_fruits[x];
            x++;
        }
        StorTmpArr[m_cnt] = Frutz;
        delete[] m_fruits;
        m_fruits = StorTmpArr;
        m_cnt++;
        return *this;
    }
    std::ostream &Basket::display(std::ostream &os) const
    {
        if (operator bool())
        {

            os << "Basket Content:" << std::endl;// If the basket contains fruits, print the content in the format:
            int x = 0;
            while ( x < m_cnt)
            {
                os.setf(std::ios::right);
                os.width(10);
                os << m_fruits[x].m_name<<": ";
                os.unsetf(std::ios::right);
                os.setf(std::ios::fixed);
                os.precision(2);
                os<<m_fruits[x].m_qty<<"kg"<<std::endl;
                os.unsetf(std::ios::fixed);
                x++;
            }
            os<<"Price: ";
            os.setf(std::ios::fixed);
            os.precision(2);
            os<<m_price;
            os.unsetf(std::ios::fixed);
            os<<std::endl;
        }
        else
        {
            os << "The basket is empty!" << std::endl;// If the basket doesn't contain any fruit, print the message The basket is empty!<ENDL>.
        }
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const Basket &bskt)
    {
        return bskt.display(os);
    }
}
