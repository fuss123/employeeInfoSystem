//
//  Database.hpp
//  employeeInfoSystem
//
//  Created by GODJin on 2017. 12. 31..
//  Copyright © 2017년 GODJin. All rights reserved.
//

#ifndef Database_hpp
#define Database_hpp

#include <vector>
#include "Employee.hpp"

const int firstEmployeeNumber = 1000;

class Database {
public:
    Database();
    Employee& addEmployee(const std::string& name);
    Employee& getEmployee(int employeeNumber);
    Employee& getEmployee(const std::string& name);
    
    void displayAll() const;
    void displayCurrent() const;
    void displayFormer() const;
    
private:
    std::vector<Employee> mEmployees;
    int mNextEmployeeNumber;
};

#endif /* Database_hpp */
