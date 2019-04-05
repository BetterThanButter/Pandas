//
// Created by agavrilenko on 05.04.19.
//

#ifndef READER_LESSON_H
#define READER_LESSON_H

#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
//#include <boost/algorithm/string.hpp>
#include <iostream>

#include "reader.h"


class Lesson {
public:
    bool exist;
    std::string subject;
    std::string room;
    std::string professor;
    std::string time;
    Lesson(bool exist = false, std::string subject = "" ,std::string room = "", std::string professor = "", std::string time = "") :
            exist(exist),
            subject(subject),
            room(room),
            professor(professor),
            time(time)
            { };

    Lesson(std::string data) {
                std::vector <std::string> tt = split(data, "#");
        if (tt[0] != "") {
            exist =true;
            subject = tt[0];
            professor = tt[1];
            room = tt[2];
        }
        this->print();
        std::cout << std::endl;
    };

    void print();

};

void Lesson::print() {

    std::cout << "subject: " << subject << " ";
    std::cout << "room: " << room << " ";
    std::cout << "professor: " << professor << " ";
    std::cout << "time: " << time << " ";

};
#endif //READER_LESSON_H
