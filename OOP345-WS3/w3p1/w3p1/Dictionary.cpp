

#include "Dictionary.h"
#include <iomanip>
namespace sdds
{
    Dictionary::Dictionary(){}

    bool Dictionary::operator==(const Dictionary &dictobj)
    {
        return (m_term == dictobj.m_term && m_definition == dictobj.m_definition);
    }

    std::ostream &operator<<(std::ostream &out, const Dictionary &dictobj)
    {
        out << std::setw(20) << std::right << dictobj.getTerm() << ": " << dictobj.getDefinition();
        return out;
    }

}

