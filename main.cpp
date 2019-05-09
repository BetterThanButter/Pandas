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

double score_preps(DataFrame preps) {
    double avg_score = 0;
    std::string::size_type sz;

    for (size_t i = 0; i < preps.data.size(); i++) {
        double score = std::stod (preps.data[i][8],&sz);
        avg_score+= score;
    }

    return avg_score/preps.data.size();
}



Group optimize(Grade grade,Group current, DataFrame preps);

int main()
{
    // Creating an object of CSVWriter

    DataFrame preps(",");
    std::unordered_map <std::string, Professor> preps_map;

    std::cout << "Loading preps ..." << std::endl;
    preps.read_csv(path_to_dir + path_to_preps);

   // std::cout << "avg_score: " << avg_score << std::endl;

    //load preps(check data_hashed)
    for (size_t i = 0; i< preps.data.size(); i++) {

        std::string hash = preps.data[i][9];
        preps_map[hash] = Professor(preps.data[i]);

    }

    Grade new_grade(path_to_dir, path_to_rawdata, preps_map);

    //new_grade.print();
    //Group my_group = new_grade.group_map[3];
    Group my_group1 = optimize(new_grade, new_grade.group_map[6], preps);
    my_group1.print();
   // my_group.print();
  //  double score = my_group.score(avg_score);

   // std::cout << "score777 = " << my_group.score(preps) << " score778 = " << my_group1.score(preps) << std::endl;
    return 0;

}

Group optimize(Grade grade,Group current, DataFrame preps) {

    std::vector<std::pair<double,int >> lessons_score;
    double avg_score = score_preps(preps) /2 ;
    for (auto & x : current.lesson_map) {
        std::pair<double,int> p1 = {x.score(avg_score),x.lesson_id};
        lessons_score.push_back(p1);
    }

    sort(lessons_score.begin(), lessons_score.end());
    std::vector <int> id_for_swap = {};
    for (int i=0; i<std::fmin(lessons_score.size(), 30); i++){
        id_for_swap.push_back(lessons_score[i].second);
    }


    for(int i = 0; i < id_for_swap.size(); i++) {
        if (current.lesson_map[id_for_swap[i]].exist) {
            if (current.lesson_map[id_for_swap[i]].moveable){
                Lesson shit = current.lesson_map[id_for_swap[i]];
                //shit.print();
                for(int j = 0; j < grade.group_map.size(); j++) {
                    for (int k = 0; k < grade.group_map[j].lesson_map.size(); k++) {
                        if (grade.group_map[j].lesson_map[k].subject == shit.subject) {
                            if(grade.group_map[j].lesson_map[k].score(avg_score) >= shit.score(avg_score)) {
                                current.lesson_map[id_for_swap[i]].exist = false;
                                current.lesson_map[k] = grade.group_map[j].lesson_map[k];

                                break;
                            }
                            break;
                        }

                    }
                }

            }
        }

    }

    for (auto const& x : grade.group_map) {
        std::set<std::string> intersect;
        set_intersection(x.lesson_set.begin(),x.lesson_set.end(),current.lesson_set.begin(),current.lesson_set.end(),
                         std::inserter(intersect,intersect.begin()));
        if(!intersect.empty())
        {

           // std::cout << " not empty" << std::endl;
        }
    }
    return current;

}