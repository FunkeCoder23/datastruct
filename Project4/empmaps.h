//
//  empmaps.h
//  Project
//
//  Created by Noah Krill on 3/10/20.
//  Copyright © 2020 Noah Krill. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include "employee.h"

#ifndef empmaps_h
#define empmaps_h

std::vector<Employee> employees();

std::map<int,std::vector<Employee>> mapEmpDept(std::vector<Employee> & emp);

std::map<int,std::vector<Employee>> mapSalRange(std::vector<Employee> & emp);

void printSalRange(std::map<int,std::vector<Employee>> & salRange);

std::unordered_map<int,std::vector<Employee>> umapEmpDept(std::vector<Employee> & emp);

std::unordered_map<int,std::vector<Employee>> umapSalRange(std::vector<Employee> & emp);

void uprintSalRange(std::unordered_map<int,std::vector<Employee>> & salRange);


#endif /* empmaps_h */
