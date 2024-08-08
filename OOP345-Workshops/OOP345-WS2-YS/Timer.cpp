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

#include "Timer.h"
using namespace std;
namespace sdds
{
    void Timer::start()
    {
        m_startTime = chrono::steady_clock::now();
    }
    long long Timer::stop()
    {
        m_endTime = chrono::steady_clock::now();
        return chrono::duration_cast<chrono::nanoseconds>(m_endTime - m_startTime).count();
    }
}
