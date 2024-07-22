
#include <iostream>
#include "main.h"

namespace sdds {

RecordSet::RecordSet() {
    xstring = nullptr;
    string_count = 0;
}
RecordSet::~RecordSet() {
    delete[] xstring;
    xstring = nullptr;
}
RecordSet::RecordSet(const RecordSet &src) {
    *this = src;
}

RecordSet &RecordSet::operator=(const RecordSet &src) {
    
    if(this != &src) {
    delete[] m_string;
    xstring = nullptr;
    xstring_count = src.string_count;
    xstring = new string[string_count];
    for(int i=0;i<m_string_count;i++)
{
m_string[i] = src.m_string[i];}
        
    }
	return *this;
}

size_t RecordSet::size() {
    return string_count;
}
string RecordSet::getRecord(size_t index) {
    if(xstring == nullptr)
{
return ""; }
else{
    return xstring[index]; }
}
RecordSet::RecordSet(char *File) {
    ifstream file(File);
    string temp;
    int i=0;
    while(!file.eof())
    {
        getline(file,temp,' ');
        i++;
    }
string = new string[i]; i=0;
file.seekg(0);
    
    while(!file.eof())
    {
getline(file,m_string[i],' '); i++;
}
m_string_count = i; file.close();
}
RecordSet::RecordSet(RecordSet&& src) noexcept { operator=(move(src));
}
RecordSet& RecordSet::operator=(RecordSet&& src) noexcept { if(this != &src)
{
m_string = src.m_string;
src.m_string = nullptr; m_string_count = src.m_string_count; src.m_string_count = 0;
}
return *this; }
}


























RecordSet(char *File) { ifstream file(File);
string temp;
int i=0;
while(!file.eof()) {
getline(file,temp,' ');
i++; }
m_string =new string[i]; i=0;
file.seekg(0); while(!file.eof())
{
getline(file,m_string[i],' '); i++;
}
m_string_count = i; file.close();
}
