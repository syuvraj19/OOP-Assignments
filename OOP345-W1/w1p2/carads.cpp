

#include "carads.h"

using namespace std;

double g_taxrate = 0.13,g_discount = 0.05;

namespace sdds
{
    Cars::Cars()
    {
        Price = 0;
        status = '\0';
        Model[0] = '\0';
        Year = 0;
        DiscStatus = false;
        Brand = nullptr;
    }
    Cars::Cars(const Cars &PresentCar)
    {
        if (PresentCar.Brand == nullptr)
        {
            Brand = nullptr;
        }
        else
        {
            Brand = new char[strlen(PresentCar.Brand) + 1];
            strcpy(Brand, PresentCar.Brand);
        }
        status = PresentCar.status;
        Year = PresentCar.Year;
        DiscStatus = PresentCar.DiscStatus;
        Price = PresentCar.Price;
        strcpy(Model, PresentCar.Model);
    }

    Cars &Cars::operator=(const Cars &PresentCar)
    {
        if (this != &PresentCar)
        {
            if (Brand == nullptr)
            {
                Brand = nullptr;
            }
            else
            {
                delete[] Brand;
                Brand = nullptr;
            }
            if (PresentCar.Brand != nullptr)
            {
                Brand = new char[strlen(PresentCar.Brand) + 1];
                strcpy(Brand, PresentCar.Brand);
            }
            strcpy(Model, PresentCar.Model);
            Price = PresentCar.Price;
            status = PresentCar.status;
            DiscStatus = PresentCar.DiscStatus;
            Year = PresentCar.Year;
        }
        return *this;
    }

    void Cars::display(bool reset)
    {
        static int count = 0;
        if (reset)
        {
            count = 0;
        }
        count++;
        cout << setw(2) << left << count << ". ";
        if (Brand[0] != '\0')
        {
            double priceWTax = Price * (1 + g_taxrate);
            double SpecialPrice = priceWTax * (1 - g_discount);
            cout << setw(10) << left << Brand << "| ";
            cout << setw(15) << left << Model << "| ";
            cout << setw(4) << right << Year << " |";
            cout << setw(12) << right << fixed << setprecision(2) << priceWTax << "|";
            if (DiscStatus)
            {
                cout << setw(12) << right << fixed << setprecision(2) << SpecialPrice;
            }
            cout << endl;
        }
        else
        {
            cout << "No Car" << endl;
        }
    }

    void Cars::read(istream &in)
    {
        if (!in.good())
        {
            return;
        }
        else
        {
            
            if (Brand != nullptr)
            {
                delete[] Brand;
            }
            Brand = nullptr;
            string line;
            in >> status;
            in.ignore(1000, ',');
            getline(in, line, ',');
            Brand = new char[strlen(line.c_str()) + 1];
            strcpy(Brand, line.c_str());
            in.getline(Model, 15, ',');
            in >> Year;
            in.ignore(1000, ',');
            in >> Price;
            in.ignore(1000, ',');
            
            char SpecialPrice;
            in >> SpecialPrice;
            if (in.peek() == '\n')
                in.ignore();
            
            if (SpecialPrice == 'Y')
                DiscStatus = true;
            else
                DiscStatus = false;
        }
    }

    char Cars::getStatus()
    {
        return status;
    }
    Cars::operator bool()
    {
        return status == 'N';
        
    }

    istream &operator>>(istream &is, Cars &car)
    {
        car.read(is);
        return is;
    }

    void operator>>(const Cars &car1, Cars &car2)
    {
        car2 = car1;
    }

    void listArgs(int argc, char* argv[])
    {
        cout << "Command Line:\n";
        cout << "--------------------------\n";
        for (int i = 0; i < argc; i++)
        {
            cout << setw(3)
                << i + 1 << ": "
                << argv[i] << endl;
        }
        cout << "--------------------------\n\n";
    }

    Cars::~Cars()
    {
        if (Brand != nullptr)
            delete[] Brand;
        Brand = nullptr;
    }

}
