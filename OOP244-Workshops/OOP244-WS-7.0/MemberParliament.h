/*
*****************************************************************************
                          Workshop - #7 (P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 17/07/22

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_MEMBERPARLIAMENT_H_
#define SDDS_MEMBERPARLIAMENT_H_
#include <iostream>

namespace sdds {
    class MemberParliament {
        
        char ID[32+1];//The parliament id number as a statically allocated array of characters of size 32.
        
        char Dis[64+1];//The district the MP represents as a statically allocated array of characters of size 64.
        
        int Age;//The age of the MP.
        
    public:
        MemberParliament(const char*, int); //A custom constructor that receives as parameters the MP Id and age. Set the district the MP represents as Unassigned. Assume all data is valid.
        
        void NewDistrict(const char* New_Dis); //assigns the MP to new district. Prints to the screen the message
        
        std::ostream& write(std::ostream& os) const ;// a query that inserts into os the content of the object in the format
        
        std::istream& read(std::istream& in);//a mutator that reads from the stream in the data for the current object
        
    };
    std::ostream& operator<<(std::ostream& os, const MemberParliament& Mem_Par);

    std::istream& operator>>(std::istream& in, MemberParliament& Mem_Par);

}
#endif

