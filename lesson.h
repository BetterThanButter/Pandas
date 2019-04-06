#ifndef READER_LESSON_H
#define READER_LESSON_H

#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

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

    Lesson(size_t i, std::string data) {

        std::map< int, std::string > time_splits;
        time_splits[0] = "9:00-10:25";
        time_splits[1] = "10:45-12:10";
        time_splits[2] = "12:20-13:45";
        time_splits[3] = "13:55-15:20";
        time_splits[4] = "15:30-16:55";
        time_splits[5] = "17:05-18:30";
        time_splits[6] = "18:35-20:00";

        std::vector <std::string> raw_data = split(data, "#");

        if (raw_data[0] != "") {
            exist = true;
            subject = raw_data[0];
            professor = raw_data[1];
            room = raw_data[2];
            time = time_splits[i];
        }
//        this->print();
//        std::cout << std::endl;
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
