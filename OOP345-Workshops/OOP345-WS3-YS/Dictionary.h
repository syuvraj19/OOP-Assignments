/*
*****************************************************************************
                          Workshop - #3(P2)
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Date       : 02/10/2022
 
 I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
namespace sdds
{
  class Dictionary
  {
    std::string m_term{};
    std::string m_definition{};

  public:
    const std::string &getTerm() const { return m_term; }
    const std::string &getDefinition() const { return m_definition; }
    Dictionary(const std::string &term, const std::string &definition) : m_term{term}, m_definition{definition} {}
    Dictionary();
    bool operator==(const Dictionary &dictobj);
    friend std::ostream &operator<<(std::ostream &out, const Dictionary &dictobj);
  };
}
#endif

