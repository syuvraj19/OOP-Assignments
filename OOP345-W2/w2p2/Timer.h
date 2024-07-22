
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
