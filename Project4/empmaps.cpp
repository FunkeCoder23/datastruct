//
//  empmaps.cpp
//  Project
//
//  Created by Noah Krill on 3/10/20.
//  Copyright © 2020 Noah Krill. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>
#include "employee.h"
 
#ifndef EMPMAPS
#define EMPMAPS
//This function is the creation of new employees and takes the input from
//the user to determine which file to read from
std::vector<Employee> employees()
{
    std::ifstream file;
    std::string fileName;
    bool isOpen = false;
    std::vector<Employee> Emp;
    
    //While the file is not open go into this loop to continue
    while (!isOpen)
    {
        std::cout << "Please enter a file name to read from "<< std::endl;
        std::getline(std::cin, fileName);
        file.open(fileName);
        if (file.fail())
        {
            std::cerr << "File does not exist";
            std::exit(1);
        }
        else
        {
            isOpen=true;
        }
    }
    int identity = 0 , salary = 0;
    std::string employeeName = " ";
    while (!file.eof()) {
        file >> identity;
        file >> employeeName;
        file >> salary;
        Employee newEmp(identity, employeeName, salary);
        Emp.push_back(newEmp);
    }
    return Emp;

}
//This funciton makes an ordered map of the employees departments
std::map<int,std::vector<Employee>> mapEmpDept(std::vector<Employee> & emp)
{
    std::map<int,std::vector<Employee>> depart;
    int dept;
    for (auto const & employee : emp)
    {
        dept = employee.id()/100;
        depart[dept].push_back(employee);
    }
    return depart;
}
//This funciton makes an ordered map of the employees salary ranges
std::map<int,std::vector<Employee>> mapSalRange(std::vector<Employee> & emp)
{
    std::map<int, std::vector<Employee>> salary;
    for (auto const& employee : emp)
    {
        int salRange = (employee.sal() / 10000) * 10000;
        salary[salRange].push_back(employee);
    }
    return salary;
    
}
//This function outputs the values of the salary ranges in the ordered map
void printSalRange(std::map<int,std::vector<Employee>> & salRange)
{
  int highNumber = 0;
  int highSalary = 0;
  // iterate through each salary range in the map
  for (auto const& salaryRange : salRange)
  {
    // add up number of employees in each salary range
    int numEmp = 0;
    for (auto employee : salaryRange.second)
    {
      ++numEmp;
    }
    // determine highest employee salary range frequency
    if (numEmp > highNumber)
    {
      highNumber = numEmp;
      highSalary = salaryRange.first;
    }
    std::cout << "ORDERED Map Salary Range " << salaryRange.first << " contains " << numEmp << '\n';
  }

  std::cout << "ORDERED Map Salary Range with most employees: " << highSalary << " containing "
  << highNumber << " employees" << '\n';
}
//This funciton makes an unordered map of the employees salary ranges
std::unordered_map<int,std::vector<Employee>> umapSalRange(std::vector<Employee> & emp)
{
    std::unordered_map<int,std::vector<Employee>> salary;
    for(auto const& employee : emp)
    {
        int salaryRange = (employee.sal() / 10000) * 10000;
        salary[salaryRange].push_back(employee);
    }
    return salary;
}
//This function outputs the values of the salary ranges in the unordered map
void uprintSalRange(std::unordered_map<int, std::vector<Employee>> & salRange)
{
  int highNumber = 0;
  int highSalary = 0;
  // iterate through each salary range in the map
  for (auto const& salaryRange : salRange)
  {
    // add up number of employees in each salary range
    int numEmp = 0;
    for (auto employee : salaryRange.second)
    {
      ++numEmp;
    }
    // determine highest employee salary range frequency
    if (numEmp > highNumber)
    {
      highNumber = numEmp;
      highSalary = salaryRange.first;
    }
    std::cout << "UNORDERED Map Salary Range " << salaryRange.first << " contains " << numEmp << '\n';
  }

  std::cout << "UNORDERED Map Salary Range with most employees: " << highSalary << " containing "
  << highNumber << " employees" << '\n';
}
//This funciton makes an unordered map of the employees departments
std::unordered_map<int,std::vector<Employee>> umapEmpDept(std::vector<Employee> & emp)
{
  std::unordered_map<int, std::vector<Employee>> department;
  int dept;
  /*
   loop through all employees in the vector and
  perform integer division to find the department number
  */
  for (auto const& employee : emp)
  {
    dept = employee.id() / 100;
    department[dept].push_back(employee);
  }
  return department;
}


#endif
