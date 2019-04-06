#ifndef READER_LESSON_H
#define READER_LESSON_H

#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include "reader.h"
#include "prep.h"

class Lesson {
public:
    bool exist;
    std::string subject;
    std::string room;
    std::string professor;
    std::vector <Professor> prep_list;
    std::string time;
    Lesson(bool exist = false, std::string subject = "" ,std::string room = "", std::string professor = "", std::string time = "") :
            exist(exist),
            subject(subject),
            room(room),
            professor(professor),
            prep_list(),
            time(time)
            { };

    Lesson(size_t i, std::string data, std::unordered_map <std::string, Professor> preps_map) {

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
            //std::cout << professor << std::endl;
            //std::cout << data << std::endl;
            std::vector <std::string> raw_preps = split(professor, "_");
            for(size_t i = 0; i < raw_preps.size(); i++) {
                //std::cout << "hash: " << raw_preps[i] ;
                Professor realPrep = Professor(preps_map[raw_preps[i]]);
                prep_list.push_back(realPrep);
            }
        }
//        this->print();
//        std::cout << std::endl;
    };

    void print();

};

void Lesson::print() {

    std::cout << "subject: " << subject << " ";
    std::cout << "room: " << room << " ";

    for(size_t i = 0; i < prep_list.size(); i++) {

        prep_list[i].print();
    }
    std::cout << "time: " << time << " ";

};
#endif //READER_LESSON_H
