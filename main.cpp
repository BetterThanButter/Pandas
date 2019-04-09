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
#include <experimental/filesystem>
#include "grade.h"

namespace fs = std::experimental::filesystem;
const std::string path_to_dir = "/home/agavrilenko/Coding/Pandas/departments_2/";

int main()
{
    // Creating an object of CSVWriter
   // DataFrame df;
    DataFrame preps;
    std::unordered_map <std::string, Professor> preps_map;

    // Get the data from CSV File
    //df.read_csv("/home/agavrilenko/Coding/Pandas/departments_2/1.csv");
    preps.read_csv("/home/agavrilenko/Coding/Pandas/data_hashed.csv");


    //load preps(check data_hashed)
    for (size_t i = 0; i< preps.data.size(); i++) {

        std::string hash = preps.data[i][9];
        preps_map[hash] = Professor(preps.data[i]);

    }

    Grade new_grade(path_to_dir, preps_map);
//paramerts
    new_grade.print("7", "", 5);


    return 0;

}