/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 09 JUNE 2022
WORKSHOP 4 PART 1

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
class Car{
    void resetInfo();

    public:
    char* m_type;
    char* m_brand;
    char* m_model;
    int m_year;
    int m_code;
    double m_price;
    Car();
    Car(const char* type, 
    const char* brand, 
    const char* model, 
    int year, 
    int code, 
    double price);
    Car(const char* type, 
    const char* brand, 
    const char* model);
    ~Car();
    Car& setInfo(const char* type, 
             const char* brand, 
             const char* model, 
             int year, 
             int code, 
             double price);

    void printInfo() const;
    bool isValid() const;
    bool isSimilarTo(const Car& car) const;

};

namespace sdds{
bool has_similar(const Car car[], const int num_cars);
bool has_invalid(const Car car[], const int num_cars);
void print(const Car car[], const int num_cars);

}
