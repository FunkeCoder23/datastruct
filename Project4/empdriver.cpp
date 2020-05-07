//
//  empdriver.cpp
//  Project
//
//  Created by Noah Krill on 3/10/20.
//  Copyright © 2020 Noah Krill. All rights reserved.
//
#include <iostream>
#include "empmaps.h"

int main()
{
  //create a clock for timing
  clock_t start, stop;
  start = clock();
  std::vector<Employee> vEmployee = employees();
  stop = clock();
  std::cout << "Number of employees: " << vEmployee.size()  << '\n';
  std::cout << "Number of clock ticks: " << double(stop - start) << '\n';

  start = clock();
  std::map<int, std::vector<Employee>> mapDept = mapEmpDept(vEmployee);
  stop = clock();
  std::cout << "ORDERED Map creation with Department as key clock ticks: " << double(stop - start) << '\n';
  std::cout << "ORDERED Map number of Departments:  " << mapDept.size() << '\n';

  start = clock();
  std::map<int, std::vector<Employee>> mapSal = mapSalRange(vEmployee);
  stop = clock();
  std::cout << "ORDERED Map creation with Salary as key clock ticks: " << double(stop - start) << '\n';
  std::cout << "ORDERED Map number of Salary Ranges:  " << mapSal.size() << '\n';

  printSalRange(mapSal);

  start = clock();
  std::unordered_map<int, std::vector<Employee>> umapDept = umapEmpDept(vEmployee);
  stop = clock();
  std::cout << "UNORDERED Map creation with Department as key clock ticks: " << double(stop - start) << '\n';
  std::cout << "UNORDERED Map number of Departments:  " << umapDept.size() << '\n';

  start = clock();
  std::unordered_map<int, std::vector<Employee>> umapSal = umapSalRange(vEmployee);
  stop = clock();
  std::cout << "UNORDERED Map creation with Salary as key clock ticks: " << double(stop - start) << '\n';
  std::cout << "UNORDERED Map number of Salary Ranges:  " << umapSal.size() << '\n';

  uprintSalRange(umapSal);

  return 0;
}
