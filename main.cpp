#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
//#include <boost/algorithm/string.hpp>
#include <iostream>


#include "reader.h"
#include "dept.h"
//#include "dept.h"


int main()
{
    // Creating an object of CSVWriter



    DataFrame df;

    // Get the data from CSV File
    df.read_csv("/home/agavrilenko/Coding/Pandas/rt.csv");
    //df.print(1);
    Department new_dep(df);
    new_dep.print("777");


    return 0;

}