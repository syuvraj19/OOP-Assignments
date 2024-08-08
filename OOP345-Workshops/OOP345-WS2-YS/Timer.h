/*
*****************************************************************************
                          Workshop - #2(P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 25/09/2022
 
 I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <iostream>
#include <chrono>

namespace sdds
{
    class Timer
    {
        std::chrono::time_point<std::chrono::steady_clock,std::chrono::duration<double, std::ratio<1>>>m_startTime;
        std::chrono::time_point<std::chrono::steady_clock,std::chrono::duration<double, std::ratio<1>>>m_endTime;
    public:
        void start();
        long long stop();
    };
}
#endif
