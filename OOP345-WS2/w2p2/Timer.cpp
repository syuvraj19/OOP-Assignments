

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
