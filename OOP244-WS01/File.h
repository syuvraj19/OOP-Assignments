/*Name           : yuvraj singh
  Student Number : 155580210
  Student Email  : yuvraj-singh5@myseneca.ca
  Section        : OOP244-ZBB
  Date completed : 20th may 2022
 
  I have done all the coding by myself and only copied the code
  that my professor provided to complete my workshops and assignments.*/

#ifndef   SDDS_FILE_H
#define   SDDS_FILE_H
#include "ShoppingRec.h"
#include <iostream>

namespace sdds{

    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif
