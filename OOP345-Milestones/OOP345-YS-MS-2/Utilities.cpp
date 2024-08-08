// Name: yuvraj singh
// Seneca Student ID: 155580210
// Seneca email: yuvraj-singh5@myseneca.ca
// Date of completion: 24/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
#include <iostream>

using namespace std;

namespace sdds
{
    string whitespace = " \n\r\t\f\v";

    string ltrim(string& str)
    {
        size_t lstr = str.find_first_not_of(whitespace);

        return (lstr == string::npos) ? "" : str.substr(lstr);
    }

    char Utilities::m_delimiter{};

    void Utilities::setFieldWidth(size_t new_Width)
    {
        m_widthField = new_Width;
    }

    size_t Utilities::getFieldWidth()
    {
        return m_widthField;
    }

    string Utilities::extractToken(const string& et_str, size_t& next_pos, bool& more)
    {

        size_t pos = (et_str.find(getDelimiter(), next_pos));

        string etk = et_str.substr(next_pos, pos - next_pos);

        etk = ltrim(etk);

        if (pos == next_pos)
        {
            more = false;

            throw string("Failed to find the delimiter");
        }

        next_pos = pos + 1;

        setFieldWidth(max(m_widthField, etk.size()));

        more = pos != string::npos;

        return etk;
    }

    void Utilities::setDelimiter(char new_Delimiter)
    {
        m_delimiter = new_Delimiter;
    }

    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }

}

