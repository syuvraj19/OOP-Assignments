/*
*****************************************************************************
                          Workshop - #4 (P1)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 08/06/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
namespace sdds{
    class Car{
        private:
        char *m_type;
        char *m_brand;
        char *m_model;
        int m_year;
        int m_code;
        double m_price;

        public:
        Car();
        
        Car(const char *type, const char *brand, const char *model, int year = 2022, int code = 100, double price = 1);
        
        ~Car();
        
        Car& setInfo(const char *type, const char *brand, const char *model,int yera,int code, double price);
        
        bool isValid() const;
        
        void printInfo() const;
        
        void resetInfo();
        
        bool isSimilarTo(const Car& car) const;
    };
    bool has_similar(const Car car[], const int num_cars);

    bool has_invalid(const Car car[], const int num_cars);

    void print(const Car car[], const int num_cars);
}
#endif 
