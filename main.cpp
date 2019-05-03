#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <dirent.h>
#include "prep.h"
#include "reader.h"
#include "dept.h"
#include <string.h>
#include "dept.h"
#include <iomanip>
#include "grade.h"

//path to project
const std::string path_to_dir = "/home/agavrilenko/Coding/Pandas/";
const std::string path_to_rawdata = "departments_2/";
const std::string path_to_preps = "data_hashed.csv";

int main()
{
    // Creating an object of CSVWriter
   // DataFrame df;
    DataFrame preps;
    std::unordered_map <std::string, Professor> preps_map;


    // Get the data from CSV File
    //df.read_csv("/home/agavrilenko/Coding/Pandas/departments_2/1.csv");

    preps.read_csv(path_to_dir + path_to_preps);
 //   preps.print(2);

    //load preps(check data_hashed)
    for (size_t i = 0; i< preps.data.size(); i++) {

        std::string hash = preps.data[i][9];
        preps_map[hash] = Professor(preps.data[i]);

    }

    Grade new_grade(path_to_dir, path_to_rawdata, preps_map);
    std::string mygroup_name = "";
    std::cin >> mygroup_name;
    Group my_group = new_grade.group_map[mygroup_name];
    //paramerts
    //new_grade.print("771");
    my_group.print();
    my_group.shuffle();
    my_group.print();



    return 0;

}