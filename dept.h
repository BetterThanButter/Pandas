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


const std::string default_group = "NaN";

class Department {
public:
    int deptNumber;

    std::map<std::string, Group> groups;
    Department(int deptNumber = 0) :
            deptNumber(deptNumber)
    { }

    Department( DataFrame table, std::unordered_map <std::string, Professor> preps_map) {
        transpose(table.data);
        for(size_t i = 0; i < table.header.size(); i++){
           // std::cout << table.header[i] << ":\n";
            groups[table.header[i]] = Group(table.header[i], table.data[i], preps_map);
        }
    }


    void print(std::string group_id = "", int day_id = default_day);
   // int getLessonsNumber();

};

void Department::print(std::string group_id, int day_id) {

    //print a group
    if (group_id != default_group) {
        std::cout << "group: " << group_id << std::endl;
        if (day_id != default_day) {
            groups[group_id].print(day_id);
        }
        else {
            groups[group_id].print();
        }

    }
    //print all groups
    else {
        for (std::pair<std::string, Group> element : groups) {
            element.second.print();
            std::cout << std::endl;
        }
    }

}

#endif //READER_DEPT_H
