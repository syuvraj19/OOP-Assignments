

#ifndef UNIQUEQUEUE_H
#define UNIQUEQUEUE_H
#include "Queue.h"
#include <cmath>
namespace sdds
{
    template <typename T>
    class UniqueQueue : public Queue<T, 100>
    {
    private:
    public:
        bool push(const T &item);
    };

    template <typename T>
    bool UniqueQueue<T>::push(const T &item)
    {
        bool curr = false;

        size_t i = 0;
        while (i < this->size())
        {
            if ((*this)[i] == item)
            {
                curr = true;
                break;
            }
            i++;
        }
        if (!curr)
        {
            return Queue<T, 100>::push(item);
        }
        return false;
    }

    template <>
    bool UniqueQueue<double>::push(const double &item)
    {
        bool curr = false;

        size_t i = 0;
        while (i < this->size())
        {
            if (std::fabs((*this)[i] - item) <= 0.005)
            {
                curr = true;
                break;
            }
            i++;
        }
        if (!curr)
        {
            return Queue<double, 100>::push(item);
        }
        return false;
    }
}
#endif
