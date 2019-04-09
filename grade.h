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
#include <bits/stdc++.h>



class Grade {
public:
    int gradeNumber;

    std::map<std::string, Department> departments;

    Grade(int gradeNumber = 0) :
            gradeNumber(gradeNumber)
    { }

    Grade( std::string path_to_dir, std::unordered_map <std::string, Professor> preps_map) {

        DIR *dir;
        struct dirent *ent;
        std::vector<std::string> file_names;
        const char* mask = ".csv";
        if ((dir = opendir ("/home/agavrilenko/Coding/Pandas/departments_2/")) != NULL) {
            /* print all the files and directories within directory */
            while ((ent = readdir (dir)) != NULL) {
                if(strstr(ent->d_name, mask) != NULL) {
                   // printf ("%s\n", ent->d_name);
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
            std::cout << path_to_dir + *i << std::endl;
            df.read_csv(path_to_dir + *i);

            std::string dep_number = (*i).substr(0, (*i).size()-4);
            Department new_dep(dep_number, df, preps_map);


            departments[dep_number] = new_dep;
        }
        std::cout <<"Files loaded." << std::endl;

    }


   void print(std::string dep_id = "", std::string group_id = "", int day_id = default_day);

};
//
void Grade::print(std::string dep_id, std::string group_id, int day_id) {

    //print a group

    if (dep_id != "") {
        departments[dep_id].print(group_id, day_id);
    }
    else {
            std::cout << "printall" << std::endl;
    }

}

#endif //READER_GRADE_H
