/*Name           : yuvraj singh
  Student Number : 155580210
  Student Email  : yuvraj-singh5@myseneca.ca
  Section        : OOP244-ZBB
  Date completed : 20th may 2022
 
  I have done all the coding by myself and only copied the code
  that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds{

    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);

}
#endif
