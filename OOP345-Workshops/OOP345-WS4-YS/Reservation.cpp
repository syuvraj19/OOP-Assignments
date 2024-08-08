/*
*****************************************************************************
                          Workshop - #4(P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 09/10/2022
 
*****************************************************************************
*/

#include "Reservation.h"
using namespace std;
namespace sdds
{
    string tokenExtractSpaceRemover(string &str, char terminator)
    {
        int termIdx = str.find(terminator);
        string res = str.substr(0, termIdx);
        str.erase(0, termIdx + 1);
        res.erase(0, res.find_first_not_of(' '));
        res.erase(res.find_last_not_of(' ') + 1);
        return res;
    }
    Reservation::Reservation() {}
    void Reservation::update(int day, int time)
    {
        p_day = day;
        p_hour = time;
    }
    Reservation::Reservation(const string &yuv)
    {
        string record = yuv;
        res_Id = tokenExtractSpaceRemover(record, ':');
        res_name = tokenExtractSpaceRemover(record, ',');
        res_email = tokenExtractSpaceRemover(record, ',');
        noOfPeople = stoi(tokenExtractSpaceRemover(record, ','));
        p_day = stoi(tokenExtractSpaceRemover(record, ','));
        p_hour = stoi(tokenExtractSpaceRemover(record, ','));
    }
    ostream &operator<<(ostream &os, const Reservation &res_ob)
    {
        os << "Reservation ";
        os.width(10);
        os << right << res_ob.res_Id << ": ";
        os.width(20);
        os << right << res_ob.res_name << "  ";
        os.width(20);
        os << left << ("<" + res_ob.res_email + ">") << "    ";
        if (res_ob.p_hour >= 6 && res_ob.p_hour <= 9)
        {
            os << "Breakfast";
        }
        else if (res_ob.p_hour >= 11 && res_ob.p_hour <= 15)
        {
            os << "Lunch";
        }
        else if (res_ob.p_hour >= 17 && res_ob.p_hour <= 21)
        {
            os << "Dinner";
        }
        else
        {
            os << "Drinks";
        }
        os << " on day " << res_ob.p_day;
        os << " @ " << res_ob.p_hour << ":00";
        os << " for " << res_ob.noOfPeople;
        if (res_ob.noOfPeople == 1)
        {
            os << " person";
        }
        else
        {
            os << " people";
        }
        os << "." << endl;
        return os;
    }
}
