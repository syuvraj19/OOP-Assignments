/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.ca
DATE CREATED ON : 13 JUNE 2022
WORKSHOP 4 Part-2

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
/* ------------------------------------------------------
Workshop 4 part 2
Module: N/A
Filename: main.cpp
Version 1.0
Author: Asad Norouzi
-----------------------------------------------------------*/
#include <iostream>
#include "CleanerBot.h"

using namespace std;
using namespace sdds;

int main()
{
	const int num_bots = 8;
	CleanerBot bot[num_bots] = {
		{},
		{"library", 82.5, 7, false},
		{"corridor", 75, 3, true},
		{"pantry", 23.6, 12, false},
		{"parking", 30.1, 9, true},
		{"storage", 57, 2, true},
		{"?", -1, 1, false},
		{"basement", 29.9, 1, true}
	};

	report(bot, num_bots);

	return 0;
}
