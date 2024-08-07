

#define _CRT_SECURE_NO_WARNINGS
#include "carads.h"
#include <iostream>
#include <string>
#include <iomanip>

double g_taxrate,g_discount;

namespace sdds {
    int Cars::counter = 1;

    Cars::Cars()
    {
        this->Brand[0] = '\0';
        this->Model[0] = '\0';
        this->price = -1;
        this->status = '0';
        this->DiscStatus = '0';
        this->flag = false;
        this->Year = -1;
    }

    void Cars::read(std::istream& is)
    {
        this->Brand[0] = '\0';
        this->Model[0] = '\0';
        this->price = -1;
        this->status = '0';
        this->DiscStatus = '0';
        this->flag = false;
        this->Year = -1;

        if (is.good()) {
            is >> this->status;

            if (is.peek() == ',')
            {
                is.get();
            }
            else
            {
                is.setstate(std::ios::failbit);
            }

            is.getline(this->Brand, 10, ',');
            is.getline(this->Model, 15, ',');
            is >> Year;
            is.get();
            is >> price;
            is.get();
            is >> this->DiscStatus;
            is.get();
        }

    }

    char Cars::getStatus()
    {
        return this->status;
    }

    void listArgs(int argc, char* argv[])
    {
        std::cout << "Command Line:" << std::endl;
        std::cout << "--------------------------" << std::endl;
        for (int i = 0; i < argc; i++) {
            std::cout <<"  "<<i + 1 << ": " << argv[i] << std::endl;
        }
        std::cout << "--------------------------\n" << std::endl;
    }

    void Cars::display(bool reset)
    {
        if (reset) {
            counter = 1;
        }

        double PriceWTax = (price * g_taxrate) + price;
        std::cout << std::left << std::setw(2) << counter++ << ". ";

        if (this->Brand[0] != '\0')
        {
            std::cout << std::left << std::setw(10) << this->Brand;
            std::cout << "| " << std::left << std::setw(15) << this->Model;
            std::cout << "| " << this->Year;
            std::cout << " |" << std::right << std::setw(12) << std::setprecision(2) << std::fixed << PriceWTax;

            if (this->DiscStatus == 'Y')
            {
                double SpecialPrice = PriceWTax - (PriceWTax * g_discount);
                std::cout << "|" << std::right << std::setw(12) << std::setprecision(2) << std::fixed << SpecialPrice;
            }
            else
            {
                std::cout << "|";
            }

        }
        else
        {
            std::cout << "No Order";

        }

        std::cout << std::endl;

    }

    
}
