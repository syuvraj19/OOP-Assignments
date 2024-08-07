

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Dictionary.h"
namespace sdds
{
    template <typename T, size_t CAPACITY>
    class Queue
    {
    private:
        T arrays[CAPACITY];
        size_t n;
        static T dmy;

    public:
        Queue() : arrays{}
        {
            n = 0;
        }

        virtual bool push(const T &item)
        {
            if (n < CAPACITY)
            {
                arrays[n] = item;
                n++;
                return true;
            }
            return false;
        }

        T pop()
        {
            T temp = arrays[0];
            size_t i = 0;
            while (i < n - 1)
            {
                arrays[i] = arrays[i + 1];
                i++;
            }
            if (n > 0)
                n--;
            return temp;
        }

        size_t size()
        {
            return n;
        }
        
        void display(std::ostream &out = std::cout)
        {
            out << "----------------------" << std::endl;
            out << "| Dictionary Content |" << std::endl;
            out << "----------------------" << std::endl;
            size_t i = 0;
            while (i < n)
            {
                out << arrays[i] << std::endl;
                i++;
            }

            out << "----------------------" << std::endl;
        }

        T operator[](size_t ind)
        {
            if (ind >= n)
            {
                return dmy;
            }
            return arrays[ind]; 
        }

        virtual ~Queue(){}
    };

    template <typename T, size_t CAPACITY>
    T Queue<T, CAPACITY>::dmy = T();

    template <>
    sdds::Dictionary Queue<sdds::Dictionary, 100>::dmy = Dictionary("Empty Term", "Empty Substitute");
}

#endif
