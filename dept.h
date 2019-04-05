//
// Created by agavrilenko on 05.04.19.
//

#ifndef READER_DEPT_H
#define READER_DEPT_H

#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
//#include <boost/algorithm/string.hpp>
#include <iostream>
#include <unordered_map>
#include <map>
#include "Group.h"
#include "reader.h"
class Department {
public:
    int deptNumber;

    std::map<std::string, Group> groups;
    Department(int deptNumber = 0) :
            deptNumber(deptNumber)
    { }

    Department( DataFrame table) {
        for(size_t i = 0; i < table.header.size(); i++){
            std::cout << table.header[i] << ":\n";
            groups[table.header[i]] = Group(table.header[i], table.data[i]);
        }
    }


    void print();
   // int getLessonsNumber();

};

void Department::print() {

    for (std::pair<std::string, Group> element : groups) {
        element.second.print();
        std::cout << std::endl;
    }
}

#endif //READER_DEPT_H
