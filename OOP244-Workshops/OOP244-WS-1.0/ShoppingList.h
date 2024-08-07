
/*Name           : yuvraj singh
  Student Number : 155580210
  Student Email  : yuvraj-singh5@myseneca.ca
  Section        : OOP244-ZBB
  Date completed : 20th may 2022
 
  I have done all the coding by myself and only copied the code
  that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

namespace sdds {

    bool loadList();
    void displayList();
    void removeBoughtItems();
    void removeItem(int index);
    bool saveList();
    void clearList();
    void toggleBought();
    void addItemToList();
    void removeItemfromList();
    bool listIsEmpty();

}

#endif
