// Name: yuvraj singh
// Seneca Student ID: 155580210
// Seneca email: yuvraj-singh5@myseneca.ca
// Date of completion: 17/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>

using namespace std;

namespace sdds {

    class Utilities {
        size_t m_widthField = 1; //specifies the length of the token extracted; used for display purposes; default value is 1
        static char m_delimiter;// separates the tokens in any given std::string object.

    public:
        void setFieldWidth(size_t newWidth);// sets the field width of the current object to the value of parameter newWidth.
        static char getDelimiter();// returns the delimiter for this class.
        size_t getFieldWidth();//returns the field width of the current object.
        string extractToken(const string& str, size_t& next_pos, bool& more); //extracts a token from string str referred to by the first parameter.
        static void setDelimiter(char newDelimiter); //sets the delimiter for this class to the character received.
    };
}
#endif

