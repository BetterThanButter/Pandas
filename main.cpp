#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
//#include <boost/algorithm/string.hpp>
#include <iostream>
/*
 * A class to read data from a csv file.
 */

std::vector<std::string> split (std::string line, std::string delim);

class DataFrame
{


public:

    std::string fileName;
    std::string delimeter;
    std::vector<std::vector<std::string>> data;
    std::vector<std::string> header;

    DataFrame(std::string filename, std::string delm = ",") :
            fileName(filename), delimeter(delm)
    { }

    // Function to fetch data from a CSV File
    std::vector<std::vector<std::string>> read_csv();

    void print(int rows_number = 5);

};

void DataFrame::print(int rows_number) {
    std::cout<< "Printig data:\n";
    for (size_t i = 0; i < rows_number; i++) {
        for (size_t j = 0; j < data[i].size(); j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
};

std::vector<std::vector<std::string>>  DataFrame::read_csv()
{
    std::ifstream file(fileName);
    std::string delimiter = ";";

    size_t pos = 0;
    std::string token;


    std::vector<std::string> dataList;

    std::vector<std::string> header;
    std::string line = "";

    if(getline(file, line)) {
        std::cout << "Get header:\n";
        header = split(line, delimiter);
    }

    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        std::vector <std::string> row = split(line, delimiter);
        data.push_back(row);
    }
    // Close the File
    file.close();

    return data;
}

std::vector<std::string> split (std::string line, std::string delim) {

    size_t pos = 0;
    std::string token;
    std::vector <std::string> row;

    while ((pos = line.find(delim)) != std::string::npos) {
        token = line.substr(0, pos);
        row.push_back(token);
        line.erase(0, pos + delim.length());
    }
    return row;
}

int main()
{
    // Creating an object of CSVWriter
    DataFrame df("/home/agavrilenko/Coding/TimeTable/CSV war/reader/data.csv");

    // Get the data from CSV File
    std::vector<std::vector<std::string>> dataList = df.read_csv();

    df.print(10);

    return 0;

}