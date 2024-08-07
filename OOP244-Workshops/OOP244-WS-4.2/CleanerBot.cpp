/*
*****************************************************************************
                          Workshop - #4 (P2)
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

#include "CleanerBot.h"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

CleanerBot::CleanerBot() {
  this->location = new char[2];
  strcpy(this->location, "?");

  this->battery = -1;
  this->active = false;
  this->brush = 0;

}

CleanerBot::CleanerBot(const char *location, double battery, int brushes, bool act){
  this->location = new char[strlen(location) + 1];
  strcpy(this->location, location);
  this->battery = battery;
  this->brush = brushes;
  this->active = act;
}

void CleanerBot::set(const char *location, double battery, int brushes, bool act) {
  this->location = new char[strlen(location) + 1];
  strcpy(this->location, location);
  this->battery = battery;
  this->brush = brushes;
  this->active = act;
  delete[] location;
}

CleanerBot::~CleanerBot() { delete[] this->location; }

void CleanerBot::display() {
  cout << left << "| " << setw(9) << location << right << "  |  " << fixed
       << setprecision(1) << setw(6) << battery << " |  " << setw(17) << brush
       << " | " << left << setw(6) << (active ? "YES" : "NO") << " |" << endl;
}

void CleanerBot::setLocation(char *location) {
  strcpy(this->location, location);
}

void CleanerBot::setActive(bool act) { this->active = act; }

double CleanerBot::getBattery() { return this->battery; }

char *CleanerBot::getLocation() { return this->location; }

bool CleanerBot::isActive() { return this->active; }

int CleanerBot::getBrush() { return this->brush; }

bool CleanerBot::isValid() {
  if (strcmp(this->location, "?") == 0 || this->battery < 0 ||
      this->brush < 1) {
    return false;
  }

  return true;
}

namespace sdds {
int report(CleanerBot *bots, short num_bots) {
  cout << "         ------ Cleaner Bots Report -----" << endl;
  cout << "     ---------------------------------------" << endl;
  cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
  cout << "|------------+---------+--------------------+--------|" << endl;
  int notmuchcharge = 0, x = 0;
    
  while( x < num_bots) {
    if (bots[x].isValid()) {
      bots[x].display();

      if (bots[x].getBattery() < 30) {
          notmuchcharge += 1;
      }
    }x++;
  }

  cout << endl << "|====================================================|" << endl;
  cout << "| LOW BATTERY WARNING:                               |" << endl;
  cout << "|====================================================|" << endl;
  cout << "| Number of robots to be charged: " << notmuchcharge
       << "                  |" << endl;
  cout << "| Sorting robots based on their available power:     |" << endl;

    cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
    cout << "|------------+---------+--------------------+--------|" << endl;

  char *nploc;
  int npbrush;
double standbybatry;
  bool npactive;

    for (int x = 0; x < num_bots; x++) {
        int y=0;
        while (y < num_bots) {
      if (bots[x].getBattery() > bots[y].getBattery()) {
          nploc = bots[x].getLocation();
          
          npactive = bots[x].isActive();
          
          npbrush = bots[x].getBrush();
          
          standbybatry = bots[x].getBattery();
          
        bots[x].set(bots[y].getLocation(),
                    bots[y].getBattery(),
                    bots[y].getBrush(),
                    bots[y].isActive());
        bots[y].set(nploc, standbybatry, npbrush, npactive);
      }y++;
    }
  }
    int z=0;
  while( z < num_bots) {
    if (bots[z].isValid()) {
      bots[z].display();
    } z++;
  }

  cout << "|====================================================|" << endl;
  return 1;
}
}
