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
class CleanerBot{

char  location[50];
double battery; 
int brush;
bool is_active;

int getLowBatteryBots(CleanerBot* bot, const short num_bots);
void sort_bots(CleanerBot* bot, const short num_bots);
public:
CleanerBot();
CleanerBot(const char location[],double battery,int brush,bool active);
 ~CleanerBot();
void set(const char location[],double battery,int brush,bool active);
void setLocation(const char location[]);
void setActive(bool isActive);
const char* getLocation();
double getBattery();
int getBrush();
bool isActive();
bool isValid();
void display();
int report(CleanerBot* bot, const short num_bots);
};


namespace sdds{
void report(CleanerBot* bot, const short num_bots);
int getLowBatteryBots(CleanerBot* bot, const short num_bots);
void sort_bots(CleanerBot* bot, const short num_bots);
}
