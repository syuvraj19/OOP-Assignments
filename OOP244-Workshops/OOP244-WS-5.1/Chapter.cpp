/*
*****************************************************************************
                          Workshop - #5 - P1
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Chapter.h"

using namespace std;
namespace sdds {

void Chapter::init_chapter() {
    m_title[0] = '\0';
    m_num_pages = 0;
    m_num_words = 0;
    m_chapter_number = 0;
}

Chapter::Chapter() {
    init_chapter();}

Chapter::Chapter(const char* title_) {
    init_chapter();
    strcpy(m_title , title_);
}
               
Chapter::Chapter(const char* title_, int chapter_num,  int n_pages, int n_words){
    strcpy(m_title, title_);
    m_chapter_number = chapter_num;
    m_num_pages = n_pages;
    m_num_words = n_words;
}

ostream& Chapter::display(std::ostream& os)const{
    cout.setf(std::ios::left);
    os << "| Chapter ";
    os.width(2);
    os << m_chapter_number << " | ";
    os.width(MAX_CHAPTER_TITLE);
    os << m_title << " |" << endl;
    return os;
}
    
void Chapter::operator = (const Chapter& it){
    strcpy(m_title, it.m_title);
    m_num_pages = it.m_num_pages;
    m_num_words = it.m_num_words;
    m_chapter_number = it.m_chapter_number;
}

int Chapter::operator -- (){
    return --m_num_pages;}
    
int Chapter::operator ++ (){
    return ++m_num_pages;}
}
