#ifndef READER_GROUP_H
#define READER_GROUP_H

#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <random>
#include <ctime>
#include "day.h"
const int default_day = 777;

class Group {
public:
    std::string groupNumber;
    std::vector <Day> days ;
    std::map<size_t, Lesson> lesson_map;

    Group(std::string groupNumber = "") :
            groupNumber(groupNumber)
            { };

    Group(std::string groupNumber, std::vector<std::string> data, std::unordered_map <std::string, Professor> preps_map) :
            groupNumber(groupNumber)
    {
        for(size_t i = 0; i < data.size(); i++) {

            //size_t key = i;
            lesson_map[i] = Lesson(i, data[i],preps_map);
            //Lesson one_lesson(i, data[i],preps_map);

//            std::vector<std::string>::const_iterator first = data.begin() + i ;
//            std::vector<std::string>::const_iterator last = data.begin() + i + 7;
//            std::vector<std::string> newVec(first, last);
//
//            Day one_day(i/7, newVec, preps_map);
//            days.push_back(one_day);
        }
    };

    void print(int day_id = default_day);
    void shuffle();
    void score();
    void swapLessons(Lesson lesson1, Lesson lesson2);
    int getLessonsNumber();

};

//void Group::swapLessons(Lesson lesson1, Lesson lesson2) {
//    Lesson extra_lesson = lesson1;
//    for (auto it = s.begin(); it != s.end(); it++) {
//        cout << *it << endl;
//    }
//}

void Group::score() {
    int Loss = 0;

}
int myrandom (int i) { return std::rand()%i;}
void Group::shuffle() {


    srand(time(0));
    std::map<size_t,Lesson> m = lesson_map;
    std::vector<size_t> v;

       for(auto i: m)
    {
        v.push_back(i.first);
    }
    random_shuffle(v.begin(), v.end(),myrandom);
    std::vector<size_t>::iterator it=v.begin();

    for(auto& i:m)
    {
        Lesson ts=i.second;
        i.second=m[*it];
        m[*it]=ts;
        it++;
    }
    lesson_map = m;

}

void Group::print(int day_id) {

    std::cout << "group_id:" << groupNumber << std::endl;

    for (size_t i = 0; i < lesson_map.size(); i++) {
        if(i%7 == 0) {
            std::cout <<"day: " << i/6 << std::endl;
        }
        std::cout << "id: " << i << " ";
        lesson_map[i].print();
        std::cout << std::endl;
    }

}



#endif //READER_GROUP_H
