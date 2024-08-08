/*
*****************************************************************************
                          Workshop - #4(P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 09/10/2022
 
*****************************************************************************
*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <string>
namespace sdds
{
    class Reservation
    {
    private:
        std::string res_Id{};
        std::string res_name{};
        std::string res_email{};
        std::size_t noOfPeople{0u};
        std::size_t p_day{0u};
        std::size_t p_hour{0u};

    public:
        Reservation();
        void update(int day, int time);
        Reservation(const std::string &res_ob);
        friend std::ostream &operator<<(std::ostream &ostr, const Reservation &obj);
    };
}
#endif // !SDDS_RESERVATION_H

