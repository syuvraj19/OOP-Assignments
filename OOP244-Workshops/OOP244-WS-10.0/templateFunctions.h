//Name: yuvraj singh
//ID: 155580210
//Email: yuvraj-singh5@myseneca.ca
// Date: 5/08/2022
//Section: ZBB

#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"
namespace sdds {

    //Find with 3 parameters
    template <typename T1, typename T2>
    bool find(Collection<T1>& item, int num, T2 key)
    {
        if (item[num] == key)
            return true;
        return false;
    }
    
    //Find with 4 parameters
    template <typename T1, typename T2, typename T3>
    int find(Collection<T1>& item, int size, T2 key1, T3 key2)
    {
        int x=0;
        while (x < size)
        {
            if (item[x] == key1 && item[x] == key2)
            {
                return x;
            }
            x++;
        }
        return -1;
      }
      
    
    //Insertion operator
    template <typename T>
    std::ostream& operator<<(std::ostream& os, Collection<T>& item)
    {
        int x = 0;
        while (x < item.size())
        {
            os << item[x]<<std::endl;
            x++;
        }
        return os;
    }
        
    //Load Collection
    template <typename T>
    Collection<T> loadCollection(Collection<T>& item, T elem)
    {
        item += elem;
        return item;
    }
}
#endif // !SDDS_SEARCH_H_
