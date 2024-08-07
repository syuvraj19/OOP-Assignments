/*
*****************************************************************************
                              milestone - 5
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : OOP-244-ZBB
Date       : 7/08/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include"LibApp.h"
#include"PublicationSelector.h"
#include<iostream>
#include<iomanip>
#include <fstream>
#include<string.h>
using namespace std;
namespace sdds {
    void LibApp::load() {
        cout << "Loading Data" << std::endl;
        ifstream infile(file_name);
        while(infile) {
            char type;
            infile >> type;
            infile.ignore();
            if (infile) {
                if (type == 'P')
                    PPA[NOLP] = new Publication;
                else if (type == 'B')
                    PPA[NOLP] = new Book;
                if (PPA[NOLP]) {
                    infile >> *PPA[NOLP++];
                }
            }
        }
        LLRN = PPA[NOLP - 1]->getRef();
    }
    void LibApp::save() {
        cout<<"Saving Data"<< endl;
        ofstream outfile(file_name);
        int i = 0;
        while ( i < NOLP) {
            if (PPA[i]->getRef()!= 0) {
                outfile <<*PPA[i]<<endl;
            }
            i++;
        }
    }
    int LibApp::search(int version) {
        
        int selection = m_pubMenu.run();
        if (selection != 0) {
            char type = selection==1?'B':'P';
            cout << "Publication Title: ";
            char name[256];
            cin.clear();
            cin.ignore(10000, '\n');
            cin.getline(name, 256);
            PublicationSelector ps("Select one of the following found matches:");
            int i = 0;
            while ( i < NOLP) {
                if (version == 0) {
                    if ((strstr(*PPA[i], name)) && PPA[i]->type() == type && PPA[i]->getRef() != 0) {
                        ps << PPA[i];
                    }
                }
                else if (version == 1) {
                    if (PPA[i]->onLoan() && (strstr(*PPA[i], name)) && PPA[i]->type() == type && PPA[i]->getRef() != 0) {
                        ps << PPA[i];
                    }
                }
                
                else {
                    if (!PPA[i]->onLoan() && (strstr(*PPA[i], name)) && PPA[i]->type() == type && PPA[i]->getRef() != 0) {
                        ps << PPA[i];
                    }
                }
                i++;

            }
            if (ps) {
                ps.sort();
                int ref = ps.run();
                if (ref) {
                    getPub(ref)->write(cout);
                    cout << endl;
                    return ref;
                }
                else {
                    cout << "Aborted!" << endl;
                    return -1;
                }
            }
            else {
                cout << "No matches found!" << endl;
                return -1;
            }
        }
        cout << "Aborted!"<<endl;
            return -1;
    }
    void LibApp::returnPub() {
        cout << "Return publication to the library" << endl;
        int ref=search(1);
        if (ref > 0) {
            if (confirm("Return Publication?")) {
                Date date(2022,7,26);
                date.setToToday();
                int days = date-(getPub(ref)->checkoutDate());
                if (days > 15) {
                    cout << "Please pay $"<< fixed << setprecision(2) << 0.5 * (days - 15) << " penalty for being " << days - 15 << " days late!" << endl;
                }
                getPub(ref)->set(0);
                cout << "Publication returned" << endl;
                m_changed = true;
            }
        }
    }
    bool LibApp::confirm(const char* message) {
        Menu menu(message);
        menu << "Yes";
        int result = menu.run();
        return (result == 1);
    }
    void LibApp::newPublication() {
        if (NOLP == SDDS_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!"<<endl;
        }
        else {
            cout << "Adding new publication to the library" << std::endl;
            int selection = m_pubMenu.run();
            if(selection){
                Publication* pub;
                if (selection == 1) {
                    pub = new Book();
                }
                else {
                    pub = new Publication();
                }
                pub->read(cin);
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Aborted!"<<endl;
                    delete pub;
                }
                else {
                    if (confirm("Add this publication to the library?") == true) {
                        if (pub) {
                            LLRN++;
                            pub->setRef(LLRN);
                            PPA[NOLP] = pub;
                            m_changed = true;
                            cout << "Publication added" << endl;
                            NOLP++;
                        }
                        else {
                            cout << "Failed to add publication!" << endl;
                            delete pub;
                        }

                    }
                    else {
                        cout << "Aborted!" << endl;
                    }
                }
            }
            else {
                        cout << "Aborted!" << endl;
            }
        }
    }
    void LibApp::removePublication() {
        cout << "Removing publication from the library" << std::endl;
        int ref=search(0);
        if (ref >=0) {
            if (confirm("Remove this publication from the library?")) {
                getPub(ref)->setRef(0);
                m_changed = true;
                cout << "Publication removed" << endl;
            }
        }
    }


    void LibApp::checkOutPub() {
        cout << "Checkout publication from the library" << endl;
        int ref=search(2);
        if(ref>=0)
        if (confirm("Check out publication?")) {
            int memNum;
            cout << "Enter Membership number: ";
            cin >> memNum;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                memNum = -10;
            }
            while (memNum > 99999 || memNum < 10000) {
                cout << "Invalid membership number, try again: ";
                cin >> memNum;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    memNum = -10;
                }
            }
            getPub(ref)->set(memNum);
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
    }
    
    LibApp::LibApp(const char* fname) :m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_pubMenu("Choose the type of publication:") {
        strcpy(file_name,fname);
        m_changed = false;
        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";
        m_exitMenu << "Save changes and exit"
            << "Cancel and go back to the main menu";
        m_pubMenu << "Book" << "Publication";
        NOLP = 0;
        load();
    }
    void LibApp::run() {
        bool select = true;
        do {
            select = true;
            switch (m_mainMenu.run()) {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            default:
                if (m_changed==true) {
                    switch (m_exitMenu.run()){
                    case 1:
                        save();
                            select = false;
                        break;
                    case 2:
                            select = true;
                        break;
                    default:
                        if (confirm("This will discard all the changes are you sure?")) {
                            select = false;
                        }
                        else {
                            select = true;
                        }
                    }


                }
                else
                    select = false;
            }
            cout << endl;
        }while (select==true);
        cout << "-------------------------------------------" << endl
            << "Thanks for using Seneca Library Application" << endl;
    }
    Publication* LibApp::getPub(int libRef)
    {
        for (int i = 0; i < NOLP; i++) {
            if (PPA[i]->getRef() == libRef) {
                return PPA[i];
            }
        }
        return nullptr;
    }
    LibApp::~LibApp() {
        for (int i = 0; i < NOLP; i++)
            delete PPA[i];
    }
}
