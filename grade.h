//
// Created by agavrilenko on 09.04.19.
//

#ifndef READER_GRADE_H
#define READER_GRADE_H

#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <map>
#include "Group.h"
#include "reader.h"
#include "dept.h"
#include <dirent.h>
#include <string.h>




class Grade {
public:
    int gradeNumber;
    int daysNumber;
    int lessonNumbers;

    //std::map<std::string, Department> departments;
    std::map<std::string, Group> group_map;

    Grade(int gradeNumber = 0, int daysNumber = 6, int lessonNumbers = 7) :
            gradeNumber(gradeNumber),
            daysNumber(daysNumber),
            lessonNumbers(lessonNumbers)
    { }

    Grade( const std::string path_to_dir, const std::string path_to_rawdata, std::unordered_map <std::string, Professor> preps_map, int daysNumber, int lessonNumbers) {

        this->daysNumber = daysNumber;
        this->lessonNumbers = lessonNumbers;
        DIR *dir;
        struct dirent *ent;
        std::vector<std::string> file_names;

        const char* mask = ".txt";
        const std::string path = path_to_dir + path_to_rawdata;


        if ((dir = opendir(path.c_str())) != NULL) {
            /* print all the files and directories within directory */
            while ((ent = readdir (dir)) != NULL) {
                if(strstr(ent->d_name, mask) != NULL) {
                   printf ("%s\n", ent->d_name);
                    std::string str(ent->d_name);
                    file_names.push_back(ent->d_name);
                }
            }
            closedir (dir);
        } else {
            /* could not open directory */
            perror ("");
        }
        sort(file_names.begin(), file_names.end());

        std::cout <<"Processing .csv files ..." << std::endl;

        for (std::vector<std::string>::const_iterator i = file_names.begin(); i != file_names.end(); ++i) {

            DataFrame df;

            std::cout << path + *i << std::endl;
            df.read_csv(path + *i, ";");

            std::string dep_number = (*i).substr(0, (*i).size()-4);
            //Department new_dep(dep_number, df, preps_map);

            transpose(df.data);
           // deptNumber = dep_number;
            for(size_t i = 0; i < df.header.size(); i++){
                //std::cout << "ajsjdl";
                std::cout << df.header[i] << ":\n";
                group_map[df.header[i]] = Group(df.header[i],df.data[i], preps_map, daysNumber, lessonNumbers);
            }

            //departments[dep_number] = new_dep;
        }
        std::cout <<"Files loaded." << std::endl;

    }


   void print(std::string group_id = "777", int day_id = default_day);

};
//
void Grade::print(std::string group_id, int day_id) {

    //print a group
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~ Printing ~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
//    if (dep_id != "") {
//
//        departments[dep_id].print(group_id, day_id);
//    }
//    else {
//            std::cout << "printall" << std::endl;
//    }

   // group_map[group_id].print();

}

#endif //READER_GRADE_H
