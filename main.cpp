#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <map>
//#include <boost/algorithm/string.hpp>
#include <iostream>

#include "prep.h"
#include "reader.h"
#include "dept.h"
#include "dept.h"


int main()
{
    // Creating an object of CSVWriter
    DataFrame df;
    DataFrame preps;
    std::unordered_map <std::string, Professor> preps_map;

    // Get the data from CSV File
    df.read_csv("/home/agavrilenko/Coding/Pandas/rt.csv");
    preps.read_csv("/home/agavrilenko/Coding/Pandas/data_hashed.csv");
    //preps.print(1);

    for (size_t i = 0; i< preps.data.size(); i++) {
        std::string hash = preps.data[i][9];

        preps_map[hash] = Professor(preps.data[i]);

        //std:: cout << hash << std::endl;
    }

    Department new_dep(df, preps_map);
    //give print string group number and day number(int)
    new_dep.print("778");

    return 0;

}