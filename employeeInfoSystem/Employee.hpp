//
//  Employee.hpp
//  employeeInfoSystem
//
//  Created by GODJin on 2017. 12. 31..
//  Copyright © 2017년 GODJin. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp
#include <string>

const int defaultStartingSalary = 30000;

class Employee {
public:
    Employee();
    void promote(int raiseAmount = 1000);
    void demote(int demeritAmount = 1000);
    void hire();
    void fire();
    void display() const;
    
    // getter, setter
    void setName(const std::string& name);
    const std::string& getName() const;
    void setEmployeeNumber(int employeeNumber);
    int getEmployeeNumber() const;
    void setSalary(int salary);
    int getSalary() const;
    bool getIsHired() const;
    
private:
    std::string mName;
    int mEmployeeNumber;
    int mSalary;
    bool mHired;
};

#endif /* Employee_hpp */
