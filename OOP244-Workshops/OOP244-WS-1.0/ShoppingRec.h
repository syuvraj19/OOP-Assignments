/*Name           : yuvraj singh
  Student Number : 155580210
  Student Email  : yuvraj-singh5@myseneca.ca
  Section        : OOP244-ZBB
  Date completed : 20th may 2022
 
  I have done all the coding by myself and only copied the code
  that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_SHOPPINGREC_HPP__
#define SDDS_SHOPPINGREC_HPP__

const int MAX_TITLE_LENGTH = 50;
const int MAX_QUANTITY_VALUE = 50;

struct ShoppingRec {
   char m_title[MAX_TITLE_LENGTH + 1];
   int m_quantity;
   bool m_bought;
};

namespace sdds {

    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}

#endif
