/***********************************************************************
 NAME : Yuvraj Singh
 CLASS : OOP244
 SECTION : ZBB
 STUDENT NUMBER : 155580210
 EMAIL : yuvraj-singh5@myseneca.cas
DATE CREATED ON : 22 JULY 2022
WORKSHOP 8 PART 1

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include "SavingsAccount.h"
#include<iomanip>
using namespace std;
namespace sdds{
SavingsAccount::SavingsAccount(double bal, double intr):Account(bal){
	if (intr >= 0) {
		interestRate = intr;
	}
	else {
		interestRate = 0.0;
	}
}
void SavingsAccount::monthEnd(){
	credit(balance() * interestRate);
}
void SavingsAccount::display(std::ostream& os) const
{

	os << "Account type: Savings" << endl;
	os << "Balance: $" << fixed<<setprecision(2) << balance() << endl;
	os << "Interest Rate (%): " << setprecision(2) <<fixed<<interestRate*100<< endl;

}
}
