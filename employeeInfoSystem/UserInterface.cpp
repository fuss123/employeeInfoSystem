//
//  UserInterface.cpp
//  employeeInfoSystem
//
//  Created by GODJin on 2017. 12. 31..
//  Copyright © 2017년 GODJin. All rights reserved.
//

#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.hpp"
using namespace std;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

enum Selection { HIRE = 1, FIRE, PROMOTE, DEMOTE, DISPLAY_ALL, DISPLAY_CURRENT, DISPLAY_FORMER, DONE = 0 };

int main() {
    Database employeeDB;
    bool done = false;
    
    while(!done) {
        int selection = displayMenu();
        switch(selection) {
            case HIRE:
                doHire(employeeDB);
                break;
            case FIRE:
                doFire(employeeDB);
                break;
            case PROMOTE:
                doPromote(employeeDB);
                break;
            case DEMOTE:
                doDemote(employeeDB);
                break;
            case DISPLAY_ALL:
                employeeDB.displayAll();
                break;
            case DISPLAY_CURRENT:
                employeeDB.displayCurrent();
                break;
            case DISPLAY_FORMER:
                employeeDB.displayFormer();
                break;
            case DONE:
                done = true;
                break;
            default:
                cerr << "Unknown command." << endl;
        }
    }
    
    return 0;
}

int displayMenu() {
    int selection;
    
    cout << endl;
    cout << "Employee Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Hire a new employee" << endl;
    cout << "2) Fire an employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) Demote an employee" << endl;
    cout << "5) List all employees" << endl;
    cout << "6) List all current employees" << endl;
    cout << "7) List all former employees" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    cin >> selection;
    
    return selection;
}

void doHire(Database& db) {
    string name;
    cout << "name: ";
    cin >> name;
    
    try {
        db.addEmployee(name);
    } catch(const exception& exception) {
        cerr << "Unable to add new employee: " << exception.what() << endl;
    }
}

void doFire(Database& db) {
    int employeeNumber;
    cout << "Employee number: ";
    cin >> employeeNumber;
    
    try {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.fire();
        cout << "Employee " << employeeNumber << " terminated." << endl;
    } catch(const exception& exception) {
        cerr << "Unable to terminate employee: " << exception.what() << endl;
    }
}

void doPromote(Database& db) {
    int employeeNumber;
    int raiseAmount;
    
    cout << "Employee number: ";
    cin >> employeeNumber;
    cout << "How much of a raise: ";
    cin >> raiseAmount;
    
    try {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.promote(raiseAmount);
    } catch(const exception& exception) {
        cerr << "Unable to promote employee: " << exception.what() << endl;
    }
}

void doDemote(Database& db) {
    int employeeNumber;
    int demeritAmount;
    
    cout << "Employee number: ";
    cin >> employeeNumber;
    cout << "How much of a demerit: ";
    cin >> demeritAmount;
    
    try {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.demote(demeritAmount);
    } catch(const exception& exception) {
        cerr << "Unable to demote employee: " << exception.what() << endl;
    }
}
