//
// Created by agavrilenko on 05.04.19.
//

#ifndef READER_DAY_H
#define READER_DAY_H
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
//#include <boost/algorithm/string.hpp>
#include <iostream>
#include "lesson.h"
class Day
{
public:

    std::vector <Lesson>  lessons ;
    std::string name = "";

    Day(std::string name = "friday") :
            name(name)
            { };

    Day(std::vector <std::string> data)
    {
        for(size_t i = 0; i < data.size(); i++) {
            Lesson one_lesson(i, data[i]);
            lessons.push_back(one_lesson);
        }
    };

    void print();
    int getLessonsNumber();

};

int Day::getLessonsNumber() {
    int number = 0;
    for (size_t i = 0; i < lessons.size(); i++) {
        if(lessons[i].exist == true) {
            number++;
        }
    }
    return number;
}
void Day::print() {

    for (size_t i = 0; i < lessons.size(); i++) {
        lessons[i].print();
        std::cout << std::endl;
    }
};

#endif //READER_DAY_H
