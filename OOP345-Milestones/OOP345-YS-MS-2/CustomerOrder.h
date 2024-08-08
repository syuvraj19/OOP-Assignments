// Name: yuvraj singh
// Seneca Student ID: 155580210
// Seneca email: yuvraj-singh5@myseneca.ca
// Date of completion: 24/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <string>
#include "Station.h"

namespace sdds {

    struct Item {
        std::string m_itemName;
        size_t m_serialNo{ 0 };
        bool m_isFilled{ false };

        Item(const std::string& src) : m_itemName(src)
        {};
    };

    class CustomerOrder {
        std::string m_name;
        std::string m_item;
        size_t m_cntItem;
        Item** m_lstItem;

        static size_t m_widthField;

    public:
        CustomerOrder();
        CustomerOrder(const std::string& str);

        CustomerOrder(const CustomerOrder&) {
            throw "Copying Disabled";
        };
        CustomerOrder& operator=(const CustomerOrder&) = delete;
        CustomerOrder(CustomerOrder&& src) noexcept;
        CustomerOrder& operator=(CustomerOrder&& src) noexcept;
        virtual ~CustomerOrder();

        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;
    };
}

#endif //SDDS_CUSTOMERORDER_H
