
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>

using namespace std;

namespace sdds {

    class Utilities {

        size_t m_widthField = 1;

        static char m_delimiter;

    public:

        void setFieldWidth(size_t newWidth);
        static char getDelimiter();
        size_t getFieldWidth();
        string extractToken(const string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
    };
}
#endif
