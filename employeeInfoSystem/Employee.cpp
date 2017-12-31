//
//  Employee.cpp
//  employeeInfoSystem
//
//  Created by GODJin on 2017. 12. 31..
//  Copyright © 2017년 GODJin. All rights reserved.
//

#include "Employee.hpp"
#include <iostream>
using namespace std;

Employee::Employee()
: mName("")
, mEmployeeNumber(-1)
, mSalary(defaultStartingSalary)
, mHired(false)
{}

void Employee::promote(int raiseAmount) {
    setSalary(getSalary() + raiseAmount);
}

void Employee::demote(int demeritAmount) {
    setSalary(getSalary() - demeritAmount);
}

void Employee::hire() {
    mHired = true;
}

void Employee::fire() {
    mHired = false;
}

void Employee::display() const {
    cout << "Employee: " << getName() << endl;
    cout << "--------------------------" << endl;
    cout << (mHired? "Current Employee" : "Former Employee") << endl;
    cout << "Employee Number: " << getEmployeeNumber() << endl;
    cout << "Salary: $" << getSalary() << endl;
    cout << endl;
}

void Employee::setName(const string& name) {
    mName = name;
}

const string& Employee::getName() const {
    return mName;
}

void Employee::setEmployeeNumber(int employeeNumber) {
    mEmployeeNumber = employeeNumber;
}

int Employee::getEmployeeNumber() const {
    return mEmployeeNumber;
}

void Employee::setSalary(int salary) {
    mSalary = salary;
}

int Employee::getSalary() const {
    return mSalary;
}

bool Employee::getIsHired() const {
    return mHired;
}
