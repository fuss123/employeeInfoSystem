//
//  Database.cpp
//  employeeInfoSystem
//
//  Created by GODJin on 2017. 12. 31..
//  Copyright © 2017년 GODJin. All rights reserved.
//

#include "Database.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

Database::Database()
: mNextEmployeeNumber(firstEmployeeNumber)
{}

Employee& Database::addEmployee(const string& name) {
    Employee theEmployee;
    theEmployee.setName(name);
    theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
    theEmployee.hire();
    mEmployees.push_back(theEmployee);
    
    return mEmployees[mEmployees.size() - 1];
}

Employee& Database::getEmployee(int employeeNumber) {
    for(auto& employee : mEmployees) {
        if(employee.getEmployeeNumber() == employeeNumber)
            return employee;
    }
    
    throw runtime_error("No employee found.");
}

Employee& Database::getEmployee(const string &name) {
    for(auto& employee : mEmployees) {
        if(employee.getName() == name)
            return employee;
    }
    
    throw runtime_error("No employee found.");
}

void Database::displayAll() const {
    for(const auto& employee : mEmployees)
        employee.display();
}

void Database::displayCurrent() const {
    for(const auto& employee : mEmployees) {
        if(employee.getIsHired())
            employee.display();
    }
}

void Database::displayFormer() const {
    for(const auto& employee : mEmployees) {
        if(!employee.getIsHired())
            employee.display();
    }
}
