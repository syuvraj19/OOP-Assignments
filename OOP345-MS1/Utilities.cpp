
#include "Utilities.h"
#include <iostream>

using namespace std;

namespace sdds
{
    string whitespace = " \n\r\t\f\v";

    string ltrim(string& str)
    {
        size_t fist = str.find_first_not_of(whitespace);

        return (fist == string::npos) ? "" : str.substr(fist);
    }

    char Utilities::m_delimiter{};

    void Utilities::setFieldWidth(size_t width_newly)
    {
        m_widthField = width_newly;
    }

    size_t Utilities::getFieldWidth()
    {

        return m_widthField;
    }
    string Utilities::extractToken(const string& my_str, size_t& next_pos, bool& more)
    {

        size_t idx = (my_str.find(getDelimiter(), next_pos));

        string etc = my_str.substr(next_pos, idx - next_pos);

        etc = ltrim(etc);

        if (idx == next_pos)
        {
            more = false;

            throw string("Failed to find the delimiter");
        }

        next_pos = idx + 1;

        setFieldWidth(max(m_widthField, etc.size()));

        more = idx != string::npos;

        return etc;
    }
    void Utilities::setDelimiter(char Delimiter_newly)
    {
        m_delimiter = Delimiter_newly;
    }

    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }

}
