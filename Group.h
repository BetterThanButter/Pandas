#ifndef READER_GROUP_H
#define READER_GROUP_H

#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include "day.h"
const int default_day = 777;

class Group {
public:
    std::string groupNumber;
    std::vector <Day> days ;

    Group(std::string groupNumber = "") :
            groupNumber(groupNumber)
            { };

    Group(std::string groupNumber, std::vector<std::string> data) :
            groupNumber(groupNumber)
    {
        for(size_t i = 0; i < data.size(); i+=7) {

            std::vector<std::string>::const_iterator first = data.begin() + i ;
            std::vector<std::string>::const_iterator last = data.begin() + i + 7;
            std::vector<std::string> newVec(first, last);

            Day one_day(i/7, newVec);
            days.push_back(one_day);
        }
    };

    void print(int day_id = default_day);
    int getLessonsNumber();

};

void Group::print(int day_id) {

    if(day_id != default_day ){
        days[day_id].print();
    }
    else {
        for (size_t i = 0; i < days.size(); i++) {
            days[i].print();
            std::cout << std::endl;
        }
    }

}



#endif //READER_GROUP_H
