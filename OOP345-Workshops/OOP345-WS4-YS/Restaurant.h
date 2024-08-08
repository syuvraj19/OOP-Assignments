/*
*****************************************************************************
                          Workshop - #4(P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 09/10/2022
 
*****************************************************************************
*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include <string>
#include "Reservation.h"
namespace sdds
{
    class Restaurant
    {
        Reservation **m_ptrArr{nullptr};
        size_t m_elements{0u};

    public:
        Restaurant(const Reservation *reservations[], size_t cnt);
        Restaurant(const Restaurant &res_obj);
        Restaurant &operator=(const Restaurant &res_obj);
        Restaurant(Restaurant &&obj) noexcept;
        Restaurant &operator=(Restaurant &&res_obj) noexcept;
        ~Restaurant();
        size_t size() const;
        friend std::ostream &operator<<(std::ostream &ostr, const Restaurant &res_obj);
    };
}
#endif // !SDDS_RESTAURANT_H

